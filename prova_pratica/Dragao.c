#include <stdlib.h>
#include <stdio.h>
typedef struct Dragao
{
	int dias;
	int multa;

}Dragao;
Dragao novoDragao(int x, int y)
{
	Dragao tmp;
	tmp.dias =x;
	tmp.multa = y;
	return tmp;
}
int getMultas(Dragao d[], int i, int n)
{
    int dgtreinando = i;
    int soma = 0;
    for(int j = i; j<n; j++)
    {
        soma += d[j].multa;
    }
    return soma;

}
void Dsort(Dragao *d, int i, int n)
{
	for(int j = i; j<n-1; j++)
	{

         int maior = j;
	 for(int m = (j+1); j<n; j++)
	 {
		if(d[maior].multa < d[j].multa)
			maior = j;
	 } 
           Dragao tmp = d[maior];
	   d[maior] = d[j];
	   d[j] = tmp;
	}

}
int main()
{
	int n = 0;
	Dragao d[105];
	int x, y;
	int total = 0;
	int dgtreinando = 0;
	int i = 0;
	if(n !=0)
	{
            scanf("%d %d", &x, &y);
	    d[0] = novoDragao(x, y);
	    n++;
	    total +=getMultas(d, 0, n);
	}	
        while(!feof())
	{
		scanf("%d %d", &x, &y);
		d[i] = novoDragao(x, y);
		n++;
		total += getMultas(d, dgtreinando, n);
		if(d[dgtreinando].dias == 0)
		{
			dgtreinando++;
			Dsort(d, dgtreinando, n);
		}
		else
			d[dgtreinando].dias--;
		i++;

	}
	printf("DRAGAO ATUAL %d", dgtreinando);

}

