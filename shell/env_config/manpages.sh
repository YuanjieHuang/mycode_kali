sudo apt-get install manpages manpages-dev manpages-de  manpages-de-dev

sudo apt-get install manpages-posix manpages-posix-dev

sudo apt-get install linux-doc libcorelinux-dev

#或者直接下载 C++ 帮助文档，然后把文件拷贝到 /usr/share/man/man3 # man std::vector
sudo apt-get install libc-dev glibc-doc libstdc++-10-dev libstdc++-10-doc

#/*manpages颜色  .bashrc*/
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_mb=$'\E[01;32m'
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_md=$'\E[01;36m'   # man description
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_me=$'\E[0m'
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_so=$'\E[01;32m'
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_se=$'\E[0m' 
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_us=$'\E[01;32m'  # underly select  
export <font face = "Courier" size = 5 color = "#a52a2a">LESS_TERMCAP_ue=$'\E[0m' 

