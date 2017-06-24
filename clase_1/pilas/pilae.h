#include <stdlib.h>
#include <stdbool.h>

typedef int Tipo;
#define VALOR_DEFECTO 0

typedef struct pilae Pila;
struct pilae {
    int tamanio;
    Tipo * elementos;
    int tope;
};

Pila * nuevaPila(int tamanio);
void  borrarPila(Pila * pila);

bool insertar(Pila * pila, Tipo elemento);
bool eliminar(Pila * pila, Tipo * sacado);
Tipo checar(Pila * pila);

bool estaVacia(Pila * pila);
bool estaLlena(Pila * pila);

