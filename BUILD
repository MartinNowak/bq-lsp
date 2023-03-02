load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")

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
