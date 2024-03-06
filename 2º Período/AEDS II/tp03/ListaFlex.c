#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAXTAM 3923
typedef struct Jogador
{
		int id;
		char nome[100];
		int altura;
		int peso;
		char universidade[100];
		int anoNascimento;
		char cidadeNascimento[100];
		char estadoNascimento[100];
} Jogador;
typedef struct Celula
{
	struct Celula* prox;
	struct Celula* ant;
	Jogador jogador;
}Celula;
Celula* novaCelula(Jogador x)
{
	Celula *tmp = (Celula*) malloc(sizeof(Celula));
	tmp->jogador = x;
	tmp->prox = NULL;
	tmp->ant = NULL;
	return tmp;
}
 typedef struct Lista
{
	int tamanho;
	struct Celula* primeiro;
	struct Celula* ultimo;
}Lista;
 Lista NovaLista()
{
   Lista tmp;
   Jogador a;
   tmp.primeiro = novaCelula(a);
   tmp.ultimo = tmp.primeiro; 
   tmp.tamanho = 0;
   return tmp;
}

 int getId(Jogador* x)
 {
	return x->id;
 }
 char* getNome(Jogador* x )
{
	return x->nome;
}
 int getAltura(Jogador* x)
{
	return x->altura;
}
 int getPeso(Jogador* x)
{
	return x->peso;
}
 char* getUniversidade(Jogador* x)
{
	return x->universidade;
}
 int getAnoNascimento(Jogador* x)
{
	return x->anoNascimento;
}
 char* getCidadeNascimento(Jogador* x)
{
	return x->cidadeNascimento;
}
 char* getEstadoNascimento(Jogador* x)
{
	return x->estadoNascimento;
}
void setId(Jogador *x, int novoId)
{
	x->id = novoId;
}
void setNome(Jogador* x, char* nome)
{
	strcpy(x->nome, nome);
}
void setAltura(Jogador* x, int altura)
{
	x->altura = altura;
}
void setPeso(Jogador* x, int peso)
{
	x->peso = peso;
}
void setUniversidade(Jogador *x, char* universidade)
{
	strcpy(x->universidade, universidade);
}
void setAnoNascimento(Jogador* x, int anoNascimento)
{
	x->anoNascimento = anoNascimento;
}
void setCidadeNascimento(Jogador* x, char* cidadeNascimento)
{
	strcpy(x->cidadeNascimento, cidadeNascimento);
}
void setEstadoNascimento(Jogador* x, char* estadoNascimento)
{
	strcpy(x->estadoNascimento, estadoNascimento);
}
//metodo para criar um clone do jogador
Jogador clone(Jogador *x)
{
	Jogador clone;
	clone.id = getId(x);
	strcpy(clone.nome, getNome(x));
	clone.altura = getAltura(x);
        clone.peso = getPeso(x);
        clone.anoNascimento = getAnoNascimento(x);
        strcpy(clone.universidade, getUniversidade(x));
	strcpy(clone.cidadeNascimento, getCidadeNascimento(x));
	strcpy(clone.estadoNascimento, getEstadoNascimento(x));

	return clone;
}
//Metodo para ler o arquivo e retornar um ponteiro para os Jogadores selecionados
Jogador* ler()
{
 FILE* arq = fopen("/tmp/players.csv","r");
 if(arq == NULL)
 {
	 printf("nao abriu");
 }
 char temp[1000];
 int cont;
 int num = 0;
 Jogador *y=malloc(sizeof(Jogador));
 Jogador *resp = malloc(3923*sizeof(Jogador));
   while(fscanf(arq, "%[^\n]", temp) != EOF)
   {
	   cont = 0; 
	   fgetc(arq);
	   char *items[8];
	   items[4]="";
	   items[6]="";
	   items[7]="";
           char *token  = strtok(temp,",");
	   for(int i = 0; token ; i++)
	   {
            items[i] = token;
            token = strtok(NULL, ",");
            cont++;
	   }
//ifs para tratar casos em que existiam informações faltantes
	   if(cont == 7 && strlen(items[7])==0)
       {
           items[7] = items[6];
       }
	   else if(cont ==5)
	   {
		   items[5] = items[4];
		   items[4] = "";
	   }
       if(atoi(items[5]) == 0)
       {
           items[6] = items [5];
       }
	   if(atoi(items[4]) != 0)
       {
           items[5] = items[4];
       }

	   setId(y, atoi(items[0]));
	   setNome(y, items[1]);
	   setAltura(y, atoi(items[2]));
	   setPeso(y, atoi(items[3]));
	   setUniversidade(y, items[4]);
	   setAnoNascimento(y, atoi(items[5]));
       setCidadeNascimento(y, items[6]);
	   setEstadoNascimento(y, items[7]);

//ifs para setar corretamente campos não informados
           if(strlen(items[4])==0 || atoi(getUniversidade(y))>0)
	   {
	           setUniversidade(y, "nao informado");
	   }
	     if(strlen(items[6])==0)
	   {
		  setCidadeNascimento(y, "nao informado");
	   }
	     if(strlen(items[7])==0)
	   {
		   setEstadoNascimento(y, "nao informado");
	   }
	     if(getAnoNascimento(y)==0)
         {
             setAnoNascimento(y, atoi(items[4]));
         }
         
//comparar o input do usuario com o que esta sendo lid
	 resp[num] =clone(y);
	 num++;
   }
   fclose(arq);
   return resp;
}

//função para imprimir o jogador selecionado
void imprimir(Lista *l)
{
	int j = 0;
	for(Celula* i =l->primeiro->prox; i!=NULL; i = i->prox)
	{
	printf("[");
	printf("%d", getId(&i->jogador));
	printf(" ## ");
	printf("%s", getNome(&i->jogador));
	printf(" ## ");
	printf("%d", getAltura(&i->jogador));
	printf(" ## ");
	printf("%d", getPeso(&i->jogador));
	printf(" ## ");
	printf("%d", getAnoNascimento(&i->jogador));
	printf(" ## "); 
	printf("%s", getUniversidade(&i->jogador));
	printf(" ## "); 
	printf("%s", getCidadeNascimento(&i->jogador));
	printf(" ## ");
	printf("%s]", getEstadoNascimento(&i->jogador));
	printf("\n");
	}
}
//metodo para trocar dois jogadores de posição no array
void swap(Jogador *i, Jogador *j)
{
	Jogador tmp = *i;
	*i = *j;
	*j = tmp;
	
}
//metodo para comparar jogadores com o atributo primário sendo o EstadoNascimento e o secundário o nome
 int compare2(Jogador *x, Jogador *y) 
{
    char jog1[200];
    char jog2[200];
    strcpy(jog1, getEstadoNascimento(x));
    strcat(jog1, getNome(x));    
    strcpy(jog2, getEstadoNascimento(y));
    strcat(jog2, getNome(y));
      return strcmp(jog1, jog2);
}
void inserirInicio(Jogador x, Lista *l)
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
void inserirFim(Jogador x, Lista *l)
{
		l->ultimo->prox = novaCelula(x);
		l->ultimo->prox->ant = l->ultimo;
		l->ultimo = l->ultimo->prox;
		l->tamanho++;
}
void inserir(int pos, Jogador x, Lista *l)
{
	if(pos <0 || pos> l->tamanho)
		return;

	else if( pos == 0)
	{
		inserirInicio(x, l);
	}
	else if(pos == l->tamanho)
	{
		inserirFim(x, l);
	}
	else
	{
		Celula *i = l->primeiro;
		for(int x = 0; x < pos; x++)
		{
			i = i->prox;

		}
		Celula *tmp = novaCelula(x);
		tmp->prox = i->prox;
		tmp->ant = i;
		i->prox->ant = tmp;
		i->prox = tmp;
		i = tmp = NULL;
		l->tamanho++;
	}


}
Jogador removerInicio(Lista *l)
{
       if(l->tamanho == 0)
       {
	       printf("Array vazio");
	       exit(1);
       }
       Celula *tmp = l->primeiro->prox;
       Jogador removido = tmp->jogador;
       l->primeiro->prox = tmp->prox;
       tmp->prox->ant = l->primeiro;
       free(tmp);
       tmp = NULL;
       l->tamanho--;
       return removido;
}
Jogador removerFim(Lista *l)
{
	if(l->tamanho == 0)
	{
		printf("Array vazio");
		exit(1);
	}
        Jogador removido =  l->ultimo->jogador;
	l->ultimo = l->ultimo->ant;
	l->ultimo->prox->ant = NULL;
	free(l->ultimo->prox);
	l->ultimo->prox = NULL;
	l->tamanho--;
	return removido;

}
Jogador remover(int pos, Lista *l)
{
	Jogador removido;
	if(pos<0 || pos >= l->tamanho-1)
	{
		printf("Posição invalida");
		exit(1);
	}

	else if(pos == 0)
	{
		removido = removerInicio(l);
	}
	else if(pos == l->tamanho-1)
	{
		removido = removerFim(l);
	}
	else
	{
		Celula *i = l->primeiro->prox;
		for(int x = 0; x<pos; x++)
		{
			i = i->prox;
		}
		i->ant->prox = i->prox;
		i->prox->ant = i->ant;
		removido = i->jogador;
		i->prox = i->ant = NULL;
		free(i);
		i = NULL;
		l->tamanho--;

	}
	return removido;
}
	/**
	 * Algoritmo de ordenacao Quicksort.
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
	 */
         void quicksort(Celula *esq, Celula *dir, Lista *l) {
        Celula *i = esq;
	Celula *j = dir;
        Celula *pivo = esq;
        while (i->ant != j && j->prox != i->ant) {
            while (compare2(&i->jogador, &pivo->jogador)<0) i = i->prox;
            while (compare2(&j->jogador, &pivo->jogador)>0) j = j->ant;
            if (i->ant != j && j->prox != i->ant ) {
                Jogador tmp = i->jogador;
		i->jogador = j->jogador;
		j->jogador = tmp;
                i = i->prox;
                j = j->ant;
            }
        }
	if (esq != j && esq->ant != j)  quicksort(esq, j, l);
	if (i != dir && i!= dir->prox)  quicksort(i, dir, l);
    } 
   void sort(Lista *l)
{
	quicksort(l->primeiro->prox, l->ultimo, l);
}
int main()
{ 
//criação de variavéis e alocação de memória
  char temp[100];
  int i =0;
  Lista l = NovaLista();
  Jogador *y = malloc(3923*sizeof(Jogador));
  y = ler();
  //while para leitura do input ate ser digitado FIM
  while(1)
  {
  scanf("%[^\n]", temp);
  char ch = getchar();
   if(strcmp(temp, "FIM")== 0)
   {
		  break; 
   }
   int num = atoi(temp);
   inserirFim(y[num+1], &l); 
  }
          sort(&l);
	 imprimir(&l);
  
 // imprimir(&l);
  free(y);
  return 0;
}
