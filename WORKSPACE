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

workspace(name = "bqbt")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# ZetaSQL
http_archive(
    name = "com_google_zetasql",
    url = "https://github.com/google/zetasql/archive/994f3064d98f2fa996fe7cc25824e5c71aa1aae1.tar.gz",
    sha256 = "8c1b2fbd2f06b76237af53948555115cf17056d6be0350ca1f0b5185cd4cb7c7",
    strip_prefix = "zetasql-994f3064d98f2fa996fe7cc25824e5c71aa1aae1",
)

# Updated Cython for 3.11 support
# https://github.com/cython/cython/pull/4428
# https://github.com/cython/cython/issues/4681
# https://github.com/grpc/grpc/blob/fcff4bd1d04f2119ef6e4897076815659cbd7720/bazel/grpc_python_deps.bzl#L38-L47
#
# Use Cython 3 for pure python support
http_archive(
    name = "cython",
    url = "https://github.com/cython/cython/releases/download/3.0.0b1/Cython-3.0.0b1.tar.gz",
    build_file = "@com_github_grpc_grpc//third_party:cython.BUILD",
    sha256 = "30c7d7050bc0d58cbfb422a2fe16615d962a537409fd0588277add29f271c897",
    strip_prefix = "Cython-3.0.0b1",
)

# https://github.com/google/zetasql/blob/177d495a064e38684c462cf883e22428273bd996/WORKSPACE#L74-L85
# If java support is not required, copy starting from here
load("@com_google_zetasql//bazel:zetasql_deps_step_1.bzl", "zetasql_deps_step_1")
#
zetasql_deps_step_1()
#
load("@com_google_zetasql//bazel:zetasql_deps_step_2.bzl", "zetasql_deps_step_2")
#
zetasql_deps_step_2()

load("@com_google_zetasql//bazel:zetasql_deps_step_3.bzl", "zetasql_deps_step_3")

zetasql_deps_step_3()

load("@com_google_zetasql//bazel:zetasql_deps_step_4.bzl", "zetasql_deps_step_4")

zetasql_deps_step_4()
