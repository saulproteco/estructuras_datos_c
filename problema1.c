#include <stdio.h>

int main(void) {
    int *apt = &apt;

    // Solo estaremos seguros de que estas relaciones son verdad
    // si el tamanio del apuntador es el mismo que el tamanio del
    // entero
    if (&apt == apt && &apt == *apt && apt == *apt) {
        printf("Es verdad\n");
    } else {
        printf("Es mentira\n");
    }
    return 0;
}
