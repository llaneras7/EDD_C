#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "listaEnlazada.h"

void iterar(struct Node head){
    struct Node * ptrIter = &head;

    while(ptrIter->next!=NULL){
        printf("Data: %d, posición de memoria: %p, next: %p\n", ptrIter->data, (void *)ptrIter, (void *)ptrIter->next);
        ptrIter = ptrIter->next;
    }
}

void insertar_cabeza (struct Node ** direccionHead, int dato){ //Para poder modificar la direccion de head que es un puntero a struct Node debemos pasarle como parametro la direccion de head, es decir un puntero a puntero a struct Node
    struct Node * nuevo = (struct Node *) malloc(sizeof(struct Node));
    if (nuevo == NULL){
        printf("No hay memoria disponible\n");
        exit(-1);
    }
    nuevo->data = dato; //Insertamos el dato en la nueva posicion de memoria
    nuevo->next = (*direccionHead); //El siguiente del nuevo nodo sera el que antes era head
    (*direccionHead)=nuevo; //Actualizamos head para que apunte a la nueva posicion de memoria
   
}

void insertar_cola (struct Node ** direccionHead, int dato){ //Para poder modificar la direccion de head que es un puntero a struct Node debemos pasarle como parametro la direccion de head, es decir un puntero a puntero a struct Node
    struct Node * nuevo = (struct Node *) malloc(sizeof(struct Node));
    if (nuevo == NULL){
        printf("No hay memoria disponible\n");
        exit(-1);
    }
    
    nuevo->data = dato; //Insertamos el dato en la nueva posicion de memoria
    nuevo->next = NULL; //El siguiente del nuevo nodo sera NULL ya que es el ultimo nodo
    if((*direccionHead)==NULL){ //Si la lista esta vacia, el nuevo nodo sera el head
        (*direccionHead)=nuevo;
    } else {
        struct Node * ptrIter = *direccionHead; //Creamos un puntero auxiliar para recorrer la lista
        while(ptrIter->next!=NULL){ //Recorremos la lista hasta el ultimo nodo
            ptrIter = ptrIter->next;
        }
        ptrIter->next = nuevo; //El siguiente del ultimo nodo sera el nuevo nodo
    }
}

void insertar_en_medio(struct Node ** direccionHead, int dato, int posicion){
    struct Node * nuevo = (struct Node *) malloc(sizeof(struct Node));
    if (nuevo == NULL){
        printf("No hay memoria disponible\n");
        exit(-1);
    }
    nuevo->data = dato; //Insertamos el dato en la nueva posicion de memoria
    if(posicion==0){ //Si la posicion es 0, insertamos en la cabeza
        nuevo->next = (*direccionHead);
        (*direccionHead)=nuevo;
    } else {
        struct Node * ptrIter = *direccionHead; //Creamos un puntero auxiliar para recorrer la lista
        int i=0;
        while(ptrIter->next!=NULL && i<posicion-1){ //Recorremos la lista hasta la posicion anterior a la que queremos insertar
            ptrIter = ptrIter->next;
            i++;
        }
        nuevo->next = ptrIter->next; //El siguiente del nuevo nodo sera el siguiente del nodo actual
        ptrIter->next = nuevo; //El siguiente del nodo actual sera el nuevo nodo
    }
}

void insertar_lista_ordenada(struct Node ** direccionHead, int dato){
    struct Node * nuevo = (struct Node *) malloc(sizeof(struct Node));
    if (nuevo == NULL){
        printf("No hay memoria disponible\n");
        exit(-1);
    }
    nuevo->data = dato; //Insertamos el dato en la nueva posicion de memoria
    if((*direccionHead)==NULL || (*direccionHead)->data >= dato){ //Si la lista esta vacia o el dato es menor que el head, insertamos en la cabeza
        nuevo->next = (*direccionHead);
        (*direccionHead)=nuevo;
    } else {
        struct Node * ptrIter = *direccionHead; //Creamos un puntero auxiliar para recorrer la lista
        while(ptrIter->next!=NULL && ptrIter->next->data < dato){ //Recorremos la lista hasta encontrar la posicion correcta
            ptrIter = ptrIter->next;
        }
        nuevo->next = ptrIter->next; //El siguiente del nuevo nodo sera el siguiente del nodo actual
        ptrIter->next = nuevo; //El siguiente del nodo actual sera el nuevo nodo
    }
}

void destruir(struct Node ** direccionHead){
    struct Node * ptrIter = *direccionHead;
    struct Node * ptrAux;

    while(ptrIter!=NULL){ //Recorremos la lista hasta el final
        ptrAux = ptrIter; //Guardamos el nodo actual en un puntero auxiliar
        ptrIter = ptrIter->next; //Avanzamos al siguiente nodo
        free(ptrAux); //Liberamos la memoria del nodo actual
    }
    *direccionHead = NULL; //Actualizamos head para que apunte a NULL
}

bool eliminar(struct Node ** direccionHead, int data){
    struct Node * ptrIter = *direccionHead;
    struct Node * ptrPrev = NULL;

    while(ptrIter!=NULL && ptrIter->data!=data){ //Recorremos la lista hasta encontrar el nodo con el dato o llegar al final
        ptrPrev = ptrIter;
        ptrIter = ptrIter->next;
    }
    if(ptrIter==NULL){ //Si hemos llegado al final, el dato no existe
        return false;
    }
    if(ptrPrev==NULL){ //Si el nodo a eliminar es el head
        *direccionHead = ptrIter->next; //Actualizamos head para que apunte al siguiente nodo
    } else {
        ptrPrev->next = ptrIter->next; //El siguiente del nodo anterior sera el siguiente del nodo a eliminar
    }
    free(ptrIter); //Liberamos la memoria del nodo a eliminar
    return true;
}

void mostrar(struct Node * direccionHead){
    while(direccionHead!=NULL){
        printf("Dato: %d\n Siguiente:%p\n",direccionHead->data, (void *)direccionHead->next);
        direccionHead = direccionHead->next;
    }
}