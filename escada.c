#include <stdio.h>
#include <stdlib.h>

void main() {
	int qtdnumeros=0,i,contador=0,aux=0,anterior=0,comparativo=0,comparaant=0,conta=0;
	printf("Informe a quantidade de numeros a inserir: ");
	scanf("%i",&qtdnumeros);

	int numeros[qtdnumeros];
	
	printf("Entre com dez números para preencher o array, e pressione enter após digitar cada um:\n");
 	for (i = 0; i < qtdnumeros; i++) {
 		scanf("%i", &numeros[i]);
 	}
 	/*
	printf("Ordem atual dos itens no array:\n");
	for (i = 0; i < qtdnumeros-1; i++) {
 		printf("%i - ", numeros[i]);
	}
	*/
	for (contador = 1; contador < qtdnumeros; contador++) {
   		for (i = 0; i < qtdnumeros - 1; i++) {
     		if (numeros[i] > numeros[i + 1]) {
       			aux = numeros[i];
       			numeros[i] = numeros[i + 1];
       			numeros[i + 1] = aux;
     		}
  		}
 	}
 	
 	//anterior=numeros[0];
 	//comparativo=numeros[1]-numeros[0];
 	//printf("%i\n\n",comparativo);
	printf("\nElementos do array em ordem crescente:\n");
	for (i = 0; i < qtdnumeros; i++) {
		
		if (i>0){
			comparativo=numeros[i]-numeros[i-1];
			if (comparativo!=comparaant){
				printf("\n");
				conta++;
				//comparativo=numeros[i+1]-numeros[i];
			}
			//printf("%i,",numeros[i]);
		} else {
			comparaant=numeros[1]-numeros[0];
			//printf("%i, ",numeros[0]);
		}
	}
	printf("A quantidade de escadas e: %i",conta);
}
