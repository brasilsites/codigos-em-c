#include <stdio.h>
#include <stdlib.h>

    int comparecrescente (const void * a, const void * b){
        return ( *(int*)a - *(int*)b );
    }
    int comparedecrescente (const void * a, const void * b)
    {
        return ( *(int*)b - *(int*)a );
    }

void main()
{
    int num1,num2,num3;
    int n;
    char ordem;
    int erro=0;

    printf("Informe a ordem: C - Crescente | D - Decrescente: ");
    scanf("%c",&ordem);

    printf("Insira o primeiro numero inteiro: ");
    scanf("%i",&num1);
    printf("Insira o segundo numero inteiro: ");
    scanf("%i",&num2);
    printf("Insira o terceiro numero inteiro: ");
    scanf("%i",&num3);

    int valores[] = {num1,num2,num3};
    switch (ordem){
        case 'C':
            qsort (valores, 3, sizeof(int), comparecrescente);
            break;
        case 'D':
            qsort (valores, 3, sizeof(int), comparedecrescente);
            break;
        default:
            printf ("Erro, Ordem inexistente! ");
            erro=1;
    }

    if (erro==0){
        for (n=0; n<3; n++)
            printf ("%d ",valores[n]);
    }
}
