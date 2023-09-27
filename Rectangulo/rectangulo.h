#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo{
	private:
	float altura;
	float base;

	public:
	Rectangulo();
	Rectangulo (float, float);
	bool esCuadrado (void);
	float Perimetro (void);
	float Area (void);
	void Mostrar (void);
	void setAltura (float);
	void setBase (float);
};

#endif
