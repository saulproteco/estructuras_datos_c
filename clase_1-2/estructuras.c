/*
 * PROTECO: Estructuras de datos en C
 *
 * Clase 1 - Repaso de estructuras (tipo de dato)
 */

#include <stdio.h>
#include <stdlib.h>     // Necesaria para reservar memoria dinAmica (malloc, calloc)

int main(void) {

    // #####    DefiniciON    #####

    /* Las estructuras se definen mediante mediante la palabra
     * reservada struct usando la siguiente sintaxis.
     *
     *      struct [nombre_estructura] {
     *          [tipo_dato1 dato_miembro_1;]
     *          [tipo_dato1 dato_miembro_2;]
     *          ...
     *          ...
     *          ...
     *          [tipo_daton dato_miembro_n;]
     *      } [variables_de_estructura];
     *
     *      Los corchetes alrededor de las partes de la estructura
     *      simbolizan que la palabra encerrada puede ir o no.
     *
     *      Tal como se observa, todas las palabras en la definiciOn
     *      de una estructura a escepciOn de la propia palabra struct
     *      son opcionales. A consecuencia se pueden definir
     *      estructuras que no tengan nombre, que no tengan
     *      datos miembro o que no creen ninguna variable del nuevo
     *      tipo. Incluso se pueden omitir todas estas caracterIsticas
     *      a la vez aunque una estructura de dichas caracteristicas
     *      no tendrIa utilidad alguna.
     */

    /* Estructura con todos los datos */
    struct estructura1 {
        // Esta estructura estA compuesta de un entero,
        // un flotante y un caracter.
        int entero;
        float flotante;
        char caracter;
    } variable1, variable2;

    struct estructura1 variable3;   // Esta declaraciOn y las de
                                    // variable1 y variable2 son equivalentes.

    /* Estructura sin nombre */
    struct {
        int dato1;
        char dato2;
        double dato3;
    } anonima1 = { 2, 'a', 25.5 },
      anonima2;

    // No es posible declarar mAs variables de la estructura
    // anterior salvo los que se declaren en la propia definiciOn.

    /* Estructura sin variables automAticas */
    struct estructura3 {
        char nomber[30];
    };

    struct estructura3 var = { "Eduardo" };

    /* Estructura sin nombre ni datos*/

    struct {
        // vacIo
    } muchas[10000];

    printf("El tamanio del arreglo \"muchas\" es: %ld\n", sizeof(muchas));

    // #####    InicializaciOn      #####

    /* Es posible inicializar todos los datos de la estructura
     * al momento de declarar una variable, los diferentes datos
     * se habrAn de separar por comas y el conjunto entero deberA
     * estar encerrado entre llaves.
     *
     * Se puede omitir la inicializaciOn de los Ultimos datos de
     * una estructura cuyos valores seran automaticamente establecidos
     * a 0.
     */

    struct estructura1 inicializada = { 15, 0.123, 'b' };   // Inicializa los 3 datos
    struct estructura1 medio_inicializada = { 10, 4.4 };    // Inicializa solo dos

    /* Es posible alterar el orden de la inicializaciOn de los datos
     * si especificamos el nombre del tado miembro al que queremos
     * dar valor seguido de un punto.
     *
     * En el caso de no especificar el valor de todos los datos el
     * resto se establecerA con 0.
     */

    struct estructura1 inicializada2 = { .caracter = 'n', .entero = 10 };

    struct estructura1 inicializada3 = { .flotante = 5123123.4123123123 };

    // #####    Uso con memoria dinAmica    #####

    /* Las mismas reglas del uso de memoria dinAmica se aplican con las
     * estructuras.
     *
     * Sin embargo las estructuras tienen un operador mAs del que se puede
     * hacer uso para facilitar el acceso por medio de apuntadores:
     *  El operador ->
     */

    struct estructura1 * arreglo_dinamico = calloc(5, sizeof(struct estructura1));

    arreglo_dinamico->entero = 2;           // Entero de la variable 0
    arreglo_dinamico[1].caracter = 'f';     // caracter de la variable 2
    arreglo_dinamico[3].flotante = 12.4;    // flotante de la variable 4

    (arreglo_dinamico + 2)->entero = 15;

    // #####    Estructuras autorreferenciadas    #####

    /* Una estructura no puede contener un dato de si misma, sin embargo
     * si es posible que contenga una referencia de su mismo tipo
     */

    struct autorreferenciada {
        struct autorreferenciada * madre;       // referencia
        int dato;
        struct autorreferenciada * hija;
    };

    struct autorreferenciada * apt_str = malloc(sizeof(struct autorreferenciada));
    apt_str->madre = malloc(sizeof(struct autorreferenciada));
    apt_str->hija  = malloc(sizeof(struct autorreferenciada));

    /* Mediante los enlaces a otras estructuras de su tipo es posible
     * acceder a los datos de estas
     */

    apt_str->dato = 10;

    apt_str->madre->dato = 15;

    apt_str->hija->dato = 20;


    printf("El dato de apt_str es: %d\n", apt_str->dato);
    printf("El dato de apt_str->madre es: %d\n", apt_str->madre->dato);
    printf("El dato de apt_str->hija es: %d\n", apt_str->hija->dato);

    return 0;
}
