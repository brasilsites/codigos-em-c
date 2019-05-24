#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char separador[] = "Edson Ferreira;Faculdade IESP;2019.1";
	char *nome = NULL;
    char *instituicao = NULL;
    char *ano = NULL;

    nome = strtok(separador, ";");
    printf("Nome: %s\n", nome);
    
    instituicao = strtok(NULL, ";");
    printf("Instituicao: %s\n", instituicao);
    
	ano = strtok(NULL, ";");
    printf("Instituicao: %s\n", ano);
}
