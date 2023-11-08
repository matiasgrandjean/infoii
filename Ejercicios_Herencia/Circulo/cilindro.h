#ifndef CILINDRO_H
#define CILINDRO_H

#include "circulo.h"

class Cilindro: public Circulo{
	protected:
	float h;

	public:
	Cilindro(float = 0, float = 0);
	~Cilindro();
	float getVolumen(void);
};

#endif
