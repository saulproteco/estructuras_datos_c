#include "listadc.h"
#include <stdlib.h>

ListaCircular * nuevaLista(void) {
    return calloc(1, sizeof(ListaCircular));
}

void eliminarLista(ListaCircular * lista) {
    Tipo nodo;
    while (!estaVacia(lista)) {
        eliminarPrimero(lista, &nodo);
    }

    free(lista);
}

bool insertarPrincipio(ListaCircular * lista, Tipo elemento) {
    Nodo * nuevo_nodo = malloc(sizeof(Nodo));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;

    if (estaVacia(lista)) {
        lista->primero = nuevo_nodo;
        lista->ultimo = nuevo_nodo;

        lista->primero->siguiente = nuevo_nodo;
        lista->ultimo->anterior = nuevo_nodo;
    } else {
        nuevo_nodo->siguiente = lista->primero;
        lista->primero->anterior = nuevo_nodo;

        lista->primero = nuevo_nodo;

        lista->primero->anterior = lista->ultimo;
        lista->ultimo->siguiente = lista->primero;
    }

    lista->numero_elementos++;
    return true;
}

bool eliminarPrimero(ListaCircular * lista, Tipo * elemento) {
    Nodo * auxiliar;

    if (estaVacia(lista))
        return false;

    auxiliar = lista->primero;
    *elemento = auxiliar->dato;

    if (lista->numero_elementos == 1) {
        lista->primero = NULL;
        lista->ultimo = NULL;
    } else {
        lista->primero = auxiliar->siguiente;

        lista->primero->anterior = lista->ultimo;
        lista->ultimo->siguiente = lista->primero;
    }

    free(auxiliar);

    lista->numero_elementos--;
    return true;
}

bool insertarFinal(ListaCircular * lista, Tipo elemento) {
    Nodo * nuevo_nodo = malloc(sizeof(Nodo));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;

    if (estaVacia(lista)) {
        lista->primero = nuevo_nodo;
        lista->ultimo = nuevo_nodo;

        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;
    } else {
        lista->ultimo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = lista->ultimo;

        lista->ultimo = nuevo_nodo;

        lista->ultimo->siguiente = lista->primero;
        lista->primero->anterior = nuevo_nodo;
    }

    lista->numero_elementos++;
    return true;
}

bool eliminarUltimo(ListaCircular * lista, Tipo * sacado) {
    if (estaVacia(lista))
        return false;

    Nodo * nodo_aux = lista->ultimo;
    *sacado = nodo_aux->dato;

    if (lista->numero_elementos == 1) {
        lista->primero = NULL;
        lista->ultimo = NULL;
    } else {
        lista->ultimo = lista->ultimo->anterior;

        lista->primero->anterior = lista->ultimo;
        lista->ultimo->siguiente = lista->primero;
    }

    free(nodo_aux);

    lista->numero_elementos--;
    return true;
}

bool insertar(ListaCircular * lista, Tipo elemento, int posicion) {
    int indice = 1;
    Nodo * previo, * posterior;
    Nodo * nuevo_nodo;

    if (posicion < 0 || posicion > lista->numero_elementos)
        return false;
    else if (posicion == 0)
        return insertarPrincipio(lista, elemento);
    else if (posicion == lista->numero_elementos)
        return insertarFinal(lista, elemento);

    previo = lista->primero;

    while (indice != posicion) {
        previo = previo->siguiente;
        indice++;
    }

    nuevo_nodo = malloc(sizeof(Nodo *));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;

    posterior = previo->siguiente;
    previo->siguiente = nuevo_nodo;
    posterior->anterior = nuevo_nodo;

    nuevo_nodo->siguiente = posterior;
    nuevo_nodo->anterior = previo;

    lista->numero_elementos++;
    return true;
}

bool eliminar(ListaCircular * lista, Tipo * sacado, int posicion) {
    int indice = 1;
    Nodo * previo, * nodo_eliminar;

    if (posicion < 0 || posicion >= lista->numero_elementos)
        return false;
    else if (posicion == 0)
        return eliminarPrimero(lista, sacado);
    else if (posicion == lista->numero_elementos - 1)
        return eliminarUltimo(lista, sacado);

    previo = lista->primero;
    while (indice != posicion) {
        previo = previo->siguiente;
        indice++;
    }


    nodo_eliminar = previo->siguiente;
    previo->siguiente = nodo_eliminar->siguiente;

    nodo_eliminar->siguiente->anterior = nodo_eliminar->anterior;

    *sacado = nodo_eliminar->dato;

    lista->numero_elementos--;
    return true;
}

void ordenarAscendente(ListaCircular * lista) {
    // Se usa el algoritmo mAs sencillo, el algoritmo "burbuja"
    int pasadas, checados, faltantes;

    pasadas = 1;
    while (pasadas <= lista->numero_elementos) {
        Nodo * actual = lista->primero;
        faltantes = lista->numero_elementos - pasadas;

        checados = 0;
        while (checados <= faltantes) {

            if (comparar(actual->dato, actual->siguiente->dato) > 0) {
                Tipo aux = actual->dato;

                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = aux;
            }
            checados++;
            actual = actual->siguiente;
        }
        pasadas++;
    }
}

void ordenarDescendente(ListaCircular * lista) {
    // Se usa el algoritmo mAs sencillo, el algoritmo "burbuja"
    int pasadas, checados, faltantes;

    pasadas = 1;
    while (pasadas <= lista->numero_elementos) {
        Nodo * actual = lista->primero;
        faltantes = lista->numero_elementos - pasadas;

        checados = 0;
        while (checados <= faltantes) {

            if (comparar(actual->dato, actual->siguiente->dato) < 0) {
                Tipo aux = actual->dato;

                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = aux;
            }
            checados++;
            actual = actual->siguiente;
        }
        pasadas++;
    }
}

int indice(ListaCircular * lista, Tipo elemento) {
    int i = 0;
    Nodo * auxiliar = lista->primero;

    while ( i < lista->numero_elementos
            && comparar(auxiliar->dato, elemento) != 0 ) {

        auxiliar = auxiliar->siguiente;
        i++;
    }

    if (auxiliar)
        i = -1;

    return i;
}

bool indiceRev(ListaCircular * lista, Tipo elemento) {
    int i = lista->numero_elementos - 1;
    Nodo * auxiliar = lista->ultimo;

    while ( i >= 0 && comparar(auxiliar->dato, elemento) != 0 ) {
        auxiliar = auxiliar->siguiente;
        i--;
    }

    if (auxiliar)
        i = -1;

    return i;
}

inline bool estaVacia(ListaCircular * lista) {
    return lista->numero_elementos == 0;
}
