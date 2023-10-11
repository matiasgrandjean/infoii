#ifndef MOTOR_H
#define MOTOR_H

class Motor{
	private:
	int velocidad_actual;
	int velocidad_objetivo;

	public:
	Motor(int);
	void set_vel_actual(int);
	void set_vel_objetivo(int);
	int get_vel_actual();
	int get_vel_objetivo();
	void incrementar();
	void decrementar();
};

#endif
