//PILA SIMPLEMENTE LIGADA
//EQUIPO CODIGO MORTAL


#include <stdio.h>
#include <stdlib.h>

// Definimos la estructura del nodo
typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

// Definimos la estructura de la pila
typedef struct Pila {
    Nodo* tope;
} Pila;

// Función para crear una nueva pila
Pila* crearPila() {
    Pila* nuevaPila = (Pila*) malloc(sizeof(Pila));
    nuevaPila->tope = NULL;
    printf("Se ha creado una nueva pila.\n");
    return nuevaPila;
}

// Función para verificar si la pila está vacía
int pilaVacia(Pila* pila) {
    return pila->tope == NULL;
}

// Función para agregar un elemento a la pila
void push(Pila* pila, int valor) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = pila->tope;
    pila->tope = nuevoNodo;
    printf("Se ha agregado el valor %d a la pila.\n", valor);
}

// Función para eliminar el elemento superior de la pila
int pop(Pila* pila) {
    if (pilaVacia(pila)) {
        printf("Error: la pila está vacía.\n");
        return -1;
    }
    Nodo* nodoAEliminar = pila->tope;
    int valorAEliminar = nodoAEliminar->valor;
    pila->tope = nodoAEliminar->siguiente;
    free(nodoAEliminar);
    printf("Se ha eliminado el valor %d de la pila.\n", valorAEliminar);
    return valorAEliminar;
}

// Función para imprimir el contenido de la pila
void imprimirPila(Pila* pila) {
    printf("Contenido de la pila:\n");
    Nodo* actual = pila->tope;
    while (actual != NULL) {
        printf("%d ", actual->valor);
        actual = actual->siguiente;
    }
    printf("\n");
}

int main() {
    Pila* pila = crearPila();
    push(pila, 10);
    push(pila, 20);
    push(pila, 30);
    imprimirPila(pila);
    pop(pila);
    pop(pila);
    imprimirPila(pila);
    pop(pila);
    pop(pila);
    return 0;
}

