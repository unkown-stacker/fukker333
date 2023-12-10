//Q 19. Write a C program to implement the following unix/linux command (use
//fork, pipe and exec system call) ls –l | wc –l
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
int main() {
int fd[2];
pid_t pid1, pid2;
// create pipe
if (pipe(fd) == -1) {
perror("pipe");
exit(EXIT_FAILURE);
}
// fork first child (ls -l)
pid1 = fork();
if (pid1 == -1) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid1 == 0) {
// redirect stdout to write end of pipe
dup2(fd[1], STDOUT_FILENO);
// close unused read end of pipe
close(fd[0]);
// execute ls -l
execlp("ls", "ls", "-l", NULL);
perror("execlp");exit(EXIT_FAILURE);
}
// fork second child (wc -l)
pid2 = fork();
if (pid2 == -1) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid2 == 0) {
// redirect stdin to read end of pipe
dup2(fd[0], STDIN_FILENO);
// close unused write end of pipe
close(fd[1]);
// execute wc -l
execlp("wc", "wc", "-l", NULL);
perror("execlp");
exit(EXIT_FAILURE);
}
// parent process
// close both ends of pipe
close(fd[0]);
close(fd[1]);
// wait for both children to finish
wait(NULL);
wait(NULL);
return 0;
}

/*
└─$ gcc program19.c
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ ./a.out
33

*/
