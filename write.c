#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(void){
	int fd;
	int cont = 1;

	fd = open("/dev/ttyS20", O_WRONLY);
	if(fd == -1){
		printf("ERROR: unable to open /dev/ttyS20 \n");
		return -1;
	}

	while(1){
		int n = write(fd, "Hola!", 6);
		printf("Datos enviados: %d\n",n);
		for(int d = 0 ; d < 100000000; d++)
			;
	}

	close (fd);

	return 0;
}
