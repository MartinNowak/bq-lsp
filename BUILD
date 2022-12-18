load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")

pybind_extension(
    name = "zetasql",
    srcs = ["py_zetasql.cc"],
    deps = [
        "@com_google_zetasql//zetasql/public:evaluator",
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
