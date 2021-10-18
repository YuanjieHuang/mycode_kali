#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
/*
fputc/putc	fgetc getc
fputs/puts	fgets gets
fwrite		fread
fprintf		fscanf
frewind		fseek

*/
struct stu
{
	char name[10];
	int age;	
};
void main()
{
   struct stu mystu[3];
   FILE * fp;
   extern int errno; 
   char file[]="./a1.txt";
   int i;
   char str[100];
   strcpy(mystu[0].name,"Jim");
   mystu[0].age=14;
   strcpy(mystu[0].name,"Jam");
   mystu[1].age=14;  
   strcpy(mystu[0].name,"Lily");
   mystu[2].age=19; 
   fp=fopen(file,"a+");
   if(fp==NULL)
   {
   	  printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	  return;
   	}
   	else
   	{
   		printf("%s was opened.\n",file);   		
	}
 
    i=fwrite(mystu,sizeof(mystu),3,fp);
    printf("%d students was written.\n",i);
    fread(str,sizeof(mystu),3,fp);
    printf("%s.\n",str);
    fclose(fp);
}

void fputs_fgets()
{
   FILE * fp;
   extern int errno; 
   char file[]="./a1.txt";
   char *txt="hello";
   int i;
   char ch[10];
   fp=fopen(file,"w+");
   if(fp==NULL)
   {
   	  printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	  return;
   	}
   	else
   	{
   		printf("%s was opened.\n",file);   		
	}
 
   i=fputs(txt,fp);
	fgets(ch,4,fp);
   {
   	printf("%d char was written.\n",i);
		printf("%s\n",ch);
	}
	fclose(fp);
}

void fgets_fputs()
{
   FILE * fp;
   extern int errno; 
   char file[]="./a1.txt";
   fp=fopen(file,"w");
   int i;
   char a[5]="abcd";
   char b[5];
   if(fp==NULL)
   {
   	  printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	  return;
   }
   else
   {
      printf("%s was opened.\n",file);   		
	}
   fgets(b,5,fp);
   fputs(a,fp);
   printf("%s\n",b);
   fclose(fp); 
}


void getc_train()
{
   FILE * fp;
   extern int errno; 
   char file[]="./a1.txt";
   fp=fopen(file,"r");
   int i;
   char a;
   if(fp==NULL)
   {
   	  printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   	  return;
   	}
   	else
   	{
   		printf("%s was opened.\n",file);   		
	}
	for(i=0;i<10;i++)
	{
		a=getc(fp);
		if(a==EOF)
		{
			break;
		}
		printf("%c",a);
   }
   printf("\n");
   fclose(fp);   
}

void rename_()
{ 
   char path[]="/root/a.txt";
   char path1[]="/root/a11.txt";
   char newpath[]="/tmp/b.txt";
   extern int errno;
   if(rename(path,newpath)==0)
   {
      printf("the file %s was moved to %s .\n",path,newpath);	
   }
   else
   {
      printf("can't move the file %s .\n",path);	
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
  
   if(rename(path1,newpath)==0)
   {
      printf("the file %s was moved to %s .\n",path1,newpath);	
   }
   else
   {
      printf("can't move the file %s .\n",path1);	
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
} 

void fsync_()
{ 
   int fd;
   char path[]="/root/txt1.txt";
   char s[]="hello ,Linux.\nI've leart C program for two weeks.\n";
   extern int errno; 
   
   fd=open(path,O_WRONLY|O_CREAT);
   if(fd!=-1)
   {
      printf("opened file %s  .\n",path);	
   }
   else
   {
      printf("cant't open file %s.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
   write(fd,s,sizeof(s));
   if(fsync(fd)==0)
   {
   	  printf("fsync function done.\n");
   }
   else
   {
      printf("fsync function failed. \n");
   }
   close(fd);
} 

void sync_()
{ 
   int fd;
   char path[]="/root/txt1.txt";
   char s[]="hello ,Linux.\nI've leart C program for two weeks.\n";
   extern int errno; 
   
   fd=open(path,O_WRONLY|O_CREAT);
   if(fd!=-1)
   {
      printf("opened file %s  .\n",path);	
   }
   else
   {
      printf("cant't open file %s.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
   write(fd,s,sizeof(s));
   sync();
   printf("sync function done. \n");
   close(fd);
}

void lseek_()
{ 
   int fd;
   char path[]="/root/txt1.txt";
   int size;
   char s[100]="";
   extern int errno; 
   
   fd=open(path,O_RDONLY);
   if(fd!=-1)
   {
      printf("opened file %s  .\n",path);	
   }
   else
   {
      printf("cant't open file %s.\n",path);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
   
   size=read(fd,s,3);    
   printf("%d  :",size);
   printf("%s\n",s);
  
   size=read(fd,s,3); 
   printf("%d  :",size);
   printf("%s\n",s);
   
   lseek(fd,8,SEEK_SET);
   size=read(fd,s,3);
   printf("%d  :",size);
   printf("%s\n",s);

   lseek(fd,0,SEEK_SET);
   size=read(fd,s,3);
   printf("%d  :",size);
   printf("%s\n",s);
         
   close(fd);  
}

void mkstemp_()
{ 
   extern int errno;
   char path[]="mytemp-XXXXXX";
   
   if(mkstemp(path)!=-1)
   {
      printf("created temp file %s.\n",path);	
   }
   else
   {
      printf("cant't create temp file %s.\n",path);
   	  printf("errno: %d\n",errno);
   	  printf("ERR  : %s\n",strerror(errno));
   }
} 