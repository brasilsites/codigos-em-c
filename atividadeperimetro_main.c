#include <stdio.h>
#include <stdlib.h>

void main()
{
    float lado1,lado2,lado3,perimetro;
    int triangulo=0;
    //calculo do perimetro
    //Perimetro = Lado + Lado + Lado, ou se os 3 lados forem iguais: Perimetro = 3 x Lado
    printf("calculo do perimetro \n");
    printf("Informe o primeiro lado: ");
    scanf("%f",&lado1);
    printf("Informe o segundo lado: ");
    scanf("%f",&lado2);
    printf("Informe o terceiro lado: ");
    scanf("%f",&lado3);

    /*
    Verifica a condição de existência
    b-c < a < b+c
    a-c < b < a+c
    a-b < c < a+b
    */
    if (((lado2 - lado3)<lado1) && (lado1<(lado2 + lado3)) || ((lado1 - lado3)<lado2) && (lado2<(lado1 + lado3)) || ((lado1 - lado2)<lado3) && (lado3<(lado1 + lado2))){
        perimetro = lado1 + lado2 + lado3;
        printf("O Perimetro dos 3 lados e de %.2f ",perimetro);
    }
    else{
        printf("ERRO! Os lados informados nao formam um triangulo ");
    }
}
