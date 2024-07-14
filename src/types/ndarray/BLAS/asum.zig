const std = @import("std");
const NDArray = @import("../../ndarray.zig").NDArray;
const NDArrayError = @import("../../ndarray.zig").NDArrayError;
const core = @import("../../../core/core.zig");

const _add = core.supported._add;

pub fn asum(comptime T: type, allocator: ?std.mem.Allocator, x: NDArray(T)) !T {
    return;
}
