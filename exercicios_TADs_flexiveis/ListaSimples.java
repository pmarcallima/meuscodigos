class Celula
{
	int elemento;
	Celula prox;
        Celula()
	{
		this(0);
	}
	Celula(int x)
	{
		this.elemento = x;
		this.prox = null;
	}

}
class ListaSimples
{
	Celula primeiro, ultimo;
	ListaSimples()
	{
		primeiro = new Celula();
		ultimo = primeiro;
	}
	int tamanho()
	{
	    int cont = 0;	
            for(Celula i = primeiro.prox; i != null; i = i.prox)
	    {
                cont++;
	    }
	    return cont;
	}
	void inserirInicio(int x)
	{
		Celula tmp = new Celula(x);
		tmp.prox = primeiro.prox;
		primeiro.prox = tmp;
		if(primeiro == ultimo)
		{
			ultimo = tmp;
		}
		tmp = null;

	}
	void inserirFim(int x)
	{
		Celula tmp = new Celula(x);
		ultimo.prox = tmp;
		ultimo = tmp; 
		tmp = null;
	}
	void inserir(int x, int pos)
	{
		int tamanho = tamanho();
		if(pos<0 || pos> tamanho)
			return;
		else if(pos == 0)
		{
                   inserirInicio(x);
		}
		else if( pos == tamanho)
		{
			inserirFim(x);
		}
		else
		{
		Celula i = primeiro;
		Celula tmp = new Celula(x);
		for(int j = 0; j<pos; j++)
		{
		  i = i.prox;
		}
		 tmp.prox = i.prox;
		 i.prox = tmp;
		 tmp = null;
		 i = null;
		} 
	}
	int removerInicio()
	{
		if(ultimo == primeiro)
		{
			return 0;
		}

		Celula tmp = primeiro.prox;
		int resp = primeiro.prox.elemento;
		primeiro.prox = primeiro.prox.prox;
		tmp.prox = null;
		tmp = null;
		return resp;

	}
	int removerFim()
	{
		if(primeiro == ultimo)
		{
			return 0;
		}
		Celula i;
		for(i = primeiro.prox; i.prox != ultimo; i= i.prox);
		int resp = ultimo.elemento;
		ultimo = i;
		i = ultimo.prox = null;
		return resp;
	}
        int remover(int pos)
      	{
		int tamanho = tamanho();
		int resp;
 
		if(primeiro == ultimo)
			return 0;
		else if(pos == 0)
		{
		     resp =	removerInicio();
		}
		else if(pos == tamanho)
		{
		   resp =	removerFim();
		}
		else
		{
                Celula i = primeiro;
		for(int j = 0; j<pos; j++)
		{
			i = i.prox;
		}
		Celula tmp = i.prox;
		resp = tmp.elemento;
		i.prox = tmp.prox;
		tmp = null;
	        i = null;	
	
                }
		return resp;

	}
	void mostrar()
	{
		System.out.print("[ ");
		for(Celula i = primeiro.prox ; i != null; i = i.prox)
		{
			System.out.print(i.elemento+ " ");
		}
		System.out.println("]");
	}
        void inverter()
	{
		Celula i = primeiro;
		Celula j;
		for(j = primeiro; j.prox != ultimo; j = j.prox);
		while(i!=j && j.prox != i)
		{ 
		     
                    Celula tmp = i.prox.prox;
		    i.prox.prox = j.prox.prox;
		    j.prox.prox = tmp;	
		    tmp = j.prox;
		    j.prox = i.prox;
		    i.prox = tmp;
		    if(i.prox == ultimo)
		    {
			    ultimo = j.prox;
		    }
		    i = i.prox;
		    tmp = j;
		     for(j = primeiro; j.prox!=tmp; j = j.prox);
		
		}
	}
	public void qsort()
	{
		quicksort(0, tamanho()-1);
	}
	
	private void quicksort(int esq, int dir) {
        int i = esq, j = dir;
        Celula pivo = primeiro.prox;
	Celula m = primeiro.prox;
        Celula a = primeiro.prox;
	Celula k;
	for(int x =0; x< (esq+dir)/2; x++)
		pivo = pivo.prox;
		for(int x = 0; x<i; x++)
		{
			m = m.prox;
		}
		for(int x =0; x<j; x++)
		{
			a = a.prox;
		}


        while (i <= j) {
            while (m.elemento < pivo.elemento)
	    {
		    i++;
		    m = m.prox;
	    }
            while (a.elemento > pivo.elemento)
	    {
		    j--;
		    for(k = primeiro.prox; k.prox!=a; k = k.prox);
                    a = k;
	    }
            if (i <= j) {
                int tmp = a.elemento;
		a.elemento = m.elemento;
		m.elemento = tmp;
		for(k=primeiro.prox; k.prox!=a; k = k.prox);
		a = k;
		m = m.prox;
                i++;
                j--;
            }
        }
        if (esq < j)  quicksort(esq, j);
        if (i < dir)  quicksort(i, dir);
    }


	public static void main(String args[])
	{
		ListaSimples l = new ListaSimples();
		l.inserirInicio(3);
		l.inserirInicio(1);
		l.inserirInicio(5);
		l.inserirInicio(4);
		l.inserirInicio(2);
		l.mostrar();
		l.inverter();
		l.mostrar();
		l.qsort();
		l.mostrar();
	
	}


}
