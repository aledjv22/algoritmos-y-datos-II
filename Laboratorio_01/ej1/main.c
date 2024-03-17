/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
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

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

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


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
