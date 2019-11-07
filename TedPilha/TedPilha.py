'''
TED1 - Pilha
1. Desenvolva um algoritmo para testar se uma pilha P1 tem mais elementos que
uma pilha P2. Considere que P1 e P2 já existem.
O protótipo da função deve ser:
def testaMaisElementos(pilha1, pilha2):
# A função retornará 1 para verdadeiro (P1 > P2) e 0 para falso.
'''

class Pilha():
    def __init__(self):
        self.pilha1=[]
        self.pilha2=[]

    def carregaPilha1(self,valor):
        self.pilha1.append(valor)

    def carregaPilha2(self,valor):
        self.pilha2.append(valor)

    def testaMaisElementos(self):
        if (len(self.pilha1)>len(self.pilha2)):
            return "1 - Condição verdadeira "+str(len(self.pilha1))+">"+str(len(self.pilha2))+"!"
        elif (len(self.pilha1)==len(self.pilha2)):
            return "Condição neutra "+str(len(self.pilha1))+"="+str(len(self.pilha2))+"!"
        else:
            return "0 - Condição falsa "+str(len(self.pilha1))+"<"+str(len(self.pilha2))+"!"


