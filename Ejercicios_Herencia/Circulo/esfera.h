#ifndef ESFERA_H
#define ESFERA_H

#include "circulo.h"

class Esfera : public Circulo{
	public:
	Esfera(float = 0);
	~Esfera();
	float getVolumen(void);
};

#endif
