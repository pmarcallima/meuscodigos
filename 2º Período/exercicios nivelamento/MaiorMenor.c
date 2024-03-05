#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 int main()
{
   char a[100];
   scanf("%s", a);
   int maior = a[0]-48, menor = a[0]-48;
   int tam = strlen(a), test;
   for (int i = 1; i<tam; i++)
   {
	   test= ((int)a[i]-48);
	   if(maior < test)
		   maior = test;
	   if(menor> test)
		   menor = test;
   }
   printf("%d \n", maior);
   printf("%d \n", menor);
   return 0;

}
}
