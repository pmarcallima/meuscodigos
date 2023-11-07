#include <stdlib.h>
#include<stdio.h>
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
typedef struct Pilha
{
    int tamanho;
    struct Celula *topo;
}Pilha;
Pilha novaPilha()
{
	Pilha temp;
	temp.topo = NULL;
	temp.tamanho = 0;
	return temp;
}
void inserir(Pilha *p, int x)
{
  Celula *tmp = novaCelula(x);
  tmp->prox = p->topo; 
  p->topo = tmp;
  p->tamanho++;
  tmp = NULL;
}
int remover(Pilha *p)
{
  if(p->topo == NULL)
  {
    return -1;
  }
  int elemento = p->topo->elemento;  
  Celula *tmp = p->topo;
  p->topo = p->topo->prox;
  tmp->prox = NULL;
  tmp = NULL;
  free(tmp);
  p->tamanho--;
  return elemento;
}
void mostrar(Pilha *p)
{
  printf("[ ");
  for(Celula *i = p->topo; i!=NULL; i = i->prox)
  {
     printf("%d ", i->elemento);
  }
  printf("]\n");
}
int main()
{
	Pilha p = novaPilha();
	inserir(&p,1);
	inserir(&p,2);
	mostrar(&p);
	remover(&p);
	mostrar(&p);
}
  


