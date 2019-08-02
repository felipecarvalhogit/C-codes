//MINUSCULA PARA MAIUSCULA

//IMPORTACAO DE BIBLIOTECAS
#include<stdio.h>


//PROTOTIPO DE FUNCOES
char paraMaiuscula (char l);

//FUNCAO PRINCIPAL
int main ()
{
	char letra;
	printf ("\n DIGITE A LETRA: ");
	scanf ("%c",&letra);
	printf("\n\nCAIXA ALTA DE %c:  %c\n\n\n",letra,paraMaiuscula(letra));	
}

char paraMaiuscula (char l)
{
	char letra;
	
	if (l >=97 && l<=122)
	{
		letra = l - 32; // (l - a) - A ou (l - 97) - 65
		return letra;
	}
	return l;
}
