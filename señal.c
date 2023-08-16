#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	FILE *archivo;
	double senal[100];
	double suma = 0;
	double suma_cuadrados = 0;
	double promedio;
	double rms;

	if (argc < 2){
		printf("Usó: %s <nombre_archivo>\n", argv[0]);
		exit(1);
	}

	archivo = fopen(argv[1], "r");
	if (archivo == NULL){
		printf("Error al abrir el archivo\n");
		exit(1);
	}


	for (int i = 0 ; i < 100; i++){
		fscanf(archivo, "%lf", &senal[i]);
		suma += senal[i];
		suma_cuadrados += senal[i] * senal[i];
	}

	fclose(archivo);

	promedio = suma / 100;
	rms = sqrt(suma_cuadrados / 100);

	printf("El promedio de la señal es: %lf\n", promedio);
	printf("El valor RMS de la señal es: %lf\n", rms);

	return 0;
}
