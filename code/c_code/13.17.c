#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

struct telnum
{
   char name[7];
   char tel[13];
};

struct telnum num[100];
int i;
int menu()
{
   int i;
   i=0;
   while(1)
   {
      printf("Please select a menu:\n");
      printf("       1: add a number.\n");
      printf("       2: all the number.\n");
      printf("       3: select a number by name.\n");
      printf("       4: delete a number .\n");
      printf("       5: save to file .\n");
      printf("       6: load numbers from file .\n");
      printf("       0: exit .\n");
      scanf("%d",&i);
      if(i==0)
      {
         printf("Byebye.\n");
         exit(1);
      }
      if(i<1 || i>6)
      {
         printf("error.\n");
         continue;
      }
      else
      {
         return(i);
      }
   }
}

void shownum(struct telnum t)
{
	printf("Name   :%s\n",t.name);
	printf("    tel:%s\n",t.tel);
}

struct telnum addnum()
{   
	struct telnum numtmp;
	char na[7],tel[13];
	printf("add a telephone number:\n");
	printf("please input the name:\n");
	scanf("%s",na);
	printf("please input the num:\n");
	scanf("%s",tel);
	strcpy(numtmp.name,na);
	strcpy(numtmp.tel,tel);
	return(numtmp); 
}

void selectbyname()
{
	char na[20];
	int n,j;
	n=0;
	printf("select a number by name:\n");
	printf("please input a name :\n");
	scanf("%s",na);
	for(j=0;j<i;j++)
	{
		if(strcmp(num[j].name,na)==0)
		{
			shownum(num[j]);
			n++;
		}
	}
	if(n==0)
	{
		printf("no such a name");
	}
}

void delenum()
{
	char na[20];
	int j,n;
	n=0;
	printf("delete a num by name:\n");
	printf("please input a name :\n");
	scanf("%s",na);
	for(j=0;j<i;j++)
	{
		if(strcmp(num[j].name,na)==0)
		{
			n++;
			for(;j<i;j++)
	        {
		       num[j]=num[j+1];
	        }
	        i--;	
			break;
		}
	}
	if(n==0)
	{
		printf("no such a name");
	}
}

void savetofile()
{
   int j,fd;
   char file[]="/root/tel.txt";
   extern int errno; 
   fd=open(file,O_WRONLY|O_CREAT);
   if(fd!=-1)
   {
      printf("opened file %s  .\n",file);	
   }
   else
   {
      printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
   }
   for(j=0;j<i;j++)
   {
   	  printf(" %d %s\n",j,num[j].name);
      write(fd,num[j].name,7);
      write(fd,num[j].tel,13);
   }
   printf("saved.\n");	
   close(fd);
}
void loadfromfile()
{
	int j=0,fd,t;
	i=0;
	char na[7];
	char tel[13];
	char file[]="/root/tel.txt";
    extern int errno; 
    fd=open(file,O_WRONLY|O_CREAT);
    if(fd!=-1)
    {
      printf("opened file %s  .\n",file);	
    }
    else
    {
      printf("cant't open file %s.\n",file);
   	  printf("errno：%d\n",errno);
   	  printf("ERR  ：%s\n",strerror(errno));
    }
    while((t=read(fd,na,7))!=0&&t!=-1)
    {
    	strcpy(num[i].name,na);
    	read(fd,tel,13);
    	strcpy(num[i].tel,tel);
    	i++;
	}
	close(fd);
}
main()
{ 
    int s,j;
    printf("- - - - Telphone Notebook. - - - \n");
    while(1)
    {
       s=menu();
       if(s==1)
      {
          num[i]=addnum();
          i++;
       }
       if(s==2)
       {
          for(j=0;j<i;j++)
          {
             shownum(num[j]);	
		  }	
	   }
	   if(s==3)
       {
          selectbyname();
	   }
	   if(s==4)
       {
          delenum();
	   }
       if(s==5)
       {
          savetofile();
	   }
	   if(s==6)
       {
          loadfromfile();
	   }
   } 
} 
