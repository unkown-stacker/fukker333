
//Q16.To handle the two way communication between Parent and child using pipe.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1024 //buffer size in bytes 
int main()
{
int fd[2]; //file descriptors for the pipe pid_t pid; //process ID
char parent_message[]="hello from parent!"; 
char child_message[]="hello from child!";
char buffer[434]; //CREATE PIPE 
if(pipe(fd)>0)
{
perror("pipe error");
printf("helloo"); 
exit(1);
}
return 0;
}

/*
is ka output nahi mila
*/
