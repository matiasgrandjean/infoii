#include <iostream>

using namespace std;

#include "rectangulo.h"

using std::cout;
using std::endl;

Rectangulo::Rectangulo(){
	base = 0;
	altura = 0;
}

Rectangulo::Rectangulo(float b, float h){
	if(b < 0)
		base = (-1)*(b);
	else
		base = b;

	if(h < 0)
		altura = (-1)*(h);
	else
		altura = h;
}

bool Rectangulo::esCuadrado(){
	if(base == altura)
		return true;
	else
		return false;
}

float Rectangulo::Perimetro(){
	return base+altura;
}

float Rectangulo::Area(){
	return base*altura;
}

void Rectangulo::Mostrar(){
	cout<<"Rect: "<<base<<", "<<altura<<endl;
}

void Rectangulo::setAltura(float h){
	if(h < 0)
		altura = (-1)*h;
	else
		altura = h;
}

void Rectangulo::setBase(float b){
	if(b < 0)
		base = (-1)*b;
	else
		base = b;
}
