
/etc/init.d/mysql stop
/usr/local/mysql/bin/mysqld_safe --skip-grant-tables &
mysql -u root -p
use mysql;
lush privileges;
update mysql.user set authentication_string=password('yuanjie') where user='root';

UPDATE user 
SET authentication_string = PASSWORD('dolphin')
WHERE user = 'dbadmin' AND 
      host = 'localhost';