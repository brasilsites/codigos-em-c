#include <stdio.h>
#include <string.h>

void main(){
	char login[50],senha[50],senhacorreta[50]="1234";
	int password=0;
	
	//O login pode ser qualquer um, é apenas um teste
	fflush (stdin);
	printf("Digite o login : ");
	scanf(&login);
	
	password=validasenha(senhacorreta);
	if (password==1){
		printf("\n\nLogado com sucesso! ");
	} else{
		printf("\n\nSenha incorreta! ");
	}
	getch();
}

int validasenha(char senhacorreta[50])
{
    char buffer[256] = {0};
    //char password[] = "password";
    char c;
    int pos = 0;
    
    fflush (stdin);
	printf("%s","Digite a senha: ");
    do {
        c = getch();       
        if( isprint(c) ){
            buffer[ pos++ ] = c;
            printf("%c", '*');
        } else if( c == sizeof(senhacorreta) && pos ){
            buffer[ pos-- ] = '\0';
            printf("%s", "\b \b");
        }
    } while( c != 13 );
    
    if( !strcmp(buffer, senhacorreta) )
        return (1);
    else
		return (2);
}
