/*
Ponteiros soltos
Convém não deixar dangling pointers no seu código,
pois isso pode mascarar erros de programação e
pode ser explorado por hackers para atacar sua máquina. 

Portanto, depois de cada  free (ptr),  faça  ptr = NULL:

free (ptr);
ptr = NULL;

Há quem diga que ponteiros soltos constituem um erro de programação. 
Isso não é verdade. Pelo contrário, atribuir valor a ponteiro que se tornou inútil
é decididamente deselegante.  Infelizmente, não há como lidar com hackers de maneira elegante…

Por motivos semelhantes, recomenda-se inicializar todo ponteiro
(ou seja, atribuir algum valor ao ponteiro) tão logo ele é declarado.

Por exemplo, recomenda-se escrever

int *p = NULL;
em vez que

int *p;


Atualizado em 2018-05-29
https://www.ime.usp.br/~pf/algoritmos/aulas/footnotes/null-after-free.html

*/
