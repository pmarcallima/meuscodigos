#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
     char temp[1000];
     FILE *arq = fopen("/tmp/players.csv", "r");
     while(fscanf(arq,"%[^,]", temp)!= EOF)
		     {
		      fgetc(arq);
		      printf("%s", temp);
		     }
     fclose(arq);

}
