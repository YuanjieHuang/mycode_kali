sudo apt install samba samba-common
# 新建目录，用于共享
sudo mkdir /usr/local/samba
# 更改权限信息
sudo chown nobody:nogroup /usr/local/samba
# 给所有用户添加读写权限
sudo chmod 777 /usr/local/samba

sudo smbpasswd -a ubuntu

sudo vim /etc/samba/smb.conf

[Volumes]
  comment = ubuntu samba server
  path = /usr/local/samba
  browseable = yes
  writable = yes
  available = yes
  valid users = ubuntu

sudo service smbd restart