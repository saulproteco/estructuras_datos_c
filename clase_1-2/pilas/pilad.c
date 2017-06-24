#include "pilad.h"
#include <stdlib.h>

PilaDinamica * nuevaPila(void) {
    return calloc(1, sizeof(PilaDinamica));
}

void  borrarPila(PilaDinamica * pila) {
    free(pila);
}

bool insertar(PilaDinamica * pila, Tipo elemento) {
    Nodo * nuevo_nodo = malloc(sizeof(Nodo));

    if (!nuevo_nodo)
        return false;

    nuevo_nodo->dato = elemento;
    nuevo_nodo->siguiente = pila->tope;
    pila->tope = nuevo_nodo;

    pila->num_elementos++;
    return true;
}

bool eliminar(PilaDinamica * pila, Tipo * sacado) {
    if (estaVacia(pila))
        return false;

    Nodo * auxiliar = pila->tope;
    *sacado = auxiliar->dato;
    pila->tope = auxiliar->siguiente;

    free(auxiliar);

    pila->num_elementos--;
    return true;
}

inline bool estaVacia(const PilaDinamica * pila) {
    return pila->num_elementos == 0;
}
