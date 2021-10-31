#include <sys/types.h>
#include <pwd.h>

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<shadow.h>
#include<string.h>
#include<crypt.h>
#include "assert.h"
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
void show_spwd(struct spwd *shadowPwd)
{
    assert(shadowPwd);
    printf("Login name:%s\n",shadowPwd->sp_namp);
    printf("Hashed passphrase:%s\n",shadowPwd->sp_pwdp);
    printf("Date of last change:%ld\n",shadowPwd->sp_lstchg);
    printf("Number of days the account may be inactive:%s\n",shadowPwd->sp_inact);
    printf("Number of days since 1970-01-01 until account expires:%ld\n",shadowPwd->sp_expire);
}
int main(int argc, char *argv[])
{
    
    struct spwd *shadowline;


    char *crypted_pass;

    char *input_pass;
    if(argc<2)
    {
    
        fprintf(stderr,"Input localhost username\n");
        exit(1);
    }
    //口令获取
    input_pass=getpass("PassWord:");
    printf("%s\n",input_pass);
    shadowline=getspnam(argv[1]);
    printf("%s\n",shadowline->sp_pwdp);
    // show_spwd(shadowline);
    assert(input_pass);
    assert(shadowline);
    crypted_pass=crypt(input_pass,shadowline->sp_pwdp);

    if(strcmp(shadowline->sp_pwdp,crypted_pass)==0)
        puts("OK!");
    else
        puts("failer!");
    return 0;
}
