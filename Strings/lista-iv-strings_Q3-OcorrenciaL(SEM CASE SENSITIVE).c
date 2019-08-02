/*
Exercícios de Fundamentos de Programação - Professor Leonardo Vianna
Strings [2018/2]

Questão 03:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
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
char paraMaiuscula (char l);
char paraMinuscula (char l);
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

int ocorrenciasL (char P[], char L)
{
	int i,cont = 0;
	char L2;
	for (i=0; P[i]!='\0'; i++)
	{
		//SE LETRAS DO MESMO TIPO
		if(verificaLetra (P[i]) == verificaLetra (L))
		{
			if(P[i]==L)
			{
				cont++;
			}
		}
		//TIPOS DIFERENTES
		else
		{
			if ((verificaLetra (P[i])) == 1) //SE MINUSCULA
			{
				//TRANSFORMA A OUTRA PARA MINUSCULA TAMBEM
				L2 = paraMinuscula (L);
				if(P[i]==L2)
				{
					cont++;
				}
			}
			if ((verificaLetra (P[i])) == 2) //SE MAIUSCULA
			{
				//TRANSFORMA A OUTRA PARA MAIUSCULA TAMBEM
				L2 = paraMaiuscula (L);
				if(P[i]==L2)
				{
					cont++;
				}
			}
		}		
	}
	return cont;
}
