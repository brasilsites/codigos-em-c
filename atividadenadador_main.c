#include <stdio.h>
#include <stdlib.h>

void main()
{
    /*
    Elabore um programa que, dada a idade de um nadador, classificá-lo
    nas categorias:
     infantil A (5 - 7 anos),
     infantil B (8 -10 anos),
     juvenil A (11 - 13 anos),
     juvenil B (14 -17 anos) e
     adulto (maiores que 18 anos).
    */

    int idade;
    printf("Informe a idade do nadador: ");
    scanf("%i",&idade);

    if (idade>=5 && idade<=7){
        printf("Inscrito na categoria - Infantil A ");
    }
    else if(idade>=8 && idade<=10){
        printf("Inscrito na categoria - Infantil B ");
    }
    else if(idade>=11 && idade<=13){
        printf("Inscrito na categoria - Juvenil A ");
    }
    else if(idade>=14 && idade<=17){
        printf("Inscrito na categoria - Juvenil B ");
    }
    else if(idade>=18){
        printf("Inscrito na categoria - Adulto ");
    }
    else{
        printf("Idade nao e compativel com nenhuma categoria ");
    }
}
 
