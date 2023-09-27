#include "iostream"

using namespace std;

#include "rectangulo.h"

int main(){
	float area, perimetro;

	Rectangulo rect;
	rect.Mostrar();

	Rectangulo rect2(5, 4);
	cout<<endl;
	rect2.Mostrar();

	if(rect2.esCuadrado() == true)
		cout<<"Rect2 es un cuadrado"<<endl;
	else
		cout<<"Rect2 es un rectangulo"<<endl;

	area = rect2.Area();
	perimetro = rect2.Perimetro();

	cout<<"Area: "<<area<<", Perimetro: "<<perimetro<<"\n"<<endl;

	rect2.setBase(8);
	rect2.setAltura(-4);
	rect2.Mostrar();

	if(rect2.esCuadrado() == true)
		cout<<"Rect2 es un cuadrado"<<endl;
	else
		cout<<"Rect2 es un rectangulo"<<endl;

	area = rect2.Area();
	perimetro = rect2.Perimetro();

	cout<<"Area: "<<area<<", Perimetro: "<<perimetro<<endl;

	return 0;
}
