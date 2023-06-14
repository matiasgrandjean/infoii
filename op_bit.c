#include <stdio.h>

void imprimir_binario(char val)
  {
  unsigned int b, mask = 1 << (8*sizeof(unsigned char)-1);

  for(b = 1; b <= 8*sizeof(unsigned char); b++)
  {
  putchar(val & mask ? '1' : '0');
  val <<= 1;

   if(b % 8 == 0)
   putchar(' ');
   }

   putchar('\n');
}

void imprimir_binario2(short int val)
  {
  unsigned int b, mask = 1 << (8*sizeof(short int)-1);

  for(b = 1; b <= 8*sizeof(short int); b++)
  {
  putchar(val & mask ? '1' : '0');
  val <<= 1;

   if(b % 8 == 0)
   putchar(' ');
   }

   putchar('\n');
}

int main(void){
	short int x;
	char c;
	int m = 15 << 7;

	while(x!=0){
		do{

		printf("Ingrese un valor para x: ");
		scanf("%hd", &x);
		if (x == 0)
			return 0;

		}while(x < 0);

		imprimir_binario2(x);

		c = (x & m) >> 7;
		printf("%d\n", c);

		imprimir_binario(c);
	}

	return 0;
}
