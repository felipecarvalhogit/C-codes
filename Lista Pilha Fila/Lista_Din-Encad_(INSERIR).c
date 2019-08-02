/********************************************************
*	LISTA DINAMICAMENTE ENCADEADA
*
*	FELIPE ANDRE DEZ/2018 versao TESTE
********************************************************/

//Importacao de Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definicao de Constantes
#define FALSE 0
#define TRUE 1

//Declaracao de Tipos..................................
typedef struct No {
	int valor;
	struct No* prox;
}TNo;

typedef TNo* TLista;

//Declaracao de Prototipos

int inserir_OrdemCre_semRep (TLista (*L), int numero);
void exibir (TLista L);
int menu ();

//Funcao Principal.....................................

int main ()
{
	TLista L = NULL; //inicia lista vazia
	int opcao,num1, num2, result;
	
	do
	{ 
		opcao = menu ();
		
		switch (opcao)
		{
			//inserir
			case 1:	printf ("\n\tENTRE COM O ELEMENTO INEDITO A SER INSERIDO EM ORDEM CRESCENTE: ");
					scanf ("%d", &num1);
					if (inserir_OrdemCre_semRep (&L, num1)) //if (inserir_OrdemCre_semRep (&L, numero) == TRUE)
			        {
			        	printf ("\n\tElemento inserido!\n\n\n");
					}
					else
					{
						printf ("\n\tNAO INSERIDO: Elemento ja existe!\n\n\n");
					}
					break;/*
			//buscar
			case 2:	printf ("\n\tENTRE COM O ELEMENTO A SER BUSCADO: ");
					scanf ("%d", &num1); 
					if(buscar (L, num1))
					{
						printf ("\n\tElemento encontrado!\n\n");
					}
					else
					{
						printf ("\n\tElemento NAO encontrado!\n\n");
					}
					break*/
			//exibir
			case 2:	exibir (L);
					printf ("\n\n");
					break;
			//remover
		/*	case 4: printf ("Entre com o numero a ser removido: ");
			        scanf ("%d", &num1);
			        
			        if (remover (&L, num1) != 0)
			        {
			        	printf ("Elemento removido!\n");
					}
					else
					{
						printf ("ERRO: Elemento nao removido!\n");
					}
					break;
			//alterar
			case 5:	printf ("Entre com o numero a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("Entre com o novo elemento: ");
			        scanf ("%d", &num2);
			        
			        result = alterar (L, num1, num2);
			        if (result)
			        {
			        	printf ("Ocorrencia de alterada!\n");
					}
					else
					{
						printf ("ERRO: Elemento nao alterado!\n");
					}
					break;*/
			//saida
			case 6: printf ("Fim do programa!");
			        break;
			        
			//opcao invalida
			default: printf ("Opcao invalida! Escolha novamente.");
		}
	}
	while (opcao != 6); // 6 = Sair	
}

//Desenvolvimento de Funcoes...........................

//Insere somente elementos ineditos e em ordem crescente
int inserir_OrdemCre_semRep (TLista (*L), int numero)
{
	int ctrl = 0;
	TLista aux = *L, novo =	(TLista)malloc(sizeof (TNo));
	if (!novo) return FALSE;
		
	while (aux)	{
		if(aux->valor == numero)
			ctrl = 1;
		else aux = aux->prox;
	}
	if(!ctrl){
		if ((!(*L)) || ((*L)->valor > numero)){
			novo->valor = numero;
			novo->prox = (*L);
			(*L) = novo;
			return TRUE;
		}
		else{
			aux = (*L);
			while (aux->prox){
				if(aux->prox->valor > numero){
					novo->valor = numero;
					novo->prox = aux->prox;
					aux->prox = novo;
					return TRUE;
				}
				aux = aux->prox;
			}
			novo->valor = numero;
			novo->prox = aux->prox;
			aux->prox = novo;
			return TRUE;
		}
	}
	return FALSE;
}

void exibir (TLista L)
{
	TLista aux;
	
	if (!L)
	{
		printf ("\n\tLista Vazia!\n\n");
	}
	else
	{
		aux = L;
		printf ("\nLISTA:");
		while (aux)
		{
			printf (" %d ", aux->valor);
			aux = aux->prox;
		}
	}
}

//MENU DE OPCOES
int menu ()
{
	int opcao;
	
	printf ("\n\t**********************************\n");
	printf ("\t\tMENU DE OPCOES\n");
	printf ("\t**********************************\n\n");
	printf ("\t(1) Inserir em ordem crescente sem repeticao\n"
			"\t(2) Exibir elementos\n"
			"\t(6) SAIR\n\n");
	printf ("\n\t..................................\n");
	printf ("\n\tENTRE COM A SUA OPCAO: ");
	scanf ("%d", &opcao);
		
	return opcao;
}


