#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} Nodo;

// Definición de la estructura Lista
typedef struct {
    Nodo* inicio;
    Nodo* fin;
    int contador;
} Lista;

// Función para inicializar una lista vacía
void inicializarLista(Lista* lista) {
    lista->inicio = NULL;
    lista->fin = NULL;
    lista->contador = 0;
}

// Función para insertar un elemento en orden en la lista
void insertarEnOrden(Lista* lista, int elemento) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->dato = elemento;
    nuevoNodo->siguiente = NULL;
    
    // Si la lista está vacía, el nuevo nodo será el inicio y el fin de la lista
    if (lista->contador == 0) {
        lista->inicio = nuevoNodo;
        lista->fin = nuevoNodo;
    }
    else {
        Nodo* actual = lista->inicio;
        Nodo* anterior = NULL;
        while (actual != NULL && actual->dato < elemento) {
            anterior = actual;
            actual = actual->siguiente;
        }
        
        // Si el nuevo nodo va al inicio de la lista
        if (anterior == NULL) {
            nuevoNodo->siguiente = lista->inicio;
            lista->inicio = nuevoNodo;
        }
        // Si el nuevo nodo va al final de la lista
        else if (actual == NULL) {
            anterior->siguiente = nuevoNodo;
            lista->fin = nuevoNodo;
        }
        // Si el nuevo nodo va en medio de la lista
        else {
            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = actual;
        }
    }
    
    lista->contador++;
}

// Función para extraer un elemento en específico de la lista
void extraerElemento(Lista* lista, int elemento) {
    Nodo* actual = lista->inicio;
    Nodo* anterior = NULL;
    while (actual != NULL && actual->dato != elemento) {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    // Si se encontró el elemento a extraer
    if (actual != NULL) {
        // Si el elemento a extraer está en el inicio de la lista
        if (anterior == NULL) {
            lista->inicio = actual->siguiente;
            free(actual);
        }
        // Si el elemento a extraer está en el fin de la lista
        else if (actual->siguiente == NULL) {
            anterior->siguiente = NULL;
            lista->fin = anterior;
            free(actual);
        }
        // Si el elemento a extraer está en medio de la lista
        else {
            anterior->siguiente = actual->siguiente;
            free(actual);
        }
        
        lista->contador--;
    }
}

// Función para buscar un elemento en la lista
Nodo* buscarElemento(Lista* lista, int elemento) {
Nodo* actual = lista->inicio;
while (actual != NULL && actual->dato != elemento) {
actual = actual->siguiente;
}
return actual;
}

// Función para comparar dos listas
int compararListas(Lista* lista1, Lista* lista2) {
if (lista1->contador != lista2->contador) {
return 0;
}
Nodo* actual1 = lista1->inicio;
Nodo* actual2 = lista2->inicio;

while (actual1 != NULL && actual2 != NULL) {
    if (actual1->dato != actual2->dato) {
        return 0;
    }
    
    actual1 = actual1->siguiente;
    actual2 = actual2->siguiente;
}

return 1;
}

// Función para copiar una lista en otra
void copiarLista(Lista* listaOriginal, Lista* listaCopia) {
inicializarLista(listaCopia);
Nodo* actual = listaOriginal->inicio;
while (actual != NULL) {
    insertarEnOrden(listaCopia, actual->dato);
    actual = actual->siguiente;
}
}

// Función para imprimir una lista
void imprimirLista(Lista* lista) {
Nodo* actual = lista->inicio;
while (actual != NULL) {
printf("%d -> ", actual->dato);
actual = actual->siguiente;
}
printf("NULL\n");
}

// Función principal
int main() {
// Inicializamos la lista
Lista lista;
inicializarLista(&lista);
// Insertamos elementos en orden
insertarEnOrden(&lista, 4);
insertarEnOrden(&lista, 2);
insertarEnOrden(&lista, 1);
insertarEnOrden(&lista, 5);
insertarEnOrden(&lista, 3);

// Imprimimos la lista
printf("Lista original: ");
imprimirLista(&lista);

// Buscamos un elemento en la lista
Nodo* elementoBuscado = buscarElemento(&lista, 4);
if (elementoBuscado != NULL) {
    printf("El elemento %d fue encontrado en la lista\n", elementoBuscado->dato);
}
else {
    printf("El elemento no fue encontrado en la lista\n");
}

// Extraemos un elemento de la lista
extraerElemento(&lista, 1);

// Imprimimos la lista modificada
printf("Lista modificada: ");
imprimirLista(&lista);

// Creamos una lista copia
Lista listaCopia;
inicializarLista(&listaCopia);
copiarLista(&lista, &listaCopia);

// Comparamos las listas
if (compararListas(&lista, &listaCopia)) {
    printf("Las listas son iguales\n");
}
else {
    printf("Las listas son diferentes\n");
}

return 0;
}

