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
class Pilha
{
	Celula topo;
	Pilha()
	{
		topo = null;
	}
	void inserir(int x)
	{
		Celula tmp = new Celula(x);
		tmp.prox = topo;
		topo = tmp;
		tmp = null;
	}
	int remover()
	{
		if(topo == null)
		{
			return 0;
		}
		int resp = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
                 return resp;        
	}
	void mostrar()
	{
		System.out.print("[ ");
		mostrar(topo);
		System.out.print("]");
	}
	void mostrar(Celula i)
	{
		if(i == null)
		{
			return;
		}
			System.out.print(i.elemento+ " ");
	                mostrar(i.prox);
			return;
	}
	void mostrarOrdem()
	{
		Celula i, j = null;
		for(i = topo; i.prox!= null; i = i.prox);
		System.out.print(i.elemento+ " ");
		while(i!=j)
		{
		for(j = topo; j.prox!= i; j = j.prox);
		System.out.print(j.elemento+ " ");
		if(j == topo)
		{
			break;
		}
		for(i = topo; i.prox!=j; i = i.prox);
		System.out.print(i.elemento+ " ");
		if(i == topo)
		{
			break;
		}
		}
	}
	void mostrarOrdemRec()
	{
		System.out.print("[ ");
		mostrarOrdemRec(topo);
		System.out.print("]");
	}
	void mostrarOrdemRec(Celula i)
	{
		if(i == null)
		{
			return;
		}
		  mostrar(i.prox);
		  System.out.print(i.elemento+ " ");
	}
	int soma()
	{
		return soma(topo);
	}
	int soma(Celula i)
	{
		int resp;
		if(i == null)
		{
			return 0;
		}
		resp = i.elemento;
		
		return resp + soma(i.prox);
	}
	int getMaior()
	{
		return getMaior(topo, topo.elemento);
	}
	int getMaior(Celula i, int maior)
	{
		if(i == null)
		{
			return maior;
		}
			if(maior<i.elemento)
			 maior = i.elemento;
		return getMaior(i.prox, maior);
	}
         public static void main (String args[])
	 {
		 Pilha p = new Pilha();
		 p.inserir(1);
		 p.inserir(5);
		 p.inserir(8);
		 p.mostrar();
		 System.out.println(p.getMaior());
		 p.mostrarOrdem();
	 }
 
}

