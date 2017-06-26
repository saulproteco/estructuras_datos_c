/*========================================================*
 * Archivo de cabecera para hacer uso de pilas de tamanio *
 * dinAmico dentro del lenguaje C.                        *
 *========================================================*/

/*
 * Las definiciones de este archivo de cabecera deben estar
 * encerradas entre macros condicionales para evitar asI
 * que sus elementos se incluyan mAs de una vez.
 */
#ifndef _PILA_DINAMICA_H
#define _PILA_DINAMICA_H

/*-* Bibliotecas que requiren ser publicas *-*/
#include <stdbool.h>
#include <stdint.h>

/*-* Macros para facilitar el cambio de tipo *-*/
typedef char Tipo;

/*-* Tipos compuestos necesarios *-*/

typedef struct nodo Nodo;
struct nodo{
    Tipo dato;
    Nodo * siguiente;
};

typedef struct pilad PilaDinamica;
struct pilad {
    Nodo * tope;
    int32_t num_elementos;
};

/*-* Constructor / Desctructor *-*/
PilaDinamica * nuevaPila(void);
void  borrarPila(PilaDinamica * pila);

/*-* Funciones que modifican los dAtos guardados *-*/
bool insertar(PilaDinamica * pila, Tipo elemento);
bool eliminar(PilaDinamica * pila, Tipo * sacado);

/*-* Auxiliares de uso rApido *-*/
extern Tipo checar(const PilaDinamica * pila);
extern bool estaVacia(const PilaDinamica * pila);

#endif /* _PILA_DINAMICA_H */
