#include "cola.h"
#include <stdio.h>

int main(){

    char name[30] = "Juanito";
    int age = 20;

    struct Person * persona1 = createPerson(name, age);

    printf("Persona1 con nombre: %s y edad: %d \n", persona1->name, persona1->age);
    return 0;
}