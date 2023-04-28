//COLA CIRCULA
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

// Función para mostrar el menú y obtener la selección del usuario
int menu() {
    int opcion;
    printf("\n");
    printf("Seleccione una opción:\n");
    printf("1. Encolar un elemento\n");
    printf("2. Desencolar un elemento\n");
    printf("3. Mostrar la cola\n");
    printf("4. Salir\n");
    scanf("%d", &opcion);
    return opcion;
}

int main() {
    int opcion;

    do {
        opcion = menu();

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a encolar: ");
                int valor;
                scanf("%d", &valor);
                encolar(valor);
                break;
            case 2:
                desencolar();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

