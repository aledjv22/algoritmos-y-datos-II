#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

/* Read status */
// fscanf returns 1 when it reads a number
#define READ_SUCCESS 1 
// fscanf returns 0 when it can't read a number
#define READ_FAILURE 0
// fscanf returns EOF when it reaches the end of the file
#define READ_EOF EOF 


static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

static unsigned int data_from_file(const char *path,
                                   unsigned int indexes[],
                                   char letters[],
                                   unsigned int max_size) {
    unsigned int i = 0;
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        printf("Error, the file could not be opened.\n");
        exit(EXIT_FAILURE);
    }

    while(!feof(file) && (i < max_size)) {
        fscanf(file, "%u -> *%c*\n", &indexes[i], &letters[i]);
        ++i;
    }

    fclose(file);

    return i;
}

int main(int argc, char *argv[]) {
    char *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    // char sorted[MAX_SIZE];
    unsigned int length=0; 

    if(argc != 2) {
        printf("Error, invalid number of arguments.\n");
        exit(EXIT_FAILURE);
    }

    file = argv[1];

    length = data_from_file(file, indexes, letters, MAX_SIZE);
    
    if(length >= MAX_SIZE) {
        printf("Error, the read size is greater than the allowed size.\n");
        exit(EXIT_FAILURE);
    }

    dump(letters, length);

    return EXIT_SUCCESS;
}

