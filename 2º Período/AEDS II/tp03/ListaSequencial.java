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
class ListaSequencial extends Jogador
{
	private Jogador[] array;
	private int n;

  public ListaSequencial()
  {
	  this(0);
  }
  public ListaSequencial(int tamanho)
  {
	  array = new Jogador[tamanho];
	  n = 0;
  }
  void inserirInicio(Jogador jogador) throws Exception{
  {

	if(n>= array.length)
	{
		throw new Exception("Erro ao inserir");
	}
	for(int i = n; i>0 ; i--)
	{
		array[i] = array[i-1];
	}
	array[0] = jogador;
	n++;
  }
}
  void inserir(Jogador jogador, int pos) throws Exception{
  {
	  if(pos<0 || pos>array.length)
	  {
		  throw new Exception("Posição Invalida");
	  }
	  for(int i =n; i>pos; i--)
	  {
		  array[i] = array[i-1];
	  }
	  array[pos] = jogador;
	  n++;
  }
}
  void inserirFim(Jogador jogador) throws Exception{
  {
	  if(n>= array.length)
	  {
		  throw new Exception("Array cheio");
	  }
	  array[n] = jogador;
	  n++;
  }
}
  Jogador removerInicio() throws Exception{
  {

	  if(n == 0)
	  {
		  throw new Exception("Array vazio");
	  }
	  Jogador resp = array[0];
	  for(int i =0; i<n-1; i++)
	  {
		  array[i] = array[i+1];
	  }
	  n--;
	  return resp;
  }
}
  Jogador remover(int pos) throws Exception{
  {
	  if(pos<0 || pos >=n || n==0)
	  {
		  throw new Exception("Nao foi possivel remover");
	  }
	  Jogador resp = array[pos];
	  for(int i = pos; i<n-1; i++)
	  {
		  array[i] = array[i+1];
	  }
	  n--;
	  return resp;
  }
}
  Jogador removerFim() throws Exception{
  {
	  if( n== 0)
	  {
		  throw new Exception("Array vazio");
	  }
	  return array[--n];
  }
  }
  public void preencher(Jogador[] tmp)
	{

		for(int i =0; i<n; i++)
		{
			n++;
			array[i] = clonej(tmp[i]);
		}
             System.out.println(n);
	}
  void mostrar()
{
	for(int i =0; i<n; i++)
	{
	System.out.print("["+i+"]");
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
	    System.out.println(" ## ");
	}
}
  
  public static void main(String args[]) throws Exception {
  {
	    String temp;
	   Jogador[] a = ler();
	   Jogador[] b = new Jogador[3922];
	   int i = 0;
	   ListaSequencial ls = new ListaSequencial(3923);
	    while(true)
	    {
		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
                   else if(Integer.parseInt(temp) <3922)
		   {
			   ls.inserirFim(PesquisaId(Integer.parseInt(temp)));
			   i++;
		   }
              }
	    int num = MyIO.readInt();
		    for(int j = 0; j<num ;j++)
		    {
			    String acao = MyIO.readString();
			    if(acao.equals("II"))
			    {
			       int id = MyIO.readInt();
                               ls.inserirInicio(PesquisaId(id));
			    }
			    else if(acao.equals("I"))
			    {
			      int id = MyIO.readInt();
			      ls.inserirFim(PesquisaId(id));

			    }
			    else if(acao.equals("I*"))
			    {
			      int pos = MyIO.readInt();
			      int id = MyIO.readInt();
			      ls.inserir(PesquisaId(id), pos);
			    }
			    else if(acao.equals("R"))
			    {
		              Jogador removido = ls.removerFim();
			      System.out.println("(R) "+ removido.getNome());

			    }
			    else if(acao.equals("RI"))
			    {
			      Jogador removido = ls.removerInicio();
			      System.out.println("(R) "+removido.getNome());

			    }
			    else
			    {
			      int pos = MyIO.readInt();
			      Jogador removido = ls.remover(pos);
			      System.out.println("(R) "+removido.getNome());

			    }
			   
		    }
		    ls.mostrar();

  }
  }
}

