
//Q 10. Write a C program to display all the files from current directory whose size
//is greater that n Bytes , Where n is accept from user.

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
int main() {
DIR *d;
struct dirent *dir;
struct stat st;
long min_size;
printf("Enter minimum file size in bytes: ");
scanf("%ld", &min_size);
d = opendir(".");
if (d) {
while ((dir = readdir(d)) != NULL) {
if (stat(dir->d_name, &st) == -1) {
perror("stat");
continue;
}
if (st.st_size > min_size) {
printf("%s\n", dir->d_name);
}
}closedir(d);
} else {
perror("opendir");
}
return 0;
}

/*
gcc program10.c
$ ./a.out
Enter minimum file size in bytes: 2
*/
