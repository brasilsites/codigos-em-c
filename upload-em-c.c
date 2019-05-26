#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  void copiaConteudo(FILE *arquivo, FILE *arquivo1);
//Crie a mesma pasta e salve o arquivo com este mesmo nome
  FILE *arquivo = fopen("tmp/curriculum.txt","r");
if (arquivo == NULL)
{
    printf ("Não foi possível abrir o arquivo");
    return 1;
}
///O programa cria um arquivo com o nome que escolher, se já tiver um arquivo com o mesmo nome será apagado
FILE *arquivo1 = fopen("home/20192024.txt","w+");

copiaConteudo(arquivo,arquivo1);

fclose(arquivo);
fclose(arquivo1);
return 0;
}

void copiaConteudo(FILE *arquivo, FILE *arquivo1){
  	char ler[100];
  	char lu[20];
  	while(fgets(ler,100,arquivo) != NULL){
            fputs(ler, arquivo1);
	}
}
