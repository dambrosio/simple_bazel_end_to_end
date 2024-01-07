workspace(name = "com_github_dambrosio_simple_bazel_end_to_end")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

# rules_ros2
maybe(
    http_archive,
    name = "com_github_mvukov_rules_ros2",
    sha256 = "ba64804ccf79e1a80762935c24c20c1c8f9c770879c05075dc78669a280cb9bf",
    strip_prefix = "rules_ros2-8fedbc779b32e762f5f1de0962e1e0ac35cb8c56",
    url = "https://github.com/mvukov/rules_ros2/archive/8fedbc779b32e762f5f1de0962e1e0ac35cb8c56.tar.gz",
)

load("@com_github_mvukov_rules_ros2//repositories:repositories.bzl", "ros2_repositories")

ros2_repositories()

load("@com_github_mvukov_rules_ros2//repositories:deps.bzl", "ros2_deps")

ros2_deps()

load("@rules_python//python:repositories.bzl", "py_repositories", "python_register_toolchains")

py_repositories()

python_register_toolchains(
    name = "rules_ros2_python",
    python_version = "3.10",
)

load("@com_github_mvukov_rules_ros2//repositories:pip_annotations.bzl", "PIP_ANNOTATIONS")
load("@rules_python//python:pip.bzl", "pip_parse")
load("@rules_ros2_python//:defs.bzl", python_interpreter_target = "interpreter")

pip_parse(
    name = "rules_ros2_pip_deps",
    annotations = PIP_ANNOTATIONS,
    python_interpreter_target = python_interpreter_target,
    requirements_lock = "@com_github_mvukov_rules_ros2//:requirements_lock.txt",
)

load(
    "@rules_ros2_pip_deps//:requirements.bzl",
    install_rules_ros2_pip_deps = "install_deps",
)

install_rules_ros2_pip_deps()

# Docker build rules
# https://docs.aspect.build/guides/rules_oci_migration/
maybe(
    http_archive,
    name = "rules_oci",
    sha256 = "686f871f9697e08877b85ea6c16c8d48f911bf466c3aeaf108ca0ab2603c7306",
    strip_prefix = "rules_oci-1.5.1",
    url = "https://github.com/bazel-contrib/rules_oci/releases/download/v1.5.1/rules_oci-v1.5.1.tar.gz",
)

load("@rules_oci//oci:dependencies.bzl", "rules_oci_dependencies")

rules_oci_dependencies()

load("@rules_oci//oci:repositories.bzl", "LATEST_CRANE_VERSION", "oci_register_toolchains")

oci_register_toolchains(
    name = "oci",
    crane_version = LATEST_CRANE_VERSION,
)

load("@rules_oci//oci:pull.bzl", "oci_pull")

oci_pull(
    name = "ubuntu_22_04",
    digest = "sha256:c88265b8f9e40ca21547aeecd90b688a167738fefda07b943cdf48f7d714d503",
    image = "public.ecr.aws/lts/ubuntu",
    platforms = [
        "linux/amd64",
    ],
)

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
