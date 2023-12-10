
//Q20. To create ‘n’ children . When the children will terminate,display total
//cumulative time children Spent in user and kernel mode.
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sys/wait.h>
#include<unistd.h> 
int main(int argc , char **argv)
{ 
int n = atoi(argv[1]);
int i,status,pid_t,pid; 
struct rusage r_usage;
struct timeval user_time,kernel_time;
long total_user_usec=0, total_kernal_usec=0;
for(i<0; i<n; i++)
{ 
pid = fork();
if(pid < 0){
perror("fork error");
exit(1);
}
else if(pid==0){
printf("child %d started \n",i+1); sleep(5);
printf("child %d finished \n",i+1);
exit(0);
}
}
while((pid = wait(&status))>0)
{
if(getrusage(RUSAGE_CHILDREN,& r_usage) < 0)
{
perror("getrusage error");
exit(1);
}
user_time = r_usage.ru_utime;
kernel_time =
r_usage.ru_stime;
printf("child %d: user time =%ld microseconds,kernel time = %ld microseconds.\n",pid,user_time.tv_usec,kernel_time.tv_usec); 
total_user_usec += user_time.tv_usec;
total_kernal_usec += kernel_time.tv_usec;
}
printf("Total time spend :%ld \n",total_user_usec);
printf("Total time spend :%ld \n",total_kernal_usec);
return 0;
}


/*
└─$ gcc program20.c
└─$ ./a.out 4
child 3 started 
child 1 started 
child 2 started 
child 4 started 
child 2 finished 
child 1 finished 
child 4 finished 
child 108498: user time =0 microseconds,kernel time = 2074 microseconds.
child 108499: user time =0 microseconds,kernel time = 3662 microseconds.
child 108501: user time =667 microseconds,kernel time = 3662 microseconds.
child 3 finished 
child 108500: user time =1690 microseconds,kernel time = 3662 microseconds.
Total time spend :2357 
Total time spend :13060 
*/






