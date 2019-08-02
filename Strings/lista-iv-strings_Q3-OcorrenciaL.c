/*
Exerc�cios de Fundamentos de Programa��o - Professor Leonardo Vianna
Strings [2018/2]

Quest�o 03:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Pede-se a implementa��o de uma fun��o que,
dadas uma palavra P e uma letra L, determine a
quantidade de ocorr�ncias de L em P.
*/

//IMPORTACAO DE BIBLIOTECAS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//DECLARACAO DE CONSTANTES :::::::::::::::
// TABELA ASCII
#define A 65
#define Z 90
#define a 97
#define z 122

//PROTOTIPO DE FUNCOES

int ocorrenciasL (char P[], char L);

//FUNCAO PRINCIPAL
int main ()
{
	char palavra [30];
	char letra;
	printf ("\n DIGITE A PALAVRA: ");
	gets (palavra);
	printf ("\n DIGITE A LETRA A SER CONTADA: ");
	scanf ("%c",&letra);
	printf("\n\nOCORRENCIAS DE %c em %s : %d\n\n\n",letra,palavra,ocorrenciasL(palavra,letra));
	
}

int ocorrenciasL (char P[], char L)
{
	int i,cont = 0;
	
	for (i=0; P[i]!='\0'; i++)
	{
		if(P[i]==L)
		{
			cont++;
		}
		
	}
	return cont;
}
