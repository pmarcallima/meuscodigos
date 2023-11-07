class No
{
	No esq;
        No dir;
	int elemento;
  No(int elemento)
  {
	  this(elemento, null, null);
  }
  No(int elemento, No esq, No dir)
  {
	  this.elemento = elemento;
	  this.esq = esq;
	  this.dir = dir;
  }
}

