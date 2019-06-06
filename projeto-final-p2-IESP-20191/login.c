#include "login.h"
#include "aluno.h"
#include "coordenador.h"

void login(char tipo[MAX]){
	BaseCoo();
	BaseAluno();
	Aluno aluno;
	
	char login[MAX];//,tipo[MAX]
	int pos = 0, linha = 0,op,senha=0;
	
	
		if (strcmp("1",tipo)==0){
			cabecalhoCoo();	
		} else if (strcmp("2",tipo)==0){
			cabecalhoaln();
		} else if (strcmp("3",tipo)==0){
			cabecalhoResp();
		}
	rewind(arquivoaluno);
	while(!feof(arquivoaluno)){	
	
	fflush(stdin);//limpa o buffer do teclado
	printf(" Login:");
	gets(login);

	senha=validasenha();
	
	while(fread(&aluno,sizeof(Aluno),1,arquivoaluno)==1){
		if((strcmp(login,aluno.login)==0)&&(senha==1)&&(strcmp(tipo,aluno.tipo)==0)){ //
			pos = 1;
			if (strcmp("1",tipo)==0){
				menucoordenador();	
			} else if (strcmp("2",tipo)==0){
				menualuno(aluno.matricula);
			} else if (strcmp("3",tipo)==0){
				menuResp(aluno.matricula);
			}
		}	
	}
	if(pos == 0){
		printf("\n\nRegistro não encontrado! erro de login/senha ");
	}
		printf("\n Pressione ENTER para voltar ao menu.");
		getche();
		cabecalhoaln();
		break;	
	}
	fclose(arquivoaluno);
}

int validasenha(){
	BaseCoo();
	Coordenador usuario;
    char buffer[256] = {0};
    //char password[] = "password";
    char c;
    int pos = 0;
    
    fflush (stdin);
	printf("%s","Digite a senha: ");
    do {
        c = getch();
        
        if( isprint(c) ) 
        {
            buffer[ pos++ ] = c;
            printf("%c", '*');
        }
        else if( c == MAX && pos )
        {
            buffer[ pos-- ] = '\0';
            printf("%s", "\b \b");
        }
    } while( c != 13 );
    
    while(fread(&usuario,sizeof(Coordenador),1,arqcoordena)==1){
		if(strcmp(buffer,usuario.senha)==0){ //&&(aluno.tipo==2)
			return (1);
		}
		else{
			return (2);
		}
	}
}
