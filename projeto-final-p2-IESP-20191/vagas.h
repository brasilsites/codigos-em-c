#ifndef VAGAS_H
#define VAGAS_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

#define ARQ_VAGA "vagas.txt"
FILE *arqvagas;

typedef struct{
		char codigovaga[MAX]; //criar um codigo como identificador unico para relacionamento nos arquivos
		char nomeempresa[MAX];
		char cargahoraria[MAX];
		char numerovagas[MAX]; //Quantitativo de vagas
		char vagasocupadas[MAX]; //Quantitativo de vagas ocupadas, quando atingir o limite igual ao Quantitativo de vagas, altera o status da vaga para 1-Encerrado
		char pontuacaominima[MAX]; //Pontuação minima que deve atingir com a média dos pontos (Entrevista, Escrita, CRE)
		char salario[MAX]; 
		char responsavel[MAX]; 
		char status[MAX]; //status da vaga (0-Ativo,1-Encerrada)
}Vagas;

void BaseVagas();
#endif
