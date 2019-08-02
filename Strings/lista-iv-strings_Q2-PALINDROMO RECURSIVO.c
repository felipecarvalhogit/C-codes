/*
Exerc�cios de Fundamentos de Programa��o - Professor Leonardo Vianna
Strings [2018/2]

Quest�o 02::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Dada uma string s, desenvolver uma fun��o recursiva
que determine se s � ou n�o um pal�ndromo.
*/

//IMPORTACAO DE BIBLIOTECAS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//DEFINICAO DE CONSTANTES
#define FALSE 0
#define TRUE 1

//PROTOTIPO DE FUNCOES
int palindromoR (char str[]);

//FUNCAO PRINCIPAL
int main ()
{
	char palavra [30];
	printf ("\n DIGITE A PALAVRA: ");
	gets (palavra);
	if (palindromoR (palavra) == TRUE) 
	{
		printf("\nEH PALINDROMO!\n\n");
	}
	else printf("\n NAO EH PALINDROMO!\n\n");
}

//DESENVOLVIMENTO DE FUNCOES
palindromoR (char str[])
{
	int pos1 = 0, pos2 = strlen(str)-1;
	//caso base: n�o ser palindromo (s[pos1] != s[pos2])
	if(str[pos1] != str[pos2])
	{
		return FALSE;
	}
	//caso geral 
	else
	{
		pos1++;
		pos2--;
	}
	return TRUE;
}
