#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define QTD 5

typedef struct {
	int matricula;
	char nome[MAX];
}professor;

professor p[QTD];

void main() {
	
	int i;
	
	for (i=0;i<QTD;i++){
		printf ("Digite a matricula: ");
		scanf("%i",&p[i].matricula);		
		printf ("Digite o nome do professor: ");
		scanf("%s",&p[i].nome);			
	} 	
	
	for (i=0;i<QTD;i++){
		printf ("%i - Matricula: %i - Professor: %s \n",i+1,p[i].matricula,p[i].nome);
	}
}
