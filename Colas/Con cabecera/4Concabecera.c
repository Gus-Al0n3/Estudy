//COLA CON CABECERA
//EQUIPO CODIGO MORTAL

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct Cola {
    Nodo* inicio;
    Nodo* fin;
    int contador;
} Cola;

// Función para crear una nueva cola
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->inicio = cola->fin = NULL;
    cola->contador = 0;
    return cola;
}

// Función para verificar si la cola está vacía
int estaVacia(Cola* cola) {
    return cola->contador == 0;
}

// Función para encolar un elemento a la cola
void encolar(Cola* cola, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    if (estaVacia(cola)) {
        cola->inicio = nuevoNodo;
    } else {
        cola->fin->siguiente = nuevoNodo;
    }
    cola->fin = nuevoNodo;
    cola->contador++;
}

// Función para desencolar un elemento de la cola
void desencolar(Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola esta vacia.\n");
    } else {
        Nodo* nodoAEliminar = cola->inicio;
        cola->inicio = cola->inicio->siguiente;
        free(nodoAEliminar);
        cola->contador--;
    }
}

// Función para mostrar los elementos de la cola
void mostrar(Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola esta vacia.\n");
    } else {
        Nodo* nodoActual = cola->inicio;
        printf("Elementos en la cola: ");
        while (nodoActual != NULL) {
            printf("%d ", nodoActual->valor);
            nodoActual = nodoActual->siguiente;
        }
        printf("\n");
    }
}

int main() {
    Cola* cola = crearCola();
    printf("La cola esta vacia: %d\n", estaVacia(cola));
    encolar(cola, 1);
    encolar(cola, 2);
    encolar(cola, 3);
    mostrar(cola);
    printf("La cola esta vacia: %d\n", estaVacia(cola));
    printf("La cola tiene %d elementos.\n", cola->contador);
    desencolar(cola);
    mostrar(cola);
    printf("La cola tiene %d elementos.\n", cola->contador);
    return 0;
}

