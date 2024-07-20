const std = @import("std");
const camel = @import("../camel.zig");
const core = @import("../core/core.zig");

const ndarray = @import("ndarray.zig");
const NDArray = ndarray.NDArray;
const Flags = ndarray.Flags;
const Error = ndarray.Error;
const MaxDimensions = ndarray.MaxDimensions;

/// Iterator for one `NDArray`.
///
/// For now, iterators are associated to an array, but if, for example, we just
/// want to use a transpose once, we have to create the transpose view, and
/// then an iterator for that view. If iterators were associated with a shape
/// and a stride, you would only need an iterator for the transpose case, but
/// that iterator would be (considerably) heavier.
///
/// Maybe, make a standard next that doesnt take iteration order and instead
/// calls `nextOrder` with the best order for the array?
pub fn Iterator(comptime T: type) type {
    return struct {
        const Self: type = @This();
        /// The iterated array.
        array: *const NDArray(T),
        /// Current position.
        position: [MaxDimensions]usize,
        /// Current index.
        index: usize,

        /// Initializes an iterator for a given array.
        ///
        /// **Description**:
        ///
        /// Initializes an iterator for a given array.
        ///
        /// **Input Parameters**:
        /// - `array`: the array for the Iterator.
        ///
        /// **Return Values**:
        /// - `Self`: the initialized iterator.
        pub fn init(array: *const NDArray(T)) Self {
            return Self{
                .array = array,
                .position = [_]usize{0} ** MaxDimensions,
                .index = 0,
            };
        }

        /// Iterates to the next element.
        ///
        /// **Description**:
        ///
        /// Iterates to the next element in the most efficient memory order, and
        /// returns it if it exists, or null otherwise. Also updates `position`
        /// and `index`.
        ///
        /// Due to the nature of the implementation, if the end of the iterator
        /// is reached, apart from `null` being returned, `position` and `index`
        /// are reset to 0, so there is no need to call `reset`.
        ///
        /// **Input Parameters**:
        /// - `self`: the iterator.
        ///
        /// **Return Values**:
        /// - `T`: the next item.
        /// - `null`: reached end.
        pub fn next(self: *Self) ?T {
            return self.nextOrder(self.array.flags.RowMajorContiguous);
        }

        /// Iterates to the next element.
        ///
        /// **Description**:
        ///
        /// Iterates to the next element in the chosen memory order, and returns
        /// it if it exists, or null otherwise. Also updates `position` and
        /// `index`.
        ///
        /// Due to the nature of the implementation, if the end of the iterator
        /// is reached, apart from `null` being returned, `position` and `index`
        /// are reset to 0, so there is no need to call `reset`.
        ///
        /// **Input Parameters**:
        /// - `self`: the iterator.
        /// - `rowMajorOrder`: what order to iterate with. If `true`, iterates
        /// in row major order (right to left, `(...,0,0)->(...,0,1)->...->
        /// (...,0,n)->(...,1,0))`, which is very efficient for arrays stored in
        /// row major order; if `false`, iterates in column major order (left to
        /// right, `(0,0,...)->(1,0,...)->...->(n,0,...)->(0,1,...)`), which is
        /// very efficient for arrays stored in column major order.
        ///
        /// **Return Values**:
        /// - `T`: the next item.
        /// - `null`: reached end.
        pub fn nextOrder(self: *Self, rowMajorOrder: bool) ?T {
            var carry: usize = 1;
            var change: i64 = undefined;
            var prev: i64 = undefined;
            var index: i64 = undefined;
            var stride: i64 = undefined;
            var mustBreak: bool = false;
            if (rowMajorOrder) {
                const length: usize = self.array.shape.len;
                for (0..self.array.shape.len) |i| {
                    prev = @intCast(self.position[length - i - 1]);
                    self.position[length - i - 1] += 1;
                    if (self.position[length - i - 1] >= self.array.shape[length - i - 1]) {
                        self.position[length - i - 1] = 0;
                    } else {
                        carry = 0;
                        mustBreak = true;
                    }
                    // change = @intCast(self.position[length - i - 1]) - prev;
                    change = @intCast(self.position[length - i - 1]);
                    change -= prev;
                    // self.index += change * self.array.strides[length - i - 1];
                    index = @intCast(self.index);
                    // index += change * self.array.strides[length - i - 1];
                    stride = @intCast(self.array.strides[length - i - 1]);
                    index += change * stride;
                    self.index = @intCast(index);
                    if (mustBreak) {
                        break;
                    }
                }
            } else {
                for (0..self.array.shape.len) |i| {
                    prev = @intCast(self.position[i]);
                    self.position[i] += 1;
                    if (self.position[i] >= self.array.shape[i]) {
                        self.position[i] = 0;
                    } else {
                        carry = 0;
                        mustBreak = true;
                    }
                    // change = @intCast(self.position[i]) - prev;
                    change = @intCast(self.position[i]);
                    change -= prev;
                    // self.index += change * self.array.strides[i];
                    index = @intCast(self.index);
                    // index += change * self.array.strides[i];
                    stride = @intCast(self.array.strides[i]);
                    index += change * stride;
                    self.index = @intCast(index);
                    if (mustBreak) {
                        break;
                    }
                }
            }

            if (carry == 1) {
                return null;
            }

            return self.array.data[self.index];
        }
    };
}
