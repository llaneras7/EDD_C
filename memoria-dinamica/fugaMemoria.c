#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *nombre = (char *)malloc(sizeof(char) * 6);
    char *apellido = (char *)malloc(sizeof(char) * 6);
    if (nombre == NULL || apellido == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }
    strcpy(nombre, "Hola");
    strcpy(apellido, "mundo");
    printf("%s + %s en direcciones de memoria %p y %p\n", nombre, apellido, (void *)nombre, (void *)apellido);

    //free(nombre); //Libero la direccion de memoria de nombre antes de perder la referencia a ella (Evito fuga de memoria)
    //nombre = (char *)malloc(sizeof(char) * 10); // Fuga de memoria

    nombre = (char *)realloc(nombre, sizeof(char) * 16); // Evito fuga de memoria sin tener que liberar antes

    strcpy(nombre, "Adios");
    printf("%s + %s en direcciones de memoria %p y %p\n", nombre, apellido, (void *)nombre, (void *)apellido);

    free(nombre);
    free(apellido);
    return 0;
}

//Se ha llegado hasta la diapositiva 26