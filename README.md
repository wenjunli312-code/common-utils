# common-utils

A C++ utility library for the OpenBuilder demo project, providing 3D math primitives, logging, and JSON-based configuration.

## Features

- **Vector3** — 3D vector with arithmetic operators, dot/cross product, normalize, magnitude
- **Matrix4x4** — 4×4 transformation matrix with identity, rotation, translation, scale, multiply, inverse
- **Logger** — `spdlog`-based logger with `CU_LOG_INFO/WARN/ERROR/DEBUG` macros
- **Config** — `nlohmann_json`-based config loader with dot-notation key access

## Dependencies

- [spdlog](https://github.com/gabime/spdlog) ≥ 1.9
- [nlohmann_json](https://github.com/nlohmann/json) ≥ 3.10

Install via Homebrew:
```sh
brew install spdlog nlohmann-json
```

## Build

```sh
cmake -S . -B build -G Ninja
cmake --build build
```

## Test

```sh
cd build && ctest --output-on-failure
```

## Install

```sh
cmake --install build --prefix /usr/local
```

Headers are installed to `include/common_utils/`.
