#include <stdbool.h>
#include <stdint.h>

typedef int Tipo;
#define VALOR_DEFECTO 0

typedef struct pilae PilaEstatica;
struct pilae {
    int32_t tamanio;
    Tipo * elementos;
    int32_t tope;
};

PilaEstatica * nuevaPila(int32_t tamanio);
void  borrarPila(PilaEstatica * pila);

bool insertar(PilaEstatica * pila, Tipo elemento);
bool eliminar(PilaEstatica * pila, Tipo * sacado);
Tipo checar(const PilaEstatica * pila);

extern bool estaVacia(const PilaEstatica * pila);
extern bool estaLlena(const PilaEstatica * pila);

