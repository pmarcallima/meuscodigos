#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//funcao que recebe uma string e um inteiro para a recursividade e retorna a string alterada pela Cifra de Cesar
char * Alterar(char s[500], int i, char letra1, char letra2)
{
    int tam = strlen(s);
    if(i == tam)
    {
        return s;
    }
      if(s[i]== letra1)
      {
          s[i] = letra2;
      }
  return (Alterar(s, i+1, letra1,letra2));
}

int main()
{

    srand(4);

    bool status = true;
//while com condicao = true ate que o if com o break tenha sua condicao atendida
    while(status)
    {
    char string[500];
    scanf("%[^\n\r]", string);
//limpando buffer
    while (getchar() != '\n');
    if(string[0]== 'F' && string[1]== 'I' && string[2]== 'M' && strlen(string)== 3)
    {
        break;
    }
    //gerando as letras aleatorias
  char letra1=(char)('a'+abs((rand()) % 26));
  char letra2=(char)('a'+abs((rand()) % 26));
        printf("%s\n", Alterar(string, 0, letra1, letra2));
    }

    return 0;
}
