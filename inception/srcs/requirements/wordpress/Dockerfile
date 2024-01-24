FROM alpine:3.18

RUN apk update && apk upgrade && apk add php8 php8-json php8-mysqli \
    php8-curl php8-dom php8-exif php8-pecl-imagick php8-pecl-igbinary \
    php8-intl php8-mbstring php8-openssl php8-xml php8-fpm php8-zip \
    php8-phar curl mariadb-client dumb-init

# Install wordpress cli
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

RUN mkdir /run/php

EXPOSE 9000

COPY ./tools/configuration.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/configuration.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "./start.sh"]
