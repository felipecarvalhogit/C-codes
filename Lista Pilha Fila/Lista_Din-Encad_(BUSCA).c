/* Esta fun��o recebe um inteiro "num" e uma
// lista encadeada "L" de inteiros e devolve
// o endere�o do "no'" que cont�m num.
// Se tal no' n�o existe, devolve NULL.
*/

TLista busca (TLista L, int num)
{
   Tlista aux;
   aux = L;
   while ((aux) && (aux->valor != num)) //verifica toda a lista
      aux = aux->prox; 
   return aux;
}

//Funcao tem comportamento correto mesmo que a lista esteja vazia.

//Recursiva:

TLista busca (TLista L, int num)
{
   if (!(L))  return NULL;
   if (L->valor == num)  return L;
   return busca_r (L->prox, num);
}
