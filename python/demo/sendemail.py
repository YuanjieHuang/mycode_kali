import smtplib#发邮件的库
from email.mime.text import MIMEText#邮件文本
#SMTP服务器
SMTPServer="smtp.163.com"
#发邮件的地址
Sender="m18569309403@163.com"
#发送者的邮箱密码
passwd="19930421p"
#
message="i am a good man"
msg=MIMEText(message)
#标题
msg["Subject"]="来自帅哥的问候"
#发送者
msg["From"]=Sender

mailServer=smtplib.SMTP(SMTPServer,25)

mailServer.login(Sender,passwd)

mailServer.sendmail(Sender,["m18569309403@163.com"],msg.as_string() )
mailServer.quit()
