sudo apt-get install curl openssh-server ca-certificates apt-transport-https

curl https://packages.gitlab.com/gpg.key | sudo apt-key add -

sudo curl -sS https://packages.gitlab.com/install/repositories/gitlab/raspberry-pi2/script.deb.sh | sudo bash

sudo EXTERNAL_URL="192.168.123.162" apt-get install gitlab-ce