#!/bin/sh

if [ ! -d "/etc/nginx/ssl" ]; then
    mkdir /etc/nginx/ssl
    # 인증서 요청을 생성
    openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
            -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Student/CN=myko" \
            -keyout /etc/nginx/ssl/myko.key -out /etc/nginx/ssl/myko.crt
    mkdir -p /run/nginx
fi

nginx -g "daemon off;"
