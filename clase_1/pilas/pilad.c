#include "pilad.h"

Pila * nuevaPila(void) {
    return calloc(1, sizeof(Pila));
}

void  borrarPila(Pila * pila) {
    free(pila);
}

bool insertar(Pila * pila, Tipo elemento) {
    Nodo * nuevo_nodo = malloc(sizeof(Nodo));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;
    nuevo_nodo->siguiente = pila->tope;
    pila->tope = nuevo_nodo;

    pila->num_elementos++;
    return true;
}

bool eliminar(Pila * pila, Tipo * sacado) {
    if (estaVacia(pila))
        return false;

    Nodo * auxiliar = pila->tope;
    *sacado = auxiliar->dato;
    pila->tope = auxiliar->siguiente;

    free(auxiliar);

    pila->num_elementos--;
    return true;
}

bool estaVacia(Pila * pila) {
    return pila->num_elementos == 0;
}
