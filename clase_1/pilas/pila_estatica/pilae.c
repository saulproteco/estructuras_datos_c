/*========================================================*
 * COdigo fuente para hacer uso de una pila de tamanio    *
 * estatico dentro del lenguaje C.                        *
 *========================================================*/

/*-* Bibliotecas que no requieren verse publicamente *-*/
#include "pilae.h"
#include <stdlib.h>

/*-* Constructor / Desctructor *-*/
PilaEstatica * nuevaPila(int32_t tamanio) {
    // No se admite 0 o menos como tamanio
    if (tamanio <= 0)
        return NULL;

    // Intentamos asignar memoria para las variables de la pila
    // (tope, tamanio, y espacio), en caso de que falle regresamos
    // NULL
    PilaEstatica * nueva_pila = malloc(sizeof(PilaEstatica));
    if (!nueva_pila)
        return NULL;

    // Intentamos asignar memoria para el arreglo de elementos
    // que van a estar guardados en la pila
    nueva_pila->elementos = calloc(tamanio ,sizeof(Tipo));
    if (!nueva_pila->elementos) {
        free(nueva_pila);
        return NULL;
    }

    // Inicializamos las variables de la pila
    nueva_pila->tamanio = tamanio;
    nueva_pila->tope = -1;

    return nueva_pila;
}

void  borrarPila(PilaEstatica * pila) {
    free(pila->elementos);
    free(pila);
}

/*-* Funciones que modifican los dAtos guardados *-*/
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
    // Borramos el valor que habia antes poniendo el valor por
    // defecto
    pila->elementos[pila->tope--] = VALOR_DEFECTO;

    return true;
}

/*-* Auxiliares de uso rApido *-*/
inline Tipo checar(const PilaEstatica * pila) {
    return estaVacia(pila) ? VALOR_DEFECTO : pila->elementos[pila->tope];
}

inline bool estaVacia(const PilaEstatica * pila) {
    return pila->tope == - 1;
}

inline bool estaLlena(const PilaEstatica * pila) {
    return pila->tope == pila->tamanio - 1;
}
