FROM alpine:3.18

RUN apk update && apk upgrade && apk add --no-cache php81 \
    #The PHP extensions listed below are highly recommended
    #in order to allow WordPress to operate optimally and to maximise compatibility with many popular plugins and themes.
    \
    #https://make.wordpress.org/hosting/handbook/server-environment/#php-extensions
    \
    #Used for communications with other servers and processing data in JSON format.
    php81-json \
    #Connects to MySQL for database interactions.
    php81-mysqli \
    #Performs remote request operations.
    php81-curl \
    #Used to validate Text Widget content and to automatically configure IIS7+.
    php81-dom \
    #Works with metadata stored in images.
    php81-exif \
    #Provides better image quality for media uploads. See WP_Image_Editor for details. Smarter image resizing (for smaller images) and PDF thumbnail support, when Ghost Script is also available
    #PECL(PHP Extension Community Library)
    php81-pecl-imagick \
    #Increases performance as a drop in replacement for the standard PHP serializer.
    php81-pecl-igbinary \
    #Enable to perform locale-aware operations including but not limited to formatting, transliteration, encoding conversion, calendar operations, conformant collation, locating text boundaries and working with locale identifiers, timezones and graphemes.
    php81-intl \
    #Used to properly handle UTF8 text.
    php81-mbstring \
    # SSL-based connections to other hosts.
    php81-openssl \
    #Used for XML parsing, such as from a third-party site.
    php81-xml \
    php81-fpm \
    #Used for decompressing Plugins, Themes, and WordPress update packages.
    php81-zip \
    #use wp
    php81-phar \
    curl \
    dumb-init \
    && rm -rf /var/cache/apk/*

COPY ./tools/configuration.sh .

#https://developer.wordpress.org/apis/wp-config-php/
RUN sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" \
      /etc/php81/php-fpm.d/www.conf && \
sed -i "s|;cgi.fix_pathinfo=1|cgi.fix_pathinfo=0|g" \
      /etc/php81/php.ini

#https://make.wordpress.org/cli/handbook/guides/installing/#recommended-installation
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "./configuration.sh"]
