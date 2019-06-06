/***************************************************
 * Vagas: 		                                   *
 * As vagas serão cadastradas pelo Coordenador, com
 * status=0, quanto o quantitativo de vagas atingir o
 * limite, esse status mudar para 1 - Finalizado
 * Os alunos fazem a candidatura e ficam cadastrados no
 * arquivo candidatovaga, o coordenador visualiza a 
 * candidatura e insere os pontos referentes a parte
 * escrita, entrevistas. O sistema soma a análise de CRE
 * cria uma média e adiciona no resultado no arquivo
 * candidatovaga. Se o aluno atingir a média,
 * automaticamente o sistema adiciona +1 ao quantitativo
 * de vagas ocupadas.
 * ************************************************/
 
#include "vagas.h"
#include "aluno.h"
#include "candidatos.h"

void BaseVagas(){ 
	arqvagas = fopen(ARQ_VAGA, "r+b"); // Abre o arquivo binário
	if(arqvagas ==NULL){
        arqvagas = fopen(ARQ_VAGA, "w+b"); //Cria o arquivo binário
        if(arqvagas==NULL){
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
 }
void ExibirVagas(Vagas *vaga){
	printf("Codigo da vaga: %s\n",vaga->codigovaga);
	printf("Empresa: %s\n",vaga->nomeempresa);
	printf("Carga Horaria: %sh\n",vaga->cargahoraria);
	printf("Numero de vagas: %s\n",vaga->numerovagas);
	printf("Vagas ocupadas: %s\n",vaga->vagasocupadas);
	printf("Pontuação mínima: %s\n",vaga->pontuacaominima);
	printf("Remuneração: R$ %s\n",vaga->salario);
	printf("Responsável: %s\n",vaga->responsavel);
	if(strcmp("0",vaga->status)==0){
		printf("Status: Ativo\n");
	} else{
		printf("Status: Encerrada\n");
	}
 }
 
void InicializarVagas(Vagas *vaga){
	strcpy(vaga->codigovaga,"");
	strcpy(vaga->nomeempresa,"");
	strcpy(vaga->cargahoraria,"0");
	strcpy(vaga->numerovagas,"0");
	strcpy(vaga->vagasocupadas,"0");
	strcpy(vaga->pontuacaominima,"0");
	strcpy(vaga->salario,"0");
	strcpy(vaga->responsavel,"0");
	strcpy(vaga->status,"0");
}

void listarVagas(){
	BaseVagas();
	Vagas vaga;	

	while(fread(&vaga,sizeof(Vagas),1,arqvagas)==1){
		ExibirVagas(&vaga);
		printf("--------------------------------------------------------------------------------------\n\n");
	}
		//,getch();
	printf("Pressione qualquer tecla para voltar ao menu principal\n\n");
	fclose (arqvagas);
	getch(); //comando para pausar a tela
}

void listarVagasResp(responsavel){
	BaseVagas();
	Vagas vaga;	

	while(fread(&vaga,sizeof(Vagas),1,arqvagas)==1){
		if(vaga.responsavel != 0 && strstr(vaga.responsavel,responsavel)){
		ExibirVagas(&vaga);
		printf("--------------------------------------------------------------------------------------\n\n");			
		}
	}
		//,getch();
	printf("Pressione qualquer tecla para voltar ao menu principal\n\n");
	fclose (arqvagas);
	getch(); //comando para pausar a tela
}

void cadastraVagas(){
	BaseVagas();
	Vagas vaga;
	InicializarVagas(&vaga);
	
		do{
			fflush(stdin);	
			printf("\nDigite o codigo da vaga: ");
			gets(vaga.codigovaga);
			
			fflush(stdin);	
			printf("Digite o nome da empresa: ");
			gets(vaga.nomeempresa);
			
			fflush(stdin);	
			printf("Digite a carga horária: ");
			//scanf("%s",&vaga.cargahoraria);
			gets(vaga.cargahoraria);
			
			fflush(stdin);	
			printf("Digite o numero de vagas: ");
			//scanf("%s",&vaga.numerovagas);
			gets(vaga.numerovagas);
			
			strcpy(vaga.vagasocupadas,"0");
			
			fflush(stdin);	
			printf("Digite a pontuação mínima: ");
			//scanf("%s",&vaga.pontuacaominima);
			gets(vaga.pontuacaominima);
			
			fflush(stdin);	
			printf("Digite o salário: ");
			gets(vaga.salario);
			
			fflush(stdin);	
			printf("Digite o responsável: ");
			gets(vaga.responsavel);
			
			strcpy(vaga.status,"0");
			
			fseek(arqvagas, 0, SEEK_END);
			fwrite(&vaga, sizeof(Vagas),1,arqvagas);
			
			printf("\n--------------------------------------------------------------------------------------\n");
			printf("deseja cadastrar nova vaga(s/n)?");			
			
		}	while (getche() == 's');
		fclose (arqvagas);
}

int BuscarVagas(codigovaga){
	BaseVagas();
	Vagas vaga;
	InicializarVagas(&vaga);
	int posi = 0, linha = 0,op;
	
	rewind(arqvagas);	
	while(!feof(arqvagas)){
		while(fread(&vaga, sizeof(Vagas), 1, arqvagas)){
				//realiza os comparativos
			    if(vaga.codigovaga != 0 && strstr(vaga.codigovaga,codigovaga)){
			    	//informa se achou o registro
			    	posi = 1;
			    	return linha;
				}
				linha++;
		}
			if(posi == 0){
				printf("Registro não encontrado");
			}	
	}fclose(arqvagas);
}

void validaVagas(char *codigovaga[],char *codigoaluno[],float *media){
	BaseVagas();
	Vagas vaga;
	
	InicializarVagas(&vaga);
	int pos = 0, linha = 0,op;
	
	rewind(arqvagas);	
	while(!feof(arqvagas)){
		while(fread(&vaga, sizeof(Vagas), 1, arqvagas)){
				//realiza os comparativos
			    if(vaga.codigovaga != 0 && strstr(vaga.codigovaga,codigovaga)){
			    	
			    	ExibirVagas(&vaga);
			    	//informa se achou o registro
					printf(&vaga.pontuacaominima);
					if (atof(vaga.pontuacaominima)<=*media){
						printf("\nA pontuação minima da vaga Atingida é: %f e o ponto atingido é de: %.2f",vaga.pontuacaominima,*media);
					} else{
						printf("\nA pontuação minima da vaga Não atingida é: %.2f e o ponto atingido é de: %.2f",vaga.pontuacaominima,*media);
					}				
					
					pos = 1;
				}
				linha++;
		}
			if(pos == 0){
				printf("Registro não encontrado");
			}	
	}fclose(arqvagas);

	//se a media for>= pontuacaominima
		//verifica se a quantidade de vagas ocupadas é menor que o numero de vagas
			//caso positivo, incrementa +1 a vagas ocupadas
			//busca o codigodoaluno no arquivo, altera o status do aluno para Aprovado
		//Verifica, após incrementar +1 a vagas ocupadas, se a quantidade de vagas ocupadas é igual ao numero de vagas
			//caso positivo, altera o status da vaga para Encerrada
	//Senão, o candidato não atingiu a média, e foi reprovado
			//busca o codigodoaluno no arquivo, altera o status do aluno para Reprovado
}

//Candidatar-se a uma vaga
void candidatarVaga(matricula){
	BaseVagas();
	Vagas vaga;
	
	//Aluno aluno;
	//InicializarVagas(&vaga);
	//InicializarAluno(&usu);
	char codigovaga[MAX];
	//matricula=aluno->matricula;
	int pos = 0, linha = 0,poscan=0,op;
	
	rewind(arqvagas);
	while(!feof(arqvagas)){	
	
	fflush(stdin);//limpa o buffer do teclado
	printf("Digite o codigo da vaga:");
	gets(codigovaga);
	//pesquisarCandidato(&vaga);
	
	while(fread(&vaga,sizeof(Vagas),1,arqvagas)==1){
		if(strcmp(codigovaga,vaga.codigovaga)==0){
			ExibirVagas(&vaga);	
		pos = 1;
		if(strcmp("1",vaga.status)==0){
			printf("\n\n Candidatura(s) encerrada(s), tente outra vaga.");
			break;	
		}
		//Compara se o canditato já se candidatou
		else{
				
			//Abre o aquivo
			BaseCandidato();
			//Estrutura de produto
 			Candidato candidato;

			//verifica se o aluno ja se candidatou a vaga
			rewind(arquivocan);
				while(!feof(arquivocan)){	
					fflush(stdin);
					while(fread(&candidato,sizeof(Candidato),1,arquivocan)==1){
						if((strcmp(matricula,candidato.matriculaaluno)==0)&&(strcmp(vaga.codigovaga,candidato.codigovaga)==0)) {	
						poscan = 1;
						}
					}	
				}

				if (poscan==1){
					printf("Candidatura ja efetuada anteriormente, pressione qualquer tecla para voltar ao menu principal.");
					getch();
					menualuno();
					
				}
				else {
			printf("\n\n confirma a candidatura(s/n)?");
				if (getche() == 's'){
									
					strcpy(candidato.codigovaga,vaga.codigovaga);
					strcpy(candidato.matriculaaluno,matricula);
					strcpy(candidato.notaescrita,"0");
					strcpy(candidato.notaentrevista,"0");
					strcpy(candidato.media,"0");
					strcpy(candidato.status,"0");
					
					fseek(arquivocan, 0, SEEK_END);
					if(fwrite(&candidato, sizeof(Candidato),1,arquivocan)){
						printf("\n\n Candidatura cadastrada com sucesso!");
					} else{
						printf("\n\n Candidatura não efetuada!");
					}
					
					fclose(arquivocan);
				}
				else{
					printf("\n\n Candidatura cancelada! Pressione ENTER para sair.");
					getche();	
				}
				//manda a posicao do registro no arquivo para exclusao e alteracao
				//return linha;			
			}
				}
			//linha++;
		}//Fim do else (strcmp vaga->status
	}	
	if(pos == 0){
		printf("Vaga não encontrada");
	}
		//printf("\n\n Pressione ENTER para continuar.");
		getche();
		break;	
	}
	fclose(arqvagas);
	
}
