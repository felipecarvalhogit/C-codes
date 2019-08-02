/*
Exercicios de Fundamentos de Programacao - Professor Leonardo Vianna
Strings [2018/2]

Questao 04::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Fazer uma funcao que, dada uma palavra P, exiba o numero de ocorrencias de cada uma de suas letras.

Exemplos:
	
P = MESA

M – 1
E – 1
S – 1
A – 1

P = TESTE

T – 2
E – 2
S – 1

*/

//IMPORTACAO DE BIBLIOTECAS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//PROTOTIPO DE FUNCOES
int contaLetras (char str[]);

//FUNCAO PRINCIPAL
int main ()
{
	return 0;
}

//DESENVOLVIMENTO 
int contaLetras (char str[])
{
	int i, qtd = 1;
	char vLetras[strlen(str)];//vetor de letras unicas
	char vQtd[strlen(str)];//vetor paralelo com quantidades
	
	//inicializando vetor de letras unicas
	vLetras [0] = str[0];
	vQtd [0] = qtd;//1

	for(i=1; i < strlen(str); i++)
	{
		if (str[i] == str[i])//se repetir letra
		{
				qtd++;//soma-se a repeticao
				vLetras [i] = str[i];//guarda-se a letra
				vQtd [i] = qtd;
			}
			else //se a letra for diferente
			{				
		}
	}
	
	return qtd;
}
