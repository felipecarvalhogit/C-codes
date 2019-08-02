/* Esta função recebe um inteiro "num" e uma
// lista encadeada "L" de inteiros e devolve
// o endereço do "no'" que contém num.
// Se tal no' não existe, devolve NULL.
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
