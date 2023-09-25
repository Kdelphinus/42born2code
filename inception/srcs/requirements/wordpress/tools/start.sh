#!/bin/bash

#https://make.wordpress.org/cli/handbook/how-to/how-to-install/
ROOT_PASSWORD=12345
DB_NAME=wordpress
DB_USER=myko
DB_PASSWORD=12345
ADMIN_USER=myko
ADMIN_PASSWORD=12345
ADMIN_EMAIL=myko@student.42seoul.kr

set -e -x
mkdir -p /var/www/html
cd /var/www/html

wp core download --allow-root
mv /wp-conf-sample.php /wp-config.php
ls -al /etc/init.d/php-fpm81
mv /wp-config.php /var/www/html/wp-config.php
wp core install --url=localhost --title="inception" --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL
/usr/sbin/php-fpm81 -F