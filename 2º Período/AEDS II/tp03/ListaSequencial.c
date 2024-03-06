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
 typedef struct Lista
{
	int tamanho;
	struct Jogador array[MAXTAM];
}Lista;
 Lista NovaLista()
{
   Lista tmp; 
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
	for(int i =0; i<l->tamanho; i++)
	{
	printf("[");
	printf("%d]", i);
	printf(" ## ");
	printf("%s", getNome(&l->array[i]));
	printf(" ## ");
	printf("%d", getAltura(&l->array[i]));
	printf(" ## ");
	printf("%d", getPeso(&l->array[i]));
	printf(" ## ");
	printf("%d", getAnoNascimento(&l->array[i]));
	printf(" ## "); 
	printf("%s", getUniversidade(&l->array[i]));
	printf(" ## "); 
	printf("%s", getCidadeNascimento(&l->array[i]));
	printf(" ## ");
	printf("%s ##", getEstadoNascimento(&l->array[i]));
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
    if (getAltura(x) != getAltura(y)) {
        return (getAltura(x) > getAltura(y));
    } else {
		return strcmp(getNome(x), getNome(y))>0;
    }
}
void inserirInicio(Jogador x, Lista *l)
{
	if(l->tamanho >= MAXTAM)
	{ 
            printf("erro");
	    return;
	}
	for(int i = l->tamanho; i>0; i--)
	{
		l->array[i] = l->array[i-1];

	}
	l->array[0] = x;
	l->tamanho++;
	
}
void inserirFim(Jogador x, Lista *l)
{
	if(l->tamanho >= MAXTAM)
	{
		printf("erro");
		return;
	}
		l->array[l->tamanho] = x;
		l->tamanho++;
}
void inserir(int pos, Jogador x, Lista *l)
{
	if(pos <0 || pos> l->tamanho || l->tamanho >= MAXTAM)
		return;
	else
	{
		for(int i = l->tamanho; i>pos; i--)
		{
			
			l->array[i] = l->array[i-1];
		}
		l->array[pos] = x;
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
       Jogador removido = l->array[0];	 
       for(int i =0; i<l->tamanho; i++)
       {
	       l->array[i] = l->array[i+1];
       }
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

	return l->array[--l->tamanho];

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
		removido = l->array[pos];
		for(int i = pos; i< l->tamanho-1; i++)
		{
			l->array[i] = l->array[i+1];
		}
		l->tamanho--;

	}
	return removido;
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
  int qnt;
  scanf("%d", &qnt);
  char ch = getchar();
 for(int j = 0; j<qnt; j++)
  {
	  char acao[2];
	  scanf("%s", acao);
	 if(strcmp(acao, "II")== 0)
		 {
		             int id;
			     scanf("%d", &id);
			     ch =getchar();
                             inserirInicio(y[id+1], &l);
		} 
	 else if(strcmp(acao, "IF")== 0)
	 {
		 int id;
		 scanf("%d", &id);
		 ch = getchar();
		 inserirFim(y[id+1], &l);
	 }
	 else if(strcmp(acao, "I*")==0)
	 {
		 int id;
		 int pos;
		 scanf("%d %d", &pos, &id);
		 inserir(pos, y[id+1], &l);
	 }
	 else if(strcmp(acao, "RI")==0)
	 {
		 Jogador removido = removerInicio(&l);
		 printf("(R) %s\n", getNome(&removido));
	 }
	 else if(strcmp(acao, "RF")==0)
	 {
	         Jogador removido = removerFim(&l);
		 printf("(R) %s\n", getNome(&removido));
	 }
	 else
	 {
		 int pos;
		 scanf("%d", &pos);
		 ch = getchar();
		 Jogador removido = remover(pos, &l);
		 printf("(R) %s\n", getNome(&removido));
	 }
  }
  imprimir(&l);
  free(y);
  return 0;
}
