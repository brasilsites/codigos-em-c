#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int numeros[2][2]={{10,12},{4,2}};
	int i,j;
	int k=0;
	
	//10 12 4 2
	//int sequencia[]={10,12,4,2};
	/*
	for (i=0;i<2;i++){	
		for (j=0;j<2;j++){
			numeros[i][j]=sequencia[k];
			//k++;
		}		
	}
	*/
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			printf("| %d |",numeros[i][j]);
		}
		printf("\n");
	}
	
	/*
	char nome[20];
	
	printf ("Infome o nome: ");
	scanf("%s",&nome);
	
	int i;
	
	for (i=strlen(nome);i>=0;i--){
		printf("%c",nome[i]);
	}
	*/
	//char nomegets[]="Nome gets";
	//printf("Teste comando gets e puts, informe um nome: ");
	//gets e puts so serve para strings, não divide caracter
	//gets(nomegets);
	//puts(nomegets);
}
