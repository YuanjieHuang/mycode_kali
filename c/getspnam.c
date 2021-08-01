#include <sys/types.h>
#include <pwd.h>

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<shadow.h>
#include<string.h>
#include<crypt.h>
#if 0
int main(int argc, char * argv[])
{
	struct spwd *sp;
	char buf[80];
 
	setpwent();
	while(gets(buf) != NULL)
	{
		if((sp = getspnam(buf)) != (struct spwd *) 0 )
		{
			printf("Vaild login name is:%s\n",sp->sp_namp);
		}
		else
		{
			setspent();
			while((sp = getspent()) != (struct spwd *)0)
			{
				printf("%s\n", sp->sp_namp);
			}
		}
	}
 
	endspent();
	return(EXIT_SUCCESS);
}
#endif

int showUserNameById(int argc,char *argv[])
{
    struct passwd *pwdline;
    if(argc<2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    pwdline=getpwuid(atoi(argv[1]));
    puts(pwdline->pw_name);
    exit(0);
}

#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
int main(int argc, char *argv[])
{
    
    struct spwd *shadowline;


    char *crypted_pass;

    char *input_pass;
    if(argc<2)
    {
    
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    //口令获取
    input_pass=getpass("PassWord:");
    
    shadowline=getspnam(argv[1]);

    crypted_pass=crypt(input_pass,shadowline->sp_pwdp);

    if(strcmp(shadowline->sp_pwdp,crypted_pass)==0)
        puts("OK!");
    else
        puts("failer!");
    exit(0);
}
