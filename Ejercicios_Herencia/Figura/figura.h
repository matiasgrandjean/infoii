#ifndef FIGURA_H
#define FIGURA_H

class Figura{
	protected:
	float x;

	public:
	Figura(float = 0);
	virtual float Perimetro(void);
	virtual float Area(void);
};

#endif
