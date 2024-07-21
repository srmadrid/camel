const std = @import("std");
const camel = @import("camel.zig");

pub fn main() !void {
    const a: std.mem.Allocator = std.heap.page_allocator;
    // Prints to stderr (it's a shortcut based on `std.io.getStdErr()`)
    //std.debug.print("All your {s} are belong to us.\n", .{"codebase"});

    // try generalTesting(a);

    // try addTesting(a);

    // try iterTesting(a);

    // try iterPerfTesting(a);

    try multiIterTesting(a);

    // try perfTesting(a);
}

fn generalTesting(a: std.mem.Allocator) !void {
    std.debug.print("Size of flags: {}\n", .{@sizeOf(camel.ndarray.Flags)});

    var A: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 20, 15, 8, 18 }, camel.ndarray.Flags{ .RowMajorContiguous = false, .ColumnMajorContiguous = true });
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

    //std.debug.print("Location of (2, 13, 3, 16) = {}\n", .{A._index(&[_]usize{ 2, 13, 3, 16 })});

    //var pos = [_]usize{ 0, 0, 0, 0 };
    //A._position(39562, &pos);
    //std.debug.print("Location of 39562 = [  ", .{});
    //for (pos) |p| {
    //    std.debug.print("{}  ", .{p});
    //}
    //std.debug.print("]\n\n", .{});
}

fn addTesting(a: std.mem.Allocator) !void {
    var B: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 3, 4 }, camel.ndarray.Flags{ .RowMajorContiguous = true, .ColumnMajorContiguous = false });
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

    var C: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 3, 4 }, camel.ndarray.Flags{ .RowMajorContiguous = true, .ColumnMajorContiguous = false });
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

    var D: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 3, 4 }, camel.ndarray.Flags{ .RowMajorContiguous = true, .ColumnMajorContiguous = false });
    defer D.deinit();
    try D.add(B, C);
    // try camel.NDArray(u64).add(&D, B, C);
    std.debug.print("\nD =\n", .{});
    for (0..D.shape[0]) |i| {
        std.debug.print("\t", .{});
        for (0..D.shape[1]) |j| {
            std.debug.print("{!}  ", .{D.get(&[_]usize{ i, j })});
        }
        std.debug.print("\n\n", .{});
    }
}

fn iterTesting(a: std.mem.Allocator) !void {
    var iterArrR: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 3, 2, 4 }, camel.ndarray.Flags{ .RowMajorContiguous = true, .ColumnMajorContiguous = false });
    defer iterArrR.deinit();
    var iterArrC: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 3, 2, 4 }, camel.ndarray.Flags{ .RowMajorContiguous = false, .ColumnMajorContiguous = true });
    defer iterArrC.deinit();
    var iterR: camel.ndarray.Iterator(f64) = camel.ndarray.Iterator(f64).init(&iterArrR);
    var iterC: camel.ndarray.Iterator(f64) = camel.ndarray.Iterator(f64).init(&iterArrC);
    std.debug.print("Position(R)    Position(C)     R   C\n", .{});
    std.debug.print("----------------------\n", .{});
    std.debug.print("[  ", .{});
    for (0..iterR.array.shape.len) |i| {
        std.debug.print("{}  ", .{iterR.position[i]});
    }
    std.debug.print("]  [  ", .{});
    for (0..iterC.array.shape.len) |i| {
        std.debug.print("{}  ", .{iterC.position[i]});
    }
    std.debug.print("],  {},  {}\n", .{ iterR.index, iterC.index });
    while (iterR.nextOrder(true) != null and iterC.nextOrder(true) != null) {
        std.debug.print("[  ", .{});
        for (0..iterR.array.shape.len) |i| {
            std.debug.print("{}  ", .{iterR.position[i]});
        }
        std.debug.print("]  [  ", .{});
        for (0..iterC.array.shape.len) |i| {
            std.debug.print("{}  ", .{iterC.position[i]});
        }
        std.debug.print("],  {},  {}\n", .{ iterR.index, iterC.index });
    }
    _ = iterC.nextOrder(true);
    std.debug.print("Final state:\n", .{});
    std.debug.print("[  ", .{});
    for (0..iterR.array.shape.len) |i| {
        std.debug.print("{}  ", .{iterR.position[i]});
    }
    std.debug.print("]  [  ", .{});
    for (0..iterC.array.shape.len) |i| {
        std.debug.print("{}  ", .{iterC.position[i]});
    }
    std.debug.print("],  {},  {}\n\n", .{ iterR.index, iterC.index });
}

fn iterPerfTesting(a: std.mem.Allocator) !void {
    std.debug.print("Row major array, long next, optimize\n", .{});

    var arrBig: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 100, 100, 10, 100 }, camel.ndarray.Flags{ .RowMajorContiguous = true, .ColumnMajorContiguous = false });
    defer arrBig.deinit();
    var iterBig: camel.ndarray.Iterator(f64) = camel.ndarray.Iterator(f64).init(&arrBig);

    //
    const n: usize = 50;
    var start_time = std.time.nanoTimestamp();

    var count: u128 = 0;
    for (0..n) |_| {
        while (iterBig.nextOrder(true) != null) {
            count += 1;
        }
    }

    var end_time = std.time.nanoTimestamp();
    var duration_ns = end_time - start_time;

    // Convert nanoseconds to seconds as a floating-point number.
    var duration_s: f128 = @as(f128, @floatFromInt(duration_ns)) / (1_000_000_000.0 * @as(f128, @floatFromInt(n)));

    // Print the duration in seconds with high precision (e.g., 9 decimal places).
    std.debug.print("Row major iteration took: {d:.9} seconds\n", .{duration_s});

    start_time = std.time.nanoTimestamp();

    for (0..n) |_| {
        while (iterBig.nextOrder(false) != null) {
            count += 1;
        }
    }

    end_time = std.time.nanoTimestamp();
    duration_ns = end_time - start_time;

    // Convert nanoseconds to seconds as a floating-point number.
    duration_s = @as(f128, @floatFromInt(duration_ns)) / (1_000_000_000.0 * @as(f128, @floatFromInt(n)));

    // Print the duration in seconds with high precision (e.g., 9 decimal places).
    std.debug.print("Column major iteration took: {d:.9} seconds\n", .{duration_s});

    start_time = std.time.nanoTimestamp();

    for (0..n) |_| {
        while (iterBig.next() != null) {
            count += 1;
        }
    }

    end_time = std.time.nanoTimestamp();
    duration_ns = end_time - start_time;

    // Convert nanoseconds to seconds as a floating-point number.
    duration_s = @as(f128, @floatFromInt(duration_ns)) / (1_000_000_000.0 * @as(f128, @floatFromInt(n)));

    // Print the duration in seconds with high precision (e.g., 9 decimal places).
    std.debug.print("Default iteration took: {d:.9} seconds\n", .{duration_s});
}

fn multiIterTesting(a: std.mem.Allocator) !void {
    var iterArrR: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{1}, camel.ndarray.Flags{ .RowMajorContiguous = true, .ColumnMajorContiguous = false });
    defer iterArrR.deinit();
    var iterArrC: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{4}, camel.ndarray.Flags{ .RowMajorContiguous = false, .ColumnMajorContiguous = true });
    defer iterArrC.deinit();

    // Other arrays for broadcasting testing.
    var A: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{1}, camel.ndarray.Flags{ .RowMajorContiguous = true, .ColumnMajorContiguous = false });
    defer A.deinit();

    const iter: camel.ndarray.MultiIterator(f64) = try camel.ndarray.MultiIterator(f64).init(&[_]*camel.NDArray(f64){ &iterArrR, &iterArrC, &A });

    std.debug.print("ndim = {}\n", .{iter.ndim});
    std.debug.print("narray = {}\n", .{iter.narray});
    std.debug.print("Shape = [  ", .{});
    for (0..iter.ndim) |i| {
        std.debug.print("{}  ", .{iter.shape[i]});
    }
    std.debug.print("]\n", .{});
}

fn perfTesting(a: std.mem.Allocator) !void {
    // Perf testing
    var big1: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 10000, 10000 }, camel.ndarray.Flags{ .RowMajorContiguous = true, .ColumnMajorContiguous = false });
    defer big1.deinit();
    var big2: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 10000, 10000 }, camel.ndarray.Flags{ .RowMajorContiguous = false, .ColumnMajorContiguous = true });
    defer big2.deinit();
    var big3: camel.NDArray(f64) = try camel.NDArray(f64).initFlags(a, &[_]usize{ 10000, 10000 }, camel.ndarray.Flags{ .RowMajorContiguous = false, .ColumnMajorContiguous = true });
    defer big3.deinit();

    std.debug.print("big3 dimentions = {}\n", .{big3.shape.len});

    std.debug.print("big3.shape = [  ", .{});
    for (big3.shape) |dim| {
        std.debug.print("{}  ", .{dim});
    }
    std.debug.print("]\n", .{});

    std.debug.print("big3.strides = [  ", .{});
    for (big3.strides) |stride| {
        std.debug.print("{}  ", .{stride});
    }
    std.debug.print("]\n", .{});

    std.debug.print("big3.size = {}\n", .{big3.size});

    // Profiling
    const n: usize = 1;
    var start_time = std.time.nanoTimestamp();

    for (0..n) |_| {
        std.debug.print(".", .{});
        try @call(.auto, camel.NDArray(f64).add, .{ &big3, big1, big2 });
        //try big3.add(big1, big2);
    }
    std.debug.print("\n", .{});

    var end_time = std.time.nanoTimestamp();
    var duration_ns = end_time - start_time;

    // Convert nanoseconds to seconds as a floating-point number.
    var duration_s: f128 = @as(f128, @floatFromInt(duration_ns)) / (1_000_000_000.0 * @as(f128, @floatFromInt(n)));

    // Print the duration in seconds with high precision (e.g., 9 decimal places).
    std.debug.print("add took: {d:.9} seconds\n", .{duration_s});

    start_time = std.time.nanoTimestamp();

    for (0..n) |_| {
        std.debug.print(".", .{});
        try @call(.auto, camel.NDArray(f64).add, .{ &big3, big1, big2 });
        //try big3.add2(big1, big2);
    }
    std.debug.print("\n", .{});

    end_time = std.time.nanoTimestamp();
    duration_ns = end_time - start_time;

    // Convert nanoseconds to seconds as a floating-point number.
    duration_s = @as(f128, @floatFromInt(duration_ns)) / (1_000_000_000.0 * @as(f128, @floatFromInt(n)));

    // Print the duration in seconds with high precision (e.g., 9 decimal places).
    std.debug.print("add2 took: {d:.9} seconds\n", .{duration_s});
}
