#include <stdbool.h>
#include <stdint.h>

typedef char Tipo;
#define VALOR_DEFECTO '\0'

struct nodo {
    Tipo dato;
    struct nodo * siguiente;
};

typedef struct pilad PilaDinamica;
struct pilad {
    struct nodo * tope;
    int32_t num_elementos;
};

PilaDinamica * nuevaPila(void);
void  borrarPila(PilaDinamica * pila);

bool insertar(PilaDinamica * pila, Tipo elemento);
bool eliminar(PilaDinamica * pila, Tipo * sacado);

extern bool estaVacia(const PilaDinamica * pila);
