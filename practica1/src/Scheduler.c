#include "Scheduler.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct Node* Scheduler_new(void){

}

size_t Scheduler_size(const struct Node* p_last){
  struct Node* ptrIter = p_last; //Siempre inicializo mi puntero igualandolo al que me dan
  size_t cont = 0;

  if(p_last != NULL){
    do{
      cont ++;
      ptrIter = ptrIter->p_next;
    }while(ptrIter != p_last);
  }

  return cont;
}

void Scheduler_clear(struct Node** p_p_last){
  if(p_p_last != NULL){
    struct Node* ptrCurrent = *p_p_last;
    struct Node* aux;
    do{
      aux = ptrCurrent; //Lo uso por que luego me voy a cargar ptrIter
      ptrCurrent = ptrCurrent->p_next;
      
      //Debemos liberar primero la tarea del nodo
      Task_free(&aux->task); //Le paso la direccion al puntero ya que la funcion pide un puntero a un puntero
      //Debemos liberar luego el nodo
      free(aux);
    }while(ptrCurrent != p_p_last);
  }
}

struct Task* Scheduler_first(const struct Node* p_last){
  struct Task* firstTask = (struct Task*) malloc(sizeof(struct Task));

  if(p_last == NULL){
    firstTask = NULL;

    return firstTask;
  }

  firstTask = p_last->p_next->task;

  return firstTask;
}


bool Scheduler_enqueue(struct Node **p_p_last, const struct Task *p_task){
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  struct Task* newTask = (struct Task*) malloc(sizeof(struct Task));
  assert(newTask != NULL && "New Task: out of memory");

  newTask = p_task;

  if(*p_p_last == NULL){
    newNode->task = newTask;
    *p_p_last = newNode;

  }

  *p_p_last->task = *newTask; //Asignamos la tarea copiada al nuevo nodo

}


