#include <stdio.h>
#include <stdlib.h>

void main() {
	int qtdnumeros,i,j,posicao,escadaini,escadafim,conta=0,erro=0;	
	
	printf("Informe a quantidade de numeros a inserir: ");
	scanf("%i",&qtdnumeros);

	int numeros[qtdnumeros];

	printf("Entre com %i numeros para preencher o array, e pressione enter apos digitar cada um:\n",qtdnumeros);
 	for (i = 0; i < qtdnumeros; i++) {
 		scanf("%i", &numeros[i]);
  			if ((numeros[i]<=0) || (numeros[i]>1000)){
  				printf("\n\n");
 				printf("Erro! nao e possivel inserir numero negativo, igual a zero ou maior do que 1.000.");
 				exit(0);
			}			
 	}		

 	//Se a quantidade for igual a 1, não faz o loop e exibe a conta igual a 1
	if (qtdnumeros==1){
		printf("O total de escadas e: 1");
	}
	//Se não, inicia o loop
	
	else{
		printf("\nIniciando escada \n\n");
		//Ordena os numeros aleatórios
		for (i=0;i<=qtdnumeros-1;i++){
			//faz um segundo loop para verificar se os proximos numeros são menores que o atual, caso positivo, muda de posicao
			for (j=i+1;j<=qtdnumeros-1;j++){
				//se o proximo numero é menor, muda de posicao
				if(numeros[j]<numeros[i]){
					//armazenei a posição atual na variavel posição
					posicao=numeros[i];
					//armazenei o vetor menor na posição do vetor atual
					numeros[i]=numeros[j];
					//armazenei a variavel posição na posição em que estava o vetor menor
					numeros[j]=posicao;
				}
			}
		}
		
		//Inicia a escada, escada inicial e escada final igual ao segundo numero menos o primeiro
		escadaini=numeros[1]-numeros[0];
		escadafim=numeros[1]-numeros[0];
		
		//Inicia o loop iniciando de zero até a quantidade de numeros -1
		for (i=0;i<=qtdnumeros-1;i++){
			if (i==0){
				printf("%i,",numeros[i]);
			}
			else{
				escadafim=numeros[i]-numeros[i-1];
				//Se houver diferença na subtração do próximo numero com o anterior, significa que o próximo número saiu da escada
				if (escadaini==escadafim){
					printf("%i,",numeros[i]);
				}
				else {
					printf("\n");
					//Imprime o último número novamente para comparar com o próximo iniciando uma nova contagem
					if (i<qtdnumeros-1){
						printf("%i,%i,",numeros[i-1],numeros[i]);	
					}conta++;
					//altera escadaini para ficar igual a escadafim e seguir para a próxima comparação
					escadaini=numeros[i]-numeros[i-1];
				} 
				
			}
		}
		printf("\n\nO total de escadas e: %i",conta);	
	}	
}


