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
int remover (TLista (*L), int numero);
int alterar (TLista L, int velho, int novo);
TLista buscar (TLista L, int numero);
void exibir (TLista L);
void exibeL (TLista L);
void destruir (TLista (*L));
int menu ();

//Funcao Principal.....................................

int main ()
{
	TLista L = NULL; //inicia lista vazia
	int opcao,num1, num2, result;
	
	do
	{
		system ("cls"); 
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
					break;
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
					break;
			//exibir
			case 3:	exibir (L);
					printf ("\n\n");
					break;
			//remover
			case 4: printf ("Entre com o numero a ser removido: ");
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

int inserir_OrdemCre_semRep (TLista (*L), int numero)
//Insere somente elementos ineditos e em ordem crescente
{
	TLista aux = (*L), novo;
	
	if(!aux) //se lista vazia
	{
		novo = (TLista) malloc (sizeof(TNo));	
		if (novo) //se foi alocada memoria
		{
			novo->valor = numero;
			novo->prox = (*L);
			(*L) = novo;			 
			return TRUE;
		}
		else return FALSE;
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

//Remove elemento unico da lista procurando-o ate o valor maior somente
int remover (TLista (*L), int numero)
{
	TLista pre = (*L), pos;
	
	//ocorrencia no inicio da lista, pre = *L
	if ((*L) && (*L)->valor == numero)
	{
		*L = (*L)->prox;
		free(pre);
		return TRUE;
	}	
	//segundo elemento em diante, pre = *L
	if (*L)
	{	
		pos = (*L)->prox;	//aponta para segundo elemento
		
		//Enquanto nao e' final da lista E elemento menor que "numero"  
		while ((pos) && (pos->prox->valor < numero)) 
		{
			if (pos->valor == numero) //se elemento encontrado
			{				
				pre->prox = pos->prox;  //aponta para o proximo do elemento a ser removido
				free(pos); 				//remove o elemento que contem 'numero'   
				return TRUE;    			
			}
			else		//se nao for encontrado, andar com os dois ponteiros
			{
				pre = pos;
				pos=pos->prox;
			}
        }
    }
	return FALSE;	
}

//Altera somente se nao provocar repeticao
int alterar (TLista L, int velho, int novo)
{
	TLista pNovo = buscar(L, novo);
	TLista pVelho;
	
	if (!pNovo) // se nao houver "novo" na lista
	{
		pVelho = buscar(L, velho);
		
		if (!pVelho) // se nao houver "velho" na lista
		{
			pVelho->valor = novo;
			return TRUE;
		}
		else
			return FALSE; // "velho" ja' existia na lista
	}
	else
		return FALSE; // // "novo" ja' existia na lista
}


TLista buscar (TLista L, int numero)
//Busca primeira ocorrencia, retorna endereco do 'no'
{
	TLista aux = L;
	
	while ((aux) && (aux->prox->valor <= numero))  //while (aux != NULL)
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

void exibeL (TLista L) {
   TLista aux;
   for (aux = L; aux != NULL; aux = aux->prox)
      printf (" %d" , aux->valor);
}

void destruir (TLista (*L))
{
	
}

//MENU DE OPCOES
int menu ()
{
	int opcao;
	
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


