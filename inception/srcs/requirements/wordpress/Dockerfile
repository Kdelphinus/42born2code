FROM alpine:3.17

RUN apk update && apk upgrade && apk add php7 php7-fpm php7-curl php7-gd php7-json php7-mbstring php7-mysqli php7-xml php7-zip

RUN mkdir /var/www/html

COPY wordpress /var/www/html

RUN chown -R www-data:www-data /var/www/html

EXPOSE 80

CMD ["php-fpm7", "-F"]

ENV WORDPRESS_DB_HOST=mariadb