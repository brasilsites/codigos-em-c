#include <stdio.h>
#include <stdlib.h>

void main() {

	/*
	Chico tem 1,50 metro e cresce 2 centímetros por ano, enquanto
	Zé tem 1,10 metro e cresce 3 centímetros por ano. Construa um
	programa que calcule e imprima quantos anos serão necessários
	para que Zé seja maior que Chico.
	*/	
	double alturachico=1.50;
	double aumentachico=0.02;
	double alturaze=1.10;
	double aumentaze=0.03;
	int anos=0;
	
	while (alturaze<alturachico){
		printf("Ano %i - Altura Ze: %.2f - Altura Chico: %.2f \n",anos,alturaze,alturachico);
		alturaze+=aumentaze;
		alturachico+=aumentachico;	
		anos++;
	}	
	printf("\n A altura final para Ze ficar maior que chico e %.2f e leva %i anos enquanto a altura de chico e %.2f",alturaze,anos,alturachico);
}
