#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000


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

static unsigned int maximum(unsigned int indexes[], 
                            unsigned int length) {
    unsigned int max_index = indexes[0];

    for(unsigned int i = 1; i < length ; ++i) {
        printf("Max index: %u\n", max_index);
        if(max_index < indexes[i]) max_index = indexes[i];
    }

    return max_index;
}

static void reconstruction(char letters[], 
                           unsigned int indexes[], 
                           char sorted[], 
                           unsigned int length) {
    unsigned int max_index = maximum(indexes, length);

    if(max_index >= MAX_SIZE) {
        printf("Error, the maximum index is greater than the allowed size.\n");
        exit(EXIT_FAILURE);   
    }

    for(unsigned int i = 0; i < length; ++i) {
        sorted[indexes[i]] = letters[i];
    }
}

int main(int argc, char *argv[]) {
    char *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0; 

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

    reconstruction(letters, indexes, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

