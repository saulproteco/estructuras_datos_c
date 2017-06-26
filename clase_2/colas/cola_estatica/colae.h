/*========================================================*
 * Archivo de cabecera para hacer uso de colas de tamanio *
 * estAtico dentro del lenguaje C.                        *
 *========================================================*/

/*
 * Las definiciones se encierran entre macros condicionales
 * para evitar la inclusiOn multiple del contenido de la
 * cabecera
 */
#ifndef _COLA_ESTATICA_H
#define _COLA_ESTATICA_H

/*-* Bibliotecas que requieren ser publicas *-*/
#include <stdbool.h>
#include <stdint.h>

/*-* Definiciones para facilitar el cambio entre tipos de datos *-*/
typedef char * Tipo;
#define VALOR_DEFECTO NULL;

/*-* Tipos compuestos necesarios *-*/
typedef struct colae ColaEstatica;
struct colae {
    int32_t tamanio;
    Tipo * elementos;

    int32_t inicio;
    int32_t fin;

    bool estaLlena;
    bool estaVacia;
};

/*-* Constructor / Destructor *-*/
ColaEstatica * nuevaCola(int32_t tamanio);
void borrarCola(ColaEstatica * cola);

/*-* Funciones que modifican los datos *-*/
bool insertar(ColaEstatica * cola, Tipo elemento);
bool eliminar(ColaEstatica * cola, Tipo * sacado);

/*-* Auxiliares de uso rApido *-*/
Tipo checar(const ColaEstatica * cola);
extern bool estaLlena(const ColaEstatica * cola);
extern bool estaVacia(const ColaEstatica * cola);

#endif /* _COLA_ESTATICA_H */
