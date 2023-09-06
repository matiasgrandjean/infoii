#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(void){

	int fd;
	char buffer[20] = {0};
	int i;

	fd = open("/dev/ttyS21", O_RDWR | O_NOCTTY);
	if(fd == -1){
		printf("ERROR: unable to open /dev/ttyS21 \n");
		return -1;
	}

	while(1){
		i = read(fd, buffer, 6);

		if(buffer[5] != '\0')
			buffer[5] = '\0';

		printf("Datos recibidos (%d): %s\n",i, buffer);
	}

	close (fd);

	return 0;
}
