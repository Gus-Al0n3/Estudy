//LISTA SIMPLEMENTE LIGADA
//EQUIPO CODIGO MORTAL


#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Node {
    int data;           // El dato que contiene el nodo
    struct Node* next;  // El puntero al siguiente nodo
} Node;

// Función para insertar un nodo en orden en la lista
void insert(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));  // Se crea un nuevo nodo
    new_node->data = data;                          // Se asigna el dato
    new_node->next = NULL;                          // Se asigna NULL al siguiente

    // Si la lista está vacía o el dato del primer nodo es mayor que el dato a insertar
    if (*head == NULL || (*head)->data >= new_node->data) {
        new_node->next = *head;   // El siguiente del nuevo nodo es la cabeza de la lista
        *head = new_node;         // El nuevo nodo es la nueva cabeza
    } 
    else {
        Node* current = *head;
        // Se recorre la lista hasta encontrar la posición correcta para insertar el nuevo nodo
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;   // El siguiente del nuevo nodo es el siguiente del nodo actual
        current->next = new_node;         // El siguiente del nodo actual es el nuevo nodo
    }
}

// Función para extraer un elemento en específico de la lista
void extract(Node** head, int data) {
    Node* current = *head;
    Node* previous = NULL;

    // Se busca el nodo que contiene el dato a extraer
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    // Si se encontró el nodo, se elimina de la lista
    if (current != NULL) {
        if (previous == NULL) {
            *head = current->next;
        } 
        else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Función para buscar un elemento en la lista
int search(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;   // Se encontró el dato
        }
        current = current->next;
    }
    return 0;           // No se encontró el dato
}

// Función para comparar dos listas
int compare(Node* head1, Node* head2) {
    Node* current1 = head1;
    Node* current2 = head2;

    // Se recorren las dos listas simultáneamente y se comparan los datos de cada nodo
    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) {
            return 0;   // Las listas no son iguales
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    // Si las dos listas tienen la misma longitud, son iguales
    return (current1 == NULL && current2 == NULL);
}

// Función para copiar una lista
void copy(Node* head, Node** new_head) {
    Node* current = head;
    Node* last = NULL;

    // Se recorre la lista original y se va creando una copia de cada nodo
    while (current != NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));  // Se crea un nuevo nodo
        new_node->data = current->data;                // Se copia el dato
        new_node->next = NULL;                         // El siguiente se asigna a NULL

        if (*new_head == NULL) {
            *new_head = new_node;
        } 
        else {
            last->next = new_node;
        }
        last = new_node;
        current = current->next;
    }
}

// Función principal
int main() {
    Node* head = NULL;      // Cabeza de la lista original
    Node* copy_head = NULL; // Cabeza de la lista copiada

    // Se insertan algunos nodos en la lista original
    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 9);
    insert(&head, 1);
    insert(&head, 4);

    // Se busca el dato 9 en la lista original
    if (search(head, 9)) {
        printf("El dato 9 se encuentra en la lista.\n");
    } 
    else {
        printf("El dato 9 no se encuentra en la lista.\n");
    }

    // Se busca el dato 6 en la lista original
    if (search(head, 6)) {
        printf("El dato 6 se encuentra en la lista.\n");
    } 
    else {
        printf("El dato 6 no se encuentra en la lista.\n");
    }

    // Se copia la lista original
    copy(head, &copy_head);

    // Se comparan las dos listas
    if (compare(head, copy_head)) {
        printf("Las dos listas son iguales.\n");
    } 
    else {
        printf("Las dos listas no son iguales.\n");
    }

    return 0;
}

