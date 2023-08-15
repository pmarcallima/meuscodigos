#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 bool EstaContido(char a[], int x)

  {
  int tam = strlen(a);
  int test;
  for(int i = tam/2; i<tam; )
  {
      test = ((int)a[i]-48);
      if (x == test)
      {
          return true;
      }
      else if(test > x)
      {
          i--;
      }
      else
      {
          i++;
      }

  }
   return false;
}
  int main()
{
  int x;
  char temp[100];
  scanf("%s", temp);
  fflush(stdin);
  scanf("%d", &x);
  bool res = EstaContido(temp, x);
    if ( res == true)
            printf("Esta contido");
    else
    {
        printf("Nao esta contido");
    }

   return 0;
}
