#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "upload.h"
#include "vagas.h"
#include "aluno.h"
#include "candidatos.h"

int upload(matricula) {
	char origem[100];	
  	
	fflush(stdin);
  	printf("Informe o caminho completo do arquivo de origem: ");
  	gets(origem);
  		//"tmp/curriculum.txt"
  		FILE *arquivo = fopen(origem,"r");
	if (arquivo == NULL){
    	printf ("Não foi possível abrir o arquivo");
    	return 1;
	}
	
	char destino[100] = "curriculum/";
  	strcat(destino,matricula);
  	strcat(destino,".txt");
	FILE *arquivo1 = fopen(destino,"w+");

	copiaConteudo(arquivo,arquivo1);
	printf("Curriculum enviado com sucesso! ");

	printf("\n\n Pressione ENTER para voltar ao inicio.");
	fclose(arquivo);
	fclose(arquivo1);
	getche();	
	cabecalhoaln();	
	menualuno(matricula);

return 0;
}

void copiaConteudo(FILE *arquivo, FILE *arquivo1){
  	char ler[100];
  	char lu[20];
  	while(fgets(ler,100,arquivo) != NULL){
            fputs(ler, arquivo1);
	}
}

int exporta(){
	BaseVagas();
	Vagas vaga;
	InicializarVagas(&vaga);
	
	int posi = 0, linha = 0,op;
	
	char codigovaga[MAX],destino[100],caminho[100];
	
	fflush(stdin);//limpa o buffer do teclado
	printf("Digite o codigo da vaga:");
	gets(codigovaga);
	
	fflush(stdin);//limpa o buffer do teclado
	printf("Informe o caminho completo da pasta de destino (Ex: c:/destino/envio):");
	gets(caminho);
	
  	strcat(destino,caminho);
  	strcat(destino,codigovaga);
  	strcat(destino,".txt");
	FILE *arquivo1 = fopen(destino,"w+");
	
	rewind(arqvagas);	
	while(!feof(arqvagas)){
		while(fread(&vaga, sizeof(Vagas), 1, arqvagas)){
				//realiza os comparativos
			    if(vaga.codigovaga != 0 && strstr(vaga.codigovaga,codigovaga)){
			    	//informa se achou o registro
			    posi=1;	
			    
			    fprintf(arquivo1, "=========================================\n");
			    fprintf(arquivo1, "      RELATÓRIO DE CANDIDATOS A VAGA     \n");
			    fprintf(arquivo1, "                  EMPRESA                \n");
			    fprintf(arquivo1, "=========================================\n");
				fprintf(arquivo1,"Codigo da vaga: %s\n",vaga.codigovaga);
				fprintf(arquivo1,"Empresa: %s\n",vaga.nomeempresa);
				fprintf(arquivo1,"Carga Horaria: %sh\n",vaga.cargahoraria);
				fprintf(arquivo1,"Numero de vagas: %s\n",vaga.numerovagas);
				fprintf(arquivo1,"Vagas ocupadas: %s\n",vaga.vagasocupadas);
				fprintf(arquivo1,"Pontuação mínima: %s\n",vaga.pontuacaominima);
				fprintf(arquivo1,"Remuneração: R$ %s\n",vaga.salario);
				fprintf(arquivo1,"Responsável: %s\n",vaga.responsavel);
					if(strcmp("0",vaga.status)==0){
						fprintf(arquivo1,"Status: Ativo\n");
					} else{
						fprintf(arquivo1,"Status: Encerrada\n");
					}
					//fwrite(&vaga, sizeof(Vagas),1,arquivo1);
				}
		}
			if(posi == 0){
				printf("Registro não encontrado");
			}	
	}
	
	if(posi == 1){
		BaseCandidato();
		Candidato candidato;
 		InicializarCandidatos(&candidato); 	
 		int pos = 0, op,atingiu,erro=0,i=1;	
		 
		rewind(arquivocan);	
		while(!feof(arquivocan)){
			while(fread(&candidato, sizeof(Candidato), 1, arquivocan)){
				//realiza os comparativos
			    if(candidato.codigovaga != 0 && strstr(candidato.codigovaga,codigovaga)){
			    	//informa se achou o registro
			    	pos = 1;
			    	
			    	fprintf(arquivo1, "=========================================\n");
			    	fprintf(arquivo1, "              CANDIDATO %i               \n",i);
			    	fprintf(arquivo1, "=========================================\n");
 					fprintf (arquivo1,"\n Matricula: %s", candidato.matriculaaluno);
					fprintf (arquivo1,"\n Nota Escrita: %s", candidato.notaescrita);
					fprintf (arquivo1,"\n Nota Entrevista: %s", candidato.notaentrevista);
					fprintf (arquivo1,"\n Média: %s",candidato.media);	
						if(strcmp("0",candidato.status)==0){
							fprintf (arquivo1,"\n Status: Aguardando...");
						} else if (strcmp("1",candidato.status)==0){
							fprintf(arquivo1,"\n Status: Aprovado\n");
						} else if (strcmp("2",candidato.status)==0){
							fprintf(arquivo1,"\n Status: Reprovado\n");
						} else{
							fprintf (arquivo1,"\n Status: Indefinido! %i",candidato.status);
						}
					printf("Arquivo salvo com sucesso!");
					i++;
				} 
			}
			if(pos == 0){
				printf("Registro não encontrado");
			}
			    	fprintf(arquivo1, "=========================================\n");
			    	fprintf(arquivo1, "    Desenvolvido por: Edson Ferreira\n");
			    	fprintf(arquivo1, "    P2 Sistemas de Informação 2019.1\n");
		}fclose(arquivocan);	
	}
	fclose(arqvagas);
	fclose(arquivo1);
		
		
		printf("Voltar ao menu principal? (s/n):");
		if (getche() == 's') {
			cabecalhoCoo();	
			menucoordenador();	
		}
}
