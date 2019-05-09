#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 30

typedef struct{
	char nome[MAX];
	char login[MAX];
	char senha[MAX];
}Login; 

void main() {
	setlocale(LC_ALL,"Portuguese");
	cabecalho();
	menu();
}

void cabecalho(){
	system("cls");
	printf("======================================================================================\n");
	printf("                                CABEÇALHO TESTE \n");
	printf("======================================================================================\n\n");
}
void menu(){
	int opcao;
	
	do{
		cabecalho();
		printf(" 1 - Login Aluno\n");
		printf(" 2 - Login Coordenador\n");
		printf(" 3 - Sair\n");
		printf(" Escolha uma opção: ");
		scanf("%i",&opcao);
		
		switch (opcao){
			case 1:
				system("cls");
				cabecalho();
				loginAluno();
				break;
			case 2:
				system("cls");
				cabecalho();
				loginCoordenador();
				break;
			case 3:
				system("cls");
				printf("Obrigado pela sua visita!\n");
				getch();
				exit(1);
				break;	
			default:
				printf("Opção Invalida\n");
				getch();
				break;	
		}
	} while (opcao !=3);
}

void loginAluno(){
	Login aluno;
	
	strcpy(aluno.nome, "Edson");
	strcpy(aluno.login, "edsonfsilva");
	strcpy(aluno.senha, "EFS1234");
	
	char loginaluno[MAX],senhaaluno[MAX];
	
	printf("Informe o login de aluno : ");
	scanf("%s",&loginaluno);
	printf("Informe a senha de aluno: ");
	scanf("%s",&senhaaluno);
	
	if ((strcmp (loginaluno,aluno.login) == 0) && (strcmp (senhaaluno,aluno.senha) == 0)){
		system("cls");
		cabecalho();
		printf("Login efetuado com sucesso! Bem vindo ao sistema %s \n Pressione qualquer tecla para voltar",aluno.nome);
		getch();
	} else{
		printf("ERRO ao efetuar login! \n Pressione qualquer tecla para voltar");
		getch();
	}
	
}
void loginCoordenador(){
	Login coordenador;
	
	strcpy(coordenador.nome, "Marcelo");
	strcpy(coordenador.login, "marcelofernandes");
	strcpy(coordenador.senha, "MF20191");
	
	char logincoordenador[MAX],senhacoordenador[MAX];
	
	printf("Informe o login de coordenador: ");
	scanf("%s",&logincoordenador);
	printf("Informe a senha de coordenador: ");
	scanf("%s",&senhacoordenador);
	
	if ((strcmp (logincoordenador,coordenador.login) == 0) && (strcmp (senhacoordenador,coordenador.senha) == 0)){
		system("cls");
		cabecalho();
		printf("Login efetuado com sucesso! Bem vindo ao sistema %s \n Pressione qualquer tecla para voltar",coordenador.nome);
		getch();
	} else{
		printf("ERRO ao efeturar login! \n Pressione qualquer tecla para voltar");
		getch();
	}	
}
