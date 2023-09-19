FROM alpine:3.17

RUN apk update && apk upgrade && apk add nginx openssl \
    && rm -rf /var/cache/apk/*

RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Ko/CN=localhost" \
    -keyout /etc/ssl/server.key -out /etc/ssl/server.crt

RUN chmod 600 /etc/ssl/server.crt /etc/ssl/server.key

COPY ./conf/default.conf /etc/nginx/http.d/default.conf

# HTTPS
EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
