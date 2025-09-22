#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node * ptrnodo;

struct Node{
    int data;
    ptrnodo next;
};

void iterar(struct Node head);

void insertar_cabeza (struct Node ** direccionHead, int dato);

void insertar_cola (struct Node ** direccionHead, int dato);

void insertar_en_medio(struct Node ** direccionHead, int dato, int posicion);

void insertar_lista_ordenada(struct Node ** direccionHead, int dato);

void destruir(struct Node ** direccionHead);

bool eliminar(struct Node ** direccionHead, int data);

void mostrar(struct Node * direccionHead);