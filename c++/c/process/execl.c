#include <stdio.h>
#include <unistd.h>

int main(void)
{
	execl("/bin", "./ls", "-l", "-a", NULL);
	printf("execl end\n\n");

	char *argv[] = {"ls", "-l", "-a", "-F", NULL};

       execl("/bin/ls", "ls", "-l", "-a", "-F", NULL);
//        execl("./test", "test",  NULL);
    // execvp("ls", argv);
	printf("execvp end\n\n");
	return 0;
}
