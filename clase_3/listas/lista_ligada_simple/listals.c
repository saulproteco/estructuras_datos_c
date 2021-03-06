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
    Nodo * nuevo_nodo = malloc(sizeof(Nodo));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;
    nuevo_nodo->siguiente = NULL;

    if (estaVacia(lista))
        lista->primero = nuevo_nodo;

    lista->ultimo->siguiente = nuevo_nodo;
    lista->ultimo = nuevo_nodo;

    lista->numero_elementos++;
    return true;
}

bool eliminarUltimo(ListaSimple * lista, Tipo * elemento) {
    return eliminar(lista, elemento, lista->numero_elementos - 1);
}

bool insertar(ListaSimple * lista, Tipo elemento, int posicion) {
    int indice = 1;
    Nodo * previo, * posterior;
    Nodo * nuevo_nodo;

    if (posicion < 0 || posicion >= lista->numero_elementos)
        return false;
    else if (posicion == 0)
        insertarPrincipio(lista, elemento);

    previo = lista->primero;

    while (indice != posicion) {
        previo = previo->siguiente;
        indice++;
    }

    if (!previo)
        return false;

    nuevo_nodo = malloc(sizeof(Nodo *));

    if (!nuevo_nodo)
        return false;

    posterior = previo->siguiente;
    previo->siguiente = nuevo_nodo;
    nuevo_nodo->siguiente = posterior;

    lista->numero_elementos++;
    return true;
}

bool eliminar(ListaSimple * lista, Tipo * elemento, int posicion) {
    int indice = 1;
    Nodo * previo, * nodo_eliminar;

    if (posicion < 0 || posicion >= lista->numero_elementos)
        return false;

    previo = lista->primero;
    while (indice != posicion) {
        indice++;
        previo = previo->siguiente;
    }

    nodo_eliminar = previo->siguiente;
    previo->siguiente = nodo_eliminar->siguiente;

    *elemento = nodo_eliminar->dato;
    free(nodo_eliminar);

    return true;
}

int32_t indice(ListaSimple * lista, Tipo elemento) {
    int32_t i = 0;
    Nodo * auxiliar = lista->primero;

    while (auxiliar && comparar(auxiliar->dato, elemento) != 0)
        auxiliar = auxiliar->siguiente, i++;

    if (!auxiliar)
        i = -1;

    return i;
}

inline int32_t comparar(Tipo elemento1, Tipo elemento2) {
    return elemento1 - elemento2;
}

inline bool estaVacia(ListaSimple * lista) {
    return lista->numero_elementos == 0;
}
