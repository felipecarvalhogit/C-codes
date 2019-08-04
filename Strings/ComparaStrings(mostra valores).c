#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valor (char s[10])
{
	int val=0,i;
	for(i=0;s[i]!='\0';i++)
	{
		val += s[i]; 
	}
	return val;
}


int main ()
{
	int result;
	char s1[10], s2[10];
	
	printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf (":::::::::::::::COMPARACAO ( S1 COM S2 ):::::::::::::::::\n");
	printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("ATENCAO:\nPARA EVITAR ERRO DE ORDENACAO CRESCENTE EVITE ACENTUAR\n\tEste programa depende de como o sistema onde esta\n\tsendo executado interpreta a tabela ASCII\nEXEMPLO:\n\ta = 97 e a com o til = -58 ou pode vir como 198\n\n\n");
	printf("\n\tPalavra 1: ");
	gets (s1);
	printf("\n\tPalavra 2: ");
	gets (s2);
	
	result = strcmp (s1,s2);
	
	if (result == -1)
	{
		printf("\nstrcmp retornou %d : s1 < s2\n\ts1 vale: %d\n\ts2 vale: %d", result, valor(s1), valor(s2));
	}
	if (result == 0)
	{
		printf("\nstrcmp retornou  %d : s1 = s2\n\ts1 vale: %d\n\ts2 vale: %d", result, valor(s1), valor(s2));
	}
	if (result == 1)
	{
		printf("\nstrcmp retornou  %d : s1 > s2\n\ts1 vale: %d\n\ts2 vale: %d", result, valor(s1), valor(s2));
	}
	return 0;
}
