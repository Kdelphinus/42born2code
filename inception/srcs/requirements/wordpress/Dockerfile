FROM alpine:3.17

RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories
RUN apk update && apk upgrade && apk add \
    curl \
    tar \
    unzip \
    php8 \
    php8-fpm \
    php8-phar \
    php8-mysqli \
    php8-mysqlnd \
    php8-json \
    php8-curl \
    php8-dom \
    php8-exif \
    php8-fileinfo \
    php8-mbstring \
    php8-openssl \
    php8-xml \
    php8-zip \
    php8-redis \
    php8-ctype \
    && rm -rf /var/cache/apk/*
