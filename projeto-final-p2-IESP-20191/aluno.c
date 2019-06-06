/***************************************************
 * Aluno: 		                                   *
 * Visualiza vagas, candidatar-se a uma vaga,
 * Calculo da Média: 
* parte escrita, entrevistas e análise de CRE
 * ************************************************/
 
#include "aluno.h"
#include "vagas.h"
#include "upload.h"

//Comando para inicializar, verificando se o arquivo já existe, caso negativo cria o arquivo
void BaseAluno(){ 
	arquivoaluno = fopen(ARQ_USUARIO, "r+b"); // Abre o arquivo binário
	if(arquivoaluno ==NULL){
        arquivoaluno = fopen(ARQ_USUARIO, "w+b"); //Cria o arquivo binário
        if(arquivoaluno==NULL){
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
 }
 
 //Comando para inicializar o aluno
 void inicializarAluno(Aluno *aluno){
	strstr(aluno->matricula,""); //procura um valor passado por parâmetro num texto, se encontrar mostra o resto
	strstr(aluno->nome,"");
	strstr(aluno->login,"");
	strstr(aluno->senha,"");
	strstr(aluno->tipo,"2");
	strstr(aluno->notacre,"0");
}
void exibirAluno(Aluno *aluno){
	printf ("\n Matricula: %s", aluno->matricula); 
 	printf("\n Nome: %s",aluno->nome);
 	printf("\n Login: %s",aluno->login);
 	printf("\n Nota CRE: %s",aluno->notacre);
}

void cadastraAluno(){
	BaseAluno();
	Aluno aluno;
	inicializarAluno(&aluno);
		do{
			cabecalhoprin();
			fflush(stdin);	
			printf("Digite a matricula: ");
			gets(aluno.matricula);
					
			fflush(stdin);	
			printf("Digite o nome: ");
			gets(aluno.nome);			
			
			fflush(stdin);	
			printf("Digite o login: ");
			gets(aluno.login);	
			
			fflush(stdin);	
			printf("Digite a senha: ");
			gets(aluno.senha);
			
			strcpy(aluno.tipo,"2");
			//aluno.tipo=2;
			
			fflush(stdin);	
			printf("Digite o CRE: ");
			//scanf("%f",&aluno.notacre);
			gets(aluno.notacre);
			
			fseek(arquivoaluno, 0, SEEK_END);
			fwrite(&aluno, sizeof(Aluno),1,arquivoaluno);
			
			printf("deseja continuar(s/n)?");
			
			
		}while (getche() == 's');
		fclose (arquivoaluno);
}

void listarAluno(){
	BaseAluno();
	Aluno aluno;
	if (arquivoaluno==NULL){
		printf("Problema na abertura do arquivo");
	} else {
		fflush(stdin);//limpa o buffer do teclado
		
		cabecalhoprin();		
		while(fread(&aluno,sizeof(Aluno),1,arquivoaluno)==1){
			if(strcmp("2",aluno.tipo)==0){
				exibirAluno(&aluno);
				printf("\n--------------------------------------------------------------------------------------\n");
			}
		}
		//,getch();
		printf("Voltar ao menu principal? (s/n):");
		if (getche() == 's') {
			cabecalhoCoo();	
			menucoordenador();	
		}
	}
	fclose (arquivoaluno);
	getch(); //comando para pausar a tela
}

int PesquisarAluno(matricula){
	BaseAluno();
	Aluno aluno;
	inicializarAluno(&aluno);
	int posi = 0, linha = 0,op;
	
	rewind(arquivoaluno);
	while(!feof(arquivoaluno)){	
			
	while(fread(&aluno,sizeof(Aluno),1,arquivoaluno)==1){
		if(strcmp(matricula,aluno.matricula)==0){
		posi = 1;
		return linha;				
		}
		linha++;
	}
	getch();
	if(posi == 0){
		printf("Registro não encontrado");
	}		
		break;	
	}
	fclose(arquivoaluno);
}

int alterarAluno(){
	BaseAluno();
	Aluno aluno;
	
	inicializarAluno(&aluno);
	char matricula[30];
	int pos=0,linha=0,op;
	
	system("cls");
	cabecalhoCoo();
	
	fflush(stdin);//limpa o buffer do teclado
	printf("Digite a matricula a pesquisar:");
	gets(matricula);
	pos = PesquisarAluno(matricula);
	fseek(arquivoaluno,pos*sizeof(Aluno),SEEK_SET);

	while(fread(&aluno,sizeof(Aluno),1,arquivoaluno)==1){

		if(strcmp(matricula,aluno.matricula)==0){
			exibirAluno(&aluno);

		printf("\n 1 - MATRICULA  2 - NOME  3 - LOGIN  4 - SENHA  5 - CRE  6 - SALVAR   7-SAIR\n");
		scanf("%i", &op);					
			
			if(op == 1){
				printf("Matricula: ");
				fflush(stdin);
				//fgets(usu.matricula, MAX, stdin); //
				scanf("%s",aluno.matricula);
				printf("6 - SALVAR  7 - SAIR: ");
				scanf("%i", &op);
			}
			if(op == 2){
				printf("Nome: ");
				fflush(stdin);
				scanf("%s",aluno.nome);
				printf("6 - SALVAR  7 - SAIR: ");
				scanf("%i", &op);
			}
			if(op == 3){
				printf("Login: ");
				fflush(stdin);
				scanf("%s",aluno.login);
				printf("6 - SALVAR  7 - SAIR: ");
				scanf("%i", &op);
			}
			if(op == 4){
				printf("Senha: ");
				fflush(stdin);
				scanf("%s",aluno.senha);
				printf("6 - SALVAR  7 - SAIR: ");
				scanf("%i", &op);
			}
			if(op == 5){
				printf("CRE: ");
				fflush(stdin);
				scanf("%s",aluno.notacre);
				printf("6 - SALVAR  7 - SAIR: ");
				scanf("%i", &op);
			}
			
			if(op == 6){

				fseek(arquivoaluno,pos*sizeof(Aluno),SEEK_SET);
		        if(fwrite(&aluno,sizeof(Aluno),1,arquivoaluno) != 1){
		        	printf("\n Falha ao Alterar o Aluno!\n");
		        	printf("\n\n Pressione ENTER para continuar.");
					getche();
		        	//break;
				}else{
					printf("\n Registro alterado com sucesso!\n");
					printf("\n\n Pressione ENTER para voltar ao inicio.");
					getch();
					system("cls");
					fclose(arquivoaluno);	
					cabecalhoCoo();
					menucoordenador();	
				}
					
			}
			if(op == 7){
		    	printf("\n SAINDO \n");
		    	system("cls");
		    	getch();
				exit(1);
			}
		} 
			if(pos == 0){
		printf("Registro não encontrado");
			}
		printf("\n\n Pressione ENTER para continuar.");
		getche();
			
		//break;	
	//}
	fclose(arquivoaluno);	
	}
}

int excluirAluno(){
	BaseAluno();
	Aluno aluno;
	
	inicializarAluno(&aluno);
	char matricula[30];
	int pos=0,linha=0,op;
	
	cabecalhoCoo();
	
	fflush(stdin);//limpa o buffer do teclado
	printf("Digite a matricula a excluir:");
	gets(matricula);
	pos = PesquisarAluno(matricula);
	fseek(arquivoaluno,pos*sizeof(Aluno),SEEK_SET);

	if(fread(&aluno,sizeof(Aluno),1,arquivoaluno)==1){

		if(strcmp(matricula,aluno.matricula)==0){
			exibirAluno(&aluno);
		
		printf("\n 1 - EXCLUIR   2 - SAIR\n");
		printf("Digite a opção: ");
		scanf("%i", &op);					
		
			if(op == 1){
			strcpy(aluno.matricula,""); 
			strcpy(aluno.nome,"");
			strcpy(aluno.login,"");
			strcpy(aluno.senha,"");
			strcpy(aluno.tipo,"");
			strcpy(aluno.notacre,"");	
				
				fseek(arquivoaluno,pos*sizeof(Aluno),SEEK_SET);
		        if(fwrite(&aluno,sizeof(Aluno),1,arquivoaluno) != 1){
		        	printf("\n Falha ao Excluir o Aluno!\n");
		        	printf("\n\n Pressione ENTER para sair.");
					getche();
		        	//break;
				}else{
					printf("\n Aluno excluido com sucesso!\n");
					printf("\n\n Pressione ENTER para voltar ao inicio.");
					getch();
					system("cls");
					fclose(arquivoaluno);	
					cabecalhoCoo();
					menucoordenador();	
				}
					
			}
			if(op == 7){
		    	printf("\n SAINDO \n");
		    	system("cls");
		    	getch();
				exit(1);
			}
		} 
			if(pos == 0){
		printf("Registro não encontrado");
			}
		printf("\n\n Pressione ENTER para continuar.");
		getche();
			
		//break;	
	//}
	fclose(arquivoaluno);	
	}
}

void menualuno(matricula) {
	int opcao;
	do{
		cabecalhoaln();
		printf(" 1 - Listar Vagas\n");
		printf(" 2 - Candidatar Vaga\n");
		printf(" 3 - Listar Candidaturas\n");
		printf(" 4 - Upload Curriculum\n");
		printf(" 5 - Sair\n");
		printf(" Escolha uma opção: ");
		scanf("%i",&opcao);
		
		switch (opcao){
			case 1:
				cabecalhoaln();
				listarVagas();
				system("pause");
				break;
			case 2:
				cabecalhoaln();
				candidatarVaga(matricula);
				system("pause");
				break;
			case 3:
				cabecalhoaln();
				listarCandidatoAluno(matricula);
				system("pause");
				break;
			case 4:
				cabecalhoaln();
				upload(matricula);
				system("pause");
				break;
			case 5:
				system("cls");
				cabecalhoprin();
				printf("Acesso finalizado! clique para voltar ao menu principal\n");
				getch();
				system("cls");
				cabecalhoprin();
				menuprin();
				break;
			default:
				printf("Opção Invalida\n");
				getch();
				break;
		}
		
	} while (opcao <6);
}


void cabecalhoaln(){
	system("cls");
	printf("======================================================================================\n");
	printf("                         SISTEMA ESTAGIO - ALUNO IESP \n");
	printf("======================================================================================\n\n");
}
