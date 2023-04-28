//COLA SIMPLEMENTE LIGADA
//EQUIPO CODIGO MORTAL

#include <stdio.h>
#include <stdlib.h>

// Definir la estructura del nodo
struct node {
   int data;
   struct node *next;
};

// Definir la estructura de la cola
struct queue {
   struct node *front;
   struct node *rear;
};

// Función para crear un nuevo nodo
struct node* newNode(int data) {
   struct node* temp = (struct node*)malloc(sizeof(struct node));
   temp->data = data;
   temp->next = NULL;
   return temp;
}

// Función para crear una cola vacía
struct queue* createQueue() {
   struct queue* q = (struct queue*)malloc(sizeof(struct queue));
   q->front = q->rear = NULL;
   return q;
}

// Función para verificar si la cola está vacía
int isEmpty(struct queue* q) {
   return q->front == NULL;
}

// Función para agregar un elemento a la cola
void enqueue(struct queue* q, int data) {
   struct node* temp = newNode(data);
   if (q->rear == NULL) {
      q->front = q->rear = temp;
      return;
   }
   q->rear->next = temp;
   q->rear = temp;
}

// Función para eliminar un elemento de la cola
int dequeue(struct queue* q) {
   if (isEmpty(q)) {
      return -1;
   }
   struct node* temp = q->front;
   q->front = q->front->next;
   if (q->front == NULL) {
      q->rear = NULL;
   }
   int data = temp->data;
   free(temp);
   return data;
}

// Función principal
int main() {
   struct queue* q = createQueue();

   // Agregar elementos a la cola
   enqueue(q, 10);
   enqueue(q, 20);
   enqueue(q, 30);

   // Eliminar elementos de la cola y mostrarlos por pantalla
   printf("%d ", dequeue(q));
   printf("%d ", dequeue(q));
   printf("%d ", dequeue(q));

   return 0;
}

