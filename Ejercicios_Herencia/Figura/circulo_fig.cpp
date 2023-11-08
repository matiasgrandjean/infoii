#include "circulo_fig.h"

Circulo::Circulo(float x) : Figura(x){};

float Circulo::Perimetro(void){
	return (2 * 3.141592 * x);
}

float Circulo::Area(void){
	return (3.141592 * x * x);
}
