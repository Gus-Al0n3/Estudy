#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la cola
struct Nodo {
    int valor;
    int prioridad;
    struct Nodo* siguiente;
};

// Definición de la cola
struct Cola {
    struct Nodo* cabeza;
    struct Nodo* cola;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int valor, int prioridad) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->valor = valor;
    nodo->prioridad = prioridad;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para crear una nueva cola
struct Cola* crearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->cabeza = cola->cola = NULL;
    return cola;
}

// Función para insertar un elemento en la cola con prioridad
void insertar(struct Cola* cola, int valor, int prioridad) {
    struct Nodo* nodo = crearNodo(valor, prioridad);

    // Si la cola está vacía o si la prioridad del nuevo nodo es mayor que la cabeza
    // de la cola, insertamos el nuevo nodo al principio de la cola
    if (cola->cabeza == NULL || prioridad < cola->cabeza->prioridad) {
        nodo->siguiente = cola->cabeza;
        cola->cabeza = nodo;
    } else {
        // Si la prioridad del nuevo nodo es menor que la cabeza de la cola, buscamos
        // el lugar adecuado para insertarlo
        struct Nodo* temp = cola->cabeza;
        while (temp->siguiente != NULL && temp->siguiente->prioridad <= prioridad) {
            temp = temp->siguiente;
        }
        nodo->siguiente = temp->siguiente;
        temp->siguiente = nodo;
    }

    // Si la cola estaba vacía, establecemos el nuevo nodo como la cola también
    if (cola->cola == NULL) {
        cola->cola = nodo;
    }
}

// Función para eliminar el elemento con mayor prioridad de la cola
int eliminar(struct Cola* cola) {
    if (cola->cabeza == NULL) {
        printf("La cola está vacía.\n");
        return -1;
    }
    int valorEliminado = cola->cabeza->valor;
    struct Nodo* temp = cola->cabeza;
    cola->cabeza = cola->cabeza->siguiente;
    if (cola->cabeza == NULL) {
        cola->cola = NULL;
    }
    free(temp);
    return valorEliminado;
}

// Función para mostrar el elemento con mayor prioridad de la cola
void mostrarPrimero(struct Cola* cola) {
    if (cola->cabeza == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    printf("El elemento con mayor prioridad es: %d\n", cola->cabeza->valor);
}

// Función para mostrar el menú y obtener la opción del usuario
int mostrarMenu() {
    int opcion;
    printf("\n------------------\n");
    printf("Menú:\n");
    printf("1. Insertar un elemento en la cola\n");
printf("2. Eliminar el elemento con mayor prioridad de la cola\n");
printf("3. Mostrar el elemento con mayor prioridad de la cola\n");
printf("4. Salir\n");
printf("Ingresa una opción: ");
scanf("%d", &opcion);
return opcion;
}

// Función principal del programa
int main() {
struct Cola* cola = crearCola();
int opcion, valor, prioridad;
do {
opcion = mostrarMenu();
switch (opcion) {
case 1:
printf("Ingresa el valor a insertar: ");
scanf("%d", &valor);
printf("Ingresa la prioridad del valor (entre 1 y 10): ");
scanf("%d", &prioridad);
if (prioridad < 1 || prioridad > 10) {
printf("La prioridad debe estar entre 1 y 10.\n");
} else {
insertar(cola, valor, prioridad);
printf("El valor %d con prioridad %d se ha insertado correctamente en la cola.\n", valor, prioridad);
}
break;
case 2:
valor = eliminar(cola);
if (valor != -1) {
printf("El valor %d se ha eliminado correctamente de la cola.\n", valor);
}
break;
case 3:
mostrarPrimero(cola);
break;
case 4:
printf("Saliendo del programa...\n");
break;
default:
printf("Opción no válida. Por favor ingresa una opción del 1 al 4.\n");
break;
}
} while (opcion != 4);

return 0;

}

