#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main() {
	setlocale(LC_ALL,"Portuguese");
	float depositosaque=0;
	float valor[3];
	int i,j;

	for (j=0;j<3;j++){
		/* com o setlocale, o valor deve ser inserido com virgula */
		printf("\nDigite o %i valor (formato xxx,xx): ",j);
		scanf("%f",&valor[j]);
	}

	for (i=0;i<3;i++){
		if (valor[i]<0){
			printf("\n saque no valor de %.2f",valor[i]);
		}
		else {
			printf("\n deposito no valor de %.2f",valor[i]);
		}
		depositosaque+=valor[i];
	}
	printf("\nSaldo : %.2f",depositosaque);

}
