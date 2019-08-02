/********************************************************
*	LISTA DINAMICAMENTE ENCADEADA
*
*	FELIPE ANDRE DEZ/2018
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
int exibe_menu ();
TLista buscar (TLista L, int numero);
int inserir_OrdemCre_semRep (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int velho, int novo);
void exibir (TLista L);


//Funcao Principal.....................................

int main ()
{
	TLista L = NULL; //inicia lista vazia
	int opcao, numero,num1, num2, result;
	
	do
	{
		opcao = exibe_menu ();
		
		switch (opcao)
		{
			//inserir
			case 1: system ("cls"); 
					printf ("\n\tENTRE COM O ELEMENTO INEDITO A SER INSERIDO EM ORDEM CRESCENTE: ");
					scanf ("%d", &numero);
					if (inserir_OrdemCre_semRep (&L, numero)) //if (inserir_OrdemCre_semRep (&L, numero) == TRUE)
			        {
			        	printf ("\n\tElemento inserido!\n\n\n");
					}
					else
					{
						printf ("\n\tNAO INSERIDO: Elemento ja existe!\n\n\n");
					}
					break;
			//buscar
			case 2: system ("cls");
					printf ("\n\tENTRE COM O ELEMENTO A SER BUSCADO: ");
					scanf ("%d", &numero); 
					if(buscar (L, numero))
					{
						printf ("\n\tElemento encontrado!\n\n");
					}
					else
					{
						printf ("\n\tElemento NAO encontrado!\n\n");
					}
					break;
			//exibir
			case 3: system ("cls"); 
					exibir (L);
					printf ("\n\n");
					break;
			//remover
			case 4: printf ("Entre com o numero a ser removido: ");
			        scanf ("%d", &numero);
			        
			        if (remover (&L, numero) != 0)
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
					break;
			//saida
			case 6: printf ("Fim do programa!");
			        break;
			        
			//opcao invalida
			default: printf ("Opcao invalida! Escolha novamente.");
		}
		system ("pause");
	}
	while (opcao != 6); // 6 = Sair	
	
	return 0;
}

//Desenvolvimento de Funcoes...........................

//MENU DE OPCOES
int exibe_menu ()
{
	int opcao;
	
	system ("cls"); //limpa a tela (cls = clear screen)
	printf ("\n\t**********************************\n");
	printf ("\t\tMENU DE OPCOES\n");
	printf ("\t**********************************\n\n");
	printf ("\t(1) Inserir em ordem crescente sem repeticao\n"
			"\t(2) Buscar um elemento\n"
			"\t(3) Exibir elementos\n"
			"\t(4) Remover elementos\n"
			"\t(5) Alterar elementos\n"
			"\t(6) SAIR\n\n");
	printf ("\n\t..................................\n");
	printf ("\n\tENTRE COM A SUA OPCAO: ");
	scanf ("%d", &opcao);
		
	return opcao;
}


TLista buscar (TLista L, int numero)
//Busca primeira ocorrencia, retorna endereco do 'no'
{
	TLista aux = L;
	
	while (aux) //while (aux != NULL)
	{
		if (aux->valor == numero)
		{
			return aux;
		}
		else
		{
			aux = aux->prox; 
		}
	}
	return NULL; //Se nao encontrar ou vazia
}


int inserir_OrdemCre_semRep (TLista *L, int numero)
//Insere somente elementos ineditos e em ordem crescente
{
	TLista aux = *L, novo;
	
	if(!aux) //se lista vazia
	{
		novo = (TLista) malloc (sizeof(TNo));	
		if (novo) //se foi alocada memoria
		{
			novo->valor = numero;
			novo->prox = *L;
			*L = novo;			 
			return TRUE;
		}
	}
	// 1 'no' ou mais
	while(aux->valor != numero) //percorrer enquanto inedito
	{	//se elemento for maior que numero OU aux1 == NULL
		if ((!aux) || (aux->valor > numero))
		{
			novo = (TLista) malloc (sizeof (TNo));
			if (novo) //se alocou memoria
			{
				novo->valor = numero;
				novo->prox = aux;
				aux->prox = novo;
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		else //se elemento menor que numero E aux1 != NULL
		{//continuar percorrendo a lista
			aux = aux->prox;
		}
	}	
}


int remover (TLista *L, int numero)
//Remove elemento unico da lista procurando-o ate o valor maior somente
{
	TLista aux, pre, pos;
	
	//remover as ocorrencias do numero no inicio da lista
	while ((*L) && (*L)->valor==numero)
	{
		aux = *L;
		*L=aux->prox;
		free(aux);
		return TRUE;
	}
	
	//se lista nao vazia.
	if (*L)
	{	
		pre=*L;   		//pre apontando para o primeiro numero da lista
		pos=pre->prox;	//pos apontando para o segundo numero
		
		//Enquanto nao chegar no final da lista ou a um elemento maior que o numero procurado 
		while (pos) 
		{
			//elemento encontrado
			if(pos->valor==numero)
			{				
				pre->prox = pos->prox;  //faz o numero anterior apontar para o proximo do elemento a ser removido
				free(pos);            //remove o elemento que contem 'numero'
				return TRUE;    			
			}
			else
			{
				if( pos->valor < numero)
				{
					//se nao for encontrado, andar com os dois ponteiros
					pre = pos;
					pos=pos->prox;
				}
				else
					return FALSE;
			}
        }
    }
	return TRUE;	
}

int alterar (TLista L, int velho, int novo)
{//Altera somente se nao provocar repeticao
	TLista aux = L;
	TLista result, pre;
	
	result = buscar(L, novo);
	
	while (aux && (!result)) 
	{
		if (aux->valor == velho)
		{
			//remove para garantir ordenacao
			pre->prox = aux->prox;  //faz o numero anterior apontar para o proximo do elemento a ser removido
			free(aux); 
			aux->valor = novo;
			//conferindo local correto
			inserir_OrdemCre_semRep (&L, novo);
			return TRUE;
		}
		aux = aux->prox;
	}
	//se lista vazia OU se 'velho' nao encontrado
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



