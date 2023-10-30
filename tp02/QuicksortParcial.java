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
// Metodo para comparar 2 jogadores sendo o atributo primário estadoNascimento e o secundário nome
  static int compare2(Jogador a, Jogador b)
{
	if(a.getEstadoNascimento().compareTo(b.getEstadoNascimento()) != 0 )
		return a.getEstadoNascimento().compareTo(b.getEstadoNascimento());
	else
		return a.getNome().compareTo(b.getNome());
}
}
//Algoritmo de ordenacao Quicksort
class Quicksort extends Geracao
{
	int k;
	int cmp;
	int mov;
	/**
	 * Construtor.
	 * @param int tamanho do array de numeros inteiros.
	 */
   public Quicksort(int tamanho){
      super(tamanho);
      this.k =10;
      this.cmp = 0;
      this.mov = 0;
   }

    // Algoritmo de ordenacao Quicksort.
	
   @Override
   public void sort() {
      quicksort(0, n-1);
   }

	/**
	 * Algoritmo de ordenacao Quicksort.
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
	 */
    private void quicksort(int esq, int dir) {
        int i = esq, j = dir;
        Jogador pivo = array[(dir+esq)/2];
        while (i <= j) {
            while (compare2(array[i], pivo)<0) i++;
            while (compare2(array[j], pivo)>0) j--;
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j)  quicksort(esq, j);
        if (i < k && i < dir)  quicksort(i, dir);
    }
}
//classe que constroi o array de jogadores de tamanho n;
class Geracao extends Jogador
{
	protected Jogador[] array;
	protected int n;
//construtor com o parametro tamanho;
	public Geracao(int tamanho)
	{
		array = new Jogador[tamanho];
		n = tamanho;
	}
	public void entrada()
	{
	
	}
//Metodo para preencher o array de jogadores
	public void preencher(Jogador[] tmp)
	{
		for(int i =0; i<n; i++)
		{
			array[i] = clonej(tmp[i]);
		}
       
	}
//Chamada do metodo de sort
	public void sort()
	{
		System.out.println("Metodo a ser implementado nas subclasses");
	}
//Metodo para imprimir os jogadores na tela
        public void imprimir()
        {
         for(int i =0; i<10; i++)
	 {
            System.out.print("[");
	    System.out.print(array[i].getId());
	    System.out.print(" ## ");
	    System.out.print(array[i].getNome());
	    System.out.print(" ## ");
	    System.out.print(array[i].getAltura());
	    System.out.print(" ## ");
	    System.out.print(array[i].getPeso());
	    System.out.print(" ## ");
	    System.out.print(array[i].getAnoNascimento());
	    System.out.print(" ## ");
	    System.out.print(array[i].getUniversidade());
	    System.out.print(" ## ");
	    System.out.print(array[i].getCidadeNascimento());
	    System.out.print(" ## ");
	    System.out.print(array[i].getEstadoNascimento());
	    System.out.println("]");

        }
	}
//Metodo para trocar a posição de dois elementos no array de jogadores
 public	void swap(int menor, int i)
    {
       Jogador clone1 = clonej(array[i]);
       array[i].setId(array[menor].getId());
       array[i].setNome(array[menor].getNome());
       array[i].setAltura(array[menor].getAltura());
       array[i].setPeso(array[menor].getPeso());
       array[i].setUniversidade(array[menor].getUniversidade());
       array[i].setAnoNascimento(array[menor].getAnoNascimento());
       array[i].setCidadeNascimento(array[menor].getCidadeNascimento());
       array[i].setEstadoNascimento(array[menor].getEstadoNascimento());

       array[menor].setId(clone1.getId());
       array[menor].setNome(clone1.getNome());
       array[menor].setAltura(clone1.getAltura());
       array[menor].setPeso(clone1.getPeso());
       array[menor].setUniversidade(clone1.getUniversidade());
       array[menor].setAnoNascimento(clone1.getAnoNascimento());
       array[menor].setCidadeNascimento(clone1.getCidadeNascimento());
       array[menor].setEstadoNascimento(clone1.getEstadoNascimento()); 
   }
}
//classe principal
class Principal extends Jogador
{
   public static void main(String args[])
    {
           String temp;
	   Jogador[] a = ler();
	   Jogador[] b = new Jogador[3922];
	   int i = 0;
	    while(true)
	    {
		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
                   else if(Integer.parseInt(temp) <3922)
		   {
			   Jogador c = PesquisaId(Integer.parseInt(temp));
			   b[i] = clonej(c);
			   i++;
		   }
              }
// Chamada da função ler e em sequência imprimir o jogador selecionado pelo ID
	   Geracao c;
	   c = new Quicksort(i);
	   c.preencher(b);
	   c.sort();
	   c.imprimir();
    }
}
