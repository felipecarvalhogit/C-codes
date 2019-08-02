#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No* proximo;
    struct No* anterior;
} TNo;

typedef TNo* TLista;

void inserir (TLista *L, int numero);
void remover (TLista *L, int numero);
void alterar (TLista L, int numeroAntes, int numeroDepois);
void exibir (TLista L, int ordenacao); //1+ para crescente, 0- para decrescente
void organiza(TLista L);
TLista pesquisa(TLista L, int numero);

int main()
{
    int choice, numero;
    TLista lista = NULL;

    do
    {
        system("cls");
        printf("1 - inserir    /    2 - remover    /    3 - alterar    /    4 - exibir\n");
        scanf(" %d", &choice);

        switch(choice)
        {

            case 1:
                printf("\n\nnumero a inserir: ");
                scanf(" %d", &numero);
                inserir(&lista, numero);

            break;

            case 2:
                printf("\n\nnumero a remover: ");
                scanf(" %d", &numero);
                remover(&lista, numero);

            break;

            case 3:
                printf("\n\nnumero a alterar: ");
                scanf(" %d", &numero);
                printf("\nalterar para: ");
                scanf(" %d", &choice);
                alterar(lista, numero, choice);
                choice = 3;

            break;

            case 4:
                printf("\n\nPara ordem crescente digite   1\n     ordem decrescente digite 0\n     ordem: ");
                scanf(" %d", &numero);
                exibir(lista, numero); //1+ para crescente, 0- para decrescente

            break;

        }
    }
    while(choice!=0);

}
 
void inserir (TLista *L, int numero)
{
    TLista aux = (TLista) malloc(sizeof(TLista));

    aux->valor = numero;
    aux->anterior = NULL;
    aux->proximo = *L;
    if(*L){(*L)->anterior = aux;}
    *L = aux;
	
    organiza(*L);
}

void remover (TLista *L, int numero)
{
    TLista aux = pesquisa(*L, numero);
    aux->anterior->proximo = aux->proximo;
    aux->proximo->anterior = aux->anterior;
    free(aux);

    organiza(*L);
}

void alterar (TLista L, int numeroAntes, int numeroDepois)
{
    TLista aux = pesquisa(L, numeroAntes);
    aux->valor = numeroDepois;

    organiza(L);
}

void organiza(TLista L)
{
    TLista aux1, aux2;
    int numero;
    aux1=L;

    if(L && L->proximo)
    do
    {

        if(aux1->valor == aux1->proximo->valor)
        {
            aux2 = aux1->proximo;
            aux1->proximo->proximo->anterior = aux1;
            aux1->proximo = aux1->proximo->proximo;
            free(aux2);

        }
        else
        {
            if(aux1->valor > aux1->proximo->valor)
            {
                numero = aux1->valor;
                aux1->valor = aux1->proximo->valor;
                aux1->proximo->valor = numero;
                aux1 = L;

            }
            else
            {
                aux1 = aux1->proximo;
            }

        }
        
    }
    while(aux1->proximo!=NULL);

}

void exibir (TLista L, int ordenacao)
{
    printf("\n\n");
    if(ordenacao <= 0)
    {
        while(L->proximo!=NULL)
        {
            L = L->proximo;
        }
    }
    
    while(L!=NULL)
    {
        printf("%d ", L->valor);
        L = (ordenacao>0)?L->proximo:L->anterior;
    }

    system("pause");
}

TLista pesquisa(TLista L, int numero)
{
    while(L && L->valor <= numero)
    {
        if(L->valor == numero)
        {
            return L;
        }
        else
        {
            L = L->proximo;
        }
    }
    return NULL;
}