#include "pilae.h"
#include <stdlib.h>

PilaEstatica * nuevaPila(int32_t tamanio) {
    if (tamanio < 0)
        return NULL;

    PilaEstatica * nueva_pila = malloc(sizeof(PilaEstatica));

    if (!nueva_pila)
        return NULL;

    // Se supone que los argumentos de calloc van al revez pero me vale!
    nueva_pila->elementos = calloc(sizeof(Tipo), tamanio);
    if (!nueva_pila->elementos) {
        free(nueva_pila);
        return NULL;
    }


    nueva_pila->tamanio = tamanio;
    nueva_pila->tope = -1;

    return nueva_pila;
}

void  borrarPila(PilaEstatica * pila) {
    free(pila->elementos);
    free(pila);
}

bool insertar(PilaEstatica * pila, Tipo elemento) {
    if (estaLlena(pila))
        return false;

    pila->elementos[++pila->tope] = elemento;
    return true;
}

bool eliminar(PilaEstatica * pila, Tipo * sacado) {
    if (estaVacia(pila))
        return false;

    *sacado = pila->elementos[pila->tope];
    pila->elementos[pila->tope--] = VALOR_DEFECTO;

    return true;
}

Tipo checar(const PilaEstatica * pila) {
    return estaVacia(pila) ? VALOR_DEFECTO : pila->elementos[pila->tope];
}

inline bool estaVacia(const PilaEstatica * pila) {
    return pila->tope == - 1;
}

inline bool estaLlena(const PilaEstatica * pila) {
    return pila->tope == pila->tamanio - 1;
}
