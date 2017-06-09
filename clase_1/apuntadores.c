/*
 * PROTECO: Estructuras de datos en C
 *
 * Clase 1 - Repaso de Apuntadores y memoria dinAmica
 */

#include <stdio.h>
#include <stdlib.h>     // Necesaria para reservar memoria dinAmica (malloc, calloc)

int main(void) {
    // ######   DeclaraciOn de apuntadores   #####

    int entero;

    int         *       apuntador_entero;
/*   ^          ^           ^
     |          |           |
     |          |           +------> Nombre de la variable
     |          +---------> Indica que la variable es de tipo apuntador
     +----------> Tipo de dato a apuntar
*/

    // #####    InicializaciOn    #####

    apuntador_entero = &entero;
    /* Las variables apuntador se inicializan con la direcciOn de
     * memoria de una variable del tipo al que apuntan.
     *
     * Si no se sabe a quE deben de apuntar se inicializan con el
     * valor NULL
     */
    int * apuntador2 = &entero;
    int * apuntador3 = NULL;

    // #####   Acceso a los datos   #####

    /* El operador * permite acceder a la direcciOn de memoria a la que
     * apunta el apuntador, pudiendo asI usar y modificar su valor.
     */
    entero = 5;
    *apuntador_entero = 10;  // A la variable "entero" se le asigna 10
                             // de forma indirecta.
    printf("El valor de entero es: %d\n", entero);

    // #####    Uso de memoria dinAmica    #####

    /* Las funciones para el asignar memoria dinAmica regresan
     * la direcciOn de la memoria asignada en caso de Exito o
     * NULL en caso de fallo.
     * El lugar correcto para guardar la direcciOn de retorno es
     * un apuntador.
     */

    apuntador3 = (int *) malloc(5 * sizeof(int));
/*                              ^           ^
 *                              |           |
 *                              |           +--> Tamanio de cada variable
 *                              +--> NUmero de variables a reservar.
 */

    if ( apuntador3 == NULL )   // Si la asignaciON fallO
        exit(EXIT_FAILURE);     // se sale del programa

    /* Si todo saliO bien apuntador3 estarA apuntando al principio
     * de un arreglo de 5 enteros.
     *
     *      apuntador3
     *       |
     *       |
     *       |
     *       v
     *      +----+----+----+----+----+
     *      |    |    |    |    |    |
     *      +----+----+----+----+----+
     *        0    1    2    3    4
     */

    *apuntador3 = 10;       // Se le asigna 10 al primero de los enteros
    *(apuntador3 + 1) = 15; // Se le asigna 15 al segundo de los enteros
    apuntador3[3] = 20;     // Se le asigna 20 al tercero de los enteros

    for (int i = 0; i < 5; i++)
        printf("%d ", *(apuntador3 + i));

    putchar('\n');

    for (int i = 0; i < 5; i++)
        printf("%d ", apuntador3[i]);

    putchar('\n');

    /* Por Ultimo se tiene que liberar la memoria que se asignO
     * dinAmicamente
     */

    free( apuntador3 );
    return 0;
}
