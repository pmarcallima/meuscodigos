class PesquisaSequencial
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
    public PesquisaSequencial()
    {

    }
// Construtor com parâmetros para todos atributos
    public PesquisaSequencial(int id, String nome, int altura, int peso, String universidade, int anoNascimento, String cidadeNascimento, String estadoNascimento)
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
// Método para imprimir os atributos do jogador
    void imprimir()
    {
	    System.out.print("[");
	    System.out.print(id);
	    System.out.print(" ## ");
	    System.out.print(nome);
	    System.out.print(" ## ");
	    System.out.print(altura);
	    System.out.print(" ## ");
	    System.out.print(peso);
	    System.out.print(" ## ");
	    System.out.print(anoNascimento);
	    System.out.print(" ## ");
	    System.out.print(universidade);
	    System.out.print(" ## ");
	    System.out.print(cidadeNascimento);
	    System.out.print(" ## ");
	    System.out.print(estadoNascimento);
	    System.out.println("]");

    }

// Método para ler o jogador a partir do ID do parâmetro
    static boolean ler(String x)
    {
	    Arq.openRead("/tmp/players.csv");
	    PesquisaSequencial jogador= new PesquisaSequencial();
	    Arq.readLine();
	    while(Arq.hasNext())
	    { 
	      String jog = Arq.readLine();
	      String[] temp = new String[8];
              temp= jog.split(",", 8);
              jogador.setNome(temp[1]); 
	      String nome = jogador.getNome();
	      if(x.equals(nome))
	      {
		      Arq.close();
		      return true;
	      }
            }

	    Arq.close();
	    return false;

    }

    public static void main(String args[])
    {
           String temp= new String();
	   boolean a;
	    while(true)
	    {
		  		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
// Chamada da função ler e em sequência imprimir o jogador selecionado pelo ID
	    }
	    while(true)
	    {
		  		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
// Chamada da função ler e em sequência imprimir o jogador selecionado pelo ID
	           a = ler(temp);
		   if(a==true)
		   {
			   System.out.println("SIM");
		   }
		   else
			   System.out.println("NAO");
	    }
    }
}
  
  


