// Q7. Read the current directory and display the name of the files, no of files in current directory.
#include <dirent.h>
#include <stdio.h>
int main() {
DIR *d;
struct dirent *dir;
int count = 0;
d = opendir(".");
if (d) {
while ((dir = readdir(d)) != NULL) {
printf("%s\n", dir->d_name);
count++;
}
closedir(d);
}
printf("Number of files: %d\n", count);
return 0;
}

/*
─$ gcc program7.c 
└─$ ./a.out
.zsh_history
Desktop
.sudo_as_admin_successful
output.txt
program7.c
.bashrc.original
program4.c
Advance OS - Copy.pdf
program9.c
Pictures
.swp
..
Templates
.face.icon
.xsession-errors.old
program10.c
.Xauthority
example.txt
OS_10_15.pdf
.java
.mozilla
program26.c
program17.c
Music
.bash_logout
16_20_21_23_24_25_26.pdf
.ICEauthority
program23.c
program8.c
program19.c
.cache
.zshrc
program28.c
program15.c
.local
program16.c
Public
.xsession-errors
1_9.pdf
Advance OS - Copy.docx
.bashrc
.gnupg
a.out
program11.c
Downloads
.profile
Videos
program1.c
.config
.face
.
program2.c
Documents
.viminfo
.dmrc
program20.c
Number of files: 56
*/
