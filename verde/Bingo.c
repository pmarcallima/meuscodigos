#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Cartela
{
	int elemento;
	struct Cartela* prox;

}Cartela;

Cartela* novaCelula(int elemento)
{
	Cartela* nova = (Cartela*)malloc(sizeof(Cartela));
	nova->elemento = elemento;
	nova-> prox = NULL;
	return nova;
}
Cartela *primeiro;
Cartela *ultimo;
void start()
{
	primeiro = novaCelula(-1);
        ultimo = primeiro;
}
void inserir(int x)
{
	ultimo->prox = novaCelula(x);
	ultimo = ultimo->prox;
}
void mostrar() {
   Cartela* i;
   printf("[ ");
   for (i = primeiro->prox; i != NULL; i = i->prox) {
      printf("%d ", i->elemento);
   }
   printf("] \n");
}
Cartela fazerCartela(int n)
{
      int tmp;
      start();
      for(int i = 0; i<n; i++)
      {
	      scanf("%d", &tmp);
              char ch = getchar();
	      inserir(tmp);

      }
	      	      mostrar();
      }
int main()
{
     char string[100];
     int numeros[3];
     for(int x = 0; x<3; x++)
     {
     scanf("%d", &numeros[x]);
     char ch = getchar();
     printf("%d", numeros[x]);
     }
     Cartela c[numeros[0]];
     for(int j = 0; j<numeros[0]; j++)
     c[j] =  fazerCartela(numeros[1]);


     

}
