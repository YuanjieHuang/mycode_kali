apt update && apt install samba -y 
cat >>/etc/samba/smb.conf <<EOF
[iso]                                 
   comment = this is a iso           
   path =  /mnt/sda2/smb   
   guest ok = yes                   
   browseable = yes                  
   write list = root 
EOF
smbpasswd -a yjie
systemctl restart smbd
