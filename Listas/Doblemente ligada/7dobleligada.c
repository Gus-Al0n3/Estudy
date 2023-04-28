#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de la lista doblemente enlazada
struct Node {
    int data;           // Datos del nodo
    struct Node* prev;  // Puntero al nodo anterior
    struct Node* next;  // Puntero al nodo siguiente
};

// Función para crear un nuevo nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Función para insertar un nodo en orden ascendente
void insertNode(struct Node** head, struct Node* newNode) {
    struct Node* current;

    // Caso base: Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    if (*head == NULL) {
        *head = newNode;
    }
    // Caso general: Insertar el nodo en orden ascendente
    else if ((*head)->data >= newNode->data) {
        newNode->next = *head;
        newNode->next->prev = newNode;
        *head = newNode;
    }
    else {
        current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;

        if (current->next != NULL) {
            newNode->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Función para eliminar un nodo específico
void deleteNode(struct Node** head, struct Node* nodeToDelete) {
    // Caso base: Si la lista está vacía, no se hace nada
    if (*head == NULL || nodeToDelete == NULL) {
        return;
    }

    // Si el nodo a eliminar es la cabeza de la lista
    if (*head == nodeToDelete) {
        *head = nodeToDelete->next;
    }

    // Si el nodo a eliminar no es la última posición
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    // Si el nodo a eliminar no es la primera posición
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }

    free(nodeToDelete);
}

// Función para buscar un nodo con un valor específico
struct Node* searchNode(struct Node* head, int data) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Función para comparar dos listas doblemente enlazadas
int compareLists(struct Node* head1, struct Node* head2) {
    struct Node* current1 = head1;
    struct Node* current2 = head2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
}
// Si los dos nodos son nulos al mismo tiempo, las dos listas son iguales
return (current1 == NULL && current2 == NULL);
}

// Función para copiar una lista doblemente enlazada
struct Node* copyList(struct Node* head) {
struct Node* current = head;
struct Node* newList = NULL;
while (current != NULL) {
    struct Node* newNode = createNode(current->data);
    insertNode(&newList, newNode);
    current = current->next;
}

return newList;
}

// Función para imprimir la lista doblemente enlazada
void printList(struct Node* head) {
struct Node* current = head;
printf("Lista: ");
while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
}
printf("\n");
}

int main() {
struct Node* list = NULL;
struct Node* copy = NULL;
// Insertar nodos en orden ascendente
insertNode(&list, createNode(5));
insertNode(&list, createNode(3));
insertNode(&list, createNode(9));
insertNode(&list, createNode(1));
insertNode(&list, createNode(7));

// Imprimir la lista original
printf("Lista original:\n");
printList(list);

// Buscar un nodo con valor 9
printf("Buscando el valor 9:\n");
struct Node* nodeToFind = searchNode(list, 9);
if (nodeToFind != NULL) {
    printf("Se encontró el valor %d.\n", nodeToFind->data);
} else {
    printf("El valor 9 no se encuentra en la lista.\n");
}

// Eliminar un nodo con valor 1
printf("Eliminando el valor 1:\n");
struct Node* nodeToDelete = searchNode(list, 1);
deleteNode(&list, nodeToDelete);
printList(list);

// Comparar la lista original con una copia
printf("Comparando la lista original con una copia:\n");
copy = copyList(list);
if (compareLists(list, copy)) {
    printf("Las dos listas son iguales.\n");
} else {
    printf("Las dos listas son diferentes.\n");
}

// Liberar memoria
while (list != NULL) {
    deleteNode(&list, list);
}
while (copy != NULL) {
    deleteNode(&copy, copy);
}

return 0;
}

