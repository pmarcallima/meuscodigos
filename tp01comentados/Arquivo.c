#include <stdio.h>
#include <stdlib.h>

int main()
{
//abrindo o arquivo em modo de escrita
    FILE* arq = fopen("arq.txt", "w+");
    float s;
    int n;

    scanf("%d", &n);
    for(int i =0; i<n; i++)
    {
//lendo o numero a ser escrito e escrevendo em binario no arquivo
        scanf("%f", &s);
        fwrite(&s, 1, sizeof(s), arq);
    }
    fclose(arq);
//abrindo o arquivo para leitura binaria
    arq= fopen("arq.txt", "rb+");
//iniciando o cursor no final do arquivo
    fseek(arq,0, SEEK_END);

    while(ftell(arq)>0)
    {

//lendo linha por linha da ultima para a primeira
        fread(&s,1,sizeof(s),arq);
        fseek(arq, -8, SEEK_CUR);
        printf("%g\n", s);

    }
//imprimindo apenas a primeira
    if(ftell(arq)== 0)
    {
        fread(&s,1,sizeof(s),arq);
        printf("%g\n", s);
    }
    fclose(arq);
}
