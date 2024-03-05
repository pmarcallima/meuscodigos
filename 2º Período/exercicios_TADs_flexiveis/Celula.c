typedef struct Celula
{
	struct Celula *prox;
	int elemento;
}Celula;

Celula *novaCelula(int elemento)
{
	Celula *nova = (Celula*) malloc(sizeof(Celula));
	nova->elemento = elemento;
	nova->prox = NULL;
	return nova;

}
