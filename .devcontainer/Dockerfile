# 東方故事 MUD — FluffOS 執行/開發容器
# 以 FluffOS 官方主要支援平台 Ubuntu 24.04 為基底，自 source 建置指定版本的驅動。
FROM ubuntu:24.04

ARG FLUFFOS_VERSION=v2026.0901.0
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
      build-essential autoconf automake bison expect libtool pkg-config cmake git \
      libmysqlclient-dev libpcre3-dev libpq-dev libsqlite3-dev libssl-dev \
      libz-dev libgtest-dev libjemalloc-dev libffi-dev libdw-dev libbz2-dev \
      libicu-dev telnet ca-certificates locales less vim-tiny \
    && rm -rf /var/lib/apt/lists/*

# 這個 mudlib 已全面轉為 UTF-8；FluffOS 需要 UTF-8 locale 才能正確處理中文寬度
RUN sed -i '/en_US.UTF-8/s/^# //' /etc/locale.gen && locale-gen
ENV LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8

RUN git clone --depth 1 --branch ${FLUFFOS_VERSION} https://github.com/fluffos/fluffos.git /src/fluffos \
 && cmake -S /src/fluffos -B /src/fluffos/build -DCMAKE_BUILD_TYPE=Release -DMARCH_NATIVE=OFF \
 && cmake --build /src/fluffos/build --target install -j "$(nproc)" \
 && mkdir -p /opt/fluffos && cp -a /src/fluffos/build/bin/. /opt/fluffos/ \
 && ln -sf /opt/fluffos/driver /usr/local/bin/driver \
 && ln -sf /opt/fluffos/portbind /usr/local/bin/portbind \
 && rm -rf /src/fluffos

WORKDIR /mudlib
EXPOSE 8888
CMD ["/usr/local/bin/driver", "/mudlib/etc/fluffos.cfg"]
