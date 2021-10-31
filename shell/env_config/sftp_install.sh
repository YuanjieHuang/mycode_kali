mkdir -pv /mnt/sda1/sftp/public
groupadd sftp
useradd -g sftp -d /mnt/sda1/sftp -p sftp -s /bin/false sftp
echo "set sftp user password!"
passwd sftp
chmod 777 /mnt/sda1/sftp/public
chown -R sftp:sftp /mnt/sda1/sftp/public
chmod 755 /mnt/sda1/sftp
chown root:root /mnt/sda1/sftp
