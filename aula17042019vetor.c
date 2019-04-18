#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");

	int numeros[5]={10,20,30,40,50};
	int i;
	int j;
	for (i=0;i<5;i++){
		if (numeros[i]==30){
			printf("Remover número 30 na posição %i",i);
		}
		else{
			numeros[j]=numeros[i];
			j++;
		}
	}
	printf("\n Números");
	for (i=0;i<j;i++){
		printf("%i,",numeros[i]);
	}
}
