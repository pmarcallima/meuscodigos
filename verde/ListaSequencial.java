class ListaSequencial
{
	int[] array;
	int n;

	ListaSequencial()
	{
           array = new int[6];
	   n = 0;
	}
	ListaSequencial(int tamanho)
	{
		array = new int[tamanho];
		n = 0;
	}
	void inserirInicio(int x)
	{
		if(n>=array.length)
		{
			return;
		}
		for(int i = n; i>0; i--)
		{
			array[i] = array[i-1];
		}
		array[0] = x;
		n++;
	}
	void inserirFim(int x)
	{
		if(n>= array.length)
		{
			return;
		}
		array[n] = x;
		n++;
	}
	void inserir(int x, int pos)
	{
		if( n>= array.length || pos<0 || pos>n)
		{
			return;
		}
		for(int i = n; i>pos; i--)
		{
			array[i] = array[i-1];
		}
		array[pos] = x;
		n++;
	}
	int removerInicio()
	{
		if(n == 0)
			return 0;
		int resp = array[0];
		for(int i = 0; i<n; i++)
		{
			array[i] = array[i+1];

		}
		n--;
		return resp;
	}
	int removerFim()
	{
		if(n == 0)
		return 0;
	
		return array[--n];
	}
	int remover(int pos)
	{
		if(n == 0 || pos<0 || pos>=n)
		   return 0;
		int resp = array[pos];
		for(int i = pos; i<n; i++)
		{
                   array[i] = array[i+1];
		}
		n--;
		return resp;

	}
	void mostrar()
	{
		System.out.print("[ ");
		for(int i = 0; i<n; i++)
		{
			System.out.print(array[i]);
		        System.out.print(" ");
		}
		System.out.println("]");
	}
	public static void main(String args[])
	{
		ListaSequencial lista = new ListaSequencial(10);
		lista.inserirInicio(1);
		lista.inserirInicio(2);
		lista.mostrar();
		lista.inserirFim(3);
		lista.inserir(5, 2);
		lista.mostrar();
		lista.remover(3);
		lista.mostrar();
		lista.removerFim();
		lista.removerInicio();
		lista.mostrar();
	}
}
