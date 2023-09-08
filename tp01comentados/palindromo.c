#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
  funcao que confere se realmente e uma palindromo e retorna um booleano true ou false
*/
bool ispalin(char s[500])
{
    int tam = strlen(s);
    int cont = 0;
    //for para comparar o primeiro com o ultimo, depois o segundo com penultimo e assim em diante
    for(int i =0; i<tam; i++)
    {
        if (s[i]== s[(tam-i)-1])
        {
            cont++;
        }
    }
    if(cont == tam)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    bool status = true;
    //while com condicao = true para rola-lo ate chegar no if que possui o break
    while(status)
    {
    char string[500];
    scanf("%[^\n\r]", string);
    //while para limpar o buffer
    while (getchar() != '\n');
    if(string[0]== 'F' && string[1]== 'I' && string[2]== 'M' && strlen(string)== 3)
    {
        break;
    }
    bool resp =ispalin(string);
    if(resp == true)
    {
        printf("SIM\n");
    }
    else
        printf("NAO\n");

    }
    return 0;
}
