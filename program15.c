
// Q 15.To generate parent process to write unnamed Pipe and will read from it

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h> 
#define BUFFER_SIZE 25 
int main()
{
int fd[2];
pid_t pid;
char write_msg[BUFFER_SIZE]="Hello, child!";
char read_msg[BUFFER_SIZE];
if(pipe(fd)<0) { perror("pipeerror");
exit(1);
}
pid=fork();
if(pid<0){
perror("fork error");
exit(1);
}else if (pid==0) {
close(fd[1]);
if(read(fd[0], read_msg,BUFFER_SIZE)<0){
perror("read error");
exit(1);
}
printf("child read from pipe:%s\n", read_msg);
exit(0);
}else {
close(fd[0]);
close(fd[0]);
if(write(fd[1],write_msg, strlen(write_msg)+1)<0){
perror("write error");
exit(1);
}
printf("parent wrote to pipe:%s\n",write_msg);
exit(0);
}
close(fd[1]);return 0;
}

/*
└─$ gcc program15.c
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ ./a.out
parent wrote to pipe:Hello, child!
child read from pipe:Hello, child!
*/
