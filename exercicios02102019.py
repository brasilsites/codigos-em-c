def main():
    questao=int(input("Escolha o numero da questao: "))
    '''
    1) Faça um algoritmo que leia a idade de uma pessoa expressa em anos, em seguida mostre a idade expressa apenas
    em dias
    '''
    if questao==1:
        idade=int(input("Informe a sua idade: "))
        print("Voce tem ",idade*365," dias de vida!")

    '''
    2) Escreva um algoritmo para ler as dimensões de um retangulo (basexaltura) calcular e escrever a area do retangulo
    '''
    if questao==2:
        base=float(input("Informe a base: "))
        altura=float(input("Informe a altura: "))
        print("A area do retangulo e igual a ",base*altura)
    '''
    3) Ler um valor e escrever a mensagem É MAIOR QUE 10! Se o valor lido for maior que 10, caso contrário escrever
    NÂO É MAIOR QUE 10!
    '''
    if questao==3:
        valor=float(input("Informe um valor: "))
        if valor>10:
            print(valor," E MAIOR QUE 10")
        else:
            print(valor," NAO E MAIOR QUE 10")
    '''
    4) Ler um valor e escrever se é positivo ou negativo (considere o valor zero como positivo)
    '''
    if questao == 4:
        valor = float(input("Informe um valor (positivo ou negativo): "))
        if valor<=0:
            print(valor, " negativo")
        else:
            print(valor, " positivo")
    '''
    5) As maçãs custam R$ 1,30 cada se forem compradas menos de uma dúzia, e R$ 1,00 se forem compradas pelo menos 12.
    Escreva um programa que leia o número de maçãs compradas, calcule e escreva o custo total da compra
    '''
    if questao == 5:
        macas = int (input("Informe a quantidade de macas: "))
        if macas <12:
            totalcompra=float(macas*1.30)
        else:
            totalcompra=float(macas*1.00)
        print ("O total a pagar e: R$ ",totalcompra)
    '''
    6) Escreva um algoritmo que leia o código de um aluno e suas três notas. Calcule a média ponderada do aluno,
    considerando que o peso para a maior nota seja 4 e para as duas restantes 3. Mostre o código do aluno, suas três 
    notas, a média calculada e uma mensagem APROVADO se a média for maior ou igual a 5 e REPROVADO se a média for menor
    que 5
    nota maior*4 
    outras notas*3
    '''
    if questao == 6:
        nota1=float (input("Informe a primeira nota: "))
        nota2=float (input("Informe a segunda nota: "))
        nota3=float (input("Informe a terceira nota: "))
        if nota1>nota2 and nota1>nota3:
            ponderada1 = nota1 * 4
            ponderada2 = nota2 * 3
            ponderada3 = nota3 * 3
        elif nota2>nota1 and nota2>nota3:
            ponderada1 = nota2 * 4
            ponderada2 = nota1 * 3
            ponderada3 = nota3 * 3
        else:
            ponderada1 = nota3 * 4
            ponderada2 = nota2 * 3
            ponderada3 = nota1 * 3
        mediaponderada=(ponderada1+ponderada2+ponderada3)/10
        print("A media ponderada e: ",mediaponderada)
        if  mediaponderada>=5:
            print("Aluno APROVADO!")
        else:
            print("Aluno REPROVADO!")
    '''
    7) Escreva um algoritmo para ler 2 valores e se o segundo valor informado for ZERO, deve ser lido um novo valor,
    ou seja, para o segundo valor não pode ser aceito o valor zero e imprimir o resultado da divisão do primeiro valor
    lido pelo segundo valor lido (utilizar a estrutura for)
    9) Acrescentar uma mensagem de VALOR INVALIDO no exercício 7 caso o segundo valor informado seja ZERO
    Obs.: Corrigido pelo amigo Ramon 
    '''
    if questao == 7 or questao == 9:
        valor1 = int(input("Informe o primeiro valor: "))
        valor2 = int(input("Informe o segundo valor: "))
        for i in range(1):
            if valor2==0:
                valor2 = int(input("VALOR INVALIDO Valor nao pode ser ZERO, informe um segundo novo valor: "))
        if valor2>0:
            print("Os valores inseridos foram: ",valor1," e ",valor2)
        else:
            print("Voce inseriu o valor ZERO e nao sera impresso!")
    '''
    8) Reescreva o exercicio anterior utilizando a estrutura while
    10) Acrescentar uma mensagem de VALOR INVALIDO no exercício 8 caso o segundo valor informado seja ZERO    
    '''
    if questao == 8 or questao == 10:
        valor1 = int(input("Informe o primeiro valor: "))
        valor2 = int(input("Informe o segundo valor: "))

        while valor1==0:
            valor1 = int(input("Valor nao pode ser ZERO, informe um primeiro novo valor: "))
        while valor2==0:
            valor2 = int(input("VALOR INVALIDO Valor nao pode ser ZERO, informe um segundo novo valor: "))
        print("Os valores inseridos foram: ", valor1, " e ", valor2)
    '''
    11) Escreva um algoritmo para ler as notas da 1a e 2a avaliações de um aluno, calcule e imprima a média (simples)
    desse aluno. Só podem ser aceitos valores válidos durante a leitura (0 a 10) para cada nota
    '''
    if questao == 11:
        nota1 = float(input("Informe a primeira nota: "))
        nota2 = float(input("Informe a segunda nota: "))
        while nota1 < 0:
            nota1 = float(input("A nota nao pode ser inferior a ZERO, informe a primeira nota: "))
        while nota2 < 0:
            nota2 = float(input("A nota nao pode ser inferior a ZERO, informe a segunda nota: "))
        print ("A media do aluno e ",(nota1+nota2)/2)

    '''
    12) Escreva um algoritmo para imprimir os numeros de 1(inclusive) a 10 (inclusive) em ordem crescente
    13) Escreva um algoritmo para imprimir os numeros de 1(inclusive) a 10 (inclusive) em ordem decrescente
    '''
    if questao == 12 or questao == 13:
        aleatorio=[]
        for i in range(1,11):
            adiciona=int(input("Informe o "+str(i)+"º numero de ZERO a DEZ"))
            if (adiciona<0 or adiciona>10):
                i=i-1
                adiciona = int(input("ERRO! NUMERO ENTRE ZERO E DEZ. Informe o numero de ZERO a DEZ"))
            aleatorio.append(adiciona)
        print("Ordem original",aleatorio)
        aleatorio.sort()
        print("Ordem crescente",aleatorio)
        aleatorio.sort(reverse=True)
        print("Ordem decrescente",aleatorio)
    '''
    14) Escreva um algoritmo para ler 10 números e ao final da leitura escrever a soma total dos 10 numeros lidos
    '''
    if questao == 14:
        soma=0
        for i in range(1,11):
            numero = int(input("Informe o "+str(i)+"º numero inteiro qualquer:"))
            soma+=numero
        print("A soma dos numeros igual a: ",soma)
    '''
    15) Uma loja está levantando o valor total de todas as mercadorias em estoque. Escreva um algoritmo que permita a 
    entrada das seguintes informações: a) o número total de mercadorias no estoque; b) o valor de cada mercadoria. Ao
    final imprimir o valor total em estoque e a média de valor das mercadorias
    '''
    if questao == 15:
        continua="s"
        i=0
        somaestoque=0
        somatotal=0
        mercadoria=[]
        while continua=="s":
            mercadoria.append([])
            nomemercadoria=input("Informe o nome da mercadoria: ")
            qtdestoque=int(input("Informe a quantidade em estoque: "))
            valormercadoria=float(input("Informe o valor da mercadoria (xxx.xx): "))
            mercadoria[i].append(nomemercadoria)
            mercadoria[i].append(qtdestoque)
            mercadoria[i].append(valormercadoria)
            i+=1
            continua=input("continua (s/n)?")
        print("Quantidade de Produtos: ",len(mercadoria))
        for i in range(len(mercadoria)):
            somaestoque+=mercadoria[i][1]
            somatotal+=mercadoria[i][2]*mercadoria[i][1]
        print("Total no estoque:",somaestoque)
        print("Total R$:", somatotal)
    '''
     16) Escreva um algoritmo que imprima a tabuada (de 1 a 10) para os números de 1 a 10
     '''
    if questao == 16:
        for j in range (1,11):
            print("== Tabuada do " + str(j) + " ==")
            for i in range(1,11):
                resultado=i+j
                print (str(j)+"+"+str(i)+"=",resultado)
    '''
     17) Faça um algoritmo para ler 10 números e armazenar em um array, após isto, o algoritmo deve ordenar os números
     no vetor em ordem crescente. Escrever o vetor ordenado
     '''
    if questao == 17:
        lista10 = []
        for i in range(1, 11):
            numero = int(input("Informe o " + str(i) + "º numero: "))
            lista10.append(numero)
        lista10.sort()
        print("Lista ordenada: ", lista10)
    '''
     18) Faça um algoritmo para ler um vetor de 20 números, após isto, deverá ser lido mais um número qualquer e verificar
     se esse número existe no array ou não. Se existir, o algoritmo deve gerar um novo vetor sem esse número.
     (considere que não haverão numeros repetidos no array)
     '''
    if questao == 18:
        sequencia20=[]
        for i in range(1,21):
            numero = int(input("Informe o " + str(i) + "º numero: "))
            sequencia20.append(numero)
        vinteum = int(input("Informe um novo numero: "))
        achounumero=sequencia20.index(vinteum)

        if achounumero:
            print("Numero localizado, removendo!")
            sequencia20.remove(vinteum)
        print(sequencia20)
main()
