#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    int prioridad;
    struct nodo* siguiente;
} Nodo;

Nodo* cabeza = NULL;

// Función para insertar un nuevo nodo en la lista
void insertar(int dato, int prioridad) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->prioridad = prioridad;
    nuevoNodo->siguiente = NULL;

    if (cabeza == NULL || prioridad > cabeza->prioridad) {
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != NULL && temp->siguiente->prioridad >= prioridad) {
            temp = temp->siguiente;
        }
        nuevoNodo->siguiente = temp->siguiente;
        temp->siguiente = nuevoNodo;
    }
}

// Función para eliminar un nodo específico de la lista
void eliminar(int dato) {
    if (cabeza == NULL) {
        return;
    }

    Nodo* temp = cabeza;
    if (cabeza->dato == dato) {
        cabeza = cabeza->siguiente;
        free(temp);
        return;
    }

    while (temp->siguiente != NULL && temp->siguiente->dato != dato) {
        temp = temp->siguiente;
    }
    if (temp->siguiente == NULL) {
        return;
    }
    Nodo* eliminarNodo = temp->siguiente;
    temp->siguiente = temp->siguiente->siguiente;
    free(eliminarNodo);
}

// Función para buscar un nodo específico en la lista
Nodo* buscar(int dato) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        if (temp->dato == dato) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}

// Función para comparar dos nodos
int comparar(Nodo* nodo1, Nodo* nodo2) {
    return nodo1->prioridad - nodo2->prioridad;
}

// Función para copiar un nodo
Nodo* copiar(Nodo* nodo) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = nodo->dato;
    nuevoNodo->prioridad = nodo->prioridad;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para imprimir la lista
void imprimir() {
    Nodo* temp = cabeza;
    printf("Lista con prioridad: ");
    while (temp != NULL) {
        printf("(%d, %d) ", temp->dato, temp->prioridad);
        temp = temp->siguiente;
    }
    printf("\n");
}

int main() {
    // Insertar nodos en la lista
    insertar(3, 1);
    insertar(5, 2);
    insertar(2, 3);
    insertar(8, 2);
    insertar(1, 4);

    // Imprimir la lista
    imprimir();

    // Eliminar un nodo específico de la lista
    eliminar(5);

    // Imprimir la lista nuevamente
    imprimir();

   
    // Buscar un nodo específico en la lista
    Nodo* nodoBuscado = buscar(2);
    if (nodoBuscado != NULL) {
        printf("Nodo encontrado: (%d, %d)\n", nodoBuscado->dato, nodoBuscado->prioridad);
    } else {
        printf("Nodo no encontrado\n");
    }

    // Comparar dos nodos
    Nodo* nodo1 = cabeza;
    Nodo* nodo2 = cabeza->siguiente;
    int resultadoComparacion = comparar(nodo1, nodo2);
    if (resultadoComparacion < 0) {
        printf("(%d, %d) es mayor que (%d, %d)\n", nodo2->dato, nodo2->prioridad, nodo1->dato, nodo1->prioridad);
    } else if (resultadoComparacion > 0) {
        printf("(%d, %d) es mayor que (%d, %d)\n", nodo1->dato, nodo1->prioridad, nodo2->dato, nodo2->prioridad);
    } else {
        printf("(%d, %d) es igual que (%d, %d)\n", nodo1->dato, nodo1->prioridad, nodo2->dato, nodo2->prioridad);
    }

    // Copiar un nodo
    Nodo* nodoOriginal = cabeza;
    Nodo* nodoCopia = copiar(nodoOriginal);
    printf("Nodo original: (%d, %d)\n", nodoOriginal->dato, nodoOriginal->prioridad);
    printf("Nodo copia: (%d, %d)\n", nodoCopia->dato, nodoCopia->prioridad);

    return 0;
}

