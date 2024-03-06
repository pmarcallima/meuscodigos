import java.util.Scanner;
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
	protected Celula prox;
	Celula()
	{
		this(null);
	}
	Celula(Jogador jogador)
	{
		this.jogador = jogador;
		prox = null;
	}
}
class PilhaFlex extends Jogador
{
	Celula topo;
	int tamanho;
	PilhaFlex()
	{
		topo = null;
		tamanho = 0;
	}
	void inserir(Jogador jogador)
	{
		Celula tmp = new Celula(jogador);
		tmp.prox = topo;
		topo = tmp;
		tmp = null;
		tamanho++;
	}
	Jogador remover()
	{
		Celula tmp = topo;
		Jogador jogador = tmp.jogador;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
		tamanho--;
		return jogador;
	}
	void mostrar()
	{
	
		mostrar(tamanho, topo);
	}
	 void mostrar(int x, Celula i)
        {
	    if(i!=null)
	    {
	    mostrar(--x, i.prox);	
	    System.out.print("["+(x)+"]");
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
	    System.out.println(" ## ");
	    }
	}

  public static void main(String args[]) throws Exception 
  {
	   String temp;
	   Jogador[] a = ler();
	   int i = 0;
	   PilhaFlex t = new PilhaFlex();
	   PilhaFlex pf= new PilhaFlex();
	    while(true)
	    {
		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
                   else if(Integer.parseInt(temp) <3922)
		   {
			   pf.inserir(PesquisaId(Integer.parseInt(temp)));
			   i++;
		   }
		   
             }
	    int num = MyIO.readInt();
		    for(int j = 0; j<num; j++)
		    {
			   
			    if(j == num-1)
			    {
				    Jogador removido = pf.remover();
				    System.out.println("(R) "+removido.getNome());
				    break;
			    }
			    String acao = MyIO.readString();
			    if(acao.equals("I"))
			    {
			      int id = MyIO.readInt();
			      pf.inserir(PesquisaId(id));
			    }
			    else if(acao.equals("R"))
			    {

			      
			      Jogador removido = pf.remover();
			      System.out.println("(R) "+removido.getNome());
			    }
			    
			
		    }  
		    pf.mostrar();
		    

  
  }

}
