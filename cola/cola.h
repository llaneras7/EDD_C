#include <stdbool.h> // Para usar el tipo bool

struct Person {
    char name[30];
    int age;
};

typedef struct Node* Queue;

struct Node {
    struct Person* person;
    struct Node* next;
};

// Prototipos de funciones
struct Person* createPerson(char* name, int age);
void createQueue(struct Node** ptrqueue);
bool isEmpty(struct Node* queue);
int size(struct Node* queue);
void enqueue(struct Node** ptrqueue, struct Person* person);
void dequeue(struct Node** ptrqueue);
struct Person* first(struct Node* queue);
void clear(struct Node** ptrqueue);
void display(struct Node* queue);
