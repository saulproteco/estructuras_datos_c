#include <stdio.h>
#include <stdbool.h>

struct Celula {
	char nombre[30];
	int tamanio;
	bool haciendo_fotosintesis;
	
	struct Celula * arriba;
	struct Celula * abajo;
	struct Celula * izquierda;
	struct Celula * derecha;
	
};

void quien_eres(struct Celula * pt_celula ) {
	printf("Mi nombre es %s, mido %d micrometros y %s estoy haciendo la fotosintesis",
		pt_celula->nombre,
		pt_celula->tamanio,
		(pt_celula->haciendo_fotosintesis) ? "si" : "no"
	);
}

int main() {
	
	struct Celula tejido[6] = {
		{ "Juan", 15, false, NULL, &tejido[2], NULL, &tejido[1] },
		{ "Ana", 12, false, NULL,  &tejido[3], &tejido[0], NULL },
		{ "Pepe", 30, true, &tejido[0],  NULL, NULL, &tejido[3] },
		{ "Sofia", 17, true, &tejido[1], &tejido[5], &tejido[2], &tejido[4] },
		{ "Rene", 2, false, NULL, NULL, &tejido[3], NULL },
		{ "Alberto", 14, false, &tejido[3], NULL, NULL, NULL }
	};
	
	struct Celula * ap_celula = &tejido[3];
	
	ap_celula = ap_celula->derecha->izquierda->
				izquierda->arriba->derecha->arriba;	

	printf("La direccion de la celula es: %p",
			ap_celula);
	// quien_eres(ap_celula);
	
	getchar();
	return 0;
}
