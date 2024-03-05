class Jogador
{
    private int id;
    private String nome;
    private int altura;
    private int peso;
    private String universidade;
    private int anoNascimento;
    private String cidadeNascimento;
    private String estadoNascimento;
// Construtor sem parâmetros
    public Jogador()
    {

    }
// Construtor com parâmetros para todos atributos
    public Jogador(int id, String nome, int altura, int peso, String universidade, int anoNascimento, String cidadeNascimento, String estadoNascimento)
    {
         this.id = id;
	 this.nome = nome;
	 this.altura = altura;
	 this.peso = peso;
	 this.universidade = universidade;
	 this.anoNascimento = anoNascimento;
	 this.cidadeNascimento = cidadeNascimento;
	 this.estadoNascimento = estadoNascimento;
    }
// Metódos setters
    void setId(int id)
    {
	    this.id =id;
    }
    void setNome(String nome)
    {
	    this.nome= nome;
    }
    void setAltura(int altura)
    {
	    this.altura = altura;
    }
    void setPeso(int peso)
    {
	    this.peso = peso;
    }
    void setUniversidade(String universidade)
    {
	    this.universidade = universidade;
    }
    void setAnoNascimento(int anoNascimento)
    {
	    this.anoNascimento = anoNascimento;
    }
    void setCidadeNascimento(String cidadeNascimento)
    {
	    this.cidadeNascimento = cidadeNascimento;
    } 
    void setEstadoNascimento(String estadoNascimento)
    {
	    this.estadoNascimento = estadoNascimento;
    }
// Metódos getters
    int getId()
    {
	    return id;
    }
    String getNome()
    {
	    return nome;
    }
    int getAltura()
    {
	    return altura;
    }
    int getPeso()
    {
	    return peso;
    }
    String getUniversidade()
    {
	    return universidade;
    }
    int getAnoNascimento()
    {
	    return anoNascimento;
    }
    String getCidadeNascimento()
    {
	    return cidadeNascimento;
    }
    String getEstadoNascimento()
    {
	    return estadoNascimento;
    }
//Metodo para encontrar o jogador com o id inserido
    static Jogador PesquisaId(int x)
    {
	    Jogador[] temp = ler();
	    for(int i = 0; i<3922; i++)
	    {
		    if(temp[i].getId()==x)
		    {
			    return temp[i];
		    }
	    }
	    return temp[0];
    }
// Método para ler o jogador a partir do ID do parâmetro
    static Jogador[] ler()
    {
	    Arq.openRead("/tmp/players.csv");
	    Jogador[] jogador= new Jogador[3922];
	    int i = 0;
	    Arq.readLine();
	    while(Arq.hasNext())
	    {
            jogador[i] = new Jogador(); 
	    String jog = Arq.readLine();
	    String[] temp = new String[8];
            temp= jog.split(",", 8);
	    jogador[i].setId(Integer.parseInt(temp[0]));
            jogador[i].setNome(temp[1]);
	    jogador[i].setAltura(Integer.parseInt(temp[2]));
	    jogador[i].setPeso(Integer.parseInt(temp[3]));
	    jogador[i].setUniversidade(temp[4]);
	    jogador[i].setAnoNascimento(Integer.parseInt(temp[5]));
	    jogador[i].setCidadeNascimento(temp[6]);
	    jogador[i].setEstadoNascimento(temp[7]);

// Ifs para lidar com campos vazios
	    if(temp[4].isEmpty())
	           jogador[i].setUniversidade("nao informado");  
	    if(temp[6].isEmpty())
		   jogador[i].setCidadeNascimento("nao informado");
	    if(temp[7].isEmpty())
		   jogador[i].setEstadoNascimento("nao informado");
	    i++;
            }
	    Arq.close();
	    return jogador;


    }
// Metodo para clonar um jogador
   static Jogador clonej(Jogador jogador) {
	    String temp;
	    Jogador clone = new Jogador();
	    temp =  Integer.toString(jogador.getId());
	    clone.setId(Integer.parseInt(temp));
	    temp = jogador.getNome();
	    clone.setNome(temp);
	    temp = Integer.toString(jogador.getAltura());
	    clone.setAltura(Integer.parseInt(temp));
	    temp = Integer.toString(jogador.getPeso());
	    clone.setPeso(Integer.parseInt(temp));
	    temp = jogador.getUniversidade();
	    clone.setUniversidade(temp);
	    temp = Integer.toString(jogador.getAnoNascimento());
	    clone.setAnoNascimento(Integer.parseInt(temp));
	    temp = jogador.getCidadeNascimento();
	    clone.setCidadeNascimento(temp);
	    temp = jogador.getEstadoNascimento();
	    clone.setEstadoNascimento(temp);
	    return clone;
    }
}
class Celula
{
	protected Jogador jogador;
	protected Celula prox, ant;
	Celula()
	{
		this(null);
	}
	Celula(Jogador jogador)
	{
		this.jogador = jogador;
		prox = null;
		ant = null;
	}
}
class ListaFlex extends Jogador 
{
   private Celula ultimo,primeiro;
   private int tamanho;
   ListaFlex()
   {
	   ultimo = primeiro = new Celula();
	   tamanho = 0;
   }
  void inserirFim(Jogador x)
  {
	  ultimo.prox = new Celula(x);
	  ultimo.prox.ant = ultimo;
	  ultimo = ultimo.prox;
	  tamanho++;
  }
  void inserirInicio(Jogador x)
  {
	  Celula tmp = new Celula(x);
	  tmp.prox = primeiro.prox;
	  primeiro.prox = tmp;
	  tmp.ant = primeiro;
	  if(primeiro == ultimo)
	  {
		  ultimo = tmp;
	  }
	  else
	  {
		  tmp.prox.ant = tmp;
	  }
	  tmp = null;
	  tamanho++;
  }
  void inserir(int pos, Jogador x)
  {
	  if(pos<0 || pos > tamanho)
	  {
		  return;
	  }
	  else if(pos == 0)
	  {
		  inserirInicio(x);
	  }
	  else if(pos == tamanho)
	  {
		  inserirFim(x);
	  }
	  else
	  {
		  Celula tmp = new Celula(x);
		  Celula i = primeiro;
		  for(int j = 0; j<pos; j++)
		  {
			  i = i.prox;

		  }
		  tmp.prox = i.prox;
		  tmp.prox.ant = tmp;
		  i.prox = tmp;
		  tmp.ant = i;
		  i = null;
		  tmp = null;
		  tamanho++;
	  }
	  
  }
  Jogador removerInicio()
  {
	  if(primeiro == ultimo)
	  {
		  return null;
	  }
	  Jogador elemento = primeiro.prox.jogador;
	  Celula tmp = primeiro.prox;
	  tmp.prox.ant = primeiro;
	  primeiro.prox = tmp.prox;
	  tmp.ant =null;
	  tmp.prox = null;
	  tmp = null;
	  tamanho--;
          return elemento;

  }
  Jogador removerFim()
  {
	  if(primeiro == ultimo)
	  {
		  return null;
	  }
	  Jogador elemento = ultimo.jogador;
	  ultimo = ultimo.ant;
	  ultimo.prox.ant = null;
	  ultimo.prox = null;
	  tamanho--;
	  return elemento;
  }
  Jogador remover(int pos)
  {
	  Jogador elemento;
	  if(pos<0 || pos >= tamanho || ultimo == primeiro)
	  {
		  return null;
	  }
	  else if (pos == 0)
	  {
               elemento = removerInicio();
	  }
	  else if(pos == tamanho -1)
	  {
		  elemento = removerFim();
	  }
	  else
	  {
		  Celula i = primeiro.prox;
		  for(int j = 0; j<pos; j++)
		  {
			  i = i.prox;
		  }
		  elemento = i.jogador;
		  i.ant.prox = i.prox;
		  i.prox.ant = i.ant;
		  i.prox = i.ant = null;
		  i = null;
	          tamanho--;	  
	  }


	  return elemento;
  }

  void mostrar()
{
	int j = 0;
	for(Celula i = primeiro.prox; i!=null; i = i.prox)
	{


	    System.out.print("["+i.jogador.getId());
	    System.out.print(" ## ");
	    System.out.print(i.jogador.getNome());
	    System.out.print(" ## ");
	    System.out.print(i.jogador.getAltura());
	    System.out.print(" ## ");
	    System.out.print(i.jogador.getPeso());
	    System.out.print(" ## ");
	    System.out.print(i.jogador.getAnoNascimento());
	    System.out.print(" ## ");
	    System.out.print(i.jogador.getUniversidade());
	    System.out.print(" ## ");
	    System.out.print(i.jogador.getCidadeNascimento());
	    System.out.print(" ## ");
	    System.out.print(i.jogador.getEstadoNascimento());
	    System.out.println("]");
	}
}
  public void sort() {
      quicksort(primeiro.prox, ultimo);
   }

	/**
	 * Algoritmo de ordenacao Quicksort.
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
	 */
      private void quicksort(Celula esq, Celula dir) {
        Celula i = esq, j = dir;
        Celula pivo = dir;
        while (i.ant != j && j.prox != i.ant) {
            while (compare2(i.jogador, pivo.jogador)<0) i = i.prox;
            while (compare2(j.jogador, pivo.jogador)>0) j = j.ant;
            if (i.ant != j && j.prox != i.ant ) {
                Jogador tmp = i.jogador;
		i.jogador = j.jogador;
		j.jogador = tmp;
                i = i.prox;
                j = j.ant;
            }
        }
        if (esq != j && esq.ant != j)  quicksort(esq, j);
        if (i != dir && i!= dir.prox)  quicksort(i, dir);
    } 
      static Celula getPivo(Celula esq, Celula dir)
{
	while(esq != dir && esq.prox!=dir)
	{
		esq = esq.prox;
		dir = dir.ant;
	}
	return esq;
}
   static int compare2(Jogador a, Jogador b)
{
	String jog1;
	String jog2;
	jog1 = a.getEstadoNascimento() + a.getNome().trim();
	jog2 = b.getEstadoNascimento() + b.getNome().trim();
	return jog1.compareTo(jog2);
} 
  public static void main(String args[]) throws Exception 
  {
	   String temp;
	   Jogador[] a = ler();
	   int i = 0;
	   ListaFlex lf = new ListaFlex();
	    while(true)
	    {
		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
                   else if(Integer.parseInt(temp) <3922)
		   {
			   lf.inserirFim(PesquisaId(Integer.parseInt(temp)));
			   i++;
		   }
             }
	            lf.sort();
		    lf.mostrar();
		    

  
  }
}

