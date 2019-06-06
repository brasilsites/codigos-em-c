// ==========================================================
//  	             IESP FACULDADE                                             
// ==========================================================
//  ---------------------------------------------------------
// - Sistema para cadastro/candidatura de estagio.                           -
//  ---------------------------------------------------------
//  - Autor: Edson Ferreira da Silva                             -
//  - Data: 01/05/2019                                      -
//  ---------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include "login.h"

void main() {
	system("color 1F");
	setlocale(LC_ALL,"Portuguese");
	SetConsoleTitle("Sistema - Estagio - IESP Faculdades");
	
	cabecalhoprin();
	menuprin();
}

void menuprin(){
	int opcao;
		cabecalhoprin();
	do{
		
		printf(" 1 - Login Aluno\n");
		printf(" 2 - Login Coordenador\n");
		printf(" 3 - Login Responsável\n");
		printf(" 4 - Sair\n");
		printf(" Escolha uma opção: ");
		scanf("%i",&opcao);
		
		switch (opcao){
			case 1:
				system("cls");
				login("2");
				break;
			case 2:
				system("cls");
				login("1");
				break;
			case 3:
				system("cls");
				login("3");
				break;
			case 4:
				system("cls");
				cabecalhoprin();
				printf("Obrigado pela sua visita!\n");
				getch();
				exit(1);
				break;
			default:
				printf("Opção Invalida\n");
				getch();
				break;
		}
		
	} while (opcao !=5);
}
void cabecalhoprin(){
	system("cls");
	printf("======================================================================================\n");
	printf("                         SISTEMA ESTAGIO IESP \n");
	printf("======================================================================================\n\n");
} 

