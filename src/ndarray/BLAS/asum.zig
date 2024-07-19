const std = @import("std");
const NDArray = @import("../../ndarray.zig").NDArray;
const NDArrayError = @import("../../ndarray.zig").NDArrayError;
const core = @import("../../../core/core.zig");

const _add = core.supported._add;

pub fn asum(allocator: ?std.mem.Allocator, comptime T: type, x: NDArray(T)) !T {
    return;
}
