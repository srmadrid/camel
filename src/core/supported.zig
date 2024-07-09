const std = @import("std");
const camel = @import("../camel.zig");

pub const SupportedNumericType = enum {
    /// u8, u16, u32, u64, u128, i8, i16, i32, i64, i128
    BuiltinInt,
    /// f16, f32, f64, 128
    BuiltinFloat,
    /// bool
    BuiltinBool,
    /// BigInt
    CustomInt,
    /// Fraction
    CustomReal,
    /// cf32, cf64, cf128
    CustomComplexFloat,
    /// Complex
    CustomComplex,
    /// Expression
    CustomExpression,
    Unsupported,
};

pub inline fn whatSupportedNumericType(comptime T: type) SupportedNumericType {
    const info = @typeInfo(T);
    const name = @typeName(T);

    return switch (info) {
        .Int => SupportedNumericType.BuiltinInt,
        .Float => SupportedNumericType.BuiltinFloat,
        .Bool => SupportedNumericType.BuiltinBool,
        else => { // Maybe just use the ones from the standard library, and fix so this works
            if (std.mem.eql(u8, name, "bigint.BigInt")) {
                return SupportedNumericType.CustomInt;
            } else if (std.mem.eql(u8, name, "fraction.Fraction")) {
                return SupportedNumericType.CustomReal;
            } else if (std.mem.eql(u8, name, "types.cf.cf(f16)") or
                std.mem.eql(u8, name, "types.cf.cf(f32)") or
                std.mem.eql(u8, name, "types.cf.cf(f64)") or
                std.mem.eql(u8, name, "types.cf.cf(f128)"))
            {
                return SupportedNumericType.CustomComplexFloat;
            } else if (std.mem.eql(u8, name, "complex.Complex")) {
                return SupportedNumericType.CustomComplex;
            } else if (std.mem.eql(u8, name, "expression.Expression")) {
                return SupportedNumericType.CustomExpression;
            } else {
                @compileError("Unsupported numeric type: " ++ name);
            }
        },
    };
}
