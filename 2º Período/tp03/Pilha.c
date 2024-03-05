#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
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
	struct Celula *prox;
	Jogador jogador;
}Celula;

Celula *novaCelula(Jogador x)
{
	Celula *nova = (Celula*) malloc(sizeof(Celula));
	nova->jogador = x;
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
void imprimirRec(int x, Celula* i, Pilha *p)
{
	if(i!=NULL)
	{
	imprimirRec(--x, i->prox, p);	
	printf("[");
	printf("%d]", x);
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
	}
}
void imprimir(Pilha *p)
{
	imprimirRec(p->tamanho, p->topo, p);
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
void inserir(Jogador x, Pilha *p)
{
  Celula *tmp = novaCelula(x);
  tmp->prox = p->topo; 
  p->topo = tmp;
  p->tamanho++;
  tmp = NULL;
}
Jogador remover(Pilha *p)
{
  if(p->topo == NULL)
  {
    Jogador a;   
    return a;
  }
  Jogador removido = p->topo->jogador;  
  Celula *tmp = p->topo;
  p->topo = p->topo->prox;
  tmp->prox = NULL;
  tmp = NULL;
  free(tmp);
  p->tamanho--;
  return removido;
}
  int main()
{ 
//criação de variavéis e alocação de memória
  char temp[100];
  int i =0;
  Pilha p = novaPilha();
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
   inserir(y[num+1], &p); 
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
		 inserir(y[id+1], &p);
	 }
	 else if(strcmp(acao, "R")==0)
	 
	 {
	 	 Jogador removido = remover(&p);
		 printf("(R) %s\n", getNome(&removido));
	 }
   }
  imprimir(&p);
  free(y);
  return 0;
}


