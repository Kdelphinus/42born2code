FROM alpine:3.17

RUN apk update && apk upgrade && apk add mariadb mariadb-client vim \
    && rm -rf /var/cache/apk/* \
    && mkdir -p /var/run/mysqld \
    && chmod 777 /var/run/mysqld; \
    sed -i "s|\[mysqld\]|\[mysqld\]\nskip-host-cache\nskip-name-resolve\nbind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf; \
    sed -i "s|skip-networking|skip-networking=0|g" /etc/my.cnf.d/mariadb-server.cnf; \
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

EXPOSE 3306

COPY ./conf/setup.sh .
RUN sh setup.sh && rm setup.sh
USER mysql
CMD ["mysqld"]
