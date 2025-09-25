#include "Task.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct Task* Task_new(unsigned int id, const char name[], unsigned int quantum){
    assert(strlen(name) <= MAX_NAME_LEN && "Task new: name to long");
    
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));

    assert(newTask != NULL && "New Task: out of memory");

    newTask->id = id;
    strncpy(newTask->name, name, sizeof(newTask->name) - 1);
    newTask->quantum = quantum;

    return newTask;
}

void Task_free(struct Task** p_p_task) {
    if(*p_p_task != NULL){
        free(*p_p_task);
        *p_p_task = NULL;
    }   
}

struct Task* Task_copyOf(const struct Task* p_task){
    struct Task* copy = (struct Task*)malloc(sizeof(struct Task));
    assert(copy != NULL && "Task copy: out of memory");
    
    copy->id = p_task->id;
    strncpy(copy->name, p_task->name, sizeof(copy->name) - 1);
    copy->quantum = p_task->quantum;

    return copy;
}

void Task_print(const struct Task* p_task) {
    printf("Tarea con ID: %d, con nombre: %s y con un quantum: %d", p_task->id, p_task->name, p_task->quantum);
}





