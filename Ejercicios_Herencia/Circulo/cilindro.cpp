#include "cilindro.h"

Cilindro::Cilindro(float altura, float r) : Circulo(r){
	h = altura;
}

Cilindro::~Cilindro(){};

float Cilindro::getVolumen(void){
	return getArea() * h;
}
