#!/bin/sh

if [ ! -d "/etc/nginx/ssl" ]; then
    mkdir /etc/nginx/ssl
    # 인증서 요청을 생성
    # rsa:4096 4096비트의 키를 생성, -x509: 자체 서명된 인증서를 생성하기 위한 옵션
    openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
            -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Student/CN=myko" \
            -keyout /etc/nginx/ssl/myko.key -out /etc/nginx/ssl/myko.crt
    mkdir -p /run/nginx
fi

# nginx를 포그라운드에서 실행
nginx -g "daemon off;"
