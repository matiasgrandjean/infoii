#include "cuadrado_fig.h"

Cuadrado::Cuadrado(float x) : Figura(x){};

float Cuadrado::Perimetro(void){
	return (4 * x);
}

float Cuadrado::Area(void){
	return (x * x);
}
