const std = @import("std");
const camel = @import("camel.zig");

pub fn main() !void {
    const a: std.mem.Allocator = std.heap.page_allocator;
    // Prints to stderr (it's a shortcut based on `std.io.getStdErr()`)
    std.debug.print("All your {s} are belong to us.\n", .{"codebase"});

    var A: camel.NDArray(f64) = try camel.NDArray(f64).initOrder(a, &[_]usize{ 20, 15, 8, 17 }, camel.ndarray.NDArrayOrder.ColumnMajor);
    defer A.deinit();

    std.debug.print("A dimentions = {}\n", .{A.shape.len});

    std.debug.print("A.shape = [  ", .{});
    for (A.shape) |dim| {
        std.debug.print("{}  ", .{dim});
    }
    std.debug.print("]\n", .{});

    std.debug.print("A.strides = [  ", .{});
    for (A.strides) |stride| {
        std.debug.print("{}  ", .{stride});
    }
    std.debug.print("]\n", .{});

    std.debug.print("A.size = {}\n", .{A.size});

    std.debug.print("Location of (2, 13, 3, 16) = {}\n", .{A._index(&[_]usize{ 2, 13, 3, 16 })});

    var pos = [_]usize{ 0, 0, 0, 0 };
    A._position(39562, &pos);
    std.debug.print("Location of 39562 = [  ", .{});
    for (pos) |p| {
        std.debug.print("{}  ", .{p});
    }
    std.debug.print("]\n\n", .{});

    var B: camel.NDArray(f64) = try camel.NDArray(f64).initOrder(a, &[_]usize{ 3, 4 }, camel.ndarray.NDArrayOrder.ColumnMajor);
    defer B.deinit();
    for (0..B.size) |i| {
        B.data[i] = @floatFromInt(i);
    }
    std.debug.print("B =\n", .{});
    for (0..B.shape[0]) |i| {
        std.debug.print("\t", .{});
        for (0..B.shape[1]) |j| {
            std.debug.print("{!}  ", .{B.get(&[_]usize{ i, j })});
        }
        std.debug.print("\n", .{});
    }

    var C: camel.NDArray(f64) = try camel.NDArray(f64).initOrder(a, &[_]usize{ 3, 4 }, camel.ndarray.NDArrayOrder.RowMajor);
    defer C.deinit();
    C.setAll(10);
    std.debug.print("\nC =\n", .{});
    for (0..C.shape[0]) |i| {
        std.debug.print("\t", .{});
        for (0..C.shape[1]) |j| {
            std.debug.print("{!}  ", .{C.get(&[_]usize{ i, j })});
        }
        std.debug.print("\n", .{});
    }

    var D: camel.NDArray(f64) = try camel.NDArray(f64).initOrder(a, &[_]usize{ 3, 4 }, camel.ndarray.NDArrayOrder.RowMajor);
    defer D.deinit();
    try D.divew(B, C);
    // try camel.NDArray(u64).add(&D, B, C);
    std.debug.print("\nD =\n", .{});
    for (0..D.shape[0]) |i| {
        std.debug.print("\t", .{});
        for (0..D.shape[1]) |j| {
            std.debug.print("{!}  ", .{D.get(&[_]usize{ i, j })});
        }
        std.debug.print("\n", .{});
    }
}
