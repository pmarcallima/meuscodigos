#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXQUANT 1000000
#define MIN 1
#define MAXTAM 100
#define MAXRAIO 10000
#define MAXELEMENTOS 100


/**
 * Struct para definir "Lua".
 */
typedef struct Lua
{
	char nomeLua[MAXTAM];
	int raioLua;
} Lua;
/**
 * Struct para definir "Planeta".
 */
typedef struct Planeta
{
	char nomePlaneta[MAXTAM];
	int raioPlaneta;
        int quantidadeLuas;
	Lua* luas;
} Planeta;
/** 
 * Struct para definir "Sistema".
 */
typedef struct Sistema
{
	int tempoDescoberta;
	char nomeSistema[MAXTAM];
	int raioSol;
	int quantidadePlanetas;
	Planeta* planetas;
} Sistema;
/**
 * Metódo que cria um Sistema.
 * @return Sistema inicializado.
 */
Sistema* novoSistema()
{
      Sistema *tmp= (Sistema*) malloc(sizeof(Sistema));
      tmp->tempoDescoberta = 0;
      strcpy(tmp->nomeSistema, "");
      tmp->raioSol = 0;
      tmp->quantidadePlanetas = 0;
      return tmp;
}
/** 
 * Metódo para imprimir os planetas de trás pra frente.
 * @param s Sistemas a serem impressos.
 * @param numSistemas Quantidade de sistemas alocadas no ponteiro.
 */
void imprimir(Sistema *s, int numSistemas)
{
	for(int i = numSistemas-1; i>=0; i--)
	printf("%s\n", s[i].nomeSistema);
}
/**
 * Metódo iterativo para achar o maior planeta do sistema.
 * @param s Sistema a ser buscado o planeta.
 * @return valor int do maior raio de planeta do sistema.
 */
int getMaiorPlaneta(Sistema s)
{
	int maior = s.planetas[0].raioPlaneta;
	for(int i =1; i< s.quantidadePlanetas; i++)
	{
		if(maior < s.planetas[i].raioPlaneta)
			maior = s.planetas[i].raioPlaneta;
	}
	return maior;
}
/**
 * Metódo iterativo para achar a maior lua de um sistema.
 * @param s Sistema a ser buscada a lua.
 * return valor int do maior raio de lua do sistema.
 */
int getMaiorLua(Sistema s)
{
	int maior = s.planetas[0].luas[0].raioLua;
	for(int i = 0; i< s.quantidadePlanetas; i++)
	{
		for(int j = 0; j<s.planetas[i].quantidadeLuas; j++)
		
		{
			if(maior < s.planetas[i].luas[j].raioLua)
				maior = s.planetas[i].luas[j].raioLua;
		}
	}
}
/**
 * Metódo para comparar dois sistemas com base em 6 critérios.
 * @param a Primeiro Sistema.
 * @param b Segundo Sistema.
 * @return true caso a seja menor que b.
 */
bool comparar(Sistema a, Sistema b)
{
	/**
	 * Caso ambos possuam o mesmo valor no criteŕio,
	 * é utilizado o próximo if
	 */
	if(a.raioSol != b.raioSol)
	  return a.raioSol<b.raioSol;
	if(a.quantidadePlanetas != b.quantidadePlanetas)
		return a.quantidadePlanetas<b.quantidadePlanetas;
	if(getMaiorPlaneta(a) != getMaiorPlaneta(b))
		return getMaiorPlaneta(a) < getMaiorPlaneta(b);
	if(a.planetas->quantidadeLuas != b.planetas->quantidadeLuas)
		return a.planetas->quantidadeLuas < b.planetas->quantidadeLuas;
	if(getMaiorLua(a) != getMaiorLua(b))
		return getMaiorLua(a) < getMaiorLua(b);
	if(a.tempoDescoberta != b.tempoDescoberta)
		return a.tempoDescoberta < b.tempoDescoberta;
	else
		printf("ERRO NAS COMPARACOES\n");
}
/**
 * Metódo iterativo para escolha de pivo e partição do vetor(Ritação).
 * @param s Vetor de sistemas a serem utilizados.
 * @param l Limite da esquerda do subvetor.
 * @param r Limite da direita do subvetor.
 * @return pivô escolhido pela ritação.
 */
int Ritacao(Sistema *s, int l, int r) 
{
    int q = r;
    int i = l - 1;
    int j = l;
    
    for(j =l; j<r; j++)
    {
	    if(comparar(s[j], s[q]))	
	    {
        i++;
        Sistema tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
	    }
    }
    i++;
    Sistema tmp = s[q];
    s[q] = s[i];
    s[i] = tmp;

    return i;
}
/**
 * Metodo recursivo do BromeroSort.
 * @param s Vetor de sistemas a serem ordenados.
 * @param l Limite da esquerda do subvetor.
 * @param r Limite da direita do subvetor.
 */
void BromeroSort(Sistema *s, int l, int r) 
{
    if (l < r) 
    {
        int q = Ritacao(s, l, r);
        BromeroSort(s, l, q - 1);
        BromeroSort(s, q + 1, r);
    }
}
/**
 * Metódo para inicialização da recursividade do BromeroSort.
 * @param s Vetor de sistemas a serem ordenados.
 * @param numSistemas número total de sistemas no vetor.
 */
void Sort(Sistema *s, int numSistemas) 
{
    BromeroSort(s, 0, numSistemas-1);
}

int main()
{
	//Declaração de variavéis.
	int numSistemas;
	int numPlanetas;
	int numLuas;
	Sistema *s;
	//Aberta do arquivo para leitura
	FILE* arq = fopen("/tmp/case-2", "r");
	if(arq == NULL)
	{
		printf("NAO ABRIU\n");
		return -1;
	}


        //Leitura dos dados do arquivo e atribuições
	fscanf(arq, "%d", &numSistemas);

	if(numSistemas<=MIN || numSistemas>=MAXQUANT)
	{
		printf("Numero de sistemas invalido!\n");
		return -1;
	}

	//Alocação dinâmica de memória
	s = (Sistema*)malloc(numSistemas*sizeof(Sistema));
	for(int i =0; i<numSistemas; i++)
	{
	    fscanf(arq, "%d", &s[i].tempoDescoberta);
	    fscanf(arq, "%s", s[i].nomeSistema);
	    fscanf(arq,"%d", &s[i].raioSol);

	    if(s[i].raioSol > MAXRAIO)
	    {
		    printf("Tamanho de raio invalido!\n");
		    return -1;
	    }

	    fscanf(arq,"%d", &numPlanetas);

	    if(numPlanetas > MAXELEMENTOS)
	    {
		    printf("Numero de planetas invalido!\n");
		    return -1;
	    }

	  //Alocação dinâmica de memória
	  s[i].planetas = (Planeta*)malloc(numPlanetas*sizeof(Planeta)); 
          for(int j = 0; j<numPlanetas; j++)
	  {
		  fscanf(arq, "%s", s[i].planetas[j].nomePlaneta);
		  fscanf(arq, "%d", &s[i].planetas[j].raioPlaneta);

		  if(s[i].planetas[j].raioPlaneta > MAXRAIO)
		  {
			  printf("Tamanho de raio invalido!\n");
			  return -1;
		  }

		  fscanf(arq, "%d", &numLuas);

		  if(numLuas > MAXELEMENTOS)
		  {
			  printf("Numero de luas invalido!\n");
			  return -1;
		  }

		  //Alocação dinâmica de memória
		  s[i].planetas[j].luas = malloc(numLuas*sizeof(Lua));
		   for(int x = 0; x<numLuas; x++)
		  {
			  fscanf(arq, "%s", s[i].planetas[j].luas[x].nomeLua);
			  fscanf(arq, "%d", &s[i].planetas[j].luas[x].raioLua);

			  if(s[i].planetas[j].luas[x].raioLua > MAXRAIO)
			  {
				  printf("Tamanho de raio invalido!\n");
				  return -1;
			  }

		  }
	  }
	  
	}

        //Chamada metodo de ordenação e impressão
	Sort(s, numSistemas);
	imprimir(s, numSistemas);


        //Fechar o arquivo e desalocar memória
	fclose(arq);
	free(s);
	return 0;

}
