/*
Exercícios de Fundamentos de Programação - Professor Leonardo Vianna
Strings [2018/2]

Questão 03:::::::::::::::::::::::::: VERSAO 2 ::::::::::::::::::::::::::::::::
Pede-se a implementação de uma função que,
dadas uma palavra P e uma letra L, determine a
quantidade de ocorrências de L em P.
*/

//IMPORTACAO DE BIBLIOTECAS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//PROTOTIPO DE FUNCOES
int verificaLetra (char L);
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
	printf("\n\nOCORRENCIAS DE '%c' em '%s' : %d\n\n\n",letra,palavra,ocorrenciasL(palavra,letra));	
}

//DESENVOLVIMENTO DE FUNCOES
int verificaLetra (char L)
{
	if (L>=97 && L<=122)//minuscula
	{
		return 1;
	}
	if (L>=65 && L<=90)//maiuscula
	{
		return 2;
	}
	return -1; //caracter especial
}

int ocorrenciasL (char P[], char L)
{
	int i,cont = 0;
	char L2;
	
	for (i=0; P[i]!='\0'; i++)
	{
		//SE LETRA DA VEZ FOR MINUSCULA
		if(verificaLetra (P[i]) == 1)
		{
			if(verificaLetra (L) == 1)//se L tambem minuscula
			{
				if(P[i]==L)//se iguais
				{
					cont++;
				}
			}
			else //se L maiuscula
			{
				L2 = L+32; //passa para minuscula
				if(P[i]==L2)
				{
					cont++;
				}
			}
		}
		else //SE LETRA DA VEZ FOR MAIUSCULA
		{
			if (verificaLetra (L) == 2) //se L tambem maiuscula
			{
				if(P[i]==L)//se iguais
				{
					cont++;
				}
			}
			else //se L for minuscula ou outro caractere
			{
				L2 = L-32;//passa para maiuscula
				if(P[i]==L2)
				{
					cont++;
				}
			}
		}		
	}
	return cont;
}
