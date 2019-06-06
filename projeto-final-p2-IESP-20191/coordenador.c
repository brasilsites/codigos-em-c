/***************************************************
 * Coordenador: 		                                   *
 * Visualiza vagas, classifica aluno
 * Calculo da Média: 
 * parte escrita, entrevistas e análise de CRE
 * 
 * ************************************************/
/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
#include "coordenador.h"
#include "aluno.h"
#include "vagas.h"
#include "upload.h"

void BaseCoo(){ 
	Coordenador usu;
	arqcoordena=fopen(ARQ_USUARIO,"r+b"); //rb
	if (arqcoordena==NULL){
		arqcoordena = fopen(ARQ_USUARIO,"w+b"); //
				strcpy(usu.matricula,"1111");
				strcpy(usu.nome,"Admin");
				strcpy(usu.login,"admin");
				strcpy(usu.senha,"1234");
				strcpy(usu.tipo,"1");
				strcpy(usu.notacre,"0");
				fwrite(&usu, sizeof(Coordenador),1,arqcoordena);
				fclose (arqcoordena);
				//cabecalhoCoo();
				//loginCoordenador();
				printf("\n\nArquivo usuário criado, pressione qualquer tecla para voltar ao inicio");
	} 
	if (arqcoordena==NULL){	
		printf("Problema na abertura do arquivo");
	}
}
void InicializarCoordenador(Coordenador *usu){
	strcpy(usu->matricula,"");
	strcpy(usu->nome,"");
	strcpy(usu->login,"");
	strcpy(usu->senha,"");
	strcpy(usu->tipo,"1");
	strcpy(usu->notacre,"0");
}
void menucoordenador() {
	int opcao;
	
	do{
		cabecalhoCoo();
		printf(" 1 - Inserir Aluno\n");
		printf(" 2 - Listar Aluno\n");
		printf(" 3 - Alterar Aluno\n");
		printf(" 4 - Inserir Responsável Seleção\n");
		printf(" 5 - Listar Responsável Seleção\n");
		printf(" 6 - Remover Aluno\n");
		printf(" 7 - Inserir Vaga de Estagio\n");
		printf(" 8 - Listar Vagas de Estagio (todas)\n");
		printf(" 9 - Listar Candidatos por Vaga\n");
		printf(" 10 - Exportar Candidatos por vaga\n");
		printf(" 11 - Sair \n");
		printf(" Escolha uma opção: ");
		scanf("%i",&opcao);
		
		switch (opcao){
			case 1:
				cabecalhoCoo();
				cadastraAluno();
				break;
			case 2:
				cabecalhoCoo();
				listarAluno();
				break;
			case 3:
				cabecalhoCoo();
				alterarAluno();
				break;
			case 4:
				cabecalhoCoo();
				cadastraResponsavel();
				break;
			case 5:
				cabecalhoCoo();
				listarResponsavel();
				break;
			case 6:
				cabecalhoCoo();
				excluirAluno();
				break;
			case 7:
				cabecalhoCoo();
				cadastraVagas();
				break;
			case 8:
				cabecalhoCoo();
				listarVagas();
				break;
			case 9:
				cabecalhoCoo();
				listarCandidatoCoo();
				break;
			case 10:
				cabecalhoCoo();
				exporta();
				break;
			case 11:
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
		
	} while (opcao <12);
}

void menuResp(responsavel) {
	int opcao;
	do{
		cabecalhoResp();
		printf(" 1 - Listar Vagas (que sou responsavel)\n");
		printf(" 2 - Listar Candidatos\n");
		printf(" 3 - Classificar Candidatos \n");
		printf(" 4 - Sair\n");
		printf(" Escolha uma opção: ");
		scanf("%i",&opcao);
		
		switch (opcao){
			case 1:
				cabecalhoResp();
				listarVagasResp(responsavel);
				break;
			case 2:
				cabecalhoResp();
				listarCandidatoResp(responsavel);
				system("pause");
				break;
			case 3:
				cabecalhoResp();
				AlterarCandidato(responsavel);
				break;
			case 4:
				cabecalhoResp();
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
		
	}  while (opcao !=5);
}	
void cadastraResponsavel(){
	BaseCoo();
	Coordenador usu;
	InicializarCoordenador(&usu);
		do{
			cabecalhoprin();
			printf("------------------- Cadastro Responsável ------------------\n");
			fflush(stdin);	
			printf("Digite a matricula: ");
			gets(usu.matricula);
					
			fflush(stdin);	
			printf("Digite o nome: ");
			gets(usu.nome);

			fflush(stdin);	
			printf("Digite o login: ");
			gets(usu.login);	

			fflush(stdin);	
			printf("Digite a senha: ");
			gets(usu.senha);				
					
			strcpy(usu.tipo,"3");
			strcpy(usu.notacre,"0");
			
			fseek(arqcoordena, 0, SEEK_END);
			fwrite(&usu, sizeof(Coordenador),1,arqcoordena);
			
			printf("deseja continuar(s/n)?");
			
			
		}while (getche() == 's');
		fclose (arqcoordena);
}

void exibirResponsavel(Coordenador *resp){
	printf ("\n Matricula: %s", resp->matricula); 
 	printf("\n Nome: %s",resp->nome);
 	printf("\n Login: %s",resp->login);
}

void listarResponsavel(){
	BaseCoo();
	Coordenador resp;
		cabecalhoCoo();		
		while(fread(&resp,sizeof(Coordenador),1,arqcoordena)==1){
			if(strcmp("3",resp.tipo)==0){
				exibirResponsavel(&resp);
				printf("\n--------------------------------------------------------------------------------------\n");
			}
		}
		printf("Voltar ao menu principal? (s/n):");
		if (getche() == 's') {
			cabecalhoCoo();	
			menucoordenador();	
		}
	fclose (arqcoordena);
	getch(); //comando para pausar a tela
}

void cabecalhoCoo(){
	system("cls");
	printf("======================================================================================\n");
	printf("                         SISTEMA ESTAGIO - ADM IESP \n");
	printf("                         Login:admin - Senha:1234 \n");
	printf("======================================================================================\n\n");
} 
void cabecalhoResp(){
	system("cls");
	printf("======================================================================================\n");
	printf("                       SISTEMA ESTAGIO - Responsável IESP \n");
	printf("======================================================================================\n\n");
} 
