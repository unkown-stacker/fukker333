
//Q1). Create a File with Hole in it
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define a file pointer
    FILE *file;

    // Open a file for writing (creating if it doesn't exist)
    file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Write data to the file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a test file.\n");

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Read and print the contents of the file
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}

/*
└─$ gcc program1.c 
                                                                                                                                                                       
┌──(kali㉿kali)-[~]
└─$ ./a.out
Hello, World!
This is a test file.

*/
