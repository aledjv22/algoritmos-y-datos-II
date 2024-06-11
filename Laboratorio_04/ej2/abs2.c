#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y)
{
    if (x >= 0)
    {
        *y = x;
    }
    else
    {
        *y = -x;
    }
}

int main(void)
{
    int a=0, res=0;
    a = -10;
    absolute(a, &res);
    printf("El valor absoluto de %d es %d.\n", a, res);
    assert(res >= 0 && (res == a || res == -a));
    res = 0;
    return EXIT_SUCCESS;
}

/*
    El parámetro  int *y de absolute() es de tipo in/out.
    Para el parámetro in: int a.
    Para el parámetro out: return res.
    Para el parámetro in/out: int *y.
*/