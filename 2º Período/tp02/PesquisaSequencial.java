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
	    if(temp[4] == "")
	           jogador[i].setUniversidade("nao informado");  
	    if(temp[6] == "")
		   jogador[i].setCidadeNascimento("nao informado");
	    if(temp[7] == "")
		   jogador[i].setEstadoNascimento("nao informado");
	    i++;
            }
	    Arq.close();
	    return jogador;


    }
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
   /* static Jogador[] Inserir(Jogador temp)
    {
	   
    return temp;  
    }*/
    static boolean PesquisaSequencial(String temp, Jogador[] x, int cont)
    {
	    for(int i = 0; i<cont; i++)
	    {
              if((x[i].getNome()).contains(temp))
			      return true;
	    }
	    return false;
    }
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
    public static void main(String args[])
    {
           String temp;
	   Jogador[] a = ler();
	   Jogador[] b = new Jogador[1000];
	   int i = 0;
	    while(true)
	    {
		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
                   else if(Integer.parseInt(temp) <3922)
		   {
			   Jogador c = PesquisaId(Integer.parseInt(temp));
			   b[i] = c;
			   i++;
		   }
              }
// Chamada da função ler e em sequência imprimir o jogador selecionado pelo ID
	    
            while(true)
	    {
		    temp = MyIO.readLine();
		    if(temp.equals("FIM"))
				    break;
	          boolean c = PesquisaSequencial(temp, b, i);
		   if(c == true)
		     System.out.println("SIM");
		   else
		     System.out.println("NAO");
	    }	    
    }
}
