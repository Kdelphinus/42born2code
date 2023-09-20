FROM alpine:3.17

RUN apk update && apk upgrade && apk add mariadb mariadb-client \
    && rm -rf /var/cache/apk/* \
    && mkdir -p /run/mysqld \
    && chown -R mysql:mysql /run/mysqld \
    && mysql_install_db --user=mysql --datadir=/var/lib/mysql

COPY ./conf /conf

EXPOSE 3306

CMD ["mysqld_safe"]
