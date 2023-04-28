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

// Función para mostrar los elementos de la cola
void displayQueue(struct queue* q) {
   if (isEmpty(q)) {
      printf("La cola está vacía\n");
      return;
   }
   printf("Elementos en la cola: ");
   struct node* current = q->front;
   while (current != NULL) {
      printf("%d ", current->data);
      current = current->next;
   }
   printf("\n");
}

// Función principal
int main() {
   struct queue* q = createQueue();

   int option, value;

   do {
      printf("\nSeleccione una opción:\n");
      printf("1. Agregar un elemento a la cola\n");
      printf("2. Eliminar un elemento de la cola\n");
      printf("3. Mostrar los elementos de la cola\n");
      printf("4. Salir\n");

      scanf("%d", &option);

      switch (option) {
         case 1:
            printf("Ingrese el valor a agregar a la cola: ");
            scanf("%d", &value);
            enqueue(q, value);
            break;

         case 2:
            value = dequeue(q);
            if (value == -1) {
               printf("La cola está vacía\n");
            } else {
               printf("Elemento eliminado de la cola: %d\n", value);
            }
            break;

         case 3:
            displayQueue(q);
            break;

         case 4:
            printf("Saliendo...\n");
            break;

         default:
            printf("Opción inválida\n");
      }
   } while (option != 4);

   return 0;
}

