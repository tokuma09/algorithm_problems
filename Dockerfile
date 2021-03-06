FROM ubuntu:20.04
LABEL maintainer="Tokuma Suzuki tokuma.suzuki09@gmail.com"

ENV SHELL /bin/bash
ENV DEBIAN_FRONTEND noninteractive
ENV JULIA_MINOR_VERSION=1.6
ENV JULIA_PATCH_VERSION=2

## C++のビルドなどに必要なものを入れる
RUN apt-get update && apt-get install -y \
    build-essential cmake git wget  && \
    # python install
    apt-get install -y python3.8 python3.8-venv python3-pip && \
    cd /usr/local && \
    wget https://julialang-s3.julialang.org/bin/linux/x64/${JULIA_MINOR_VERSION}/julia-${JULIA_MINOR_VERSION}.${JULIA_PATCH_VERSION}-linux-x86_64.tar.gz && \
    tar xvf julia-${JULIA_MINOR_VERSION}.${JULIA_PATCH_VERSION}-linux-x86_64.tar.gz && \
    rm julia-${JULIA_MINOR_VERSION}.${JULIA_PATCH_VERSION}-linux-x86_64.tar.gz && \
    ln -s $(pwd)/julia-$JULIA_MINOR_VERSION.$JULIA_PATCH_VERSION/bin/julia /usr/bin/julia && \
    # clean-up
    apt-get autoremove -y && \
    apt-get clean &&\
    rm -rf /var/lib/apt/lists/* && \
    rm -rf /usr/local/src/*

# Python Libraries
COPY requirements.txt /tmp
RUN pip install --upgrade pip && \
    pip install --no-cache-dir -r /tmp/requirements.txt

# Julia Packages
ENV JULIA_PROJECT=/workspaces/algorithm_problems
COPY ./Project.toml /workspaces/algorithm_problems/Project.toml
RUN julia -e 'using Pkg; \
Pkg.activate("/workspaces/algorithm_problems"); \
Pkg.instantiate(); \
Pkg.precompile(); \
'

CMD ["/bin/bash"]
