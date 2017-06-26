/*========================================================*
 * Archivo de cabecera para hacer uso de pilas de tamanio *
 * estatico dentro del lenguaje C.                        *
 *========================================================*/

/*
 * Todas las definiciones de este archivo de cabecera requieren
 * estar dentro de macros condicionales para evitar su inclusiOn
 * multiple.
 */
#ifndef _PILA_ESTATICA_H
#define _PILA_ESTATICA_H

/*-* Bibliotecas que requieren ser publics *-*/
#include <stdbool.h>
#include <stdint.h>

/*-* Definiciones para facilitar el cambio de tipo *-*/
typedef int32_t Tipo;
#define VALOR_DEFECTO 0

/*-* Tipos compuestos requeridos *-*/
typedef struct pilae PilaEstatica;
struct pilae {
    int32_t tamanio;
    Tipo * elementos;
    int32_t tope;
};

/*-* Constructor / Desctructor *-*/
PilaEstatica * nuevaPila(int32_t tamanio);
void  borrarPila(PilaEstatica * pila);

/*-* Funciones que modifican los dAtos guardados *-*/
bool insertar(PilaEstatica * pila, Tipo elemento);
bool eliminar(PilaEstatica * pila, Tipo * sacado);

/*-* Auxiliares de uso rApido *-*/
extern Tipo checar(const PilaEstatica * pila);
extern bool estaVacia(const PilaEstatica * pila);
extern bool estaLlena(const PilaEstatica * pila);

#endif /* _PILA_ESTATICA_H */
