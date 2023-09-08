#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* funcao que recebe como parametro uma string e um inteiro e retorna true caso a string seja um palindromo
*/
bool ispalin(char s[500], int i)
{
      int tam = strlen(s)-1;
//condicao de parada
      if(i==tam)
      {
          return true;
      }
        if (s[i]== s[tam-i])
        {
            return true && ispalin(s, i+1);
        }
    else
        return false;
}

int main()
{
    bool status = true;
// while com condicao = true ate que o if com break tenha sua condicao atendida
    while(status)
    {
    char string[500];
    scanf("%[^\n\r]", string);
    while (getchar() != '\n');
    if(string[0]== 'F' && string[1]== 'I' && string[2]== 'M' && strlen(string)== 3)
    {
        break;
    }
//imprimindo o resultado
    bool resp =ispalin(string, 0);
    if(resp == true)
    {
        printf("SIM\n");
    }
    else
        printf("NAO\n");

    }
    return 0;
}
