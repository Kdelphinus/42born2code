#!bin/sh

# mysql이 없을 때 mysql 구성
if [ ! -d "/var/lib/mysql/mysql" ]; then

        chown -R mysql:mysql /var/lib/mysql # /var/lib/mysql의 소유권을 mysql 사용자 및 그룹에게 부여

        # init database
        mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

        tfile=`mktemp`
        if [ ! -f "$tfile" ]; then
                return 1
        fi
fi

# wordpress database가 없을 때 생성
if [ ! -d "/var/lib/mysql/wordpress" ]; then

        cat << EOF > /tmp/create_db.sql
USE mysql;                               # mysql 데이터베이스 사용
FLUSH PRIVILEGES;                        # 권한 설정을 새로고침해서 현재까지 변경 사항 적용
DELETE FROM mysql.user WHERE User='';    # 빈 사용자 계정 삭제
DROP DATABASE test;                      # test 데이터베이스 삭제
DELETE FROM mysql.db WHERE Db='test';    # test 데이터베이스에 대한 권한 삭제

# root 계정 중 호스트 주소가 로컬 호스트가 아닌 것을 삭제 -> 원격 접속 제한
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';                    # root 계정의 비밀번호 변경
CREATE DATABASE wordpress CHARACTER SET utf8 COLLATE utf8_general_ci;  # wordpress 데이터베이스 생성
CREATE USER 'myko'@'%' IDENTIFIED by '1234';                           # 모든 호스트에서 접속 가능한 wordpress 사용자 생성
GRANT ALL PRIVILEGES ON wordpress.* TO 'myko'@'%';                     # wordpress 데이터베이스에 대한 모든 권한 부여

#ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT}';
#CREATE DATABASE ${DB_NAME} CHARACTER SET utf8 COLLATE utf8_general_ci;
#CREATE USER '${DB_USER}'@'%' IDENTIFIED by '${DB_PASS}';
#GRANT ALL PRIVILEGES ON wordpress.* TO '${DB_USER}'@'%';

FLUSH PRIVILEGES; # 권한 설정을 새로고침해서 현재까지 변경 사항 적용
EOF
        # run init.sql
        /usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_db.sql
        rm -f /tmp/create_db.sql
fi
