// 通过在主线程中阻塞一些信号，其它的线程会继承信号掩码，
// 然后专门用一个线程使用sigwait函数来同步的处理信号，使其它的线程不受到信号的影响。 
#include <pthread.h>  
#include <stdio.h>  
#include <sys/signal.h>  
#define NUMTHREADS 3  
void sighand(int signo);  
void *threadfunc(void *parm)  
{  
    pthread_t             tid = pthread_self();  
    int                   rc;  
    printf("Thread %u entered\n", tid);  
    rc = sleep(3);  
    printf("Thread %u did not get expected results! rc=%d\n", tid, rc);  
    return NULL;  
}  
void *threadmasked(void *parm)  
{  
    pthread_t             tid = pthread_self();  
    sigset_t              mask;  
    int                   rc;  
    printf("Masked thread %lu entered\n", tid);  
    sigfillset(&mask); /* Mask all allowed signals */  
    // sigemptyset(&mask);  
    rc = pthread_sigmask(SIG_BLOCK, &mask, NULL);  
    if (rc != 0)  
    {  
        printf("%d, %s\n", rc, strerror(rc));  
        return NULL;  
    }  
    // rc = sleep(1);  
    if (rc != 0)  
    {  
        printf("Masked thread %lu did not get expected results! ""rc=%d \n",tid, rc);  
        return NULL;  
    }  
 sigwait(&mask,&rc);  
    printf("Masked thread %lu completed masked work\n",tid);  
    return NULL;  
}  
int main(int argc, char **argv)  
{  
    int                     rc;  
    int                     i;  
    struct sigaction        actions;  
    pthread_t               threads[NUMTHREADS];  
    pthread_t               maskedthreads[NUMTHREADS];  
    printf("Enter Testcase - %s\n", argv[0]);  
    printf("Set up the alarm handler for the process\n");  
    memset(&actions, 0, sizeof(actions));  
    sigemptyset(&actions.sa_mask);  
    actions.sa_flags = 0;  
    actions.sa_handler = sighand;  
    rc = sigaction(SIGALRM,&actions,NULL); 
    printf("Create masked and unmasked threads\n");  

    for(i=0; i<NUMTHREADS; ++i)  
    {  
        rc = pthread_create(&threads[i], NULL, threadfunc, NULL);  
        printf("threads[%u]:%lu\n",i,threads[i]);
        if (rc != 0)  
        {  
            printf("%d, %s\n", rc, strerror(rc));  
            return -1;  
        }  
        rc = pthread_create(&maskedthreads[i], NULL, threadmasked, NULL);  
        if (rc != 0)  
        {  
            printf("%d, %s\n", rc, strerror(rc));  
            return -1;  
        }  
    }  
    sleep(5);  
    printf("Send a signal to masked and unmasked threads\n");  
    for(i=0; i<NUMTHREADS; ++i)  
    {  
        rc = pthread_kill(threads[i], SIGALRM);  
        rc = pthread_kill(maskedthreads[i], SIGALRM);  
    }  
    printf("Wait for masked and unmasked threads to complete\n");  
    for(i=0; i<NUMTHREADS; ++i) {  
        rc = pthread_join(threads[i], NULL);  
        rc = pthread_join(maskedthreads[i], NULL);  
    } 
     
    printf("Main completed\n");  
    return 0;  
}  
void sighand(int signo)  
{  
    pthread_t             tid = pthread_self();  
    printf("Thread %lu in signal handler\n",tid);  
    return;  
  
}  
// Enter Testcase - ./a.out
// Set up the alarm handler for the process
// Create masked and unmasked threads
// threads[0]:139873710872128
// Thread 3805910592 entered
// Masked thread 139873702479424 entered
// threads[1]:139873694086720
// Thread 3789125184 entered
// Masked thread 139873685694016 entered
// threads[2]:139873677301312
// Thread 3772339776 entered
// Masked thread 139873668908608 entered
// Thread 3805910592 did not get expected results! rc=0
// Thread 3772339776 did not get expected results! rc=0
// Thread 3789125184 did not get expected results! rc=0
// Send a signal to masked and unmasked threads
// Wait for masked and unmasked threads to complete
// Masked thread 139873702479424 completed masked work
// Masked thread 139873668908608 completed masked work
// Masked thread 139873685694016 completed masked work
// Main completed
                                               
