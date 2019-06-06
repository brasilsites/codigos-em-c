#ifndef COORDENADOR_H
#define COORDENADOR_H

/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

#define ARQ_USUARIO "usuario.txt"

FILE *arqcoordena;

typedef struct{
		char matricula[MAX];
		char nome[MAX];
		char login[MAX];
		char senha[MAX];
		char tipo[MAX]; //tipo=2: Aluno - tipo=1: Coordenador - tipo=3: Responsavel
		char notacre[MAX]; //nota do CRE
}Coordenador;

void cabecalhoCoo();
void menucoordenador();
#endif
