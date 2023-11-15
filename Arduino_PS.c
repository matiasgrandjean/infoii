#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

void configureSerialPort(int fd) {
    struct termios serial;

    // Configuración de la estructura termios
    tcgetattr(fd, &serial);
    cfsetispeed(&serial, B9600);
    cfsetospeed(&serial, B9600);
    serial.c_cflag |= (CLOCAL | CREAD);
    serial.c_cflag &= ~PARENB;
    serial.c_cflag &= ~CSTOPB;
    serial.c_cflag &= ~CSIZE;
    serial.c_cflag |= CS8;
    serial.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    serial.c_iflag &= ~(IXON | IXOFF | IXANY);
    serial.c_oflag &= ~OPOST;
    tcsetattr(fd, TCSANOW, &serial);
}

int main() {
    int fd, val_menu, val_tiempo, val_velocidad, option;
    char buffer[10];

    // Abre el puerto serie
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    if (fd == -1) {
        perror("Error al abrir el puerto serie");
        return 1;
    }

    // Configura el puerto serie
    configureSerialPort(fd);
    sleep(3);

    while (1) {

        printf("Ingrese 1 para ingresar al menú de configuración de parámetros: ");
	do{
        	scanf(" %d", &option);

		if(option != 1)
			printf("ERROR!\n");

	}while(option != 1);

        if (option == 1) {
		dprintf(fd, "%d", option);
		sleep(8);

        	printf("Ingrese 1 para configurar tiempo entre pitidos o 2 para velocidad de vibración: ");

		do{
            		scanf(" %d", &val_menu);

			if(val_menu != 1 && val_menu != 2)
				printf("!ERROR\n");

		}while(val_menu != 1 && val_menu != 2);

		dprintf(fd, "%d", val_menu);

        	if (val_menu == 1) {
			printf("Ingrese un valor entre 1 y 5: ");

			do{
				scanf(" %d", &val_tiempo);

				if(val_tiempo < 1 || val_tiempo > 5)
					printf("ERROR!\n");

			}while(val_tiempo < 1 || val_tiempo > 5);
		// Envía el entero al Arduino
                	dprintf(fd, "%d", val_tiempo);
                	printf("Entero enviado: %d\n", val_tiempo);
        	}

        	if (val_menu == 2) {
			printf("Ingrese un valor entre 1 y 5: ");

			do{
				scanf(" %d", &val_velocidad);

				if(val_velocidad < 1 || val_velocidad > 5)
					printf("ERROR!\n");

			}while(val_velocidad < 1 || val_velocidad > 5);
		// Envía el entero al Arduino
                	dprintf(fd, "%d", val_velocidad);
                	printf("Entero enviado: %d\n", val_velocidad);
        	}

        }
    }

    // Cierra el puerto serie
    close(fd);

    return 0;
}
