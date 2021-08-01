#include <fcntl.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/types.h>		/* some systems still require this */
#include <sys/stat.h>
#include <sys/termios.h>	/* for winsize */
#include <stdio.h>		/* for convenience */
#include <stdlib.h>		/* for convenience */
#include <stddef.h>		/* for offsetof */
#include <string.h>		/* for convenience */
#include <unistd.h>		/* for convenience */
#include <signal.h>		/* for SIG_ERR */
#include <bits/getopt_core.h>
int main(int argc, char **argv)
{
   int ch;
//    opterr = 0;
   while((ch = getopt(argc, argv, "a:bcde")) != -1)
   switch(ch)
   {
      case 'a':
         printf("option a:'%s'\n", optarg);  break;
      case 'b':
         printf("option b :b\n");  break;
      default:
         printf("other option :%c\n", ch);
   }
   printf("optopt +%c\n", optopt);
}