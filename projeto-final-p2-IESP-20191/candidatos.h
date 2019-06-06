#ifndef CANDIDATOS_H
#define CANDIDATOS_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

#define ARQ_CANDIDATOS "candidatos.txt"

FILE *arquivocan;

typedef struct{
		char codigovaga[MAX]; 
		char matriculaaluno[MAX];
		char notaescrita[MAX];
		char notaentrevista[MAX]; 
		char media[MAX]; //a media e a soma da notaescrita+notaentrevista+notacre / 3
		char status[MAX]; //0 - Em analise | 1 - Aprovado | 2 - Reprovado
}Candidato;

void BaseCandidato();
#endif
