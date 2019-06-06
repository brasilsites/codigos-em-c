#include "candidatos.h"
#include "aluno.h"
#include "vagas.h"
#include "coordenador.h"

void BaseCandidato(){ 
	arquivocan = fopen(ARQ_CANDIDATOS, "r+b"); // Abre o arquivo binário
	if(arquivocan ==NULL){
        arquivocan = fopen(ARQ_CANDIDATOS, "w+b"); //Cria o arquivo binário
        if(arquivocan==NULL){
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
 }

int InicializarCandidatos(Candidato *candidato){
	strcpy(candidato->codigovaga,""); //codigovaga
	strcpy(candidato->matriculaaluno,""); //matriculaaluno
	strcpy(candidato->notaescrita,"0");
	strcpy(candidato->notaentrevista,"0");
	strcpy(candidato->media,"0");
	strcpy(candidato->status,"0");
}

void ExibirCandidato(Candidato *candidato){
 	printf ("\n Codigo: %s", candidato->codigovaga); 
 	printf ("\n Matricula: %s", candidato->matriculaaluno);
	printf ("\n Nota Escrita: %s", candidato->notaescrita);
	printf ("\n Nota Entrevista: %s", candidato->notaentrevista);
	printf ("\n Média: %s",candidato->media);	
	
	if(strcmp("0",candidato->status)==0){
		printf ("\n Status: Aguardando...");
	} else if (strcmp("1",candidato->status)==0){
		printf("\n Status: Aprovado\n");
	} else if (strcmp("2",candidato->status)==0){
		printf("\n Status: Reprovado\n");
	} else{
		printf ("\n Status: Indefinido! %i",candidato->status);
	}	
 }

int BuscarCandidato(codigovaga,matricula){
	BaseCandidato();
	Candidato candidato;
	InicializarCandidatos(&candidato);
	int posi = 0, linha = 0,op;
	
	rewind(arquivocan);	
	while(!feof(arquivocan)){
		if(strlen(matricula) < 1){
	    	printf("Matrícula Inválida! \n\n");
	    	getch();
		}else{
			while(fread(&candidato, sizeof(Candidato), 1, arquivocan)){
				//realiza os comparativos
			    if(candidato.matriculaaluno != 0 && strstr(candidato.matriculaaluno,matricula) && candidato.codigovaga != 0 && strstr(candidato.codigovaga,codigovaga)){
			    	//informa se achou o registro
			    	posi = 1;
			    	return linha;
				}
				linha++;
			}
			if(posi == 0){
				printf("Registro não encontrado");
			}			
		}
	}fclose(arquivocan);
}

void AlterarCandidato(responsavel){
	//Abre o aquivo
	BaseCandidato();

 	Candidato candidato;
 	InicializarCandidatos(&candidato);
 	
 	char codigovaga[MAX],matricula[MAX],nota[MAX],msgerro[MAX];
 	
 	int pos = 0, op,atingiu,erro=0;
 	//float somanotas;
 	
 	fflush(stdin);
 	printf(" Informe o código da vaga: ");
	gets(codigovaga);
	fflush(stdin);
	printf(" Informe a matricula do aluno: ");
	gets(matricula);
	
	pos = BuscarCandidato(codigovaga,matricula);
	fseek(arquivocan,pos*sizeof(Candidato),SEEK_SET);

	while(fread(&candidato,sizeof(Candidato),1,arquivocan)==1){
			system("cls");
			cabecalhoResp();
			ExibirCandidato(&candidato);
			printf("\n\n------------------------ ALTERAR CANDIDATO -------------------------------------- \n");
	
	if(strcmp("1",candidato.status)==0){ 
		erro=1;
		strcpy(msgerro,"Candidato já foi avaliado anteriormente. ");
	}
	
	if (erro==0){					
	fflush (stdin);
	printf("Informe a nota Escrita: ");
	//scanf("%s",&candidato.notaescrita);
	gets(candidato.notaescrita);
	fflush (stdin);
	printf("\nInforme a nota Entrevista: ");
	//scanf("%s",&candidato.notaentrevista);
	gets(candidato.notaentrevista);
	fflush (stdin);
			
	//Calculo da Media////////////////////////////////////////////////////////////////////////////////////////	
	//somanotas=calculaMedia(candidato.matriculaaluno,candidato.notaescrita,candidato.notaentrevista);
			BaseAluno();
			Aluno aluno;	
			float somanotas;
			
			inicializarAluno(&aluno);
			rewind(arquivoaluno);
			int acha=0;
			while(!feof(arquivoaluno)){
				while(fread(&aluno,sizeof(Aluno),1,arquivoaluno)){
				//realiza os comparativos
			    	if(strcmp(aluno.matricula,candidato.matriculaaluno)==0){		
			    	//informa se achou o registro
			    	somanotas=atof(aluno.notacre);	
			    	somanotas+=atof(candidato.notaescrita);	
			    	somanotas+=atof(candidato.notaentrevista);	
			    	somanotas=somanotas/3;
					acha=1;	 
					
					sprintf(nota, "%.2f",somanotas);
					}
				
				}
					if(acha == 0){
					printf("Registro não encontrado");
					} 
			}fclose(arquivoaluno);	
			
	//sprintf(nota, "%.2f",somanotas);
	strcpy(candidato.media,nota);										
	//printf("\nA media é: %s",candidato.media);	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////	
			
	//Verifica se o candidato atingiu a média para ser aprovado/////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////		
	BaseVagas();
	//Estrutura
 	Vagas vaga;	
 	InicializarVagas(&vaga);
 	float notaaluno,notarequerida; 
 	int qtdvagas,qtdlimite,statusvaga;
	char novaqtd[MAX]	;
 	int posvg = 0,atingiu,status;
 	
	posvg = BuscarVagas(codigovaga);
	
	fseek(arqvagas,posvg*sizeof(Vagas),SEEK_SET);
	if(fread(&vaga,sizeof(Vagas),1,arqvagas)==1){
		notarequerida=atof(vaga.pontuacaominima);
		notaaluno=atof(candidato.media);
		qtdvagas=atoi(vaga.vagasocupadas);
		qtdlimite=atoi(vaga.numerovagas);
		
		if (strcmp("1",vaga.status)==0){ 
			erro=1;
			strcpy(msgerro,"Vagas encerradas! ");
		}
		if (notarequerida<=notaaluno){
			//printf("\n\nA nota requerida : %.2f é maior ou igual a nota do aluno: %.2f",notarequerida,notaaluno);
			strcpy(candidato.status,"1");
			qtdvagas+=1;
			sprintf(novaqtd, "%i",qtdvagas);
			strcpy(vaga.vagasocupadas,novaqtd);
			
			if(qtdvagas>=qtdlimite){ 
				strcpy(vaga.status,"1");	
			}
			fseek(arqvagas,posvg*sizeof(Vagas),SEEK_SET);
			fwrite(&vaga,sizeof(Vagas),1,arqvagas);
			
			fclose(arqvagas);			
		} if (notarequerida>notaaluno){
			//printf("\n\nA nota requerida : %.2f é menor que a nota do aluno: %.2f",notarequerida,notaaluno);	
			strcpy(candidato.status,"2");
		}
	}
	//printf("\n\nO status do candidato é %s",candidato.status);
	}
	if (erro==1){
		printf("\n\n%s",msgerro);
		printf("\n\n Pressione ENTER para sair.");
		fclose(arquivocan);
		getche();	
		cabecalhoResp();	
		menuResp(responsavel);		
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
		if (erro==0){
			printf("\nDeseja salvar os dados? (s/n): ");	
				
			if(getche() == 's'){
				fseek(arquivocan,pos*sizeof(Candidato),SEEK_SET);
			       if(fwrite(&candidato,sizeof(Candidato),1,arquivocan) != 1){
			       	printf("\n Falha ao Alterar o candidato!\n");
			       	printf("\n\n Pressione ENTER para continuar.");
					getche();
				}else{
					printf("\n Candidato alterado com sucesso!\n");
					printf("\n\n Pressione ENTER para continuar.");
					fclose(arquivocan);
					getche();	
					cabecalhoResp();	
					menuResp(responsavel);		
				} 
			}
				
			if(getche() != 's'){
			    getche();
			}
		}
	}
	fclose(arquivocan);
    getche();		
}

int calculaMedia(matricula,notaescrita,notaentrevista){
			BaseAluno();
			Aluno aluno;	
			float somanotas;
			
			inicializarAluno(&aluno);
			rewind(arquivoaluno);
			int acha=0;
			while(!feof(arquivoaluno)){
				while(fread(&aluno,sizeof(Aluno),1,arquivoaluno)){
				//realiza os comparativos
			    	if(strcmp(aluno.matricula,matricula)==0){		
			    	//informa se achou o registro
			    	somanotas=atof(aluno.notacre);	
			    	somanotas+=atof(notaescrita);	
			    	somanotas+=atof(notaentrevista);	
			    	somanotas=somanotas/3;
					acha=1;	 
					
					return somanotas; 
					}
				
				}
					if(acha == 0){
					printf("Registro não encontrado");
					} 
			}fclose(arquivoaluno);	
}

void listarCandidatoResp(responsavel){
	BaseCandidato();
 	Candidato candidato;
 	InicializarCandidatos(&candidato);
 	
 	char codigovaga[MAX];
 	int pos = 0, op,atingiu,erro=0;
 	
 	fflush(stdin);
 	printf(" Informe o código da vaga: ");
	gets(codigovaga);
	
	rewind(arquivocan);	
	while(!feof(arquivocan)){
		while(fread(&candidato, sizeof(Candidato), 1, arquivocan)){
			if(candidato.codigovaga != 0 && strstr(candidato.codigovaga,codigovaga)){
			ExibirCandidato(&candidato);
			printf("\n=======================================================================\n");
			pos=1;
			}
		}
		if(pos == 0){
			printf("Candidato(s) não encontrado(s)");
		}
	}
	printf("\n\n Pressione ENTER para voltar ao inicio.");
	fclose(arquivocan);
	getche();	
	cabecalhoResp();	
	menuResp(responsavel);	
}

void listarCandidatoCoo(){
	BaseCandidato();
 	Candidato candidato;
 	InicializarCandidatos(&candidato);
 	
 	char codigovaga[MAX];
 	int pos = 0, op,atingiu,erro=0;
 	
 	fflush(stdin);
 	printf(" Informe o código da vaga: ");
	gets(codigovaga);
	
	rewind(arquivocan);	
	while(!feof(arquivocan)){
		while(fread(&candidato, sizeof(Candidato), 1, arquivocan)){
			if(candidato.codigovaga != 0 && strstr(candidato.codigovaga,codigovaga)){
			ExibirCandidato(&candidato);
			printf("\n=======================================================================\n");
			pos=1;
			}
		}
		if(pos == 0){
			printf("Candidato(s) não encontrado(s)");
		}
	}
	printf("\n\n Pressione ENTER para voltar ao inicio.");
	fclose(arquivocan);
	getche();	
	cabecalhoCoo();	
	menucoordenador();	
}

void listarCandidatoAluno(matricula){
	BaseCandidato();
 	Candidato candidato;
 	InicializarCandidatos(&candidato);
 	
 	//char codigovaga[MAX];
 	int pos = 0, op,atingiu,erro=0;
	
	rewind(arquivocan);	
	while(!feof(arquivocan)){
		while(fread(&candidato, sizeof(Candidato), 1, arquivocan)){
			if(candidato.matriculaaluno != 0 && strstr(candidato.matriculaaluno,matricula)){
			ExibirCandidato(&candidato);
			printf("\n=======================================================================\n");
			pos=1;
			}
		}
		if(pos == 0){
			printf("Candidatura(s) não encontrada(s)");
		}
	}
	printf("\n\n Pressione ENTER para voltar ao inicio.");
	fclose(arquivocan);
	getche();	
	cabecalhoaln();	
	menualuno(matricula);	
}
