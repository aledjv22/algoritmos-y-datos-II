#ifndef _SORT_HELPERS_H
#define _SORT_HELPERS_H

#include <stdbool.h>

bool goes_before(int x, int y);
/* Orden total abstracto para algoritmos de ordenamiento */

bool array_is_sorted(int a[], unsigned int length);
/* Verifica si el array 'a' está en orden ascendente */

void swap(int a[], unsigned int i, unsigned int j);
/* Intercambia los elementos del array 'a' en las posiciones dadas 'i' y 'j'
   El array permanece igual si las dos posiciones son las mismas
*/

#endif
