//COLA CIRCULAR
//EQUIPO CODIGO MORTAL

#include <stdio.h>
#define MAX 5 // Tamaño máximo de la cola

int frente = -1, final = -1;
int cola[MAX];

// Función para verificar si la cola está vacía
int estaVacia() {
    if (frente == -1 && final == -1)
        return 1;
    else
        return 0;
}

// Función para verificar si la cola está llena
int estaLlena() {
    if ((final + 1) % MAX == frente)
        return 1;
    else
        return 0;
}

// Función para encolar un elemento a la cola
void encolar(int valor) {
    if (estaLlena()) {
        printf("La cola esta llena.\n");
    } else if (estaVacia()) {
        frente = final = 0;
        cola[final] = valor;
    } else {
        final = (final + 1) % MAX;
        cola[final] = valor;
    }
}

// Función para desencolar un elemento de la cola
void desencolar() {
    if (estaVacia()) {
        printf("La cola esta vacia.\n");
    } else if (frente == final) {
        printf("Elemento desencolado: %d\n", cola[frente]);
        frente = final = -1;
    } else {
        printf("Elemento desencolado: %d\n", cola[frente]);
        frente = (frente + 1) % MAX;
    }
}

// Función para mostrar los elementos de la cola
void mostrar() {
    if (estaVacia()) {
        printf("La cola esta vacia.\n");
    } else {
        int i;
        printf("Elementos en la cola: ");
        for (i = frente; i != final; i = (i + 1) % MAX) {
            printf("%d ", cola[i]);
        }
        printf("%d\n", cola[i]);
    }
}

int main() {
    encolar(1);
    mostrar();
    encolar(2);
    mostrar();
    encolar(3);
    mostrar();
    desencolar();
    mostrar();
    encolar(4);
    mostrar();
    encolar(5);
    mostrar();
    encolar(6); // Esto debería producir un error de cola llena
    mostrar();
    desencolar();
    mostrar();
    desencolar();
    mostrar();
    desencolar();
    mostrar();
    desencolar(); // Esto debería producir un error de cola vacía
    mostrar();
    return 0;
}

