#include <malloc.h>
#include <sys/io.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>


#if 0
//列出某个目录下的文件列表以及相应 i 节点号，并且当遇到子目录，在其后面标示“（DIR）”字样。
int main()
{
    DIR *dp;
    struct dirent *dirp;
    char dirname[]="./";
    if((dp=opendir(dirname))==NULL){
        perror("opendir error");
        exit(1);
    }
    while((dirp=readdir(dp))!=NULL){
        if((strcmp(dirp->d_name,".")==0)||(strcmp(dirp->d_name,"..")==0))
            continue;
        printf("%6d:%-19s %5s\n",dirp->d_ino,dirp->d_name,(dirp->d_type==DT_DIR)?("(DIR)"):(""));
    }
    return 0;
}
#endif

//传入路径即可
void show_all(const char* path)
{

    DIR* dirp=opendir(path); //类似于FILE
    struct dirent* de=NULL; //dirent 获取文件夹目录属性
    struct stat st; //stat 获取文件属性
    char path2[500];
    while(de=readdir(dirp))
    {
        if(strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0) continue;
        printf("%s\n",de->d_name);
        strcpy(path2,path);
        strcat(path2,"/");
        strcat(path2,de->d_name);
        stat(path2,&st);
        if(S_ISDIR(st.st_mode))
        {
            show_all(path2);
        }
    }
    closedir(dirp);
}

/* 文件大小和修改时间 */
static int get_file_size_time(const char *filename)
{
	struct stat statbuf;
	/* 判断未打开文件 */ 
	if(stat(filename,&statbuf)==-1)
	{
		printf("Get stat on %s Error: %s\n", filename, strerror(errno));
		return(-1);
	}
	if(S_ISDIR(statbuf.st_mode)) // 目录
		return(1);
	if(S_ISREG(statbuf.st_mode)) // 文件
		printf("%s size: %ld bytes\tmodified at %s", filename, statbuf.st_size, ctime(&statbuf.st_mtime));
	return(0);
}

void strrp(char *src, char *beRepalcedStr, char *rpStr,char *dest)
{
    int sub_len = strlen(beRepalcedStr);
    char *po = NULL;
	char *q = src;
    while((po=strstr(q,beRepalcedStr))!=NULL)
    {
        strncat(dest, q, po-q);
        strcat(dest, rpStr);
        q += po - q + sub_len;
    }
    strcat(dest,q);
}
 
void changeFileName(char *dirname)
{
	DIR *dirp = opendir(dirname);
	struct dirent *direntp;
	struct  stat st;
	char dirbuf[1024];
	while((direntp=readdir(dirp))!=NULL) 
	{
		// char *dirbuf = NULL;
		// dirbuf = calloc(10,1024);
		memset(dirbuf,0,sizeof(dirbuf)); 
		strcpy(dirbuf,dirname); 
		strcat(dirbuf,"/"); 
		strcat(dirbuf,direntp->d_name); 
		stat(dirbuf,&st);
        if(strstr(dirbuf, ".txt"))
        {
            char dest[100];
            memset(dest,0,100);
            strrp(dirbuf,".txt",".cpp",dest);
            rename(dirbuf, dest);
			printf("%s\n",dest);
        }
		if(S_ISDIR(st.st_mode))
        {
            changeFileName(dirbuf);
        }
		// free(dirbuf);
	}
	closedir(dirp);
}

// int main(int argc, char **argv)
// {
// 	if(argc!=2)
// 	{
// 		printf("argc:%u argv[0]: %s  argv[1]:%s argv[2]:%s\n\a",argc, argv[0], argv[1],  argv[2]);
// 		exit(1);
// 	}
// 	changeFileName(argv[1]);
// 	// show_all(argv[1]);
// 	return 0;
// }

// 列出目录及子目录下的文件
int ReadDir(const char *strpathname)
{
  DIR *dir;   // 定义目录指针
  char strchdpath[256];  // 子目录的全路径
 
  if ( (dir=opendir(strpathname)) == 0 ) return -1; // 打开目录
 
  struct dirent *stdinfo; // 用于存放从目录读取到的文件和目录信息
 
  while (1)
  {
    if ((stdinfo=readdir(dir)) == 0) break;   // 读取一记录
 
    if (strncmp(stdinfo->d_name,".",1)==0) continue;  // 以.开始的文件不读
 
    if (stdinfo->d_type==8)    // 如果是文件，显示出来
    {
        printf("name=%s/%s\n",strpathname,stdinfo->d_name);
        if(strstr(stdinfo->d_name, ".txt"))
        {
            char dest[500],src[500];
            memset(dest,0,500);
            memset(src,0,500);
            sprintf(src,"%s/%s",strpathname,stdinfo->d_name);
            strrp(src,".txt",".cpp",dest);
            rename(src, dest);//para:absolute path
            printf("%s\n",dest);
        }
    }
 
    if (stdinfo->d_type==4)   // 如果是目录，再调用一次ReadDir
    {
      sprintf(strchdpath,"%s/%s",strpathname,stdinfo->d_name);
      ReadDir(strchdpath);
    }
  }
 
  closedir(dir);   // 关闭目录指针
}

int main()
{
    char strpwd[301];
    memset (strpwd,0,sizeof(strpwd));
    getcwd(strpwd,300);
    printf("cur dir:%s", strpwd);
    ReadDir(strpwd);
    return 0;
}