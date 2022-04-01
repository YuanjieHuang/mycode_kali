# ref:https://segmentfault.com/a/1190000020891701
# site:https://nextcloud.com/install/#instructions-server

sudo apt update && sudo apt upgrade && sudo apt install -y libreoffice ffmpeg;
sudo apt install -y nginx;
sudo apt install -y redis;
sudo apt install mariadb-server;
sudo apt install -y php7.4 php7.4-fpm php7.4-curl php7.4-gd php7.4-xml php-mbstring \
 php-mysql php7.4-zip php7.4-bz2 php7.4-intl php-imagick;
sudo apt install -y  php7.4-commonphp-redis php7.4-openssl 
unzip nextcloud-*.zip
sudo mv nextcloud-xxx /var/www/html/nextcloud;
mkdir /var/www/html/nextcloud/data && sudo chown -R www-data:www-data /var/www/html/nextcloud;


配置php：打开/etc/php/7.4/fpm/php.ini文件，做如下更改：

    expose_php改成off
    date.timezone 一行删掉前面的;号，值改成Asia/Shanghai
    删掉opcache.enable=1，opcache.validate_timestamps=1，opcache.revalidate_freq=2这三行前面的;号，将opcache.revalidate_freq的值改成30;

配置fpm：打开/etc/php/7.4/fpm/pool.d/www.conf文件，移除clear_env=no，env[开头那几行前面的;号（即388，401-405这几行前面的分号）；

mysqladmin -uroot password '你的密码';

mysql -uroot -p'yuanjie' -e 'create user nextcloud@"%" identified by "nextcloud";
 create database nextcloud default charset=utf8mb4; grant all privileges on nextcloud.* to nextcloud@"%"; flush privileges;'；



 upstream php-handler {
    server unix:/run/php/php-fpm.sock;
}

server {
    listen 80;
    listen [::]:80;
    server_name cloud.example.com;
    # enforce https
    #return 301 https://$server_name:443$request_uri;
    #}

    #server {
    #    listen 443 ssl http2;
    #    listen [::]:443 ssl http2;
    #    server_name cloud.example.com;

    # Use Mozilla's guidelines for SSL/TLS settings
    # https://mozilla.github.io/server-side-tls/ssl-config-generator/
    # NOTE: some settings below might be redundant
    #    ssl_certificate /etc/ssl/nginx/cloud.example.com.crt;
    #    ssl_certificate_key /etc/ssl/nginx/cloud.example.com.key;

    # Path to the root of your installation
    root /var/www/html/nextcloud;

    location = /robots.txt {
        allow all;
        log_not_found off;
        access_log off;
    }

    # The following 2 rules are only needed for the user_webfinger app.
    # Uncomment it if you're planning to use this app.
    #rewrite ^/.well-known/host-meta /public.php?service=host-meta last;
    #rewrite ^/.well-known/host-meta.json /public.php?service=host-meta-json last;

    # The following rule is only needed for the Social app.
    # Uncomment it if you're planning to use this app.
    #rewrite ^/.well-known/webfinger /public.php?service=webfinger last;

    location = /.well-known/carddav {
        return 301 $scheme://$host:$server_port/remote.php/dav;
    }
    location = /.well-known/caldav {
        return 301 $scheme://$host:$server_port/remote.php/dav;
    }

    # set max upload size
    client_max_body_size 512M;
    fastcgi_buffers 64 4K;

    # Enable gzip but do not remove ETag headers
    gzip on;
    gzip_vary on;
    gzip_comp_level 4;
    gzip_min_length 256;
    gzip_proxied expired no-cache no-store private no_last_modified no_etag auth;
    gzip_types application/atom+xml application/javascript application/json application/ld+json application/manifest+json application/rss+xml application/vnd.geo+json application/vnd.ms-fontobject application/x-font-ttf application/x-web-app-manifest+json application/xhtml+xml application/xml font/opentype image/bmp image/svg+xml image/x-icon text/cache-manifest text/css text/plain text/vcard text/vnd.rim.location.xloc text/vtt text/x-component text/x-cross-domain-policy;

    # Uncomment if your server is build with the ngx_pagespeed module
    # This module is currently not supported.
    #pagespeed off;

    location / {
        rewrite ^ /index.php;
    }

    location ~ ^\/(?:build|tests|config|lib|3rdparty|templates|data)\/ {
        deny all;
    }
    location ~ ^\/(?:\.|autotest|occ|issue|indie|db_|console) {
        deny all;
    }

    location ~ ^\/(?:index|remote|public|cron|core\/ajax\/update|status|ocs\/v[12]|updater\/.+|oc[ms]-provider\/.+)\.php(?:$|\/) {
        fastcgi_split_path_info ^(.+?\.php)(\/.*|)$;
        set $path_info $fastcgi_path_info;
        try_files $fastcgi_script_name =404;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $path_info;
        #fastcgi_param HTTPS on;
        # Avoid sending the security headers twice
        fastcgi_param modHeadersAvailable true;
        # Enable pretty urls
        fastcgi_param front_controller_active true;
        fastcgi_pass php-handler;
        fastcgi_intercept_errors on;
        fastcgi_request_buffering off;
    }

    location ~ ^\/(?:updater|oc[ms]-provider)(?:$|\/) {
        try_files $uri/ =404;
        index index.php;
    }

    # Adding the cache control header for js, css and map files
    # Make sure it is BELOW the PHP block
    location ~ \.(?:css|js|woff2?|svg|gif|map)$ {
        try_files $uri /index.php$request_uri;
        add_header Cache-Control "public, max-age=15778463";
        # Add headers to serve security related headers (It is intended to
        # have those duplicated to the ones above)
        # Before enabling Strict-Transport-Security headers please read into
        # this topic first.
        #add_header Strict-Transport-Security "max-age=15768000; includeSubDomains; preload;" always;
        #
        # WARNING: Only add the preload option once you read about
        # the consequences in https://hstspreload.org/. This option
        # will add the domain to a hardcoded list that is shipped
        # in all major browsers and getting removed from this list
        # could take several months.
        add_header Referrer-Policy "no-referrer" always;
        add_header X-Content-Type-Options "nosniff" always;
        add_header X-Download-Options "noopen" always;
        add_header X-Frame-Options "SAMEORIGIN" always;
        add_header X-Permitted-Cross-Domain-Policies "none" always;
        add_header X-Robots-Tag "none" always;
        add_header X-XSS-Protection "1; mode=block" always;

        # Optional: Don't log access to assets
        access_log off;
    }

    location ~ \.(?:png|html|ttf|ico|jpg|jpeg|bcmap)$ {
        try_files $uri /index.php$request_uri;
        # Optional: Don't log access to other assets
        access_log off;
    }
}

Alan Skorkin将bash快捷键分成四类，接下来一一给出。
编辑

    Ctrl + a – 跳到行首
    Ctrl + e – 跳到行尾
    Ctrl + k – 删除当前光标至行尾内容
    Ctrl + u – 删除当前光标至行首内容
    Ctrl + w – 删除当前光标至词首内容
    Ctrl + y – 将剪切的内容粘贴在光标后
    Ctrl + xx – 在行首和当前光标处(来回)移动
    Alt + b – 跳到词首
    Alt + f – 跳到词尾
    Alt + d – 删除自光标处起的单词内容
    Alt + c – 大写光标处的字符（注：该条内容与原文不同）
    Alt + u – 大写自光标处起的单词内容
    Alt + l – 小写自光标处起的单词内容
    Alt + t – 将光标处单词与上一个词交换
    Ctrl + f – 向前移动一个字符(相当于按向左箭头)
    Ctrl + b – 向后移动一个字符(相当于按向右箭头)
    Ctrl + d – 删除光标后一个字符（相当于按Delete）
    Ctrl + h – 删除光标前一个字符（相当于按后退键）
    Ctrl + t – 交换光标处的两个字符

搜索

    Ctrl + r – 反向搜索历史命令
    Ctrl + g – 退出历史搜索模式（相当于按Esc）
    Ctrl + p – 上一个历史命令（相当于按向上箭头）
    Ctrl + n – 下一个历史命令（相当于按向下箭头）
    Alt + . – 使用上一个命令的最后一个单词

控制

    Ctrl + l – 清屏
    Ctrl + s – 终止输出到屏幕（对长时间运行并打印详细信息的命令）
    Ctrl + q – 允许输出到屏幕（如果之前用过终止输出命令）
    Ctrl + c – 终止命令
    Ctrl + z – 中断命令

Bang(即感叹号)

    !! – 执行上一条命令
    !blah –执行最近运行过的以blah开头的命令
    !blah:p – 打印!blah要执行的命令（并将其作为最后一条命令加入到命令历史中）
    !$ – 上一条命令的最后一个单词 (等同于Alt + .)
    !$:p – 打印!$指代的单词
    !* – 上一条命令除最后一个词的部分
    !*:p – 打印!*指代部分
