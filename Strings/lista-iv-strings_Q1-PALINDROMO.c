/*
Exerc�cios de Fundamentos de Programa��o - Professor Leonardo Vianna
Strings [2018/2]

Quest�o 01:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Dada uma string s, desenvolver uma fun��o que determine se s � ou n�o um pal�ndromo.

Observa��o: uma string s ser� um pal�ndromo quando seus caracteres formarem a mesma
sequ�ncia, independente se s � percorrida da esquerda para direita ou vice-versa.
*/

//IMPORTACAO DE BIBLIOTECAS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//DEFINICAO DE CONSTANTES
#define FALSE 0
#define TRUE 1

//PROTOTIPO DE FUNCOES

int palindromo (char s[]);

//FUNCAO PRINCIPAL
int main ()
{
	char palavra [30];
	printf ("\n DIGITE A PALAVRA: ");
	gets (palavra);
	if (palindromo (palavra) == TRUE) 
	{
		printf("\nEH PALINDROMO!\n\n");
	}
	else printf("\n NAO EH PALINDROMO!\n\n");
}

int palindromo (char s[])
{
	int i,j;
	for (i=0, j=strlen(s)-1; i<j; i++, j--)
	{
		if(s[i] != s[j])
		{
			return FALSE;
		}
	}
	return TRUE;
}
