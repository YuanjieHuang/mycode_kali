    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/mman.h>

    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>    
    #include <sys/types.h>

    #define A 0
    #define B 0
    #if 1
    void my_pthread()
    {
        if(vfork() == 0)
        {
            printf("This is the child process\n");
        }
        else
        {
            printf("This is the parent process\n");
        }
    }
    void my_isatty()
    {
        int fd;
        char * file = "/dev/tty";
        fd = open (file, O_RDONLY);
        printf("%s, fd=%d", file, fd);
        if(isatty(fd))
        {
            printf("\tis a tty. \n");
            printf("ttyname = %s \n", ttyname(fd));
        }
        else
            printf(" is not a tty\n");
        close(fd);
    }
    void my_env()
    {
         char *p;
        if((p = getenv("USER")))
        printf("USER = %s\n", p);
        putenv("USER=test");
        printf("USER:%s\n", getenv("USER"));
    }

    void my_fseek()
    {
         FILE * stream;
        long offset;
        fpos_t pos;
        stream = fopen("/etc/passwd", "r");
        fseek(stream, 5, SEEK_SET);
        printf("offset = %d\n", ftell(stream));
        rewind(stream);
        fgetpos(stream, &pos);
        printf("offset = %d\n", pos);
        // pos = 10;
        fsetpos(stream, &pos);
        printf("offset = %d\n", ftell(stream));
        fclose(stream);
    }
    void open_write()
    {
        int fd, size;
        char s[] = "Linux Programmer!\n", buffer[80];
        fd = open("/tmp/temp", O_WRONLY|O_CREAT);
        write(fd, s, sizeof(s));
        close(fd);
        fd = open("/tmp/temp", O_RDONLY);
        size = read(fd, buffer, sizeof(buffer));
        close(fd);
        printf("%s", buffer);
    }
    void my_file()
    {
        printf("uid is %d\tgid is %d\n", getuid(), getgid());
        FILE * fp;
        int fd;
        fp = fopen("/etc/passwd", "r");
        fd = fileno(fp);
        sync();
        if(!isatty(fd))
        {
            printf("\033[32mfd=%d\033[0m\n", fd);
        // fsync(fd);
          fp = freopen("/etc/group", "r", fp);

        }
        
        fclose(fp); 

        open_write();
        my_fseek();
    }
    void number2Ascii()
    {
        double a = 123.45;
        double b = -1234.56;
        char *ptr;
        int decpt, sign;
        gcvt(a, 5, ptr);
        printf("a value=%s\n", ptr);
        ptr = gcvt(b, 6, ptr);
        printf("b value=%s\n", ptr);

    }
    void memmap()
    {
        int fd;
        void *start;
        struct stat sb;
        fd = open("/etc/passwd", O_RDONLY); /*打开/etc/passwd */
        fstat(fd, &sb); /* 取得文件大小 */
        start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if(start == MAP_FAILED) /* 判断是否映射成功 */
            {
                return;
            }
        printf("%s", start); munmap(start, sb.st_size); /* 解除映射 */
        close(fd);
    }

    void charMemSearch()
    {
        char *s = "0123456789012345678901234567890";
        char *p;
        p = memchr(s, '5', 10);
        printf("%s\n", p);
        printf("page size = %d\n", getpagesize());

    }

    void my_localtime()
    {
        char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        time_t timep;
        struct tm *p;
        time(&timep);
        p = localtime(&timep); //取得当地时间
        printf ("%d%d%d ", (1900+p->tm_year), (p->tm_mon), p->tm_mday);
        printf("%s%d:%d:%d\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
    }

    void myTime()
    {
        time_t timep;
        time (&timep);
        printf("timep:%d\n",timep);
        printf("%s\n\n", ctime(&timep));
        my_localtime();
    }

    void my_exec()
    {
        // execl("/bin/ls", "ls", "-al", "/etc/group", (char *)0);
        // execlp("ls", "ls", "-al", "/etc/passwd", (char *)0);
        // char * argv[] = {"ls", "-al", "/etc/passwd", (char*)};
        // execv("/bin/ls", argv);

        // char * argv_p[] = {"ls", "-al", "/etc/passwd", 0};
        // execvp("ls", argv_p);
        system("ls -al /etc/passwd /etc/shadow");//在编写具有 SUID/SGID 权限的程序时请勿使用system(), system()会继承环境变量, 
                                                    // 通过环境变量可能会造成系统安全的问题.
    }
    void main(){
        printf("init gid = %d   current gid = %d\n", getpgid(1),getpid());
        printf("pid=%d  ppid=%d\n", getpid(), getppid());
        my_exec();
        charMemSearch();
        // number2Ascii();
        myTime();
        my_file();
        my_env();
        my_isatty();
        my_pthread();

        
    }
    #elif 1
    void main(){
    double a = 123.45;
    double b = -1234.56;
    char *ptr;
    int decpt, sign;
    gcvt(a, 5, ptr);
    printf("a value=%s\n", ptr);
    ptr = gcvt(b, 6, ptr);
    printf("b value=%s\n", ptr);
}
#else

    #endif