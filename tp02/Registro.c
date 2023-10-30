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

 typedef struct Log
{
    int matricula;
    int mov;
    int cmp;
    clock_t tempo;


} Log;

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
bool desempate(Jogador *x, Jogador *y)
{
	if(getPeso(x)!= getPeso(y)) 
			{
			  return false;
			}
	else
	{
		if(strcmp(getNome(x), getNome(y))<0)
		{
			return false;
		}
		else
			return true;
	}
}
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
void imprimir(Jogador *x)
{
	printf("[");
	printf("%d", getId(x));
	printf(" ## ");
	printf("%s", getNome(x));
	printf(" ## ");
	printf("%d", getAltura(x));
	printf(" ## ");
	printf("%d", getPeso(x));
	printf(" ## ");
	printf("%d", getAnoNascimento(x));
	printf(" ## "); 
	printf("%s", getUniversidade(x));
	printf(" ## "); 
	printf("%s", getCidadeNascimento(x));
	printf(" ## ");
	printf("%s]", getEstadoNascimento(x));
	printf("\n");
}
void swap(Jogador *i, Jogador *j)
{
	Jogador tmp = *i;
	*i = *j;
	*j = tmp;
	
}
int Compare2(Jogador *x, Jogador *y)
{

	if(getAnoNascimento(x) != getAnoNascimento(y))
	{
		return getAnoNascimento(x) > getAnoNascimento(y);
	}
	else
		return strcmp(getNome(x), getNome(y));
}
//=============================================================================
void bolha(Jogador *array, int n){
    int i, j;
    for (i = 0; i < (n-1); i++) {
      for (j = 0; j < (n-1); j++) {
         if (Compare2(&array[j], &array[j + 1] )> 0) {
            swap(&array[j], &array[j + 1]);
         }
      }
   }
}
//=============================================================================
	int getMax(Jogador *array, int n) {
	    int maior = getId(&array[0]);

	    for (int i = 1; i < n; i++) {
		if(maior < getId(&array[i])){
		    maior = getId(&array[i]);
		}
	    }
	    return maior;
	}
 void radcountingSort(Jogador *array, int n, int exp) {
        int count[10];
        Jogador *output = malloc( n*sizeof(Jogador));;

        //Inicializar cada posicao do array de contagem
        for (int i = 0; i < 10; count[i] = 0, i++);

        //Agora, o count[i] contem o numero de elemento iguais a i
        for (int i = 0; i < n; i++) {
            count[(getId(&array[i])/exp) % 10]++;
        }

        //Agora, o count[i] contem o numero de elemento menores ou iguais a i
        for (int i = 1; i < 10; i++) {
            count[i] += count[i-1];
        }

        //Ordenando
        for (int i = n-1; i >= 0; i--) {
            output[count[(getId(&array[i])/exp) % 10] - 1] = clone(&array[i]);
            count[(getId(&array[i])/exp) % 10]--;
        }

        //Copiando para o array original
        for (int i = 0; i < n; i++) {
            array[i] = output[i];
        }
    }
//=============================================================================
void radixsort(Jogador *array, int n) {
    //Array para contar o numero de ocorrencias de cada elemento
    int max = getMax(array, n);
    for (int exp = 1; max/exp > 0; exp *= 10) {
            radcountingSort(array, n, exp);
    }
}
//=============================================================================
void insercao(Jogador *array, int n){
    for (int i = 1; i < n; i++) {
	int k = 10;
      Jogador tmp = array[i];
      int j = (i - k) ? i-1 : k-1;

      while ((j >= 0) && (Compare2(&array[j], &tmp)>0)) {
         array[j + 1] = array[j];
         j--;
      }
      array[j+1] = tmp;
   }
}
//=============================================================================
void selecao(Jogador *array, int n, int i){
   if(i == n-1)
	  return; 
      int menor = i;
      for (int j = (i + 1); j < n; j++){
         if (strcmp(getNome(&array[menor]), getNome(&array[j]))>0){
            menor = j;
         }
      }
      swap(&array[menor], &array[i]);
      selecao(array, n, i+1);   
}
void sort(Jogador *array, int n)
{
	selecao(array, n, 0);
}
int pesqBin(Jogador *array, int n, char *x){
      bool resp = false;
      int dir = (n - 1), esq = 0, meio;

      while (esq <= dir){
         meio = (esq + dir) / 2;
         if(strcmp(x, getNome(&array[meio])) ==0){
            resp = true;
            esq = dir + 1;
         } else if (strcmp(x, getNome(&array[meio]))>0) {
            esq = meio + 1;
         } else {
            dir = meio - 1;
         }
      }
      return resp;
   }
//=============================================================================
void construir(Jogador *array, int tamHeap){
    for(int i = tamHeap; i > 1 && Compare2(&array[i],&array[i/2])>0; i /= 2){
        swap(&array[i], &array[i/2]);
    }
}
//=============================================================================
int getMaiorFilho(Jogador *array, int i, int tamHeap){
    int filho;
    if (2*i == tamHeap){ //|| Compare2(&array[2*i],&array[2*i+1] )>0){
        filho = 2*i;
    } else {
        filho = 2*i + 1;
    }
    return filho;
}
//=============================================================================
void reconstruir(Jogador *array, int tamHeap){
    int i = 1;
    while(i <= (tamHeap/2)){
        int filho = getMaiorFilho(array, i, tamHeap);
        if(Compare2(&array[i], &array[filho])<0){
            swap(&array[i], &array[filho]);
            i = filho;
        }else{
            i = tamHeap;
        }
    }
}
//=============================================================================
void heapsort(Jogador *array, int n) {
    //Alterar o vetor ignorando a posicao zero
    int k = 10;
    Jogador *arrayTmp= malloc((n+1)*sizeof(Jogador));
    for(int i = 0; i < n; i++){
        arrayTmp[i+1] = clone(&array[i]);
    }

    //Contrucao do heap
/*    for(int tamHeap = 2; tamHeap <= k; tamHeap++){
        construir(arrayTmp, tamHeap);	
    }

    //Ordenacao propriamente dita
    int tamHeap = n;
    for(int i = k+1; i <=n; i++){
	if(Compare2(&array[i], &array[1])<0)
			{
        swap(&arrayTmp[i], &arrayTmp[1]);
        reconstruir(arrayTmp, k);
               }
    }
     tamHeap = k;
     while(tamHeap>1)
	     swap(&array[1], &array[tamHeap--]); reconstruir(arrayTmp, tamHeap);*/
    for(int tamHeap = 2; tamHeap <= n; tamHeap++){
        construir(arrayTmp, tamHeap);
    }

    //Ordenacao propriamente dita
    int tamHeap = n;
    while(tamHeap > 1){
        swap(arrayTmp + 1, arrayTmp + tamHeap--);
        reconstruir(arrayTmp, tamHeap);
    }
    //Alterar o vetor para voltar a posicao zero
    for(int i = 0; i < k; i++){
        array[i] = arrayTmp[i+1];
    }
}
void quicksortRec(Jogador *array, int esq, int dir) {
    int i = esq, j = dir;
    Jogador pivo = array[(dir+esq)/2];
    while (i <= j) {
         while (strcmp(getEstadoNascimento(&array[i]), getEstadoNascimento(&pivo)) < 0 || Compare2(&array[i], &pivo)<0)
    i++;
while (strcmp(getEstadoNascimento(&array[j]), getEstadoNascimento(&pivo)) > 0 || Compare2(&pivo, &array[j])<0)
    j--;
     if (i <= j)
	{
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    if (esq < j)  quicksortRec(array, esq, j);
    if (i < dir)  quicksortRec(array, i, dir);
}
//=============================================================================
void quicksort(Jogador *array, int n) {
    quicksortRec(array, 0, n-1);
}
void insercaoPorCor(Jogador *array, int n, int cor, int h){
    for (int i = (h + cor); i < n; i+=h) {
        Jogador tmp = array[i];
        int j = i - h;
	  while ((j >= 0) && Compare2(&array[j], &tmp)>0)
	 {

		array[j+h] = array[j];
		j-=h;

        }
        array[j + h] = tmp;
    }
}
//=============================================================================
void shellsort(Jogador *array, int n) {
    int h = 1;

    do { h = (h * 3) + 1; } while (h < n);

    do {
        h /= 3;
        for(int cor = 0; cor < h; cor++){
            insercaoPorCor(array, n, cor, h);
        }
    } while (h != 1);
}
//=============================================================================i
//=============================================================================
int main()
{
  Log log;
  char temp[100];
  int i =0;
  Jogador *y = malloc(3923*sizeof(Jogador));
  y = ler();
  Jogador *z= malloc(3923*sizeof(Jogador));
  while(1)
  {
  scanf("%[^\n]", temp);
  char ch = getchar();
   if(strcmp(temp, "FIM")== 0)
   {
		  break; 
   }
   int num = atoi(temp);
   z[i]= y[num+1]; 
  i++; 

  }
  log.tempo = clock();
  insercao(z,i);
  int m = 0;
 /* while(1)
  {
	  
   scanf("%[^\n]", temp);
   char ch = getchar();
   if(strcmp(temp, "FIM") == 0)
   {
	   break;
   }
   bool resp = pesqBin(z, i, temp);
   if(resp == true)
   {
	   printf("SIM\n");
	   
   }
   else
	   printf("NAO\n");
  }*/
 for(int j = 0; j<10 ; j++)
  imprimir(z+j);
  free(z);
  free(y);
  return 0;
}

