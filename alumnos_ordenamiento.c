#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{
	char nombre[20];
	int nota;
};

void ordenar(struct  alumno *x){

	int i, j;
	struct {
		char nombre[20];
		int nota;
	} t;
	for(i = 0 ; i < 5-1 ; i++)
	for(j = i+1 ; j < 5 ; j++)
		if(strcmp(x[i].nombre, x[j].nombre)>0){
			strcpy(t.nombre, x[j].nombre);
			strcpy(x[j].nombre, x[i].nombre);
			strcpy(x[i].nombre, t.nombre);
		}
	return;
}

void main(){

	struct alumno x[5];

	for(int i = 0 ; i < 5 ; i++){
		printf("Ingrese el nombre del %d° alumno: ", i+1);
		scanf("%s", x[i].nombre);
		printf("Ingrese la nota del %d° alumno: ", i+1);
		scanf("%d", &(x[i].nota));
	}

	ordenar(x);

	for(int i = 0 ; i < 5 ; i++){
		printf("Nombre: %s, nota: %d\n", x[i].nombre, x[i].nota);
	}

	return 0;
}
