#ifndef ALUNO_H
#define ALUNO_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "vagas.h"
//#include "candidatos.h"

#define MAX 30

#define ARQ_USUARIO "usuario.txt"
FILE *arquivoaluno;

typedef struct{
		char matricula[MAX];
		char nome[MAX];
		char login[MAX];
		char senha[MAX];
		char tipo[MAX]; //tipo=2: Aluno - tipo=1: Coordenador
		char notacre[MAX]; //nota do CRE
}Aluno;

#endif
