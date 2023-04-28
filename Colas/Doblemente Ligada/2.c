//COLA DOBLEMENTE LIGADA
//EQUIPO CODIGO MORTAL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir la estructura del nodo
struct node {
   int data;
   struct node *next;
   struct node *prev;
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
   temp->prev = NULL;
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
   temp->prev = q->rear;
   q->rear = temp;
}

// Función para eliminar un elemento de la cola
int dequeue(struct queue* q) {
   if (isEmpty(q)) {
      return -1;
   }
   struct node* temp = q->front;
   int data = temp->data;
   q->front = q->front->next;
   if (q->front == NULL) {
      q->rear = NULL;
   }
   else {
      q->front->prev = NULL;
   }
   free(temp);
   return data;
}

// Función para agregar múltiples elementos a la cola
void enqueueMultiple(struct queue* q, char* input) {
   char* token = strtok(input, ",");
   while (token != NULL) {
      int data = atoi(token);
      enqueue(q, data);
      token = strtok(NULL, ",");
   }
}
// Función principal
int main() {
   struct queue* q = createQueue();

   // Agregar elementos a la cola
   enqueue(q, 10);
   enqueue(q, 20);
   enqueue(q, 30);

   int choice, data;

   do {
      printf("\nMenu:\n");
      printf("1. Agregar elemento a la cola\n");
      printf("2. Eliminar elemento de la cola\n");
      printf("3. Mostrar el elemento frontal de la cola\n");
      printf("4. Salir\n");
      printf("Ingrese su eleccion: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            printf("Ingrese el elemento que desea agregar a la cola: ");
            scanf("%d", &data);
            enqueue(q, data);
            printf("Elemento agregado a la cola\n");
            break;

         case 2:
            data = dequeue(q);
            if (data == -1) {
               printf("La cola esta vacia\n");
            }
            else {
               printf("Elemento eliminado de la cola: %d\n", data);
            }
            break;

         case 3:
            if (isEmpty(q)) {
               printf("La cola esta vacia\n");
            }
            else {
               printf("El elemento frontal de la cola es: %d\n", q->front->data);
            }
            break;

         case 4:
            printf("Saliendo del programa...\n");
            break;

         default:
            printf("Opcion no valida, intente de nuevo\n");
      }
   } while (choice != 4);

   return 0;
}

