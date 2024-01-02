workspace(name = "com_github_dambrosio_simple_bazel_end_to_end")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

maybe(
    http_archive,
    name = "com_github_nelhage_rules_boost",
    sha256 = "1ef96e5c4c7c05024e60dc5927f7c1f39c692530d1a396f0968ce1715cd00df4",
    strip_prefix = "rules_boost-e72eb259976357f6e82f4d74d74a7c12d1c3776d",
    url = "https://github.com/nelhage/rules_boost/archive/e72eb259976357f6e82f4d74d74a7c12d1c3776d.tar.gz",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

# Add ability to generate compile commands
maybe(
    http_archive,
    name = "hedron_compile_commands",
    sha256 = "17c45d95e0e95c41d1d8c03430ba50dea80cdf545b9916c6c0619f342e0edbbb",
    strip_prefix = "bazel-compile-commands-extractor-388cc00156cbf53570c416d39875b15f03c0b47f",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/388cc00156cbf53570c416d39875b15f03c0b47f.tar.gz",
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()
