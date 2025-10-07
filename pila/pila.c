#include "pila.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void stack_ll_init(struct Stack_ll **ptrStack){
    *ptrStack = malloc(sizeof(struct Stack_ll));

    (*ptrStack) -> size = 0;
    (*ptrStack) -> top = NULL;
}

void stack_ll_push(struct Stack_ll *ptrStack, struct Node element)
{
    if (ptrStack != NULL)
    {
        struct Node *copy = (struct Node *)malloc(sizeof(struct Node)); //Creamos un puntero al que le asignamos un espacio en memoria
        assert(copy != NULL && "New Task: out of memory");
        *copy = element; //Copiamos el Node entero que nos pasan 

        copy->next = ptrStack->top; //El 
        ptrStack->top = copy;
        ptrStack->size ++;
    }
}

struct Node stack_ll_top(struct Stack_ll *ptrStack) {
    if(ptrStack != NULL && ptrStack->top){
      struct Node element = *ptrStack->top; //Desreferenciamos el puntero para devolver la estructura y no un puntero a ella

      return element;
    }

    struct Node empty = {0}; 
    return empty;
}

bool stack_ll_pop(struct Stack_ll *ptrStack){

  if (ptrStack == NULL || ptrStack->top == NULL) {
    return false; // pila vacía o inválida
  }

  struct Node * aux = ptrStack->top; //Guardo el nodo que voy a eliminar
  ptrStack->top = ptrStack->top->next; //Actualizo el top al siguiente nodo
  ptrStack->size --;
  free(aux); //Libero la memoria del nodo que he eliminado

  return true;
}

bool stack_ll_isEmpty(struct Stack_ll * ptrStack){
    if(ptrStack == NULL || ptrStack->top == NULL){
        return true;
    }
    return false;
}

int stack_ll_size(struct Stack_ll * ptrStack){
  if(ptrStack == NULL || ptrStack->top == NULL){
    return 0;
  }

  return ptrStack->size;
}

void stack_ll_clear(struct Stack_ll *ptrStack) {
  if (ptrStack != NULL) {
      struct Node *current = ptrStack->top;
      while (current != NULL) {
          struct Node *aux = current;
          current = current->next;
          free(aux);
      }
      ptrStack->top = NULL;
      ptrStack->size = 0;
  }
}

void stack_ll_show(struct Stack_ll * ptrStack){
  if(ptrStack != NULL){
    printf("Capacidad de la pila: %i \n", ptrStack->size);

    struct Node * current = ptrStack->top;

    for(int i = 0; i<ptrStack->size; i++){
      printf("Material %d de tipo %i con color %d y capacidad %f \n", i, current->material, current->color, current->capacidad);
      current = current->next;
    }
  }
}






