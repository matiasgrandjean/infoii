#include <iostream>

using namespace std;

#include "motor.h"

Motor::Motor(int v){

velocidad_actual = 0;
velocidad_objetivo = v;

}

void Motor::set_vel_actual(int vel_actual){

velocidad_actual = vel_actual;

}

void Motor::set_vel_objetivo(int vel_objetivo){

velocidad_objetivo = vel_objetivo;

}

int Motor::get_vel_actual(){

return velocidad_actual;

}

int Motor::get_vel_objetivo(){

return velocidad_objetivo;

}

void Motor::incrementar(){

velocidad_actual++;

}

void Motor::decrementar(){

velocidad_actual--;

}
