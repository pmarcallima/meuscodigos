#include <stdlib.h>
#include <stdio.h>
typedef struct Celula
{
	struct Celula *prox;
	int elemento;
}Celula;

Celula *novaCelula(int elemento)
{
	Celula *nova = (Celula*) malloc(sizeof(Celula));
	nova->elemento = elemento;
	nova->prox = NULL;
	return nova;

}
typedef struct Lista
{
	int tamanho;
	Celula *primeiro;
	Celula *ultimo;
}Lista;
Lista novaLista()
{
	Lista tmp;
	tmp.tamanho = 0;
	tmp.primeiro = tmp.ultimo = novaCelula(-1);
	return tmp;
}
void inserirInicio(Lista *l, int x)
{
	Celula *tmp = novaCelula(x);
	tmp->prox = l->primeiro->prox;
	l->primeiro->prox = tmp;
	if(l->primeiro == l->ultimo)
		l->ultimo = tmp;
	tmp = NULL;
	l->tamanho++;
}
void inserirFim(Lista *l, int x)
{
	Celula *tmp = novaCelula(x);
	l->ultimo->prox = tmp;
	l->ultimo = tmp;
	tmp = NULL;
	l->tamanho++;
}
void inserir(Lista *l, int x, int pos)
{
   if(pos<0 || pos>l->tamanho)
   {
	   return;
   }
   else if(pos == 0)
	   inserirInicio(l, x);
   else if(pos == l->tamanho)
	   inserirFim(l, x);
   else
   {
   Celula *i = l->primeiro;
   for(int x = 0; x<pos; x++)
   {
	   i = i->prox;
   }
   Celula *tmp = novaCelula(x);
   tmp->prox = i->prox;
   i->prox = tmp;
   tmp = i = NULL;
   l->tamanho++;
   }	
}
int removerInicio(Lista *l)
{
   if(l->primeiro == l->ultimo)
	   return -1;
   Celula *tmp = l->primeiro->prox;
   int elemento = tmp->elemento;
   l->primeiro->prox = tmp->prox;
   tmp->prox = NULL;
   free(tmp);
   tmp = NULL;
   l->tamanho--;
   return elemento;
}
int removerFim(Lista *l)
{
   if(l->ultimo == l->primeiro)
          return -1;	   
   Celula *i = l->primeiro->prox;
   while(i->prox != l->ultimo) i = i->prox;
   int elemento = l->ultimo->elemento;
   l->ultimo = i;
   free(l->ultimo->prox);
   i = l->ultimo->prox = NULL;
   l->tamanho--;
   return elemento;
}
int remover(Lista *l, int pos)
{
	int elemento;
	if(l->ultimo == l->primeiro || pos <0 || pos> l->tamanho-1)
	{
		return -1;
	}
	else if (pos == 0)
	    elemento =	removerInicio(l);
	else if(pos == l->tamanho-1)
            elemento = 	removerFim(l);
	else
	{
	Celula *i;
	i = l->primeiro;
	for(int x =0; x<pos ; x++)
	{
             i = i->prox;
	}
	Celula *tmp = i->prox;
	i->prox = tmp->prox;
	tmp->prox = NULL;
	elemento = tmp->elemento;
	free(tmp);
	tmp = i = NULL;
	l->tamanho--;
	}
	return elemento;
}
int removerSegundo(Lista *l)
{
	if(l->tamanho<2 || l->ultimo == l->primeiro)
		return -1;
	Celula *i = l->primeiro;
	for(int x = 0; x<1; x++)
		i= i->prox;
	Celula *tmp = i->prox;
	if(tmp == l->ultimo)
		l->ultimo = i;
	int elemento = tmp->elemento;
	i->prox = tmp->prox;
	tmp->prox = NULL;
	free(tmp);
	tmp= i = NULL;
	return elemento;

}
void mostrar(Lista *l)
{
	printf("[ ");
	for(Celula *i = l->primeiro->prox; i!=NULL; i = i->prox)
	{
		printf("%d ", i->elemento);

	}
	printf("]\n");
}
void inverter(Lista *l)
{
     Celula *i, *j;
     i = l->primeiro->prox;
     j = l->ultimo;
     while(i!=j && j->prox != i)
     {
	     int tmp = i->elemento;
	     i->elemento = j->elemento;
	     j->elemento = tmp;
	     i = i->prox;
	     Celula *k = l->primeiro;
	     while(k->prox != j) k = k->prox;
	      j = k;
     }
}
int main()
{
	Lista l = novaLista();
	inserirInicio(&l, 2);
	inserirFim(&l, 5);
	inserir(&l,3, 1);
	inserirFim(&l,4);
        inserirFim(&l, 10);
	mostrar(&l);
	inverter(&l);
	mostrar(&l);
}
