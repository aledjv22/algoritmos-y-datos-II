#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

static void print_array(int arr[], unsigned int length) {
    printf("\nTu array es: [");
    for(unsigned int i = 0; i < length; ++i) {
        printf("%d", arr[i]);
        if(i < length - 1) printf (", ");
    }
    printf("]\n");
}

static void input_numbers(int arr[], unsigned int length) {
    for(unsigned int i = 0; i < length; ++i) {
        printf("Ingrese su nro. %d: ", i);
        scanf("%d", &arr[i]);
    }
}

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    res.is_upperbound = arr[0] <= value;
    res.is_lowerbound = arr[0] >= value;
    res.exists = arr[0] == value;
    if(res.exists) res.where = 0;

    for(unsigned int i = 1; i < length; ++i) {
        if (!res.is_upperbound && !res.is_lowerbound) break;

        if(arr[i] == value && !res.exists) {
            res.exists = true;
            res.where = i;
        }

        res.is_upperbound = res.is_upperbound && arr[i] <= value;
        
        res.is_lowerbound = res.is_lowerbound && arr[i] >= value;
    }

    return res;
}

int main(void) {
    unsigned int array_size = 0;
    int value;
    printf("Bienvenido/a, a continuación se le solicitaran los datos necesarios para el programa.\n");

    while(array_size < 1) {
        printf("Ingrese el tamaño para su array: ");
        scanf("%d", &array_size);
        if(array_size < 1) printf("Por favor ingrese un valor mayor a 0.\n");
    }

    int a[array_size];

    input_numbers(a, array_size);

    print_array(a, array_size);

    printf("\nIngrese el nro. a comparar: ");
    scanf("%d", &value);
    printf("\n");

    struct bound_data result = check_bound(value, a, array_size);

    if (result.exists && result.is_lowerbound)
        printf("El valor %d está en el array y es el mínimo. Se encuentra en la posición %d.\n", value, result.where);
    else if (result.exists && result.is_upperbound)
        printf("El valor %d está en el array y es el máximo. Se encuentra en la posición %d.\n", value, result.where);
    else if (result.is_lowerbound)
        printf("El valor %d no está en el array. Es una cota inferior.\n", value);
    else if (result.is_upperbound)
        printf("El valor %d no está en el array. Es una cota superior.\n",value);
    else printf("El valor %d no está en el array. No es un cota superior ni inferior.\n",value);

    return EXIT_SUCCESS;
}

