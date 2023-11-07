class PilhaFlex
{
	int elemento;
	
	PilhaFlex()
	{
		this(0);
	}
	PilhaFlex(int x)
	{
		this.prox = null;
		this.elemento = x;
	}
}
