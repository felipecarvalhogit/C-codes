/******************************************
*	Lista Duplamente Encadeada  
*	( Ordem Crescente | sem repeticao )
*	FELIPE ANDRE' 2018-2
******************************************
* VERSAO 0.0 (12/DEZ/2018)
*	
*18:01 Adaptanco p lista Duplamente Encad
*19:30 Inserir adaptada
*19:32 Alterando Remover...
*21:55 Remover testada
*Fazendo Exibir do Fim ao Inicio
******************************************/


#include <stdio.h>
#include <stdlib.h>

//Definicao de constantes
#define FALSE 0
#define TRUE 1

//Definicao de tipos

//definindo o struct que representara' cada posicao da lista, denominado de No'.
//Cada No' contera' o elemento da lista e o ponteiro para o proximo elemento

typedef struct No {
int valor; //cada valor sendo manipulado pela lista
struct No* prox; //endereco do no' que contem o proximo elemento
struct No* ant; 
} TNo;

typedef TNo* TLista;

//prototipos das funcoes
int inserir (TLista* L, int numero);
int remover (TLista* L, int numero);
int alterar (TLista *L, int velho, int novo);
TLista buscar (TLista L, int numero);
void exibir_ordem (TLista L);
void exibir_contrario (TLista L);
void destruir (TLista* L);
int menu ();


//MAIN
int main ()
{
	TLista pos, L = NULL; //criando a lista, inicialmente vazia
	int op, num1, num2;
	
	do
	{
		system ("cls");
		op = menu ();
		switch (op)
		{
			case 1: //Inserir
					printf ("Entre com o elemento a ser inserido: ");
					scanf ("%d", &num1);
					if (inserir (&L, num1) == TRUE)
					{
						printf ("Elemento %d inserido com sucesso!\n", num1);
					}
					else
					{
						printf ("ERRO: Elemento %d nao inserido!\n", num1);
					}
					break;
			case 2: //Remover
					printf ("Entre com o elemento a ser removido: ");
					scanf ("%d", &num1);
					if (remover (&L, num1) == TRUE)
					{
						printf ("Elemento %d foi removido!\n", num1);
					}
					else
					{
						printf ("ERRO: Elemento %d nao existe na lista!\n", num1);
					}
					break;
			case 3: //Alterar
					printf ("Entre com o elemento a ser alterado: ");
					scanf ("%d", &num1);
					printf ("Entre com o novo elemento: ");
					scanf ("%d", &num2);
					if (alterar (&L, num1, num2) == TRUE)
					{
						printf ("Alteracao realizada!\n");
					}
					else
					{
						printf ("ERRO: alteracao nao realizada!\n", num1);
					}
					break;
			case 4: //Buscar
					printf ("Entre com o elemento a ser buscado: ");
					scanf ("%d", &num1);
					pos = buscar (L, num1);
					if (pos)
					{
						printf ("Elemento %d foi encontrado!\n", num1);
					}
					else
					{
						printf ("ERRO: Elemento %d nao existe na lista!\n", num1);
					}
					break;
			case 5: //Exibir
					exibir_ordem(L);
					break;
			case 6: //Exibir
					exibir_contrario(L);
					break;
			case 7: //Sair
					printf ("Fim do programa!\n");
					break;
			//opcao invalida
			default: printf ("Opcao invalida! Escolha novamente.");
		}
		system ("pause");
	}
	while (op != 7);
}

//Implementacoes..................................................

//Insere somente elementos ineditos e em ordem crescente
int inserir (TLista* L, int numero)
{
	TLista aux,pos, novo;
	if (buscar (*L, numero) == NULL) //verificando se o elemento nao existe
	{
		novo = (TLista) malloc (sizeof(TNo));
		novo->ant = novo->prox = NULL;
		novo->valor = numero;
		if (!novo){
			return FALSE; //sem memoria disponivel
		}		
		else
		{	// vazia : inserir primeiro no' 
			if (!(*L)){	
				novo->prox = (*L);
				(*L) = novo;
				return TRUE;
			}
			else{	
				//inserir antes do primeiro no'
				if ((*L)->valor > numero){				
						novo->prox = (*L);
						(*L)->ant = novo;
						(*L) = novo;
						return TRUE;
				}
				else { // inserir apos o primeiro no' em diante
					aux = (*L);
					pos = (*L)->prox;
					while (pos) //anda no maximo ate' antes de NULL
					{
						if((aux)&&(aux->valor < numero)&&(pos->valor > numero)){
							novo->prox = pos;
							pos->ant = novo;
							aux->prox = novo;
							return TRUE;
						}
						aux = pos;
						pos = pos->prox;
					}
					//nao entra no while: se pos == NULL, aux e' o ultimo no'
					//inserir no final (apos 'aux')
					novo->prox = pos;
					novo->ant = aux;
					aux->prox = novo;
					return TRUE;			
				}
			} 			
		}
	}
	else
	{
		return FALSE; // pois o elemento ja existe na lista
	}
}
//Remove elemento unico da lista procurando-o ate o valor maior somente
int remover (TLista* L, int numero)
{
	TLista pre= *L, pos=(*L)->prox;
	
	if(!*L){
		return FALSE; //se vazia
	} 
	else{		
		if ((*L)->valor == numero)		// PRIMEIRO NO' 
		{ 	
			if ((*L)->prox == NULL){	//se ha' somente 1 elemento
				*L = (*L)->prox;
				free (pre);
				return TRUE;
			}
			else{	//lista com mais de 1 elemento
				*L = (*L)->prox;
				pos->ant = *L;
				free (pre);
				return TRUE;
			}
		}
		else{	//segunda posicao em diante 
			while (pos)
			{	//encontrar antes do ultimo OU ate' o ultimo				
				if (pos->valor != numero) //elemento encontrado
				{
					if ((pos->prox->valor) && (pos->prox->valor > numero)){	
						return FALSE;							
					}
					else {
						pre = pos;
						pos = pos->prox;
					}
				}
				else //se encontrar
				{
					if (pos->prox) //se depois ha' outros elementos
					{ 
						pre->prox = pos->prox;
						pos->prox->ant = pos->ant;
						free (pos);
						return TRUE;
					}
					else{	//ultimo no'
						pre->prox = pos->prox;
						free (pos);
						return TRUE;
					}
				}				
			}			
			return FALSE; //elemento inexistente
		}
	}	
}
//Altera 'velho' por 'novo', se nao provocar repeticao,
//mantendo ordem crescente e retornando TRUE ou FALSE
int alterar (TLista *L, int velho, int novo)
{
	TLista posNovo = buscar (*L, novo);
	TLista posVelho;
	if (posNovo == NULL) //se o novo nao existir...
	{
		posVelho = buscar (*L, velho);
		if (posVelho != NULL) //se o velho existir ...
		{
			if (remover (L, velho) == FALSE) { 
		       return FALSE;
			}
			else {
		        if (inserir (L,novo) == FALSE) {
	                //desfazer o que foi feito
	                inserir (L, velho);
	                return FALSE;
		        }
		        else{ // tudo funcionar
		           return TRUE;	
				}
			}
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}
//Busca o numero em L, retornando a posicao de sua primeira ocorrencia (caso ele exista).
//Se o numero nao for encontrado, NULL sera' retornado
TLista buscar (TLista L, int numero)
{
	TLista aux = L;
	while (aux != NULL)
	{
		if (aux->valor == numero)
		{
			return aux;
		}
		else //se aux->valor != numero verificar se e' maior
		{
			if (aux->valor > numero)
				return NULL;				
			else
				aux = aux->prox; //anda
		}
	}
	return NULL;
}
//Exibe todos os elementos em ordem crescente
//Da cabeca ate' NULL
void exibir_ordem (TLista L)
{
	if (!L)
	{
		printf ("Lista vazia\n");
	}
	else
	{
		printf ("Lista: ");
		while (L)
		{
			printf ("%d ", L->valor);
			L = L->prox;
		}
		printf ("\n");
	}
}

//Exibe todos os elementos em ordem decrescente
//Do final ate' cabeca
void exibir_contrario (TLista L)
{
	if (!L)
	{
		printf ("Lista vazia\n");
	}
	else
	{
		while (L)
		{
			L = L->prox;
		}
		printf ("Lista: ");
		while (L)
		{
			printf (" %d ", L->valor);
			L = L->ant;
		}
		printf ("\n");
	}
}

//Exibe um menu ao usu?rio, retornando a op??o escolhida
int menu ()
{
	int opcao;
	printf ("Menu de opcoes:\n");
	printf ("(1) Inserir\n(2) Remover\n(3) Alterar\n(4) Buscar\n(5) Exibir em Ordem\n(6) Exibir ao Contrario\n(7) Sair\n\n");
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	return opcao;
}
