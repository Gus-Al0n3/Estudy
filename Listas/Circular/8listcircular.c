//LISTA CIRCULAR
//EQUIPO CODIGO MORTAL

#include <stdio.h>
#include <stdlib.h>

// Define una estructura de Nodo que contiene un valor y un puntero al siguiente nodo en la lista.
struct Node {
   int data;
   struct Node *next;
};

// Función auxiliar para crear un nuevo nodo con un valor dado.
struct Node* createNode(int data) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Función para insertar un nuevo nodo en orden en la lista.
void insertInOrder(struct Node** head, int data) {
   struct Node* newNode = createNode(data);
   struct Node* current = *head;
   // Si la lista está vacía, el nuevo nodo es la cabeza de la lista y apunta a sí mismo.
   if (*head == NULL) {
      *head = newNode;
      newNode->next = *head;
   }
   // Si el valor del nuevo nodo es menor que el valor de la cabeza de la lista, se inserta el nuevo nodo al principio.
   else if (newNode->data < current->data) {
      while (current->next != *head) {
         current = current->next;
      }
      current->next = newNode;
      newNode->next = *head;
      *head = newNode;
   }
   // De lo contrario, se inserta el nuevo nodo en orden ascendente en la lista.
   else {
      while (current->next != *head && current->next->data < newNode->data) {
         current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
   }
}

// Función para eliminar un nodo con un valor dado de la lista.
void deleteNode(struct Node** head, int data) {
   // Si la lista está vacía, se imprime un mensaje de error.
   if (*head == NULL) {
      printf("List is empty.\n");
   }
   else {
      struct Node* current = *head;
      struct Node* previous = NULL;
      // Busca el nodo con el valor dado y mantiene un puntero al nodo anterior.
      while (current->data != data) {
         if (current->next == *head) {
            printf("Data not found in the list.\n");
            return;
         }
         previous = current;
         current = current->next;
      }
      // Si el nodo a eliminar es el único nodo en la lista, se establece la cabeza de la lista en NULL y se libera la memoria.
      if (current->next == *head && previous == NULL) {
         *head = NULL;
         free(current);
         return;
      }
      // Si el nodo a eliminar es el primer nodo de la lista, se ajusta la cabeza de la lista.
      if (current == *head) {
         previous = *head;
         while (previous->next != *head) {
            previous = previous->next;
         }
         *head = (*head)->next;
         previous->next = *head;
         free(current);
      }
      // Si el nodo a eliminar es el último nodo de la lista, se ajusta el puntero del nodo anterior.
      else if (current->next == *head) {
         previous->next = *head;
         free(current);
      }
        }
  // De lo contrario, se ajustan los punteros de los nodos adyacentes para eliminar el nodo de la lista.
  else {
     previous->next = current->next;
     free(current);
  }
  
}

// Función para buscar un nodo con un valor dado en la lista.
struct Node* searchNode(struct Node* head, int data) {
// Si la lista está vacía, se devuelve NULL.
if (head == NULL) {
return NULL;
}
else {
struct Node* current = head;
// Busca el nodo con el valor dado en la lista.
while (current->data != data) {
if (current->next == head) {
return NULL;
}
current = current->next;
}
return current;
}
}

// Función para comparar dos listas circulares.
int compareLists(struct Node* head1, struct Node* head2) {
struct Node* current1 = head1;
struct Node* current2 = head2;
// Compara cada nodo de las dos listas circulares.
while (current1 != NULL && current2 != NULL) {
if (current1->data != current2->data) {
return 0;
}
current1 = current1->next;
current2 = current2->next;
}
// Si una de las dos listas tiene más nodos que la otra, no son iguales.
if (current1 != NULL || current2 != NULL) {
return 0;
}
// Si todas las comparaciones fueron iguales, las listas son iguales.
else {
return 1;
}
}

// Función para copiar una lista circular en otra.
struct Node* copyList(struct Node* head) {
// Si la lista está vacía, se devuelve NULL.
if (head == NULL) {
return NULL;
}
else {
struct Node* current = head;
struct Node* newHead = createNode(head->data);
struct Node* newCurrent = newHead;
current = current->next;
// Copia cada nodo de la lista circular original en la nueva lista.
while (current != head) {
struct Node* newNode = createNode(current->data);
newCurrent->next = newNode;
newCurrent = newCurrent->next;
current = current->next;
}
newCurrent->next = newHead;
return newHead;
}
}

// Función para imprimir los valores de la lista circular.
void printList(struct Node* head) {
// Si la lista está vacía, se imprime un mensaje de error.
if (head == NULL) {
printf("List is empty.\n");
}
else {
struct Node* current = head;
// Imprime cada valor de la lista circular.
do {
printf("%d ", current->data);
current = current->next;
} while (current != head);
printf("\n");
}
}

// Función principal para probar las operaciones de la lista circular.
int main() {
struct Node* head = NULL;
struct Node* newList = NULL;
// Inserta algunos nodos en la lista circular.
insertInOrder(&head, 5);
insertInOrder(&head, 3);
insertInOrder(&head, 9);
insertInOrder(&head, 2);
insertInOrder(&head, 7);
printf("Lista original: ");
printList(head);
// Elimina un nodo de la lista circular.
deleteNode(&head, 5);
printf("Lista después de eliminar el nodo con valor 5: ");
printList(head);
// Busca un nodo en la lista circular.
struct Node* searchedNode = searchNode(head, 3);
if (searchedNode != NULL) {
printf("El nodo con valor 3 se encontró en la lista.\n");
}
else {
printf("El nodo con valor 3 no se encontró en la lista.\n");
}
// Compara la lista original con una copia de la lista.
newList = copyList(head);
if (compareLists(head, newList)) {
printf("La lista original y la copia son iguales.\n");
}
else {
printf("La lista original y la copia son diferentes.\n");
}
// Libera la memoria ocupada por las listas.
deleteList(&head);
deleteList(&newList);
return 0;
}

