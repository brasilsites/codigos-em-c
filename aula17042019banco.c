#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	int depositosaque=0;
	int valor[3];
	int i,j;

	for (j=0;j<3;j++){
		printf("\nDigite o valor: ");
		scanf("%i",&valor[j]);
	}

	for (i=0;i<3;i++){
		if (valor[i]<0){
			printf("\n saque no valor de %i",valor[i]);
		}
		else {
			printf("\n deposito no valor de %i",valor[i]);
		}
		depositosaque+=valor[i];
	}
	printf("\nSaldo : %i",depositosaque);

}
