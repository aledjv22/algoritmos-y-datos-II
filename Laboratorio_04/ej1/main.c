/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person
{
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void)
{
    // Declaración de punteros
    int *number = NULL;
    char *letter = NULL;
    // Declaración e inicializado de variables a modificar
    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};
    // Modificación del valor en x
    number = &x;
    *number = 9;
    // Modificación del valor de m
    number = &m.age;
    *number = 100;
    letter = &m.name_initial;
    *letter = 'F';
    // Modificación del valor de a[1]
    number = &a[1];
    *number = 42;
    // Impreso de los resultados.
    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

