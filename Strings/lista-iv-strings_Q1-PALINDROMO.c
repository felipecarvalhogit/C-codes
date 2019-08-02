/*
Exercícios de Fundamentos de Programação - Professor Leonardo Vianna
Strings [2018/2]

Questão 01:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Dada uma string s, desenvolver uma função que determine se s é ou não um palíndromo.

Observação: uma string s será um palíndromo quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da esquerda para direita ou vice-versa.
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
