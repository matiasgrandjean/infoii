#include <stdio.h>
#include <stdlib.h>

#define MUESTRAS 256

int main() {
    FILE *archivo1, *archivo2;
    double senal[MUESTRAS];
    double suma = 0;
    double promedio;
    int i;

    // Abrir el archivo
    archivo1 = fopen("senal.txt", "r");
    if (archivo1 == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    archivo2 = fopen("senal2.txt", "w");
    if (archivo2 == NULL) {
	printf("Error al abrir el archivo\n");
	exit(1);
    }

    // Leer los datos del archivo
    for (i = 0; i < MUESTRAS; i++) {
        fscanf(archivo1, "%lf", &senal[i]);
	suma += senal[i];
    }

    for (i = 0; i < MUESTRAS; i++) 
	fprintf(archivo2, "%.0f\n", senal[i]);

    // Cerrar el archivo
    fclose(archivo1);
    fclose(archivo2);

    // Calcular el promedio
    promedio = suma / MUESTRAS;

    // Mostrar el resultado
    printf("El promedio de la señal es: %lf\n", promedio);

    return 0;
}
