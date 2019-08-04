#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	int result;
	char s1[10], s2[10];
	
	printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf (":::::::::::::::COMPARACAO ( S1 COM S2 ):::::::::::::::::\n");
	printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\n\tPalavra 1: ");
	gets (s1);
	printf("\n\tPalavra 2: ");
	gets (s2);
	
	result = strcmp (s1,s2);
	
	if (result == -1)
	{
		printf("%d : s1 < s2", result);
	}
	if (result == 0)
	{
		printf("%d : s1 = s2", result);
	}
	if (result == 1)
	{
		printf("%d : s1 > s2", result);
	}
	return 0;
}
