#include <stdio.h>
#include <stdlib.h>

float* somarVetores(float* vetor1, float* vetor2) {
    int tamanhoMenor, tamanhoMaior;
    int tamanho1 = sizeof(vetor1)/sizeof(float);
    int tamanho2= sizeof(vetor2)/sizeof(float);
    printf("%d %d", tamanho1, tamanho2);
    if (tamanho1 > tamanho2) 
	   {
           tamanhoMenor = tamanho2; 
           tamanhoMaior = tamanho1;
	   }
    else
	   tamanhoMenor = tamanho1;
           tamanhoMaior = tamanho2;

    float* soma = (float*)malloc(tamanhoMaior * sizeof(float));

    if (soma == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    for (int i = 0; i < tamanhoMenor; i++) {
        float tmp1 = vetor1[i];
       float tmp2 = vetor2[i];	
        soma[i] = tmp1 + tmp2;
    }
    if(tamanhoMaior == tamanho1)
    {
    for(int i = tamanhoMenor; i<tamanhoMaior; i++)
    {
	    float tmp = vetor1[i];
	    soma[i] = tmp;
    }
    }
    else 
	  for(int i = tamanhoMenor; i<tamanhoMaior; i++)
	  {
		  float tmp = vetor2[i];
		  soma[i] = tmp;
	  }
    return soma;
}

int main() {
    float vetor1[] = {1.5, 2.0, 3.5};
    float vetor2[] = {4.0, 2.5, 4.2, 4.6};

    float* resultado = somarVetores(vetor1, vetor2);

    int tamanho_resultado = (sizeof(vetor1) / sizeof(float) > sizeof(vetor2) / sizeof(float))
                          ? sizeof(vetor1) / sizeof(float) : sizeof(vetor2) / sizeof(float);
    
    printf("Resultado da soma:\n");
    for (int i = 0; i < tamanho_resultado; i++) {
        printf("%.2f ", resultado[i]);
    }
    printf("\n");

    free(resultado);

    return 0;
}
