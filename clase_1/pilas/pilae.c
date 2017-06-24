#include "pilae.h"

Pila * nuevaPila(int tamanio) {
    Pila * nueva_pila = malloc(sizeof(Pila));

    // Se supone que los argumentos de calloc van al revez pero me vale!
    nueva_pila->elementos = calloc(sizeof(Tipo), tamanio);
    nueva_pila->tamanio = tamanio;
    nueva_pila->tope = -1;

    return nueva_pila;
}

void  borrarPila(Pila * pila) {
    free(pila->elementos);
    free(pila);
}

bool insertar(Pila * pila, Tipo elemento) {
    if (estaLlena(pila))
        return false;

    pila->elementos[++pila->tope] = elemento;
    return true;
}

bool eliminar(Pila * pila, Tipo * sacado) {
    if (estaVacia(pila))
        return false;

    *sacado = pila->elementos[pila->tope];
    pila->elementos[pila->tope--] = VALOR_DEFECTO;

    return true;
}

Tipo checar(Pila * pila) {
    return estaVacia(pila) ? VALOR_DEFECTO : pila->elementos[pila->tope];
}

bool estaVacia(Pila * pila) {
    return pila->tope == - 1;
}

bool estaLlena(Pila * pila) {
    return pila->tope == pila->tamanio - 1;
}
