#!/bin/sh

# datadir에 기본 셋업을 진행한다.
if [ ! -d "/var/lib/mysql/mysql" ]; then
  mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db
fi

# rc 명령어로 초기화 및 부팅 시 mariadb 실행
rc default

service mariadb start

if [ ! -d "/var/lib/mysql/wordpress" ]; then
  # mysql_installation 설정
  mysql -e "CREATE USER IF NOT EXISTS ${MYSQL_USER}@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"

  # wordpress database 생성
  mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
  mysql -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO ${MYSQL_USER}@'%' ;"
  mysql -e "FLUSH PRIVILEGES"

  # mysql_root 설정
  mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
fi

service mariadb stop

# mysql 폴더 소유권 변경
chown -R mysql:mysql /var/lib/mysql

# mariadb를 사용자 'mysql'로 실행
/usr/bin/mysqld --user=mysql
