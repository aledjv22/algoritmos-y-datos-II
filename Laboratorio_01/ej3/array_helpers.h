#ifndef _ARRAY_HELPERS_H_
#define _ARRAY_HELPERS_H_

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

/* Read status */
// fscanf returns 1 when it reads a number
#define READ_SUCCESS 1 
// fscanf returns 0 when it can't read a number
#define READ_FAILURE 0
// fscanf returns EOF when it reaches the end of the file
#define READ_EOF EOF 

// Read the array from a file
unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);

// Print the array
void array_dump(int a[], unsigned int length);

#endif