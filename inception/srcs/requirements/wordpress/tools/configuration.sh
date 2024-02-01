#!/bin/bash
#https://make.wordpress.org/cli/handbook/how-to/how-to-install/

if [ ! -e "/var/www/html/wp-config.php" ]; then
    mkdir -p /var/www/html
    cd /var/www/html
    wp core download --allow-root
    wp config create --dbname=${DB_NAME} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --dbhost=${DB_HOST} --skip-check
    wp core install --url=${WP_NAME} --title=${DOMAIN_NAME} --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASSWORD} --admin_email=${WP_ADMIN_EMAIL}
    wp user create ${WP_USER} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASSWORD}
fi

/usr/sbin/php-fpm81 -F