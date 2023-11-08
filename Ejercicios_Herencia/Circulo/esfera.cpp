#include "esfera.h"

Esfera::Esfera(float r) : Circulo(r){}

Esfera::~Esfera(){};

float Esfera::getVolumen(void){
	return (3.141592 * 4/3 * r * r * r);
}
