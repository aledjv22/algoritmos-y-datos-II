#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d)
{
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void)
{

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n\n",
           sizeof(messi.name),
           sizeof(messi.age),
           sizeof(messi.height),
           sizeof(messi));

    printf("Addresses using uintptr_t:\n"
           " - name  : %lu\n"
           " - age   : %lu\n"
           " - height: %lu\n"
           " - data_t: %lu\n\n",
           (uintptr_t)&messi.name,
           (uintptr_t)&messi.age,
           (uintptr_t)&messi.height,
           (uintptr_t)&messi);

    printf("Addresses using (void *): \n"
           " - name  : %p\n"
           " - age   : %p\n"
           " - height: %p\n"
           " - data_t: %p\n",
           (void *)&messi.name,
           (void *)&messi.age,
           (void *)&messi.height,
           (void *)&messi);

    return EXIT_SUCCESS;
}

/*
    ¿La suma de los miembros coincide con el total?
    RTA: Sí, la suma de los miembros coincide con el total.

    ¿El tamaño del campo name depende del nombre que contiene?
    RTA: No, el tamaño del campo name no depende del nombre que contiene,
    sino que depende del tamaño máximo que se le asignó en NAME_MAXSIZE.

    ¿Hay algo raro en las direcciones de memoria?
    RTA: Mas que raro hay algo llamativo que las memorias son seguidas,
    es decir, la dirección de memoria de age inicializa donde finaliza
    la dirección de memoria de name, y la dirección de memoria de height
    inicializa donde finaliza la dirección de memoria de age.
    |name|age|height|
    Otro dato curioso es que la dirección de memoria de data_t inicializa
    donde inicia la dirección de memoria de name y finaliza donde finaliza
    la dirección de memoria de height.

    SALIDA ANALIZADA:
        NOMBRE: Leo Messi
        EDAD  : 36 años
        ALTURA: 169 cm

        name-size  : 30 bytes
        age-size   : 4 bytes
        height-size: 4 bytes
        data_t-size: 40 bytes

        Addresses using uintptr_t:
        - name  : 140725680800944
        - age   : 140725680800976
        - height: 140725680800980
        - data_t: 140725680800944

        Addresses using (void *):
        - name  : 0x7ffd403704b0
        - age   : 0x7ffd403704d0
        - height: 0x7ffd403704d4
        - data_t: 0x7ffd403704b0

*/