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
}
class Fila
{
	Celula primeiro, ultimo;
	Fila()	
	{
		primeiro = new Celula();
	}
	void inserir(int x)
	{

		Celula i = primeiro;
	        while(i.prox!=null)i = i.prox;
		i.prox = new Celula(x);

		
	}
	int remover()
	{
		if(primeiro.prox == null)
		{
			return 0;
		}
		Celula tmp = primeiro.prox;
		primeiro = primeiro.prox.prox;
		int resp = tmp.elemento;
		tmp.prox = null;
		tmp = null;
		mostrar();
		return resp;
	}
	void mostrar()
	{
		System.out.print("[ ");
		for(Celula i = primeiro; i != null; i = i.prox)
		{
			System.out.print(i.elemento+ " ");
		}
		System.out.println("]");
	}
	int contador()
	{
		return  contador(primeiro.prox);
			
		
	}
	int contador(Celula i)
	{
		int resp;
                if(i == null)
		{
			resp = 0;
		}
		else if(i.elemento % 2 == 0 && i.elemento % 5 == 0)
		{
			
			resp = 1+ contador(i.prox);
		}
		else
			resp = contador(i.prox);
	          return resp;	
	}
	Celula toFila(Celula topo)
	{
		Celula tmp = new Celula();
		primeiro = tmp;
		primeiro.prox = topo;
		for(tmp = primeiro.prox; tmp != null; tmp = tmp.prox)
		{
	        inserir(tmp.elemento);
                }
		ultimo = tmp;
		return primeiro;
	}
	public static void main (String args[])
	{
		
		Fila f = new Fila();
		f.inserir(3);
		f.inserir(5);
		f.inserir(7);
		f.remover();
		f.mostrar();
//		System.out.println(f.contador());
	}
}
