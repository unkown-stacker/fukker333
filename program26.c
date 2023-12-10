//Q 26.Write a C program which create a child process which catch a signal
//sighup, sigint and sigquit. The Parent process send a sighup or sigint signal after
//every 3 seconds, at the end of 15 second parent send sigquit signal to child and
//child terminates my displaying message "My Papa has Killed me!!!”.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
volatile sig_atomic_t flag = 0;
void signal_handler(int signal) {
flag = 1;
}
int main() {
pid_t pid = fork();
if (pid == -1) {
fprintf(stderr, "Failed to fork.\n");
return EXIT_FAILURE;
}
if (pid == 0) { // child process
signal(SIGHUP, signal_handler);
signal(SIGINT, signal_handler);
signal(SIGQUIT, signal_handler);
while (1) {
if (flag) {
printf("Signal received.\n");
flag = 0;}
sleep(1);
}
} else { // parent process
for (int i = 1; i <= 10; i++) {
sleep(3);
if (i % 2 == 0) {
kill(pid, SIGHUP);
} else {
kill(pid, SIGINT);
}
}
kill(pid, SIGQUIT);
int status;
wait(&status);
if (WIFEXITED(status)) {
printf("Child process terminated with status %d.\n", WEXITSTATUS(status));
} else if (WIFSIGNALED(status)) {
printf("Child process terminated by signal %d.\n", WTERMSIG(status));
}
}
return EXIT_SUCCESS;
}


/*
─$ gcc program26.c
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ ./a.out
Signal received.
Signal received.
Signal received.
Signal received.
Signal received.
Signal received.
Signal received.
Signal received.


*/
