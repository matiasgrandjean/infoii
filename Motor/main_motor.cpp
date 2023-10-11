#include <iostream>

using namespace std;

#include "motor.h"

int main(){
	int vel_objetivo_user, vel_inicial_user, vel_actual_motor, vel_objetivo_motor;

	cin >> vel_objetivo_user;
	Motor mot1 (vel_objetivo_user);

	cin >> vel_inicial_user;
	mot1.set_vel_actual(vel_inicial_user);

	vel_objetivo_motor = mot1.get_vel_objetivo();
	vel_actual_motor = mot1.get_vel_actual();

	cout << "Vel. actual: " << vel_actual_motor << ", Vel. objetivo: " << vel_objetivo_motor << endl;

	if(vel_actual_motor < vel_objetivo_motor){
		while(mot1.get_vel_actual() < vel_objetivo_motor){
			mot1.incrementar();
		}
		vel_actual_motor = mot1.get_vel_actual();
		cout << "Vel. actual incrementada: " << mot1.get_vel_actual() << endl;
	}

	if(vel_actual_motor > vel_objetivo_motor){
		while(mot1.get_vel_actual() > vel_objetivo_motor){
			mot1.decrementar();
		 }
		vel_actual_motor = mot1.get_vel_actual();
		cout << "Vel. actual decrementada: " << mot1.get_vel_actual() << endl;
	}

	return 0;
}
