#include <stdio.h>
#include <stdlib.h>
#include "listaEnlazada.h" //Librerias propias van con comillas dobles!!

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

    printf("\nEstructura antes de insertar:\n");
    mostrar(head);
    insertar_cabeza(&head, 10);
    insertar_cabeza(&head, 30);
    insertar_cabeza(&head, 20);

    printf("\nEstructura despues de insertar en la cabeza:\n");
    mostrar(head);

    insertar_cola(&head, 1);
    insertar_cola(&head, 2);
    
    printf("\nEstructura despues de insertar al final:\n");
    mostrar(head);

    insertar_en_medio(&head, 100, 0);
    insertar_en_medio(&head, 200, 2);
    
    printf("\nEstructura despues de insertar en medio:\n");
    mostrar(head);

    eliminar(&head,1);
    eliminar(&head,30);
    eliminar(&head,10);
    eliminar(&head,20);

    printf("\nEstructura despues de eliminar:\n");
    mostrar(head);

    insertar_cabeza(&head, 10);
    insertar_cabeza(&head, 30);
    insertar_cabeza(&head, 20);

    printf("\nEstructura antes de destruir:\n");
    mostrar(head);

    destruir(&head);

    printf("\nEstructura despues de destruir:\n");
    mostrar(head);

    printf("\n");

    //free(head->next);
    //free(head);

    return 0;
}