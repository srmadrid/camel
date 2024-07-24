# Camel

A Zig numerical and symbolic mathematics library.

## Features

- Basic N-dimensional array support.

## Installation

To use this library in your project, run

```bash
zig fetch --save git+https://github.com/srmadrid/camel
```

and add it to your build.zig file:

```zig
const camel = b.dependency("camel", .{});
exe.root_module.addImport("camel", camel.module("camel"));
```

## Notes

This library is in the early stages of development and is not yet ready for use. Breaking changes are to be expected every commit, and only the most basic functionality is currently implemented (see [Features](#features) for more information).
