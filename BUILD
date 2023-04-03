load("@com_github_grpc_grpc//bazel:cython_library.bzl", "pyx_library")
load("@rules_python//python:packaging.bzl", "py_package", "py_wheel")
# load("@cython//Tools:rules.bzl", "pyx_library")

cc_library(
    name = "bqbt-zetasql",
    hdrs = glob(["*.h"]),
    srcs = glob(["*.cc"]),
    deps = [
        "@com_google_zetasql//zetasql/public:analyzer",
        "@com_google_zetasql//zetasql/public:evaluator",
    ],
)

pyx_library(
    name = "bqbt",
    srcs = glob(["*." + ext for ext in ("py", "pxd", "pyx")]),
    deps = ["bqbt-zetasql"],
)

# https://github.com/bazelbuild/rules_python/issues/537#issuecomment-924119169
py_package(
    name = "bqbt_pkg",
    deps = [":bqbt"],
)

py_wheel(
    name = "bqbt-whl",
    distribution = "bqbt",
    python_tag = "py3",
    version = "0.0.1",
    deps = [":bqbt_pkg"],
)
