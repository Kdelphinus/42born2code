FROM alpine:3.17

RUN apk update && apk upgrade && apk add mariadb mariadb-client \
    && rm -rf /var/cache/apk/* \
    && mkdir -p /run/mysqld \
    && chown -R mysql:mysql /run/mysqld \
    && mysql_install_db --user=mysql --datadir=/var/lib/mysql

COPY ./conf/setup.sh /root/setup.sh
COPY ./conf/wordpress.sql /conf/wordpress.sql

RUN chmod 777 /root/setup.sh

EXPOSE 3306

