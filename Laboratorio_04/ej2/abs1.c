#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y)
{
    if (x >= 0)
    {
        y = x;
    }
    else
    {
        y = -x;
    }
}

int main(void)
{
    int a=0, res=0;
    a = -10;
    absolute(a, res);
    printf("El valor absoluto de %d es %d\n", a, res);
    res = 0;

    return EXIT_SUCCESS;
}

/*
    El valor que se muestra por pantalla es 0.
    El programa no coincide con el del lenguaje teórico.
*/