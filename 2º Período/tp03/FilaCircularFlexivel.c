#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAXTAM 5
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
	Jogador jogador;
}Celula;
Celula* novaCelula(Jogador x)
{
	Celula *tmp = (Celula*) malloc(sizeof(Celula));
	tmp->jogador = x;
	tmp->prox = NULL;
	return tmp;
}
 typedef struct Fila
{
	int tamanho;
	float media;
	struct Celula* primeiro; 
	struct Celula* ultimo;
}Fila;
 Fila NovaFila()
{
   Fila tmp;
   Jogador a;   
   tmp.tamanho = 0;
   tmp.media = 0;
   tmp.primeiro = novaCelula(a);
   tmp.ultimo = tmp.primeiro;
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
void imprimir(Fila *f)
{
	int j = 0;	
	for(Celula* i = f->primeiro->prox; i!=f->ultimo->prox; i = i->prox)
	{
	printf("[");
	printf("%d]", j);
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
	printf("%s ##", getEstadoNascimento(&i->jogador));
	printf("\n");
	j++;
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
    if (getAltura(x) != getAltura(y)) {
        return (getAltura(x) > getAltura(y));
    } else {
		return strcmp(getNome(x), getNome(y))>0;
    }
}
 void media(Fila *f)
{
	float cont = 0;
	float total = 0;
	for(Celula* i = f->primeiro->prox; i != f->ultimo->prox; i= i->prox)
	{
		cont++;
		total += getAltura(&i->jogador);
           
	}
	f->media = total/cont;
}
Jogador removerInicio(Fila *f)
{
       if(f->primeiro == f->ultimo)
       {
	       printf("Array vazio");
	       exit(1);
       }
       Celula* tmp = f->primeiro->prox;
       Jogador removido = tmp->jogador;
       f->primeiro->prox = tmp->prox;
       tmp->prox = NULL;
       free(tmp);
       tmp = NULL;
         f->tamanho--;
       return removido;
}

void inserirFim(Jogador x, Fila *f)
{
	if(f->tamanho == MAXTAM)
	{
		Jogador removido = removerInicio(f);
	}
		f->ultimo->prox = novaCelula(x);
		f->ultimo = f->ultimo->prox;
		f->ultimo->prox = f->primeiro;
		media(f);
		printf("%.f\n", f->media);
		f->tamanho++;
}
	
int main()
{ 
//criação de variavéis e alocação de memória
  char temp[100];
  int i =0;
  Fila f = NovaFila();
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
   inserirFim(y[num+1], &f); 
  }
  int qnt;
  scanf("%d", &qnt);
  char ch = getchar();
 for(int j = 0; j<qnt; j++)
  {
	  char acao[2];
	  scanf("%s", acao);
	 if(strcmp(acao, "I")== 0)
	 {
		 int id;
		 scanf("%d", &id);
		 ch = getchar();
		 inserirFim(y[id+1], &f);
	 }
	 else if(strcmp(acao, "R")==0)
	 
	 {
	 	 Jogador removido = removerInicio(&f);
		 printf("(R) %s\n", getNome(&removido));
	 }
   }
  imprimir(&f);
  free(y);
  return 0;
}
