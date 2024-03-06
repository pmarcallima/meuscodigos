class CelulaDupla
{
	int elemento;
	CelulaDupla prox;
	CelulaDupla ant;
        CelulaDupla()
	{
		this(0);
	}
	CelulaDupla(int x)
	{
		this.elemento = x;
		this.prox = this.ant = null;
	}

}
class ListaDupla
{
	CelulaDupla primeiro, ultimo;
	ListaDupla()
	{
		primeiro = new CelulaDupla();
		ultimo = primeiro;
	}
	int tamanho()
	{
	    int cont = 0;	
            for(CelulaDupla i = primeiro.prox; i != null; i = i.prox)
	    {
                cont++;
	    }
	    return cont;
	}
	void inserirInicio(int x)
	{
		CelulaDupla tmp = new CelulaDupla(x);
		tmp.prox = primeiro.prox;
		tmp.ant = primeiro;
		primeiro.prox = tmp;
		if(primeiro == ultimo)
		{
			ultimo = tmp;
		}
		else
		{
			tmp.prox.ant = tmp;
		}
		tmp = null;

	}
	void inserirFim(int x)
	{
		ultimo.prox = new CelulaDupla(x);
		ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox; 
                
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
		CelulaDupla i = primeiro;
		CelulaDupla tmp = new CelulaDupla(x);
		for(int j = 0; j<pos; j++)
		{
		  i = i.prox;
		}
		 tmp.prox = i.prox;
		 tmp.ant = i;
		 i.prox.ant = tmp;
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

		CelulaDupla tmp = primeiro.prox;
		int resp = primeiro.prox.elemento;
		primeiro.prox = primeiro.prox.prox;
		tmp.prox = null;
		tmp.ant = null;
		tmp = null;
		return resp;

	}
	int removerFim()
	{
		if(primeiro == ultimo)
		{
			return 0;
		}
		int resp = ultimo.elemento;
		ultimo = ultimo.ant;
		ultimo.prox.ant = null;
		ultimo.prox = null;
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
                CelulaDupla i = primeiro;
		for(int j = 0; j<pos; j++)
		{
			i = i.prox;
		}
		i.prox.ant = i.ant;
		i.ant.prox = i.prox;
		resp = i.elemento;
		i.prox = i.ant = null;
	        i = null;	
	
                }
		return resp;

	}
	void mostrar()
	{
		System.out.print("[ ");
		for(CelulaDupla i = primeiro.prox ; i != null; i = i.prox)
		{
			System.out.print(i.elemento+ " ");
		}
		System.out.println("]");
	}
	void inverter()
	{
		CelulaDupla i = primeiro.prox;
		CelulaDupla j = ultimo;
		while(i!= j && i.ant != j)
		{
			CelulaDupla tmp = i.prox;
			i.prox = j.prox;
			 if(j.prox!= null)
				 i.prox.ant = i;
			 j.prox = tmp;
			 tmp.ant = j;
			 tmp = i.ant;
			 i.ant = j.ant;
			 i.ant.prox = i;
			 j.ant = tmp;
			 tmp.prox = j;
			 tmp = i;
			 i = j;
			 j = tmp;
			 if(ultimo == i)
			 {
				 ultimo = j;
			 }
			 j = j.ant; 
			 i = i.prox;
		
		}
	}
          public void sort() {
      int h = 1;

      do { h = (h * 3) + 1; } while (h < tamanho());

      do {
         h /= 3;
         for(int cor = 0; cor < h; cor++){
            insercaoPorCor(cor, h);
         }
      } while (h != 1);
   }


   /**
    * Metodo que efetua a insercao nos pseudo-arrays do Shellsort.
    * @param int cor cor do pseudo array.
    * @param int h passo do shelsort
    */
   public void insercaoPorCor(int cor, int h){
      for (int i = (h + cor); i < tamanho(); i+=h) {
	 CelulaDupla a, m;
	 a = primeiro.prox;
	 m = primeiro.prox;
	 for(int x =0; x<i; x++)
	      a = a.prox;
         int tmp = a.elemento;
         int j = i - h;
	 for(int x = 0; x<j; x++)
	       m = m.prox;
         while ((j >= 0) && (m.elemento > tmp)) {
	    System.out.println(a.elemento +"" + m.elemento);	 
	    a.elemento = m.elemento; 
	    a = m; 
 	    for(int x = 0; x<h; x++)
	    {
		    m = m.ant;
	    }	    
            j-=h;
         }
         a.elemento = tmp;
      }
   }
      public void qsort() {
      quicksort(0, tamanho()-1);
   }

	/**
	 * Algoritmo de ordenacao Quicksort.
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
	 */
    private void quicksort(int esq, int dir) {
        int i = esq, j = dir;
        CelulaDupla pivo = primeiro.prox;
	CelulaDupla m = primeiro.prox;
        CelulaDupla a = primeiro.prox;
	for(int x =0; x< (esq+dir)/2; x++)
		pivo = pivo.prox;
	System.out.println("PIVO"+pivo.elemento);
		for(int x = 0; x<i; x++)
		{
			m = m.prox;
		}
		for(int x =0; x<j; x++)
		{
			a = a.prox;
		}
        System.out.println("ESQ"+esq);
	System.out.println("DIR"+dir);
	System.out.println("I:"+ i + "J:"+j);
	mostrar();

        while (i <= j) {
            while (m.elemento < pivo.elemento)
	    {
		//    System.out.println("elemento: "+m.elemento+" pivo: "+pivo.elemento);
		    i++;
		    m = m.prox;
	    } 
            while (a.elemento > pivo.elemento)
	    {
		    j--;
		    a = a.ant;
	    }
            if (i <= j) {
		    System.out.println("entrou");
                int tmp = a.elemento;
		System.out.println("elementos a serem trocados: "+a.elemento+ " "+m.elemento);
		a.elemento = m.elemento;
		m.elemento = tmp;
		a = a.ant;
		m = m.prox;
                i++;
                j--;
            }
        }
	System.out.println(a.elemento+ " "+m.elemento);
        if (esq < j)  quicksort(esq, j);
        if (i < dir)  quicksort(i, dir);
    }


public static void main(String args[])
	{
		ListaDupla l = new ListaDupla();
		l.inserirFim(5);
		l.inserirFim(3);
		l.inserirInicio(1);
		l.inserirInicio(4);
		l.inserirFim(2);
		l.inserirFim(220);
		l.inserirFim(20);
		l.inserirInicio(500);
		l.inserirInicio(2000);
		l.mostrar();
		l.qsort();
			l.mostrar();
	}

}
