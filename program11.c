
// Q11.Write a C Program that demonstrates redirection of standard output to afile.
#include <stdio.h>
int main() {
FILE *fp;
// Open a file for writing
fp = freopen("output.txt", "w", stdout);
// Print some text
printf("This Text is Written in Output.txt File !\n");
// Close the file
fclose(fp);
return 0;
}

/*
└─$ gcc program11.c
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ ./a.out        
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ open output.txt

*/
