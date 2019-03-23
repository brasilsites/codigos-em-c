#include <stdio.h>
#include <stdlib.h>

void main()
{
    float lado1,lado2,lado3,perimetro;
    //calculo do perimetro
    //Perimetro = Lado + Lado + Lado, ou se os 3 lados forem iguais: Perimetro = 3 x Lado
    printf("calculo do perimetro \n");
    printf("Informe o primeiro lado: ");
    scanf("%f",&lado1);
    printf("Informe o segundo lado: ");
    scanf("%f",&lado2);
    printf("Informe o terceiro lado: ");
    scanf("%f",&lado3);

    perimetro = lado1 + lado2 + lado3;

    printf("O Perimetro dos 3 lados e de %.2f ",perimetro);
}
