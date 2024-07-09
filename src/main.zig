const std = @import("std");
const camel = @import("camel.zig");

pub fn main() !void {
    const a: std.mem.Allocator = std.heap.page_allocator;
    // Prints to stderr (it's a shortcut based on `std.io.getStdErr()`)
    std.debug.print("All your {s} are belong to us.\n", .{"codebase"});

    var A: camel.NDArray(f64) = try camel.NDArray(f64).init(a, &[_]usize{ 2, 2 });
    defer A.deinit();

    const supported = camel.core.supported.whatSupportedNumericType(i256);
    switch (supported) {
        .BuiltinInt => std.debug.print("BuiltinInt.\n", .{}),
        .BuiltinFloat => std.debug.print("BuiltinFloat.\n", .{}),
        .BuiltinBool => std.debug.print("BuiltinBool.\n", .{}),
        .CustomInt => std.debug.print("CustomInt.\n", .{}),
        .CustomReal => std.debug.print("CustomFloat.\n", .{}),
        .CustomComplexFloat => std.debug.print("CustomComplexFloat.\n", .{}),
        .CustomComplex => std.debug.print("CustomComplex.\n", .{}),
        .CustomExpression => std.debug.print("CustomExpression.\n", .{}),
        .Unsupported => std.debug.print("Unsupported.\n", .{}),
    }
}
