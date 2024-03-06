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
 typedef struct No
{

	struct No *esq, *dir;
	Jogador elemento;
	int nivel;
}No;
No* novoNo(Jogador x)
{
	No *tmp = (No*)malloc(sizeof(No)); 
	tmp->elemento = x;
	tmp->esq = NULL;
	tmp->dir = NULL;
	tmp->nivel = 1;
	return tmp;
}
 typedef struct ArvoreBinaria
{
	struct No *raiz;

}ArvoreBinaria;
ArvoreBinaria novaArvore()
{
	ArvoreBinaria tmp;
	tmp.raiz = NULL;
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
  int getNivel(No *no)
{
	return (no == NULL) ? 0 : no->nivel;
}
   int max(int x, int y)
{
	if( x > y)
		return x;
	else
		return y;
}
   void setNivel(No *no)
{
	no->nivel = 1 + max(getNivel(no->esq), getNivel(no->dir));
}
   No* rotacionarDir(No *no)
{
	No* noEsq = no->esq;
	No* noEsqDir = noEsq->dir;

	noEsq->dir = no;
	no->esq = noEsqDir;
	setNivel(no);
	setNivel(noEsq);

	return noEsq;
}
  No* rotacionarEsq(No *no)
{
	No* noDir = no->dir;
	No* noDirEsq = noDir->esq;

	noDir->esq = no;
	no->dir = noDirEsq;
	setNivel(no);
	setNivel(noDir);

	return noDir;
}
    No* balancear(No *no)
{
	if(no != NULL)
	{
		int fator = getNivel(no->dir) - getNivel(no->esq);
		if(abs(fator) <= 1)
			setNivel(no);
		else if(fator == 2)
		{
			int fatorFilhoDir = getNivel(no->dir->dir) - getNivel(no->dir->esq);

			if(fatorFilhoDir == -1)
				no->dir = rotacionarDir(no->dir);
		
		no = rotacionarEsq(no);
		}
		else if( fator == -2)
		{
			int fatorFilhoEsq = getNivel(no->esq->dir) - getNivel(no->esq->esq);

		if(fatorFilhoEsq == 1)
			no->esq = rotacionarEsq(no->esq);

		      no = rotacionarDir(no);
	       }

	}
	return no;

}
      No* inserirRec(No *i, Jogador elemento)
{
	if(i == NULL)
	{
		i = novoNo(elemento);
	}
	else if(strcmp(getNome(&elemento), getNome(&(i->elemento))) < 0)
	{
              i->esq =  inserirRec((i->esq), elemento); 
	}
	else if(strcmp(getNome(&elemento), getNome(&(i->elemento))) > 0)
	{
	      i->dir = 	inserirRec(i->dir, elemento);
	}
	 return  balancear(i);
}

   void inserir(ArvoreBinaria *ab, Jogador elemento)
{
	ab->raiz = inserirRec(ab->raiz, elemento);
}
  bool pesquisarRec(No *i, char nome[])
{
	bool resp;
	if(i == NULL)
	{
		resp = false;
	}
	else
	{
		if	(strcmp(getNome(&(i->elemento)), nome) == 0)
			resp = true;
		else if(strcmp(nome, getNome(&(i->elemento))) < 0)
		{
			        printf(" esq");
				resp = pesquisarRec(i->esq, nome);
		}
		else
		{
			printf(" dir");
		 
		 	resp = pesquisarRec(i->dir, nome);
		}
	}
	return resp;
}
bool pesquisar(ArvoreBinaria *ab, char nome[])
{
	printf("%s", nome);
	printf(" raiz");
	return pesquisarRec(ab->raiz, nome);
}
   int main()
{
//criação de variavéis e alocação de memória
  char temp[100];
  int i =0;
  ArvoreBinaria ab = novaArvore();
  Jogador *y = malloc(3923*sizeof(Jogador));
  y = ler();
  //while para leitura do input ate ser digitado FIM
  while(1)
  {
  scanf("%[^\n]", temp);
  char t = getchar();
   if(strcmp(temp, "FIM")== 0)
   {
		  break;
   }
   i++;
   int num = atoi(temp);
   inserir(&ab, y[num+1]);
  }
  while(1)
  {
          scanf("%[^\n]", temp);
	  char ch = getchar();
	  if(strcmp(temp, "FIM") == 0)
		  break;
	  else 
         {	 
		 if (pesquisar(&ab, temp))
		 {
			 printf(" SIM\n");
		 }
		 else
		         printf(" NAO\n");
         }
  }
  free(y);
  return 0;
}
