FROM alpine:3.18

RUN apk update && apk upgrade && apk add --no-cache mariadb mariadb-client dumb-init \
    && rm -rf /var/cache/apk/*

COPY ./conf/my.cnf /etc/my.cnf
COPY ./tools/configuration.sh .

EXPOSE 3306

# docker-compose에서 지정한 명령어와 관계없이 항상 실행
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "./configuration.sh"]
