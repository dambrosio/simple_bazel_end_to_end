FROM ubuntu:jammy

# hadolint ignore=DL3008
RUN apt-get update && apt-get install -q -y --no-install-recommends \
  build-essential \
  ca-certificates \
  python3 \
  wget \
  zsh \
  && rm -rf /var/lib/apt/lists/*

RUN wget -q https://github.com/bazelbuild/bazelisk/releases/download/v1.17.0/bazelisk-linux-amd64 \
  && chmod +x bazelisk-linux-amd64 \
  && mv bazelisk-linux-amd64 /usr/local/bin/bazel \
  && wget -q https://github.com/bazelbuild/buildtools/releases/download/v6.4.0/buildifier-linux-amd64 \
  && chmod +x buildifier-linux-amd64 \
  && mv buildifier-linux-amd64 /usr/local/bin/buildifier

# Create development user
ARG USERNAME
ARG USER_UID=1000

# hadolint ignore=DL3008
RUN useradd -l -G sudo -ms /bin/bash -u "$USER_UID" "$USERNAME" \
  && apt-get update && apt-get install -q -y --no-install-recommends \
  sudo \
  && rm -rf /var/lib/apt/lists/* \
  && echo "$USERNAME" ALL=\(root\) NOPASSWD:ALL > "/etc/sudoers.d/${USERNAME}" \
  && chmod 0440 "/etc/sudoers.d/${USERNAME}"
ENV USER "$USERNAME"

USER ${USERNAME}

ARG WORKSPACE
WORKDIR ${WORKSPACE}
