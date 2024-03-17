/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

/* Read status */
// fscanf returns 1 when it reads a number
#define READ_SUCCESS 1 
// fscanf returns 0 when it can't read a number
#define READ_FAILURE 0
// fscanf returns EOF when it reaches the end of the file
#define READ_EOF EOF 

// Read the array from the file
unsigned int array_from_stdin(int array[], unsigned int max_size) {
    FILE *file = stdin;

    unsigned int i = 0;
    unsigned int length = 0;
    int read_status = 1;
    
    while(read_status != READ_EOF) {
        printf("Ingrese su nro. %d: ", i);
        // Read each number and store it in the array
        read_status = fscanf(file, "%d", &array[i]);

        // Check if the read was successful
        if(read_status == READ_FAILURE) {
            printf("Error, the reading could not be performed.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        
        i++;
        if (read_status == READ_SUCCESS) length++;
    }

    // Check if the length is greater than the maximum allowed
    if(length > max_size) {
        printf("Error, the read size is greater than the allowed size.\n");
        exit(EXIT_FAILURE);
    }

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


int main() {
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
