FROM buildpack-deps:jessie

ENV LIBMONGO_VERSION=1.6.0

RUN wget https://github.com/mongodb/mongo-c-driver/releases/download/$LIBMONGO_VERSION/mongo-c-driver-$LIBMONGO_VERSION.tar.gz \
    && tar xzf mongo-c-driver-$LIBMONGO_VERSION.tar.gz \
    && cd mongo-c-driver-$LIBMONGO_VERSION \
    && ./configure --disable-automatic-init-and-cleanup \
    && make \
    && make install

WORKDIR /usr/local/src

COPY . .
