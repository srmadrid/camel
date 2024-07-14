/// IMPLEMENT EFFICIENT ITERATORS SO THAT IN THE ADD (AND OTHER FUNCTIONS)
/// INSTEAD OF CALLING `_position` AND `_index` WHEN THE ORDER IS NOT THE SAME
/// (VERY INNEFICIENT), AN EFFICIENT ITERATOR IS USED INSTEAD. THIS WAY THE
/// LOOPS FOR BOTH CASES CAN JUST BE THE SAME.
///
/// REMOVE SPECIFIC ORDERING (`RowMajor` AND `ColumnMajor`) AND REPLCAE IT WITH
/// ANY CUSTOM ORDERING (AFTER ALL IT JUST AFFECTS THE STRIDES SLICE).
///
/// ADD FLAGS LIKE NUMPY (LIKE OWNED, VIEW, ETC.) AND CREATE VIEWS (JUST HAVE A
/// VIEW OR UNOWNED FLAG WITH (MAYBE) DIFFERENT METADATA (STRIDES, ORDERING,
/// SHAPE, ETC.).
const std = @import("std");
const camel = @import("../camel.zig");
const core = @import("../core/core.zig");

const _add = core.supported._add;
const _sub = core.supported._sub;
const _mult = core.supported._mult;
const _div = core.supported._div;

/// Maximal number of dimensions.
pub const MaxDimensions = 32;

/// An n-dimensional array of elements of type `T`. Initialize with `init` and
/// deinitialize with `deinit`.
///
/// Only supports the following types for `T`:
/// - Integers: u8, u16, u32, u64, u128, i8, i16, i32, i64, i128
/// - Floating-point numbers: f16, f32, f64, f128
/// - Booleans: bool
/// - Custom types: cf16, cf32, cf64, cf128, BigInt, Fraction, Complex,
///                 Expression
///
/// Stores an allocator for internal memory management.
pub fn NDArray(comptime T: type) type {
    // Catch any attempt to create with unsupported type.
    _ = core.supported.whatSupportedNumericType(T);
    return struct {
        const Self: type = @This();
        /// The data of the matrix.
        data: []T,
        /// The shape of the array, i.e., the dimensions of the array.
        shape: []usize,
        /// The strides of the array. These are the number of elements to skip
        /// to get the next element in each dimension.
        strides: []usize,
        /// Total number of elements in the array.
        size: usize,
        /// Flags holding info on the storage of the array.
        flags: usize,
        /// The allocator used for internal memory management.
        allocator: std.mem.Allocator,

        /// Initializes a matrix with the given shape and default RowMajor
        /// order. It is highly recommended to initialize all elements of the
        /// matrix after calling this function using the `set` or `setAll`
        /// functions. Failure to do so may result in undefined behavior if the
        /// uninitialized elements are accessed before being set.
        ///
        /// Deinitialize with `deinit`.
        pub fn init(allocator: std.mem.Allocator, shape: []const usize) !Self {
            return initOrder(allocator, shape, NDArrayFlag.RowMajorContiguous | NDArrayFlag.OwnsData | NDArrayFlag.Writeable);
        }

        /// Initializes an array with the given shape and order. It is highly
        /// recommended to initialize all elements of the array after calling
        /// this function using the `set` or `setAll` functions. Failure to do
        /// so may result in undefined behavior if the uninitialized elements
        /// are accessed before being set.
        ///
        /// Deinitialize with `deinit`.
        pub fn initOrder(allocator: std.mem.Allocator, shape: []const usize, flags: usize) !Self {
            if (shape.len > MaxDimensions) {
                return NDArrayError.TooManyDimensions;
            }

            for (shape) |dim| {
                if (dim == 0) {
                    return NDArrayError.ZeroDimension;
                }
            }

            var size: usize = 1;
            var shapes: []usize = try allocator.alloc(usize, shape.len);
            var strides: []usize = try allocator.alloc(usize, shape.len);
            if (shape.len > 0) {
                if (flags & NDArrayFlag.RowMajorContiguous) {
                    for (0..shape.len) |i| {
                        strides[shape.len - i - 1] = size;
                        size *= shape[shape.len - i - 1];
                        shapes[i] = shape[i];
                    }
                } else {
                    for (0..shape.len) |i| {
                        strides[i] = size;
                        size *= shape[i];
                        shapes[i] = shape[i];
                    }
                }
            }

            return Self{
                .data = try allocator.alloc(T, size),
                .shape = shapes,
                .strides = strides,
                .size = size,
                .flags = flags,
                .allocator = allocator,
            };
        }

        /// Deinitializes the array, freeing the data. The user is responsible
        /// for deinitializing the elements of `data` for custom types.
        pub fn deinit(self: *Self) void {
            self.allocator.free(self.shape);
            self.allocator.free(self.strides);
            if (self.flags & NDArrayFlag.OwnsData) {
                self.allocator.free(self.data);
            }

            self.* = undefined;
        }

        /// Deinitializes an element of the array. Only defined for custom
        /// types. For a scalar, any position will yield the only element.
        pub fn deinitElement(self: *Self, position: []const usize) !void {
            const supported = core.supported.whatSupportedNumericType(T);
            switch (supported) {
                .BuiltinInt, .BuiltinFloat, .BuiltinBool, .CustomComplexFloat => @compileError("deinitElement only defined on types that need to be deinitialized."),
                .CustomInt, .CustomReal, .CustomComplex, .CustomExpression => {
                    if (self.isScalar()) {
                        self.data[0].deinit();
                        return;
                    }

                    try self.checkPosition(position);

                    self.data[self._index(position)].deinit();
                },
                .Unsupported => unreachable,
            }
        }

        /// Deinitializes all elements of the array. Only defined for custom
        /// types.
        pub fn deinitAllElements(self: *Self) void {
            const supported = core.supported.whatSupportedNumericType(T);
            switch (supported) {
                .BuiltinInt, .BuiltinFloat, .BuiltinBool, .CustomComplexFloat => @compileError("deinitAllElements only defined on types that need to be deinitialized."),
                .CustomInt, .CustomReal, .CustomComplex, .CustomExpression => {
                    for (self.data) |element| {
                        element.deinit();
                    }
                },
                .Unsupported => unreachable,
            }
        }

        /// Calculates the index of the element at the given position of the
        /// array.
        ///
        /// No bounds checking is performed.
        pub inline fn _index(self: Self, position: []const usize) usize {
            var idx: usize = 0;
            for (0..self.shape.len) |i| {
                idx += position[i] * self.strides[i];
            }

            return idx;
        }

        /// Calculates the postion of the element at the given index in the
        /// data of the array.
        ///
        /// No bounds checking is performed.
        pub inline fn _position(self: Self, index: usize, position: []usize) void {
            var idx: usize = index;
            if (self.order == NDArrayOrder.RowMajor) {
                for (0..self.strides.len) |i| {
                    position[i] = idx / self.strides[i];
                    idx %= self.strides[i];
                }
            } else {
                for (0..self.strides.len) |i| {
                    position[position.len - i - 1] = idx / self.strides[self.strides.len - i - 1];
                    idx %= self.strides[self.strides.len - i - 1];
                }
            }
        }

        /// Checks if the given position is within the bounds of the array and
        /// matches its dimensions.
        ///
        /// This function should be used before accessing elements in the array
        /// to prevent `PositionOutOfBounds` and `DimensionMismatch` errors.
        fn checkPosition(self: Self, position: []const usize) !void {
            if (position.len != self.shape.len) {
                return NDArrayError.DimensionMismatch;
            }

            for (0..position.len) |i| {
                if (position[i] >= self.shape[i]) {
                    return NDArrayError.PositionOutOfBounds;
                }
            }
        }

        /// Sets the value at the given position, if the position is correct.
        /// For a scalar, any position will yield the only element.
        ///
        /// For custom types, the array will take ownership of the value and,
        /// therefore, should not be used outside of the array, although it
        /// should still be manually deinitialized before deinitializing the
        /// array. If there was already an element in that positon, it will be
        /// overwritten and a memory leak will occur, unless another copy of the
        /// value was kept elsewhere.
        pub fn set(self: *Self, position: []const usize, value: T) !void {
            if (self.isScalar()) {
                self.data[0] = value;
                return;
            }

            try self.checkPosition(position);

            self.data[self._index(position)] = value;
        }

        /// Sets all elements of the array to the input value.
        ///
        /// For custom types, the array will take ownership of the value and,
        /// therefore, should not be used outside of the array, although it
        /// should still be manually deinitialized before deinitializing the
        /// array. If there was already an element at some position, it will be
        /// overwritten and a memory leak will occur, unless another copy of the
        /// value was kept elsewhere.
        pub fn setAll(self: *Self, value: T) void {
            self.data[0] = value;

            const supported = core.supported.whatSupportedNumericType(T);
            switch (supported) {
                .BuiltinInt, .BuiltinFloat, .BuiltinBool, .CustomComplexFloat => {
                    for (1..self.size) |i| {
                        self.data[i] = value;
                    }
                },
                .CustomInt, .CustomReal, .CustomComplex, .CustomExpression => {
                    for (1..self.size) |i| {
                        self.data[i] = try T.init(self.allocator, value);
                    }
                },
                .Unsupported => unreachable,
            }
        }

        /// Sets the value at the given position and returns the previous value.
        /// For a scalar, any position will yield the only element.
        ///
        /// For custom types, the array takes ownership of the new value.
        /// Therefore, the new value should not be used outside of the array
        /// after being set, although it should still be manually deinitialized
        /// before deinitializing the array. The old value is returned, so it
        /// can be used or deinitialized as needed.
        pub fn replace(self: *Self, position: []const usize, value: T) !T {
            var idx: usize = undefined;
            if (self.isScalar()) {
                idx = 0;
            } else {
                try self.checkPosition(position);
                idx = self._index(position);
            }

            const prev: T = self.data[idx];
            self.data[idx] = value;
            return prev;
        }

        /// Sets the value at the given position by updating the already
        /// prexistent element. For a scalar, any position will yield the only
        /// element.
        ///
        /// This function is useful when you want to change the value at a
        /// position in the array without causing the array to take ownership of
        /// the new value. The new value can continue to be used outside of the
        /// array after this function is called.
        ///
        /// For builting numeric types (uxx, ixx, fxx) it is equivalent to
        /// `set`.
        ///
        /// For custom types, calling this on an uninitiallized element will
        /// cause undefined behavior.
        pub fn update(self: *Self, position: []const usize, value: anytype) !void {
            var idx: usize = undefined;
            if (self.isScalar()) {
                idx = 0;
            } else {
                try self.checkPosition(position);
                idx = self._index(position);
            }
            const supported = core.supported.whatSupportedNumericType(T);
            switch (supported) {
                .BuiltinInt, .BuiltinFloat, .BuiltinBool, .CustomComplexFloat => {
                    self.data[idx] = value;
                },
                .CustomReal, .CustomComplex, .CustomExpression => {
                    try self.data[idx].set(value);
                },
                else => unreachable,
            }
        }

        /// Updates all elements of the array to the input value.
        ///
        /// This function is useful when you want to change all the elements in
        /// the array without causing the array to take ownership of the new
        /// value. The new value can continue to be used outside of the array
        /// after this function is called.
        ///
        /// For builting numeric types (uxx, ixx, fxx) it is equivalent to
        /// `setAll`.
        ///
        /// For custom types, calling this when any element is uninitiallized
        /// will cause undefined behavior.
        pub fn updateAll(self: *Self, value: T) !void {
            const supported = core.supported.whatSupportedNumericType(T);
            switch (supported) {
                .BuiltinInt, .BuiltinFloat, .BuiltinBool, .CustomComplexFloat => {
                    for (0..self.size) |i| {
                        self.data[i] = value;
                    }
                },
                .CustomInt, .CustomReal, .CustomComplex, .CustomExpression => {
                    for (0..self.size) |i| {
                        try self.data[i].set(value);
                    }
                },
                .Unsupported => unreachable,
            }
        }

        /// Gets the element at the given position. For a scalar, any position
        /// will yield the only element.
        pub fn get(self: Self, position: []const usize) !T {
            if (self.isScalar()) {
                return self.data[0];
            }

            try self.checkPosition(position);
            return self.data[self._index(position)];
        }

        /// Checks if the array is a scalar.
        pub fn isScalar(self: Self) bool {
            return self.size == 1;
        }

        /// Checks if the array is a vector (1D array).
        pub fn isVector(self: Self) bool {
            return self.shape.len == 1;
        }

        /// Checks if the array is a row vector (1xN).
        pub fn isRowVector(self: Self) bool {
            return self.shape.len == 2 and self.shape[0] == 1 and self.shape[1] > 1;
        }

        /// Checks if the array is a column vector (Nx1).
        pub fn isColVector(self: Self) bool {
            return self.shape.len == 2 and self.shape[0] > 1 and self.shape[1] == 1;
        }

        /// Checks if the array is a matrix (2D array).
        pub fn isMatrix(self: Self) bool {
            return self.shape.len == 2;
        }

        // TODO: Implement the following functions (only for matrices)
        // - isSquare
        // - isUpperTriangular
        // - isLowerTriangular
        // - isSymmetric
        // - isSkewSymmetric
        // - isHermitian
        // - isSkewHermitian
        // - more property checking functions

        /// Computes elementwise addition (self = left - right). If only one  of
        /// them is a scalar, it is added to all the elements of the other
        /// array.
        pub fn add(self: *Self, left: Self, right: Self) !void {
            var oneIsScalar: bool = undefined;
            var leftIsScalar: bool = undefined;
            var bothAreScalar: bool = undefined;
            if (left.isScalar() and !right.isScalar()) {
                oneIsScalar = true;
                leftIsScalar = true;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, right.shape)) {
                    return NDArrayError.IncompatibleDimensions;
                }
            } else if (!left.isScalar() and right.isScalar()) {
                oneIsScalar = true;
                leftIsScalar = false;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, left.shape)) {
                    return NDArrayError.IncompatibleDimensions;
                }
            } else if (left.isScalar() and right.isScalar()) {
                bothAreScalar = true;
            } else {
                oneIsScalar = false;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, left.shape) or
                    !std.mem.eql(usize, left.shape, right.shape))
                {
                    return NDArrayError.IncompatibleDimensions;
                }
            }

            if (bothAreScalar) {
                _add(&self.data[0], left.data[0], right.data[0]);
                return;
            }
            if (oneIsScalar) {
                if (leftIsScalar) {
                    if (self.order == right.order) {
                        const scalar: T = left.data[0];
                        for (0..self.size) |i| {
                            _add(&self.data[i], scalar, right.data[i]);
                        }
                    } else {
                        const scalar: T = left.data[0];
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order
                            self._position(i, position);
                            _add(&self.data[i], scalar, right.data[right._index(position)]);
                        }
                    }
                } else {
                    if (self.order == left.order) {
                        const scalar: T = right.data[0];
                        for (0..self.size) |i| {
                            _add(&self.data[i], left.data[i], scalar);
                        }
                    } else {
                        const scalar: T = right.data[0];
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order
                            self._position(i, position);
                            _add(&self.data[i], left.data[left._index(position)], scalar);
                        }
                    }
                }
            } else {
                if (self.order == left.order and self.order == right.order) {
                    for (0..self.size) |i| {
                        _add(&self.data[i], left.data[i], right.data[i]);
                    }
                } else {
                    // Follow the order common to two of them (better caching).
                    if (self.order == left.order or self.order == right.order) {
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order (also used by left or right).
                            self._position(i, position);
                            _add(&self.data[i], left.data[left._index(position)], right.data[right._index(position)]);
                        }
                    } else {
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow left's order (also used by right).
                            left._position(i, position);
                            _add(&self.data[self._index(position)], left.data[i], right.data[i]);
                        }
                    }
                }
            }
        }

        /// Computes elementwise subtraction (self = left - right). If only one
        /// of them is a scalar, it is added to all the elements of the other
        /// array.
        pub fn sub(self: *Self, left: Self, right: Self) !void {
            var oneIsScalar: bool = undefined;
            var leftIsScalar: bool = undefined;
            var bothAreScalar: bool = undefined;
            if (left.isScalar() and !right.isScalar()) {
                oneIsScalar = true;
                leftIsScalar = true;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, right.shape)) {
                    return NDArrayError.IncompatibleDimensions;
                }
            } else if (!left.isScalar() and right.isScalar()) {
                oneIsScalar = true;
                leftIsScalar = false;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, left.shape)) {
                    return NDArrayError.IncompatibleDimensions;
                }
            } else if (left.isScalar() and right.isScalar()) {
                bothAreScalar = true;
            } else {
                oneIsScalar = false;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, left.shape) or
                    !std.mem.eql(usize, left.shape, right.shape))
                {
                    return NDArrayError.IncompatibleDimensions;
                }
            }

            if (bothAreScalar) {
                _sub(&self.data[0], left.data[0], right.data[0]);
                return;
            }
            if (oneIsScalar) {
                if (leftIsScalar) {
                    if (self.order == right.order) {
                        const scalar: T = left.data[0];
                        for (0..self.size) |i| {
                            _sub(&self.data[i], scalar, right.data[i]);
                        }
                    } else {
                        const scalar: T = left.data[0];
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order
                            self._position(i, position);
                            _sub(&self.data[i], scalar, right.data[right._index(position)]);
                        }
                    }
                } else {
                    if (self.order == left.order) {
                        const scalar: T = right.data[0];
                        for (0..self.size) |i| {
                            _sub(&self.data[i], left.data[i], scalar);
                        }
                    } else {
                        const scalar: T = right.data[0];
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order
                            self._position(i, position);
                            _sub(&self.data[i], left.data[left._index(position)], scalar);
                        }
                    }
                }
            } else {
                if (self.order == left.order and self.order == right.order) {
                    for (0..self.size) |i| {
                        _sub(&self.data[i], left.data[i], right.data[i]);
                    }
                } else {
                    // Follow the order common to two of them (better caching).
                    if (self.order == left.order or self.order == right.order) {
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order (also used by left or right).
                            self._position(i, position);
                            _sub(&self.data[i], left.data[left._index(position)], right.data[right._index(position)]);
                        }
                    } else {
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow left's order (also used by right).
                            left._position(i, position);
                            _sub(&self.data[self._index(position)], left.data[i], right.data[i]);
                        }
                    }
                }
            }
        }

        /// Computes elementwise multiplication (self = left .* right). If only
        /// one of them is a scalar, it is added to all the elements of the
        /// other array.
        pub fn multElementWise(self: *Self, left: Self, right: Self) !void {
            var oneIsScalar: bool = undefined;
            var leftIsScalar: bool = undefined;
            var bothAreScalar: bool = undefined;
            if (left.isScalar() and !right.isScalar()) {
                oneIsScalar = true;
                leftIsScalar = true;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, right.shape)) {
                    return NDArrayError.IncompatibleDimensions;
                }
            } else if (!left.isScalar() and right.isScalar()) {
                oneIsScalar = true;
                leftIsScalar = false;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, left.shape)) {
                    return NDArrayError.IncompatibleDimensions;
                }
            } else if (left.isScalar() and right.isScalar()) {
                bothAreScalar = true;
            } else {
                oneIsScalar = false;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, left.shape) or
                    !std.mem.eql(usize, left.shape, right.shape))
                {
                    return NDArrayError.IncompatibleDimensions;
                }
            }

            if (bothAreScalar) {
                _mult(&self.data[0], left.data[0], right.data[0]);
                return;
            }
            if (oneIsScalar) {
                if (leftIsScalar) {
                    if (self.order == right.order) {
                        const scalar: T = left.data[0];
                        for (0..self.size) |i| {
                            _mult(&self.data[i], scalar, right.data[i]);
                        }
                    } else {
                        const scalar: T = left.data[0];
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order
                            self._position(i, position);
                            _mult(&self.data[i], scalar, right.data[right._index(position)]);
                        }
                    }
                } else {
                    if (self.order == left.order) {
                        const scalar: T = right.data[0];
                        for (0..self.size) |i| {
                            _mult(&self.data[i], left.data[i], scalar);
                        }
                    } else {
                        const scalar: T = right.data[0];
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order
                            self._position(i, position);
                            _mult(&self.data[i], left.data[left._index(position)], scalar);
                        }
                    }
                }
            } else {
                if (self.order == left.order and self.order == right.order) {
                    for (0..self.size) |i| {
                        _mult(&self.data[i], left.data[i], right.data[i]);
                    }
                } else {
                    // Follow the order common to two of them (better caching).
                    if (self.order == left.order or self.order == right.order) {
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order (also used by left or right).
                            self._position(i, position);
                            _mult(&self.data[i], left.data[left._index(position)], right.data[right._index(position)]);
                        }
                    } else {
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow left's order (also used by right).
                            left._position(i, position);
                            _mult(&self.data[self._index(position)], left.data[i], right.data[i]);
                        }
                    }
                }
            }
        }

        /// Computes elementwise division (self = left ./ right). If only one of
        /// them is a scalar, it is added to all the elements of the other
        /// array.
        pub fn divElementWise(self: *Self, left: Self, right: Self) !void {
            var oneIsScalar: bool = undefined;
            var leftIsScalar: bool = undefined;
            var bothAreScalar: bool = undefined;
            if (left.isScalar() and !right.isScalar()) {
                oneIsScalar = true;
                leftIsScalar = true;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, right.shape)) {
                    return NDArrayError.IncompatibleDimensions;
                }
            } else if (!left.isScalar() and right.isScalar()) {
                oneIsScalar = true;
                leftIsScalar = false;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, left.shape)) {
                    return NDArrayError.IncompatibleDimensions;
                }
            } else if (left.isScalar() and right.isScalar()) {
                bothAreScalar = true;
            } else {
                oneIsScalar = false;
                bothAreScalar = false;
                if (!std.mem.eql(usize, self.shape, left.shape) or
                    !std.mem.eql(usize, left.shape, right.shape))
                {
                    return NDArrayError.IncompatibleDimensions;
                }
            }

            if (bothAreScalar) {
                _div(&self.data[0], left.data[0], right.data[0]);
                return;
            }
            if (oneIsScalar) {
                if (leftIsScalar) {
                    if (self.order == right.order) {
                        const scalar: T = left.data[0];
                        for (0..self.size) |i| {
                            _div(&self.data[i], scalar, right.data[i]);
                        }
                    } else {
                        const scalar: T = left.data[0];
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order
                            self._position(i, position);
                            _div(&self.data[i], scalar, right.data[right._index(position)]);
                        }
                    }
                } else {
                    if (self.order == left.order) {
                        const scalar: T = right.data[0];
                        for (0..self.size) |i| {
                            _div(&self.data[i], left.data[i], scalar);
                        }
                    } else {
                        const scalar: T = right.data[0];
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order
                            self._position(i, position);
                            _div(&self.data[i], left.data[left._index(position)], scalar);
                        }
                    }
                }
            } else {
                if (self.order == left.order and self.order == right.order) {
                    for (0..self.size) |i| {
                        _div(&self.data[i], left.data[i], right.data[i]);
                    }
                } else {
                    // Follow the order common to two of them (better caching).
                    if (self.order == left.order or self.order == right.order) {
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow self's order (also used by left or right).
                            self._position(i, position);
                            _div(&self.data[i], left.data[left._index(position)], right.data[right._index(position)]);
                        }
                    } else {
                        var position_buf: [MaxDimensions]usize = undefined;
                        const position = position_buf[0..self.shape.len];
                        for (0..self.size) |i| {
                            // Follow left's order (also used by right).
                            left._position(i, position);
                            _div(&self.data[self._index(position)], left.data[i], right.data[i]);
                        }
                    }
                }
            }
        }

        /// Namespace for BLAS functions.
        pub const BLAS = struct {
            /// Computes the sum of magnitudes of the vector elements.
            ///
            /// **Description**:
            ///
            /// The routine computes the sum of the magnitudes of elements of a
            /// real vector, or the sum of magnitudes of the real and imaginary
            /// parts of elements of a complex vector:
            ///
            /// `res = |x[1].Re| + |x[1].Im| + |x[2].Re| + |x[2].Im| + ... +
            /// |x[n].Re| + |x[n].Im|`,
            ///
            /// where `x` is an `NDArray` with shape `{n}`.
            ///
            /// **Input Parameters**:
            /// - `allocator`: an optional `std.mem.Allocator`. Only needed when
            /// `T` is `BigInt`, `Fraction`, `Complex` or `Expression`.
            /// - `x`: `NDArray` of shape `{n}`.
            ///
            /// **Return Values**:
            /// - `res`: The sum of magnitudes of real and imaginary parts of
            /// all elements of the vector.
            //pub fn asum(allocator: ?std.mem.Allocator, x: NDArray(T)) !T {
            //    return @import("ndarray/BLAS/asum.zig").asum(T, allocator, x);
            //}
            pub fn tmp() usize {
                return 3;
            }
        };

        /// Namespace for LAPACK functions.
        pub const LAPACK = struct {
            /// Computes the LU factorization of a general m-by-n matrix.
            ///
            /// **Description**:
            ///
            /// The routine computes the LU factorization of a general
            /// `m`-by-`n` matrix `A` as `A = P*L*U`, where `P` is a permutation
            /// matrix, `L` is lower triangular with unit diagonal elements
            /// (lower trapezoidal if `m > n`) and `U` is upper triangular
            /// (upper trapezoidal if `m < n`). The routine uses partial
            /// pivoting, with row interchanges.
            ///
            /// **Input Parameters**:
            /// - `a`: `NDArray` of shape `{m, n}`. Contains the matrix `A`.
            ///
            /// **Output Parameters**:
            /// - `a`: Overwritten by `L` and `U`. The unit diagonal elements of
            /// `L` are not stored.
            /// - `ipiv`: `NDArray`, of shape `{min(m, n)}`. Contains the pivot
            /// indices; for `1 ≤ i ≤ min(m, n)`, row `i` was interchanged with
            /// row `ipiv[i]`.
            ///
            /// **Return Values**:
            /// - `void`: the execution is successful.
            /// ...
            //pub fn getrf(a: *Self, ipiv: *NDArray(usize)) !void {
            //    return @import("ndarray/LAPACK/getrf.zig").getrf(T, a, ipiv);
            //}
            pub fn tmp() usize {
                return 3;
            }
        };
    };
}

/// Errors that can occur when workin with an `NDArray`.
pub const NDArrayError = error{
    /// Too many dimensions.
    TooManyDimensions,
    /// The dimensions of the array and the position do not match.
    DimensionMismatch,
    /// Some position is out of bounds.
    PositionOutOfBounds,
    /// A dimension is zero.
    ZeroDimension,
    /// The array is not a scalar.
    NotScalar,
    /// The array is not a vector.
    NotVector,
    /// The array is not a matrix.
    NotMatrix,
    /// The dimensions of the array are not compatible.
    IncompatibleDimensions,
};

/// Flags representing information on the storage of an array.
pub const NDArrayFlag = enum(usize) {
    RowMajorContiguous = 1 << 0,
    ColumnMajorContiguous = 1 << 1,
    OwnsData = 1 << 2,
    Writeable = 1 << 3,
    Aligned = 1 << 4,
};

test "test" {
    const a = 1;
    try std.testing.expect(a == 1);
}
