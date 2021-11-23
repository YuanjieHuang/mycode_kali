// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <signal.h>
// #include <errno.h>
// /* Simpleerror handling functions*/
// #define handle_error_en(en, msg)\
//         do { errno= en; perror(msg);exit(EXIT_FAILURE);}while(0)
// static void * sig_thread(void*arg)
// {
//       sigset_t *set=(sigset_t*) arg;
//       int s, sig;
//     //   for (;;){
//             s = sigwait(set,&sig);
//             if (s != 0)
//                   handle_error_en(s,"sigwait");
//             printf("Signal handling thread got signal %d\n", sig);
//     //   }
// }
// int  main(int argc, char*argv[])
// {
//       pthread_t thread;
//       sigset_t set;
//       int s;
//       /* 
//          Block SIGINT; other threads created by main() will inherit
//          a copy of the signal mask. 
//        */
//       sigemptyset(&set);
//       sigaddset(&set, SIGQUIT);
//       sigaddset(&set, SIGINT);
//       sigaddset(&set, SIGUSR1);
//       s = pthread_sigmask(SIG_BLOCK,&set,NULL);
//       if (s!= 0)
//             handle_error_en(s,"pthread_sigmask");
//       s = pthread_create(&thread,NULL,&sig_thread,(void*)&set);
//       if (s!= 0)
//             handle_error_en(s,"pthread_create");
//       /* 
//         Main thread carries on to create other threads and/ordo
//         other work 
//        */
//     //   pause();/* Dummy pause so we can test program*/
//     pthread_join(thread,NULL);
//       return 0;
// }
#include<stdio.h>
#include<pthread.h>
#include<signal.h>
static void sig_alrm(int signo);
static void sig_init(int signo);
int  main()
{
    sigset_t set;
    int sig;
    sigemptyset(&set);
    sigaddset(&set, SIGALRM);
    pthread_sigmask(SIG_SETMASK, &set, NULL);//阻塞SIGALRM信号
    signal(SIGALRM, sig_alrm);
    signal(SIGINT, sig_init);
    sigwait(&set, &sig);//sigwait只是从未决队列中删除该信号，并不改变信号掩码。也就是，当sigwait函数返回，它监听的信号依旧被阻塞。
    switch(sig){
    case 14:
        printf("sigwait, receive signal SIGALRM\n");
        /*do the job when catch the sigwait*/
        break;
    default:
        break;
    }
    sigdelset(&set, SIGALRM);
    pthread_sigmask(SIG_SETMASK, &set, NULL);
    for(;;)
    return 0;
}
static void sig_alrm(int signo)
{
    printf("after sigwait, catch SIGALRM\n");
    fflush(stdout);
    return ;
}
static void sig_init(int signo)
{
    printf("catch SIGINT\n");
    return ;
}