#include <stdlib.h>
#include <stdio.h>
typedef struct CelulaDupla
{
	struct CelulaDupla *prox;
	struct CelulaDupla *ant;
	int elemento;
}Celula;

Celula *novaCelula(int elemento)
{
	Celula *nova = (Celula*) malloc(sizeof(Celula));
	nova->elemento = elemento;
	nova->prox = nova->ant = NULL;
	return nova;

}
typedef struct ListaDupla
{
	Celula *primeiro;
	Celula *ultimo;
	int tamanho;
}Lista;
Lista novaLista()
{
	Lista tmp;
	tmp.primeiro = tmp.ultimo = novaCelula(-1);
	tmp.tamanho = 0;
	return tmp;
}
void inserirInicio(Lista *l, int x)
{
        Celula *tmp = novaCelula(x);
	tmp->prox = l->primeiro->prox;	
	l->primeiro->prox = tmp;
	tmp->ant = l->primeiro;
	if(l->ultimo == l->primeiro)
            l->ultimo = tmp;
	else
		tmp->prox->ant = tmp;
	tmp = NULL;
        l->tamanho++;
}
void inserirFim(Lista *l, int x)
{
	l->ultimo->prox = novaCelula(x);
	l->ultimo->prox->ant = l->ultimo;
	l->ultimo = l->ultimo->prox;
	l->tamanho++;
}
void inserir(Lista *l, int x, int pos)
{
	if(pos<0 || pos > l->tamanho)
	 return;
	else if (pos == 0)
		inserirInicio(l, x);
	else if(pos == l->tamanho)
		inserirFim(l, x);
	else
	{
		Celula *i = l->primeiro;
		for(int x =0; x<pos; x++)
		{
			i = i->prox;
		}
		Celula *tmp = novaCelula(x);
		tmp->prox = i->prox;
		tmp->ant = i;
		i->prox->ant = tmp;
		i->prox = tmp;
		i = tmp = NULL;
	}
	l->tamanho++;
}
int removerInicio(Lista *l)
{
	if(l->tamanho == 0)
		return -1;
	Celula *tmp = l->primeiro->prox;
	int elemento = tmp->elemento;
	l->primeiro->prox = tmp->prox;
	tmp->prox->ant = l->primeiro;
	free(tmp);
	tmp = NULL;
	l->tamanho--;
	return elemento;

}
int removerFim(Lista *l)
{
	if(l->tamanho == 0)
		return -1;
	int elemento = l->ultimo->elemento;
	l->ultimo = l->ultimo->ant;
	l->ultimo->prox->ant = NULL;
	free(l->ultimo->prox);
	l->ultimo->prox = NULL;
	l->tamanho--;
	return elemento;
	
}
int remover(Lista *l, int pos)
{
	int elemento;
	if(pos<0 || pos>l->tamanho-1 || l->tamanho == 0)
		return -1;
	else if(l->tamanho-1 == pos)
	     elemento = removerFim(l);
	else if(pos == 0)
	     elemento = removerInicio(l);
	else
	{
		Celula *i = l->primeiro->prox;
		for(int x =0; x<pos; x++) i = i->prox;
		i->ant->prox = i->prox;
		i->prox->ant = i->ant;
		elemento = i->elemento;
		i->prox = i->ant = NULL;
		free(i);
		i = NULL;
		l->tamanho--;
	}
	return elemento;
}
void mostrar(Lista *l)
{
	printf("[ ");
	for(Celula *i = l->primeiro->prox; i!= NULL; i = i->prox)
		printf("%d ", i->elemento);
	printf("]\n");
}
void inverter(Lista *l)
{
	Celula *i = l->primeiro->prox;
	Celula *j = l->ultimo;
	while(i !=j && j->prox != i)
	{
		int tmp = i->elemento;
		i->elemento = j->elemento;
		j->elemento = tmp;
		i = i->prox;
		j = j->ant;
	}
}
int main()
{
	Lista l = novaLista();
	inserirInicio(&l,2);
	inserirInicio(&l,4);
	inserir(&l, 5, 1);
	inserirInicio(&l, 15);
	inserirInicio(&l, 22);
	mostrar(&l);
	inverter(&l);
	mostrar(&l);
}
