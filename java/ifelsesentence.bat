@echo off
if exist test.txt (echo 当前目录下有test.txt) else (
    echo 当前目录下没有test.txt
    pause
    cls
    echo 即将创建test.txt文件
    cd.>test.txt&&echo 成功创建test.txt
)
pause