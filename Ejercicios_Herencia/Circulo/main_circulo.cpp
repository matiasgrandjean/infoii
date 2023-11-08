#include <iostream>

#include "circulo.h"
#include "cilindro.h"
#include "esfera.h"

using namespace std;

int main(void){
	Circulo c1(2);
	cout<<c1.getRadio()<<c1.getVolumen()<<endl;

	Cilindro cl1(3, 2);
	cout<<"Volumen del cilindro: "<<cl1.getVolumen()<<", Area: "<<cl1.getArea()<<endl;

	Esfera e1(4);
	cout<<"Volumen esfera: "<<e1.getVolumen()<<endl;
	cout<<"Volumen del circulo de esfera: "<<e1.Circulo::getVolumen()<<endl;


	return 0;
}
