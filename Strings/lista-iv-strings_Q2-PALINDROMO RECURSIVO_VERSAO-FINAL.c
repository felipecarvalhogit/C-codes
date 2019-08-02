/*
Exercícios de Fundamentos de Programação - Professor Leonardo Vianna
Strings [2018/2]

Questão 02:::::::::::::::::Versao FINAL::::::::::::::::::::::::::::
Dada uma string s, desenvolver uma função recursiva
que determine se s é ou não um palíndromo.
*/

//IMPORTACAO DE BIBLIOTECAS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//DEFINICAO DE CONSTANTES
#define FALSE 0
#define TRUE 1

//PROTOTIPO DE FUNCOES
int palindromoR2 (char str[], int pos1, int pos2);
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
int palindromoR2 (char str[], int pos1, int pos2)
{
	if (pos1 < pos2)
	{
		if (str[pos1] == str[pos2])
		{
			return palindromoR2 (str, pos1+1, pos2-1);
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return TRUE;
	}
}

int palindromoR (char str[])
{
	return palindromoR2 (str,0,strlen(str)-1);
}
