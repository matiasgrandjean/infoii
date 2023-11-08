#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"

class Circulo : public Figura{
	public:
	Circulo(float = 0);
	float Perimetro(void);
	float Area(void);
};

#endif
