#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Node * ptrnodo;

struct Node{
    int data;
    ptrnodo next;
};

void iterar(struct Node head){
    struct Node * ptrIter = &head;

    while(ptrIter->next!=NULL){
        printf("Data: %d, posición de memoria: %p, next: %p\n", ptrIter->data, (void *)ptrIter, (void *)ptrIter->next);
        ptrIter = ptrIter->next;
    }
}

void insertar (struct Node ** direccionHead, int dato){ //Para poder modificar la direccion de head que es un puntero a struct Node debemos pasarle como parametro la direccion de head, es decir un puntero a puntero a struct Node
    struct Node * nuevo = (struct Node *) malloc(sizeof(struct Node));
    if (nuevo == NULL){
        printf("No hay memoria disponible\n");
        exit(-1);
    }
    nuevo->data = dato;
    nuevo->next = (*direccionHead);
    (*direccionHead)=nuevo;
   
}

void destruir(struct Node ** direccionHead){
   ;
}

bool eliminar(struct Node ** direccionHead, int data){
    ;
}

void mostrar(struct Node * direccionHead){
    while(direccionHead!=NULL){
        printf("Dato: %d\n Siguiente:%p\n",direccionHead->data, direccionHead->next);
        direccionHead = direccionHead->next;
    }
}

int main(){

    struct Node * head = NULL;
    head = (struct Node *) malloc(sizeof(struct Node));
    

    head->data = 3;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 7;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 9;
    head->next->next->next = NULL;

    iterar(*head);

/*
    printf("\nEstructura antes de insertar:\n");
    mostrar(head);
    insertar(&head, 10);
    insertar(&head, 30);
    insertar(&head, 20);
    eliminar(&head,1);
    eliminar(&head,30);
    eliminar(&head,10);
    eliminar(&head,20);

    //VOlemos a insertar y destruimos
    insertar(&head, 10);
    insertar(&head, 30);
    insertar(&head, 20);

    destruir(&head);
*/

    printf("\n");

    free(head->next);
    free(head);

    return 0;
}