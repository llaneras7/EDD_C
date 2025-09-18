#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    // Size_t es un entero que se usa para represenar número de bytes
    // SIZE_MAX es el valor máximo de bytes de un objeto.
    size_t numBytes = SIZE_MAX;
    printf("Intento pedir %zu bytes\n", numBytes);

    int *arrDin = (int *)malloc(numBytes);

    //Siempre hay que comprobar el puntero después de pedir memoria
    if (arrDin == NULL)
    {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    arrDin[0] = 1;
    printf("Primer elemento %d en zona de memoria %p\n", arrDin[0], (void *)arrDin);

    // Libero memoria
    free(arrDin);

    return 0;
}