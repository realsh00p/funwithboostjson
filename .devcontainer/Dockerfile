FROM debian:bullseye-slim

RUN apt update && apt install -y \
        gnupg \
        wget

RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -

RUN echo "deb http://apt.llvm.org/bullseye/ llvm-toolchain-bullseye-14 main" > /etc/apt/sources.list.d/clang.list && \
    echo "deb-src http://apt.llvm.org/bullseye/ llvm-toolchain-bullseye-14 main" >> /etc/apt/sources.list.d/clang.list

RUN apt update && apt install -y \
        git \
        clang-14 \
        clang-format-14 \
        clang-tidy-14 \
        clangd-14 \
        cmake \
        build-essential \
        vim

RUN cd /opt && \
        wget https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.bz2 && echo "475d589d51a7f8b3ba2ba4eda022b170e562ca3b760ee922c146b6c65856ef39 boost_1_79_0.tar.bz2" | sha256sum -c - && \
        tar -xjf boost_1_79_0.tar.bz2 && \
        cd boost_1_79_0 && \
            ./bootstrap.sh && \
            ./b2 install \
                --prefix=/usr \
                --with-json

RUN cd /opt && \
        wget https://github.com/google/googletest/archive/refs/tags/release-1.12.0.tar.gz -O googletest-1.12.0.tar.gz && echo "2a4f11dce6188b256f3650061525d0fe352069e5c162452818efbbf8d0b5fe1c googletest-1.12.0.tar.gz" | sha256sum -c - && \
        tar -xzf googletest-1.12.0.tar.gz && \
        cd googletest-release-1.12.0 && \
            mkdir -p build && \
                cd build && \
                cmake .. -DCMAKE_INSTALL_PREFIX=/usr && \
                make -j $(nproc) && \
                make install


