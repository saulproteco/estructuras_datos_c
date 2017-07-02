#include "arbol_binario.h"
#include <stdlib.h>

ArbolBinario * nuevoArbol(void) {
    return calloc(1, sizeof(ArbolBinario));
}

void liberarArbol(ArbolBinario * arbol) {
    liberarNodosRecursivo(arbol->raiz);
    free(arbol);
}

Nodo * nuevoNodo(Tipo dato) {
    Nodo * nuevo_nodo = calloc(1, sizeof(Nodo));
    nuevo_nodo->dato = dato;

    return nuevo_nodo;
}

bool insertar(ArbolBinario * arbol, Tipo elemento) {
    Nodo * nuevo;

    if (arbol->raiz == NULL) {
        nuevo = nuevoNodo(elemento);

        if (nuevo == NULL)
            return false;

        arbol->raiz = nuevo;

        arbol->numero_elementos++;
        return true;
    } else {
        if (insertarRecursivo(arbol->raiz, elemento)) {
            arbol->numero_elementos++;
            return true;
        } else {
            return false;
        }
    }
}

bool insertarRecursivo(Nodo * raiz, Tipo elemento) {
    if (raiz->dato < elemento) {
        if (raiz->hijoIzq == NULL) {
            raiz->hijoIzq = nuevoNodo(elemento);
            raiz->hijoIzq->padre = raiz;
        } else {
            insertarRecursivo(raiz->hijoIzq, elemento);
        }
    } else if (raiz->dato > elemento) {
        if (raiz->hijoDer == NULL) {
            raiz->hijoDer = nuevoNodo(elemento);
            raiz->hijoDer->padre = raiz;
        } else {
            insertarRecursivo(raiz->hijoDer, elemento);
        }
    }
}

bool eliminar(ArbolBinario * arbol, Tipo a_sacar) {
    if (arbol->raiz == NULL)
        return false;

    if ( eliminarRecursivo(arbol->raiz, a_sacar) ) {
        arbol->numero_elementos;
        return true;
    }
}

bool eliminarRecursivo(Nodo * raiz, Tipo a_sacar) {
    if (raiz == NULL) {
        return false;
    } else if (a_sacar < raiz->dato) {
        return eliminarRecursivo(raiz->hijoIzq, a_sacar);
    } else if (a_sacar > raiz->dato) {
        return eliminarRecursivo(raiz->hijoDer, a_sacar);
    } else {
        if (raiz->hijoIzq == NULL) {
            remplazar(raiz, raiz->hijoDer);
            free(raiz);
        } else if (raiz->hijoDer == NULL) {
            remplazar(raiz, raiz->hijoIzq)
            free(raiz);
        } else {
        }

    }
}

bool existe(ArbolBinario * arbol, Tipo elemento);

void imprimirPreOrden(Nodo * nodo_arbol);
void imprimirPosOrden(Nodo * nodo_arbol);
void imprimirInOrden(Nodo * nodo_arbol);

inline bool estaVacio(const ArbolBinario * arbol) {
    return arbol->numero_elementos == 0;
}
