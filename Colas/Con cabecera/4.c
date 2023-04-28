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
    int opcion, valor;
    do {
        printf("\n------------------\n");
        printf("MENU:\n");
        printf("1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Mostrar elementos\n");
        printf("4. Salir\n");
        printf("------------------\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                printf("Ingrese el valor a encolar: ");
                scanf("%d", &valor);
                encolar(cola, valor);
                printf("Elemento encolado.\n");
                break;
            case 2:
                desencolar(cola);
                printf("Elemento desencolado.\n");
                break;
            case 3:
                mostrar(cola);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 4);
    return 0;
}

