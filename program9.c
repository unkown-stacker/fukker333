//Q 9. Write a C program to display all the files from current directory which are
//created in particular month programing code in c

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
int main() {
DIR *d;
struct dirent *dir;
struct stat st;
int month = 12; // change to desired month (1-12)
char month_str[12][12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
d = opendir(".");
if (d) {
while ((dir = readdir(d)) != NULL) {
if (stat(dir->d_name, &st) == -1) {
perror("stat");
continue;
}
int file_month = localtime(&st.st_ctime)->tm_mon;
if (file_month == month-1) {
printf("%s\n", dir->d_name);
}}
closedir(d);
} else {
perror("opendir");
}
return 0;
}

/*
$ gcc program9.c                
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ ./a.out                       
.zsh_history
Desktop
output.txt
program7.c
program4.c
Advance OS - Copy.pdf
program9.c
Pictures
.swp
.xsession-errors.old
program10.c
.Xauthority
example.txt
OS_10_15.pdf
program26.c
program17.c
16_20_21_23_24_25_26.pdf
program23.c
program8.c
program19.c
.cache
program28.c
program15.c
program16.c
.xsession-errors
1_9.pdf
Advance OS - Copy.docx
a.out
program11.c
program1.c
.config
.
program2.c
Documents
.viminfo
program20.c
               
*/
