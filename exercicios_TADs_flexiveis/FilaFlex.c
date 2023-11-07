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
typedef struct Fila
{
	Celula *ultimo;
	Celula *primeiro;
	int tamanho;
}Fila;
Fila novaFila()
{
	Fila tmp;
        tmp.primeiro = tmp.ultimo = novaCelula(-1);
	tmp.tamanho = 0;
	return tmp;
	
}
void inserir(Fila *f, int x)
{
	f->ultimo->prox = novaCelula(x);
	f->ultimo = f->ultimo->prox;
	f->tamanho++;
}
int remover(Fila *f)
{
	if(f->ultimo == f->primeiro)
		return -1;
	Celula *tmp = f->primeiro->prox;
	f->primeiro->prox = f->primeiro->prox->prox;
	int elemento = tmp->elemento;
	tmp->prox = NULL;
	free(tmp);
	tmp = NULL;
	return elemento;
}
int getMaior(Fila *f)
{
	if(f->ultimo == f->primeiro)
		return -1;
	int maior = f->primeiro->prox->elemento;
	for(Celula *i = f->primeiro->prox->prox; i!=NULL; i = i->prox)
	{
		if(i->elemento > maior)
			maior = i->elemento;
	}
	return maior;
}
int getTerceiro(Fila *f)
{
	int k = 3;
	int x = 1;
	Celula *i = f->primeiro->prox;
	while(x<k)
	 {	
		 x++;
		 i = i->prox;
	 }
	return i->elemento;
}
int getSoma(Fila* f)
{
	int soma = 0;
	for(Celula *i = f->primeiro->prox; i !=NULL; i = i->prox)
	{
		soma += i->elemento;
	}
	return soma;
}
void mostrar(Fila *f)
{
	if(f->ultimo == f->primeiro)
		return;
	printf("[ ");
	for(Celula *i = f->primeiro->prox; i != NULL; i = i->prox)
	{
		printf("%d ", i->elemento);
	}
	printf("]\n");
}
void inverter(Fila *f)
{
	Celula *i, *j;
	i = j = f->primeiro->prox;
	while(j->prox != NULL) j = j->prox;
	while(i != j && j->prox != i)
	{
		int tmp = i->elemento;
		i->elemento = j->elemento;
		j->elemento = tmp;
		i = i->prox;
		Celula *k = f->primeiro;
		while(k->prox != j) k = k->prox;
		j = k;
	}	
}
int parANDmulti5(Celula *i)
{
   if(i == NULL)
	   return 0;
   else
   {	   
	      if(i->elemento % 2 == 0 && i->elemento % 5 == 0)
		      return 1 + parANDmulti5(i->prox);
	      else
		      return parANDmulti5(i->prox);
   }

}
int parANDmulti5REC(Fila *f)
{
	return parANDmulti5(f->primeiro->prox);
}
int main()
{
	Fila f = novaFila();
	inserir(&f, 3);
	inserir(&f, 6);
	inserir(&f, 10);
	inserir(&f, 5);
	inserir(&f, 2);
	mostrar(&f);
	remover(&f);
	mostrar(&f);
	inverter(&f);
	mostrar(&f);
	printf("%d\n", parANDmulti5REC(&f));
}


