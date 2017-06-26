#include "listals.h"
#include <stdlib.h>

ListaSimple * nuevaLista(void) {
    return calloc(1, sizeof(ListaSimple));
}

void eliminarLista(ListaSimple * lista) {
    Tipo nodo;
    while (!estaVacia(lista)) {
        eliminarPrimero(lista, &nodo);
    }

    free(lista);
}

bool insertarPrincipio(ListaSimple * lista, Tipo elemento) {
    Nodo * nuevo_nodo = malloc(sizeof(Nodo));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;

    if (estaVacia(lista))
        lista->ultimo = nuevo_nodo;
    else
        lista->primero->siguiente = nuevo_nodo;

    lista->primero = nuevo_nodo;
    lista->numero_elementos++;

    return true;
}

bool eliminarPrimero(ListaSimple * lista, Tipo * elemento) {
    Nodo * auxiliar;

    if (estaVacia(lista))
        return false;

    auxiliar = lista->primero;
    lista->primero = auxiliar->siguiente;
    free(auxiliar);

    if (lista->numero_elementos == 1)
        lista->ultimo = NULL;

    lista->numero_elementos--;
    return true;
}

bool insertarFinal(ListaSimple * lista, Tipo elemento) {

}

bool eliminarUltimo(ListaSimple * lista, Tipo * elemento) {

}

bool insertar(ListaSimple * lista, Tipo elemento, int posicion) {

}

bool eliminar(ListaSimple * lista, Tipo * elemento, int posicion) {

}

bool existe(ListaSimple * lista, Tipo elemeno) {

}

inline int32_t comparar(Tipo elemento1, Tipo elemento2) {

}

inline bool estaVacia(ListaSimple * lista) {

}
