#include <stdio.h>
#include <stdlib.h>

void main()
{
    //Ler 3 numeros, ler se a ordem ser� crescente ou decrescente, imprima na ordem escolhida
    int num1,num2,num3;
    int ord1,ord2,ord3; //as vari�veis que recebem os numeros na ordem
    char ordem;

    printf("Escolha a ordem: C - Crescente, D - Decrescente: ");
    scanf("%c",&ordem);

    printf("Informe o primeiro numero inteiro: ");
    scanf("%i",&num1);
    printf("Informe o segundo numero inteiro: ");
    scanf("%i",&num2);
    printf("Informe o terceiro numero inteiro: ");
    scanf("%i",&num3);

    //Primeiro verifica se o numero 1 � maior que os outros dois
    if (num1>num2 && num1>num3){
        //O primeiro numero da ordem ser� num1
        ord1 = num1;
        //Agora, verifica se numero 2 � maior que numero 3
        if (num2>num3){
            //caso positivo, o segundo numero ser� o numero 2, e o terceiro ser� o 3
            ord2 = num2;
            ord3 = num3;
        }
        else{
            //sen�o, o numero 3 � maior, ser� o segundo na ordem
            ord2 = num3;
            ord3 = num2;
        }
    }
    //Segunda condi��o, verifica se o numero 2 � maior que os outros dois
    if (num2>num1 && num2>num3){
        //O primeiro numero da ordem ser� num2
        ord1 = num2;
        //Agora, verifica se numero 1 � maior que numero 3
        if (num1>num3){
            //caso positivo, o segundo numero ser� o numero 2, e o terceiro ser� o 3
            ord2 = num1;
            ord3 = num3;
        }
        else{
            //sen�o, o numero 3 � maior, ser� o segundo na ordem
            ord2 = num3;
            ord3 = num1;
        }
    }
    //Se nem o numero 1, nem o numero 2 � maior, ent�o s� resta o numero 3
    else{
         //O primeiro numero da ordem ser� num3
        ord1 = num3;
        //Agora, verifica se numero 2 � maior que numero 1
        if (num2>num1){
            //caso positivo, o segundo numero ser� o numero 2, e o terceiro ser� o 1
            ord2 = num2;
            ord3 = num1;
        }
        else{
            //sen�o, o numero 2 � maior, ser� o segundo na ordem
            ord2 = num1;
            ord3 = num2;
        }
    }

    switch (ordem){
        case 'C':
            printf("A ordem escolhida foi Crescente: %i - %i - %i",ord3,ord2,ord1);
            break;
        case 'D':
            printf("A ordem escolhida foi Decrescente: %i - %i - %i",ord1,ord2,ord3);
            break;
        default:
            printf("ERRO! Ordem inexistente. ");
    }
}
