#include "figura.h"

Figura::Figura(float valor){
	if(valor >= 0)
		x = valor;
	else
		x = 0;
}

float Figura::Perimetro(void){ return 0; }

float Figura::Area(void){ return 0; }
