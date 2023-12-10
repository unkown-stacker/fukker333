
// Q.2 Takes multiple files as Command Line Arguments And print their inode number.
#include<stdio.h>
#include<sys/stat.h> 
#include<unistd.h>
int main(int argc, char*argv[]){ struct
stat buf; 
int i;
// loop through coom
for(i=0;i<argc;i++){
// get file
if(stat(argv[i],&buf)<0){
perror("stat error");
continue;
}
//print node
printf("%s:inode=%ld\n",argv[i],buf.st_ino);}
return 0;
}

/*
┌──(kali㉿kali)-[~]
└─$ gcc program2.c
└─$ ./a.out example.txt
./a.out:inode=919467
example.txt:inode=919407
*/
