#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main(void)
{
    int x = 0, y = 0;
    x = 6;
    y = 4;
    printf("El valor de X es %d, mientras que el de Y es %d.\n", x, y);
    swap(&x, &y);
    printf("El valor de X es %d, mientras que el de Y es %d.\n", x, y);
    x = 0;
    y = 0;

    return EXIT_SUCCESS;
}