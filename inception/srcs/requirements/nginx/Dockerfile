FROM alpine:3.18

RUN apk update && apk upgrade && apk add nginx openssl dumb-init  \
    && rm -rf /var/cache/apk/*

COPY ./conf/nginx.conf /etc/nginx/http.d/nginx.conf
COPY ./tools/configuration.sh .

EXPOSE 443

# docker-compose에서 지정한 명령어와 관계없이 항상 실행
ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "configuration.sh"]