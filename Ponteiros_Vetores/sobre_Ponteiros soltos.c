/*
Ponteiros soltos
Conv�m n�o deixar dangling pointers no seu c�digo,
pois isso pode mascarar erros de programa��o e
pode ser explorado por hackers para atacar sua m�quina. 

Portanto, depois de cada  free (ptr),  fa�a  ptr = NULL:

free (ptr);
ptr = NULL;

H� quem diga que ponteiros soltos constituem um erro de programa��o. 
Isso n�o � verdade. Pelo contr�rio, atribuir valor a ponteiro que se tornou in�til
� decididamente deselegante.  Infelizmente, n�o h� como lidar com hackers de maneira elegante�

Por motivos semelhantes, recomenda-se inicializar todo ponteiro
(ou seja, atribuir algum valor ao ponteiro) t�o logo ele � declarado.

Por exemplo, recomenda-se escrever

int *p = NULL;
em vez que

int *p;


Atualizado em 2018-05-29
https://www.ime.usp.br/~pf/algoritmos/aulas/footnotes/null-after-free.html

*/
