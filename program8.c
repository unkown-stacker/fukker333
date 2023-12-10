//Q8. Write a C program which receives file names as command line arguments
//and display those filenames in ascending order according to their sizes


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int compare(const void *a, const void *b) {
struct stat *stat_a = (struct stat *) a;
struct stat *stat_b = (struct stat *) b;
return stat_a->st_size - stat_b->st_size;
}
int main(int argc, char *argv[]) {
struct stat *stats = malloc(sizeof(struct stat) * argc);
if (stats == NULL) {
fprintf(stderr, "Failed to allocate memory.\n");
return EXIT_FAILURE;
}
for (int i = 1; i < argc; i++) {
if (stat(argv[i], &stats[i]) != 0) {
fprintf(stderr, "Failed to get file size for %s.\n", argv[i]);
return EXIT_FAILURE;
}
}
qsort(&stats[1], argc - 1, sizeof(struct stat), compare);
for (int i = 1; i < argc; i++) {
printf("%s - %ld bytes\n", argv[i], stats[i].st_size);
}free(stats);
return EXIT_SUCCESS;
}

/*
$ gcc program8.c
$ ./a.out program1.c example.txt
program1.c - 35 bytes
example.txt - 1160 bytes

*/
