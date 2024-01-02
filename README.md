# simple_bazel_end_to_end

A repository containing a simple bazel end-to-end prototype

## Generate Compile Commands

To generate project compile commands run the following from the root of the repository:

```bash
bazel run @hedron_compile_commands//:refresh_all
```

## Run the CC Main Application

```bash
docker load < bazel-bin/cc/tarball/tarball.tar
docker run --rm cc:main-test
```

## References

- <https://docs.aspect.build/>
