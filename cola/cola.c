#include "cola.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Person* createPerson(char* name, int age) {
    struct Person* newPerson = (struct Person*)malloc(sizeof(struct Person));
    if (newPerson == NULL) {
        printf("No hay memoria disponible\n");
        exit(-1);
    }

    strncpy(newPerson->name, name, sizeof(newPerson->name) - 1);
    newPerson->age = age;

    return newPerson;
}

void createQueue(struct Node** ptrqueue){
    *ptrqueue = NULL;
}

bool isEmpty(struct Node* queue) {
    
}

int size(struct Node* queue){

}




