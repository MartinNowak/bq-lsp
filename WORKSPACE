#
# Copyright 2018 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

""" Workspace for Open Source ZetaSQL library """

workspace(name = "bq-lsp")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# ZetaSQL
http_archive(
    name = "com_google_zetasql",
    url = "https://github.com/google/zetasql/archive/177d495a064e38684c462cf883e22428273bd996.tar.gz",
    sha256 = "4092dce28d3fb5b0071d0268bcb3ba13e28eb4f981c5c267688b8c3590ca7705",
    strip_prefix = "zetasql-177d495a064e38684c462cf883e22428273bd996",
)

# https://github.com/google/zetasql/blob/177d495a064e38684c462cf883e22428273bd996/WORKSPACE#L74-L85
# If java support is not required, copy starting from here
load("@com_google_zetasql//bazel:zetasql_deps_step_1.bzl", "zetasql_deps_step_1")

zetasql_deps_step_1()

load("@com_google_zetasql//bazel:zetasql_deps_step_2.bzl", "zetasql_deps_step_2")

zetasql_deps_step_2()

load("@com_google_zetasql//bazel:zetasql_deps_step_3.bzl", "zetasql_deps_step_3")

zetasql_deps_step_3()

# https://github.com/pybind/pybind11_bazel/blob/faf56fb3df11287f26dbc66fdedf60a2fc2c6631/README.md#user-content-installation
http_archive(
  name = "pybind11_bazel",
  strip_prefix = "pybind11_bazel-faf56fb3df11287f26dbc66fdedf60a2fc2c6631",
  urls = ["https://github.com/pybind/pybind11_bazel/archive/faf56fb3df11287f26dbc66fdedf60a2fc2c6631.zip"],
)
# We still require the pybind library.
http_archive(
  name = "pybind11",
  build_file = "@pybind11_bazel//:pybind11.BUILD",
  strip_prefix = "pybind11-2.10.1",
  urls = ["https://github.com/pybind/pybind11/archive/v2.10.1.tar.gz"],
  sha256 = "111014b516b625083bef701df7880f78c2243835abdb263065b6b59b960b6bad",
)
load("@pybind11_bazel//:python_configure.bzl", "python_configure")
python_configure(name = "local_config_python")

# https://github.com/bazelbuild/rules_python#using-the-package-installation-rules
load("@rules_python//python:pip.bzl", "pip_parse")

# Create a central repo that knows about the dependencies needed from
# requirements_lock.txt.
pip_parse(
   name = "bq_lsp_deps",
   requirements_lock = "//:requirements.txt",
)
# Load the starlark macro which will define your dependencies.
load("@bq_lsp_deps//:requirements.bzl", "install_deps")
# Call it to define repos for your requirements.
install_deps()