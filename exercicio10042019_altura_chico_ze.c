#include <stdio.h>
#include <stdlib.h>

void main() {

	/*
	Chico tem 1,50 metro e cresce 2 cent�metros por ano, enquanto
	Z� tem 1,10 metro e cresce 3 cent�metros por ano. Construa um
	programa que calcule e imprima quantos anos ser�o necess�rios
	para que Z� seja maior que Chico.
	*/	
	double alturachico=1.50;
	double aumentachico=0.02;
	double alturaze=1.10;
	double aumentaze=0.03;
	
	while (alturaze<alturachico){
		printf("Altura Ze: %.2f - Altura Chico: %.2f \n",alturaze,alturachico);
		alturaze+=aumentaze;
		alturachico+=aumentachico;	
	}	
	printf("\n A altura final para Ze ficar maior que chico e %.2f enquanto a altura de chico e %.2f",alturaze,alturachico);
}
