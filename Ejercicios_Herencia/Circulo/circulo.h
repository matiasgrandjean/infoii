#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo{
	protected:
	float r;

	public:
	Circulo(float = 0);
	~Circulo();
	float getArea(void);
	float getVolumen(void);
	float getRadio(void);
	void setRadio(float);
};

#endif
