load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")
load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

# TODO: build binder with cmake and use [run_binary](https://github.com/bazelbuild/bazel-skylib/blob/5bfcb1a684550626ce138fe0fe8f5f702b3764c3/docs/run_binary_doc.md) instead for hermetic build
# load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")
#
# cmake(
#     name = "pcre",
#     cache_entries = {
#         "CMAKE_C_FLAGS": "-fPIC",
#     },
#     lib_source = "@pcre//:all_srcs",
#     out_static_libs = ["libpcre.a"],
# )

# https://github.com/hedronvision/bazel-compile-commands-extractor/tree/0197fc673a1a6035078ac7790318659d7442e27e#user-content-get-the-extractor-running
# unused library target to extract llvm compile commands from
cc_library(
    name = "_zetasql_imports",
    srcs = [
        "zetasql.cpp"
    ],
    deps = [
        "@com_google_zetasql//zetasql/public:evaluator",
        "@com_google_zetasql//zetasql/public:simple_catalog",
    ]
)

refresh_compile_commands(
    name = "refresh_compile_commands",
    targets = {
        # TODO: avoid resource dir or get it dynamically
        ":_zetasql_imports": "--cxxopt=-resource-dir=/usr/lib64/clang/15.0.6",
    },
    exclude_external_sources = True,
    exclude_headers = "external",
)

genrule(
    name = "zetasql_bindings",
    srcs = ["zetasql.cpp", "binder.cfg", "compile_commands.json",
        "@com_google_zetasql//zetasql/public:evaluator",
        "@com_google_zetasql//zetasql/public:simple_catalog"
    ],
    outs = ["bindings/zetasql.cpp"],
    cmd = "outdir=`realpath $@` && outdir=`dirname $$outdir` && rm -rf $$outdir && mkdir $$outdir && ~/binder/bin/binder --root-module zetasql --single-file --config binder.cfg --include-pybind11-stl --prefix=$$outdir $(location zetasql.cpp) -p compile_commands.json",
    # TODO: run refresh_compile_commands as part of build?
    # exec_tools = ["//:refresh_compile_commands"]
)

pybind_extension(
    name = "zetasql",
    srcs = ["bindings/zetasql.cpp"],
    deps = [
        "@com_google_zetasql//zetasql/public:evaluator",
        "@com_google_zetasql//zetasql/public:simple_catalog",
    ]
)

load("@bq_lsp_deps//:requirements.bzl", "requirement")

py_test(
    name = "zetasql_test",
    srcs = ["zetasql_test.py"],
    deps = [
      requirement("google-cloud-bigquery"),
    ],
    data = ["zetasql.so"],
)
