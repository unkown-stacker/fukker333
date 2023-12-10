
//Q23.Write a program that illustrates how to execute two commands
//concurrently with a pipe.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
int pipefd[2];
pid_t pid1, pid2;
// Create a pipe
if (pipe(pipefd) == -1) {
perror("pipe");
exit(EXIT_FAILURE);
}
// Fork first child process
pid1 = fork();
if (pid1 == -1) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid1 == 0) {
// Child process 1
// Close the read end of the pipe
close(pipefd[0]);
// Redirect stdout to the write end of the pipe
dup2(pipefd[1], STDOUT_FILENO);// Execute the first command
execlp("ls", "ls", NULL);
// Exit the child process if execlp fails
perror("execlp");
exit(EXIT_FAILURE);
}
// Fork second child process
pid2 = fork();
if (pid2 == -1) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid2 == 0) {
// Child process 2
// Close the write end of the pipe
close(pipefd[1]);
// Redirect stdin to the read end of the pipe
dup2(pipefd[0], STDIN_FILENO);
// Execute the second command
execlp("wc", "wc", "-l", NULL);
// Exit the child process if execlp fails
perror("execlp");
exit(EXIT_FAILURE);
}
// Parent process
// Close both ends of the pipe
close(pipefd[0]);
close(pipefd[1]);
// Wait for both child processes to exit
waitpid(pid1, NULL, 0);waitpid(pid2, NULL, 0);
return 0;
}



/*
└─$ gcc program23.c
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ ./a.out  
32


*/

