sudo apt-get install vsftpd
sudo systemctl status vsftpd
touch /srv/ftp/1.txt
sudo /etc/init.d/vsftpd restart
# ftp://127.0.0.1/
# sudo vim /etc/vsftpd.conf
# sudo vim /etc/allowed_users 
# https://www.myfreax.com/how-to-setup-ftp-server-with-vsftpd-on-ubuntu-18-04/
