//Q .4 Print the type of file where file name accepted Through Command line.
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
int main(int argc, char *argv[]) {
if (argc != 2)
{
printf("Usage: %s <file_name>\n", argv[0]);
return 1;
}
char *file_name = argv[1];
char *extension = strrchr(file_name, '.');
if (extension
== NULL) {
printf("File type cannot be determined.\n");
return 1;
}
if (strcmp(extension, ".txt") == 0) 
{
printf("Text file.\n");
}
else if (strcmp(extension, ".doc") == 0 || strcmp(extension,".docx") == 0) 
{
printf("Microsoft Word document.\n");
(strcmp(extension, ".pdf") == 0) ;
{
printf("PDF document.\n");
}
}
 else {
printf("File type not recognized.\n");
}
return 0;
}

/*
└─$ gcc program4.c
└─$ ./a.out example.txt 
Text file.
*/
