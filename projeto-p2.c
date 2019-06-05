#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <string.h>

#define MAX 100
#define MIN 50

typedef struct {
    char matricula[MIN];
    char nome[MAX];
    char login[MIN];
    char senha[MIN];
    float notacre;
} Aluno;

typedef struct {
    char codigoCoo[MIN];
    char nomeCoo[MIN];
    char loginCoo[MIN];
    char senhaCoo[MIN];
} Coordenador;
Coordenador coo[5];

typedef struct {
    char codigovaga[MIN];
    char empresa[MAX];
    float pontuacao;
    int qtdvagas;
	int vagasocupadas;
	int status; //0-Ativo - 1-Finalizada
} Vaga;

typedef struct {
    char codigovaga[MIN];
    char matricula[MAX];
    float notaescrita;
	float notaentrevista;
	float media;	
	int status; //0-Ativo - 1-Finalizada
} Candidato;

Aluno aluno[100];
int i,op,total=0;
Vaga vaga[100];
int v,totalvaga=0;
Candidato candidato[100];
int c,totalcandi=0;

char matricula[MIN],codigovaga[MIN];

 void inicializarCoordenador(){
	strcpy(coo[1].codigoCoo,"MAR2019");
	strcpy(coo[1].nomeCoo,"Marcelo");
	strcpy(coo[1].loginCoo,"marcelo");
	strcpy(coo[1].senhaCoo,"1234");
}

void main(){
	setlocale(LC_ALL,"portuguese");
	menugeral();	
}

void menugeral() {
	int op;
	do{
		cabecalho();
		printf(" 1 - Login aluno\n");
		printf(" 2 - Login coordenador\n");
		printf(" 3 - Sair\n");
		printf(" Escolha uma opção: ");
		scanf("%i",&op);
		
		switch (op){
			case 1:
				system("cls");
				cabecalho();
				loginAluno();
				system("pause");
				break;
			case 2:
				system("cls");
				cabecalho();
				loginCoordenador();
				system("pause");
				break;
			case 3:
				system("cls");
				//cabecalhoprin();
				printf("Acesso finalizado! clique para voltar ao menu principal\n");
				getch();
				system("cls");
				//cabecalhoprin();
				//menuprin();
				break;
			default:
				printf("Opção Invalida\n");
				getch();
				break;
		}
		
	} while (op <6);
}

void menuCoordenador() {
	int op;
	do{
		cabecalho();
		printf(" 1 - Cadastrar Aluno\n");
		printf(" 2 - Cadastrar vaga\n");
		printf(" 3 - Listar vagas\n");
		printf(" 4 - Listar Candidato\n");
		printf(" 5 - Classificar Candidato\n");
		printf(" 6 - Logout\n");
		printf(" Escolha uma opção: ");
		scanf("%i",&op);
		
		switch (op){
			case 1:
				system("cls");
				cabecalho();
				cadastraAluno();
				system("pause");
				break;
			case 2:
				system("cls");
				cabecalho();
				cadastraVaga();
				break;
			case 3:
				system("cls");
				cabecalho();
				listarVaga();
				break;
			case 4:
				system("cls");
				cabecalho();
				listarCandidatos();
				break;
			case 5:
				system("cls");
				cabecalho();
				avaliarCandidato();
				break;				
			case 6:
				system("cls");
				menugeral();
				break;
			default:
				printf("Opção Invalida\n");
				getch();
				break;
		}
		
	} while (op <6);
}

void menuAluno(matricula) {
	int op;
	do{
		cabecalho();
		printf(" 1 - Listar vagas\n");
		printf(" 2 - Candidatar Vaga\n");
		printf(" 3 - Consultar resultados\n");
		printf(" 4 - Logout\n");
		printf(" Escolha uma opção: ");
		scanf("%i",&op);
		
		switch (op){
			case 1:
				system("cls");
				cabecalho();
				listarVaga();
				break;
			case 2:
				system("cls");
				cabecalho();
				candidatarVaga(matricula);
				break;
			case 3:
				system("cls");
				cabecalho();
				listarVaga();
				break;
			case 4:
				system("cls");
				menugeral();
				break;
			default:
				printf("Opção Invalida\n");
				getch();
				break;
		}
		
	} while (op <6);
}
	
void loginCoordenador(){
	inicializarCoordenador();
	
	char login[MIN],senha[MIN];
	fflush (stdin);
	printf("%s","  Digite o login: ");
	gets(login);
	fflush (stdin);
	printf("%s","  Digite a senha: ");
	gets(senha);
	if((strcmp(login,coo[1].loginCoo)==0)&&(strcmp(senha,coo[1].senhaCoo)==0)){ //
		menuCoordenador();
	} else{
		printf("  Erro de login!\n");
	} 		
}

void loginAluno(){
	char login[MIN],senha[MIN];
	fflush (stdin);
	printf("%s","  Digite o login: ");
	gets(login);
	fflush (stdin);
	printf("%s","  Digite a senha: ");
	gets(senha);

	for (i=0;i<total;i++){
		if((strcmp(login,aluno[i].login)==0)&&(strcmp(senha,aluno[i].senha)==0)){ //
			menuAluno(aluno[i].matricula);
		} else{
			printf("  Erro de login!\n");
		} 		
	}
}

void cadastraAluno(){
	do{
		fflush(stdin);
   		printf("\n\n Digite a matrícula do aluno: ");
   		gets(aluno[total].matricula);
   		fflush(stdin);
   		printf(" Digite o nome do aluno: ");
   		gets(aluno[total].nome);
   		fflush(stdin);
   		printf(" Digite o login do aluno: ");
   		gets(aluno[total].login);
   		fflush(stdin);
   		printf(" Digite a senha do aluno: ");
   		gets(aluno[total].senha);
	 	fflush(stdin);
	 	printf(" Digite o CRE do aluno: ");
	 	scanf("%f",&aluno[total].notacre);
  		printf(" \n ------------------------------------------------------------------------\n");

		printf("deseja cadastrar um novo aluno(s/n)?");		
		total++;
	}while (getche() == 's');	
}

void cadastraVaga(){
	do{
		fflush(stdin);
   		printf("\n\n Digite o código da vaga: ");
   		gets(vaga[totalvaga].codigovaga);
   		fflush(stdin);
   		printf(" Digite o nome da empresa: ");
   		gets(vaga[totalvaga].empresa);
   		fflush(stdin);
   		printf(" Digite a pontuação mínima: ");
   		scanf("%f",&vaga[totalvaga].pontuacao);
   		fflush(stdin);
   		printf(" Digite a quantidade de vagas: ");
   		scanf("%i",&vaga[totalvaga].qtdvagas);
		vaga[totalvaga].vagasocupadas=0; // Inicia com 0 vagas ocupadas
		vaga[totalvaga].status=0; //Inicia com status 0 (Em aberto)
  		printf(" \n ------------------------------------------------------------------------\n");

		printf("deseja cadastrar uma nova vaga(s/n)?");	
		totalvaga++;
	}while (getche() == 's');	
}

void listarVaga(){
	for (v=0;v<totalvaga;v++){
		printf(" Código da Vaga: %s\n",vaga[v].codigovaga);
		printf(" Empresa: %s\n",vaga[v].empresa);
		printf(" Pontuação mínima: %.2f\n",vaga[v].pontuacao);
		printf(" Quantidade de vagas: %i\n",vaga[v].qtdvagas);
		printf(" Vagas ocupadas: %i\n",vaga[v].vagasocupadas);
		switch (vaga[v].status){
			case 0:
				printf(" Status: Ativo\n");
				break;
			case 1:
				printf(" Status: Encerrado\n");
				break;
		}
		printf(" \n ------------------------------------------------------------------------\n");
	}
	getch();
}

void achaVaga(codigovaga,codigoaluno){
	for (v=0;v<totalvaga;v++){
		if((strcmp(codigovaga,vaga[v].codigovaga)==0)){
		printf(" Código da Vaga: %s\n",vaga[v].codigovaga);
		printf(" Empresa: %s\n",vaga[v].empresa);
		printf(" Pontuação mínima: %.2f\n",vaga[v].pontuacao);
		printf(" Quantidade de vagas: %i\n",vaga[v].qtdvagas);
		printf(" Vagas ocupadas: %i\n",vaga[v].vagasocupadas);
			switch (vaga[v].status){
				case 0:
					printf(" Status: Ativo\n");
					printf(" \n\n Confirma a candidatura(s/n): ");
					if (getche() == 's'){
						strcpy(candidato[totalcandi].codigovaga,codigovaga);
						strcpy(candidato[totalcandi].matricula,codigoaluno);
						candidato[totalcandi].notaescrita=0;
						candidato[totalcandi].notaentrevista=0;
						candidato[totalcandi].media=0;
						candidato[totalcandi].status=0;
						totalcandi++;
						printf(" \n Candidatura inserida com sucesso! \n");
					}
					break;
				case 1:
					printf(" Status: Encerrado\n");
					break;
			}
		} 
	}
	getch();
}

void listarCandidatos(){
	char codigodavaga[MAX];
	fflush(stdin);
	printf(" Informe o código da Vaga: ");
	gets(codigodavaga);
	
	for (c=0;c<totalcandi;c++){
		if((strcmp(codigodavaga,candidato[c].codigovaga)==0)){
		printf(" Matricula Aluno: %s\n",candidato[c].matricula);
		printf(" Nota Escrita: %.2f\n",candidato[c].notaescrita);
		printf(" Nota Entrevista: %.2f\n",candidato[c].notaentrevista);
		printf(" Media: %.2f\n",candidato[c].media);
			switch (candidato[c].status){
				case 0:
					printf(" Status: Aguardando\n");	
					break;
				case 1:
					printf(" Status: Aprovado!\n");
					break;
				case 2:
					printf(" Status: Reprovado!\n");
					break;
			}
		printf(" \n ------------------------------------------------------------------------\n");			
		}
	}
	getch();
}

void candidatarVaga(codigoaluno){
	char codigodavaga[MAX];
	fflush(stdin);
	printf(" Informe o código da Vaga: ");
	gets(codigodavaga);
	
	achaVaga(codigodavaga,codigoaluno);
}

void achaCandidato(codigovaga,codigoaluno){
	float media=0;
	for (c=0;c<totalcandi;c++){
		if((strcmp(codigovaga,candidato[c].codigovaga)==0)&&(strcmp(codigoaluno,candidato[c].matricula)==0)){
		printf(" Código da Vaga: %s\n",candidato[c].codigovaga);
		printf(" Matricula Aluno: %s\n",candidato[c].matricula);
		printf(" Nota Escrita: %.2f\n",candidato[c].notaescrita);
		printf(" Media: %.2f\n",candidato[c].media);
			switch (candidato[c].status){
				case 0:
					printf(" Status: Aguardando\n");
					printf(" \n\n Classificar candidato(s/n): ");
					if (getche() == 's'){
						fflush(stdin);
						printf("\n Informe a nota escrita: ");	
						scanf("%f",&candidato[c].notaescrita);
						fflush(stdin);
						printf("\n Informe a nota da entrevista: ");	
						scanf("%f",&candidato[c].notaentrevista);
						
							for (i=0;i<total;i++){
								if(strcmp(codigoaluno,aluno[i].matricula)==0){
									media=(aluno[i].notacre+candidato[c].notaescrita+candidato[c].notaentrevista)/3;
									candidato[c].media=media;
								}
							}
							for (v=0;v<totalvaga;v++){
								if (vaga[v].pontuacao<=candidato[c].media){
									if(strcmp(candidato[c].codigovaga,vaga[v].codigovaga)==0){
											vaga[v].vagasocupadas++;
										if(vaga[v].vagasocupadas==vaga[v].qtdvagas){
											vaga[v].status=1;	
										}
									}
								candidato[c].status=1;
								printf(" Candidato aprovado com sucesso! Voltar ao menu");
								}
								else {
									candidato[c].status=2;
									printf(" Candidato não atingiu a média e foi Reprovado! \n");
								}										
							} 
											
					}
					break;
				case 1:
					printf(" Status: Aprovado!\n");
					break;
				case 2:
					printf(" Status: Reprovado!\n");
					break;
			}
		} 
	}
	getch();
}

void avaliarCandidato(){
	char codigovaga[MIN],codigocandidato[MIN];
	fflush(stdin);
	printf(" Informe o código da Vaga: ");
	gets(codigovaga);	
	fflush(stdin);
	printf(" Informe o código do candidato: ");
	gets(codigocandidato);	
	
	achaCandidato(codigovaga,codigocandidato);	
}
void cabecalho(){
	system("cls");
	printf("======================================================================================\n");
	printf("                         SISTEMA ESTAGIO - GERAL \n");
	printf("======================================================================================\n\n");
}
