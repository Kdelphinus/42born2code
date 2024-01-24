FROM alpine:3.18

RUN apk update && apk upgrade && apk add mariadb mariadb-client dumb-init \
    && rm -rf /var/cache/apk/* \
    && sed -i "s|\[mysqld\]|\[mysqld\]\nskip-host-cache\nskip-name-resolve\nbind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf \
    && sed -i "s|skip-networking|skip-networking=0|g" /etc/my.cnf.d/mariadb-server.cnf

EXPOSE 3306

COPY ./tools/configuration.sh .

# docker-compose에서 지정한 명령어와 관계없이 항상 실행
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "configuration.sh"]
