#include <iostream>

using namespace std;

#include "figura.h"
#include "circulo_fig.h"
#include "cuadrado_fig.h"

int main(void){
	int n, opcion = 0;
	float radio, lado;

	cout<<"Cuántos elementos desea que el arreglo posea: ";
	cin>>n;

	Figura *(*fig) = new Figura*[n];

	for(int i = 0 ; i < n ; i++){
		cout<<"Qué desea cargar (1 p/ Circulo, 2 p/ Cuadrado): ";
		cin>>opcion;
		switch(opcion){

			case 1:
				cout<<"Qué radio desea que posea el circulo: ";
				cin>>radio;
				fig[i] = new Circulo(radio);
				break;

			case 2:
				cout<<"Cuánto desea que valga el lado del cuadrado: ";
				cin>>lado;
				fig[i] = new Cuadrado(lado);
				break;
		}
	}

	for(int i = 0 ; i < n ; i++){
		cout<<"Perimetro: "<<fig[i]->Perimetro()<<endl;
		cout<<"Area: "<<fig[i]->Area()<<endl;
		cout<<endl;
	}

	delete [] *fig;

	return 0;
}
