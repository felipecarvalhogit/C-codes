//MAIUSCULA PARA MINUSCULA

//IMPORTACAO DE BIBLIOTECAS
#include<stdio.h>


//PROTOTIPO DE FUNCOES
char paraMinuscula (char l);

//FUNCAO PRINCIPAL
int main ()
{
	char letra;
	printf ("\n DIGITE A LETRA: ");
	scanf ("%c",&letra);
	printf("\n\nCAIXA BAIXA DE %c:  %c\n\n\n",letra,paraMinuscula(letra));	
}

char paraMinuscula (char l)
{
	char letra;
	
	if (l >=65 && l<=90)
	{
		letra = l + 32; // (l + a) - A ou (l + 97) - 65
		return letra;
	}
	return l;
}
