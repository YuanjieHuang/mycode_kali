wget http://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz -C /var/www/
apt install nginx mariadb-server php php-fpm php-mysql

sudo -i
mysqldump -u username -p database_name > data-dump.sql

create database ssmdemo;
use ssmdemo;
source path/sql_table.sql;

update mysql.user set password=md5('new_password') where User='root';

 flush privileges;