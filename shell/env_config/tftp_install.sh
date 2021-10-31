apt-get update
apt-get upgrade
apt-get install tftp-hpa tftpd-hpa 
mkdir -p /tmp/tftp
chown  nobody /tmp/tftp -R
cat>>/etc/default/tftpd-hpa<<eof
TFTP_USERNAME="tftp"
TFTP_DIRECTORY="/tmp/tftp" # 这是tftpd-hpa的服务目录 要和上面建立的服务器目录一样
TFTP_ADDRESS="0.0.0.0:69"
TFTP_OPTIONS="-l -c -s"    # -c是可以上传文件
eof
service tftpd-hpa restart
