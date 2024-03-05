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
Celula *novaCelulaCabeca()
{
	Celula *nova = (Celula*) malloc(sizeof(Celula));
	nova->prox = NULL;
	return nova;
}
typedef struct Lista
{
	struct Celula *primeiro;
	struct Celula *ultimo;
}Lista;
Lista novaLista()
{
	Lista tmp;
	tmp.primeiro = novaCelulaCabeca();
	tmp.ultimo = tmp.primeiro;
	return tmp;
}
typedef struct Hash
{
	int tam;
	Lista *tabela;
	
}Hash;
Hash *novoHash(int tam)
{
       Hash *hash = (Hash*) malloc(sizeof(Hash));
       hash->tam = tam;
       hash->tabela = (Lista*) malloc(tam*sizeof(Lista));
       for(int i = 0; i<tam; i++)
         hash->tabela[i] = novaLista();
       return hash;
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
   int hash(int altura, int tam)
{
	//printf("hash calculado");
	return altura % tam;
}
void inserirLista(Lista *l, Jogador j)
{
	Celula *tmp = novaCelula(j);
	l->ultimo->prox = tmp;
        l->ultimo = tmp;	
	tmp = NULL;
}
   void inserir(Hash *h, Jogador j)
{  
     int pos = hash(getAltura(&j), h->tam);
     inserirLista(&h->tabela[pos], j);
}
  bool pesquisar(Hash *h, Jogador j)
{
	bool resp = false;
	int pos = hash(getAltura(&j), h->tam);
	for(Celula *i = h->tabela[pos].primeiro->prox; i != NULL; i = i->prox)
	{
            if(strcmp(getNome(&i->jogador), getNome(&j))==0)
	    {
		    resp = true;
		    i = h->tabela[pos].ultimo;
	    }
	}
	return resp;
}
  Jogador PesquisaNome(Jogador *y, char nome[])
{
	for(int i =0; i<3923; i++)
	{
		if(strcmp(getNome(&y[i]), nome)==0)
			return y[i];
	}
}
  int main()
{
//criação de variavéis e alocação de memória
  char temp[100];
  int i =0;
  Hash *h = novoHash(25);
  Jogador *y = malloc(3923*sizeof(Jogador));
  y = ler();
  //while para leitura do input ate ser digitado FIM
  while(1)
  {
  fgets(temp, 100, stdin);
   if(strcmp(temp, "FIM")== 0)
   {
		  break;
   }
   i++;
   int num = atoi(temp);
   inserir(h, y[num+1]);
  }
  while(1)
  {
          fgets(temp, sizeof(temp), stdin);
	  char ch = getchar();
	  if(strcmp(temp, "FIM") == 0)
		  break;
	  else 
         {	
                Jogador t = PesquisaNome(y, temp);		 
		 if (pesquisar(h, t))
		 {
			 printf("%s SIM\n", getNome(&t));
		 }
		 else
		         printf("%s NAO\n", getNome(&t));
         }
  }
  free(h);
  free(y);
  return 0;
}
