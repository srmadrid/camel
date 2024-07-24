const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // Library
    const lib = b.addStaticLibrary(.{
        .name = "camel",
        .root_source_file = b.path("src/camel.zig"),
        .target = target,
        .optimize = optimize,
    });
    b.installArtifact(lib);

    // Executable (for testing)
    const exe = b.addExecutable(.{
        .name = "camel",
        .root_source_file = b.path("src/main.zig"),
        .target = target,
        .optimize = optimize,
    });
    b.installArtifact(exe);
    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());

    // Tests
    const lib_unit_tests = b.addTest(.{
        .root_source_file = b.path("src/camel.zig"),
        .target = target,
        .optimize = optimize,
    });
    const run_lib_unit_tests = b.addRunArtifact(lib_unit_tests);

    // Steps
    const run_step = b.step("run", "Run the executable");
    run_step.dependOn(&run_cmd.step);
    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&run_lib_unit_tests.step);
    const check_step = b.step("check", "Check if the code compiles; this is for ZLS.");
    check_step.dependOn(&exe.step);
}
