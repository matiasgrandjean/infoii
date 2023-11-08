#ifndef CUADRADO_H
#define CUADRADO_H

#include "figura.h"

class Cuadrado : public Figura{
	public:
	Cuadrado(float = 0);
	float Perimetro();
	float Area();
};

#endif
