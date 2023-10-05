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
    static Jogador ler(int x)
    {
	    Arq.openRead("/tmp/players.csv");
	    Jogador jogador= new Jogador();
	    Arq.readLine();
	    while(Arq.hasNext())
	    { 
	    String jog = Arq.readLine();
	    String[] temp = new String[8];
            temp= jog.split(",", 8);
	    jogador.setId(Integer.parseInt(temp[0]));
            jogador.setNome(temp[1]);
	    jogador.setAltura(Integer.parseInt(temp[2]));
	    jogador.setPeso(Integer.parseInt(temp[3]));
	    jogador.setUniversidade(temp[4]);
	    jogador.setAnoNascimento(Integer.parseInt(temp[5]));
	    jogador.setCidadeNascimento(temp[6]);
	    jogador.setEstadoNascimento(temp[7]);

// Ifs para lidar com campos vazios
	    if(temp[4] == "")
	           jogador.setUniversidade("nao informado");  
	    if(temp[6] == "")
		   jogador.setCidadeNascimento("nao informado");
	    if(temp[7] == "")
		   jogador.setEstadoNascimento("nao informado");
	    if(jogador.id == x)
	    {
		    return jogador;
	    }
            }
	    Arq.close();
	    return jogador;

    }
    public static void main(String args[])
    {
           String temp;
	    while(true)
	    {
		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
// Chamada da função ler e em sequência imprimir o jogador selecionado pelo ID
	           Jogador a = ler(Integer.parseInt(temp));
	           a.imprimir();
	    }
	   
    }
}
