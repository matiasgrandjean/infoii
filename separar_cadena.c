#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char linea[40], temp[3][10] = {0};
	char cmd[10];
	int a, b, j = 0, k = 0;
	
	printf("Ingrese una cadena: ");
	scanf("%[^\n]s", linea);
	
	for(int i = 0 ; i < strlen(linea) ; i++){
		
		if(linea[i] != ' '){
			temp[j][k] = linea[i];
			k++;
		}
		
		else{
			j++;
			k = 0;
		}
		
	}
	
	for(int i = 0 ; i < strlen(temp[0]) ; i++){
		cmd[i] = temp[0][i];
	}
	
	a = atoi(temp[1]);
	b = atoi(temp[2]);
	
	printf("%s\n", cmd);
	printf("%d\n", a);
	printf("%d\n", b);
	
	return 0;
}
