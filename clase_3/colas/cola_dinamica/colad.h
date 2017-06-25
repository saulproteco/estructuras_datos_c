/*-* Bibliotecas que requieren ser publicas *-*/
#include <stdbool.h>
#include <stdint.h>

/*-* Definiciones para facilitar el cambio entre tipos de datos *-*/
typedef int32_t Tipo;
#define VALOR_DEFECTO 0

/*-* Tipos compuestos necesarios *-*/
typedef struct nodo Nodo;
struct nodo {
    Tipo dato;
    struct nodo * siguiente;
};

typedef struct colad ColaDinamica;
struct colad {
    Nodo * primero;
    Nodo * ultimo;

    int32_t numero_elementos;
};

/*-* Constructor / Destructor *-*/
ColaDinamica * nuevaCola(int32_t tamanio);
void borrarCola(ColaDinamica * cola);

/*-* Funciones que modifican los datos *-*/
bool insertar(ColaDinamica * cola, Tipo elemento);
bool eliminar(ColaDinamica * cola, Tipo * sacado);

/*-* Auxiliares de uso rApido *-*/
extern Tipo checar(const ColaDinamica * cola);
extern bool estaVacia(const ColaDinamica * cola);
