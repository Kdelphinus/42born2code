#!/bin/sh

#https://make.wordpress.org/cli/handbook/how-to/how-to-install/
if [ ! -e "/var/www/wp-config.php" ]; then
  wp core download --allow-root
  wp config create --dbname=${DB_NAME} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --dbhost=${DB_HOST} --allow-root
  wp core install --title=${WP_NAME} --url=${DOMAIN_NAME} --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASSWORD} --admin_email=${WP_ADMIN_EMAIL} --allow-root
  wp user create ${WP_USER} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASSWORD} --allow-root

  # redis (bonus)
  wp config set WP_REDIS_HOST redis --allow-root
  wp config set WP_REDIS_PORT 6379 --raw --allow-root
  wp config set WP_CACHE_KEY_SALT ${DOMAIN_NAME} --allow-root
  wp config set WP_REDIS_CLIENT phpredis --allow-root
  wp config set WP_CACHE true --allow-root
  wp plugin install redis-cache --activate --allow-root
  wp plugin update --all --allow-root
  chmod 777 -R /var/www
fi

wp redis enable --allow-root

php-fpm8 -F