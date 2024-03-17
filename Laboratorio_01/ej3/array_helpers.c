#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

// Read the array from a file
unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    unsigned int length; 
    // Open the file in read mode
    FILE *file = fopen(filepath, "r");
    // Check if the file was opened successfully
    if(file == NULL) {
        printf("Error, the file %s could not be opened.\n", filepath);
        exit(EXIT_FAILURE);
    }

    // Read the length of the array
    fscanf(file, "%u", &length);

    // Check if the length is greater than the maximum allowed
    if(length > max_size) {
        printf("Error, the read size is greater than the allowed size.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    unsigned int i;
    for(i= 0; i < length; ++i) {
        // Read each number and store it in the array
        int read_status = fscanf(file, "%d", &array[i]);

        // Check if the read was successful
        if(read_status == READ_FAILURE) {
            printf("Error, the reading could not be performed.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        // Check if the file ended before reading all the numbers
        if(read_status == READ_EOF) {
            printf("Error, the indicated size is greater than the number of numbers.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    
    // Check if the file has more numbers than the length indicates
    if(fscanf(file, "%d", &array[length]) == READ_SUCCESS) {
        printf("Error, the indicated size is less than the number of numbers.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(file);

    return length;
}

// Print the array
void array_dump(int a[], unsigned int length) {
    printf("\nYour array is: [");

    for(unsigned int i = 0; i < length; ++i) {
        printf("%d", a[i]);
        if(i < length - 1) printf (", ");
    }
    printf("]\n");
}