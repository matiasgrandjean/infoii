#include "circulo.h"

Circulo::Circulo(float radio){
	setRadio(radio);
}

Circulo::~Circulo(){};

float Circulo::getArea(void){
	return (3.141592 * r * r);
}

float Circulo::getVolumen(void){
	return 0;
}

float Circulo::getRadio(void){
	return r;
}

void Circulo::setRadio(float radio){
	if(radio >= 0)
		r = radio;
	else
		r = 0;
}
