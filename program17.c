
//Q17.To demonstrate the use of atexit() function
#include <stdio.h> 
#include<stdlib.h> 

void cleanup1()
{
printf("Cleanup 1\n");
}

void cleanup2()
{
printf("Cleanup2\n");
}

int main() 
{
atexit(cleanup1);
atexit(cleanup2);
printf("Hello, world!\n");
}

/*
└─$ gcc program17.c
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ ./a.out
Hello, world!
Cleanup2
Cleanup 1

*/
