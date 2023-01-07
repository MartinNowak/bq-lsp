#!/usr/bin/env bash

set -ueEo pipefail

# generate compile commands for binder
env CC=clang bazel run --config=clang :refresh_compile_commands
# build and test zetasql pybind module
bazel run --config=g++ :zetasql_test
