
//Q28. Write a C program that illustrates suspending and resuming processes using signals.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void sigint_handler(int signum) {
printf("Caught signal %d (SIGINT)\n", signum);
}
int main() {
struct sigaction sa;
sigemptyset(&sa.sa_mask);
sa.sa_flags = 0;
sa.sa_handler = sigint_handler;
sigaction(SIGINT, &sa, NULL);
printf("Press Ctrl+C to suspend the program...\n");
while (1) {
sleep(1);
printf("Still running...\n");
kill(getpid(), SIGSTOP);
printf("Resuming...\n");
}
return 0;
}

/*
$ gcc program28.c

$ ./a.out        
Press Ctrl+C to suspend the program...
Still running...
zsh: suspended (signal)  ./a.out
*/
