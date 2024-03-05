/**
 * Classe jogador
 */
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
/**
 * Construtor sem parâmetros.
 */
    public Jogador()
    {

    }
/**
 * Construtor completo.
 * @param id Id do jogador.
 * @param nome Nome do jogador.
 * @param altura Altura do jogador.
 * @param peso Peso do jogador.
 * @param universidade Universidade do Jogador.
 * @param anoNascimento Ano de nascimento do Jogador.
 * @param cidadeNascimento Cidade de nascimento do Jogador.
 * @param estadoNascimento Estado de nascimento do Jogador.
 */
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
/**
 * Metódos setters
 */
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
/**
 * Metódos getters
 */
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
    /**
     * Metódo iterativo para pesquisar um jogador
     * @param x Id do jogador a se pesquisar.
     * @return temp Jogador com o id x.
     */
    static String PesquisaId(int x)
    {
	    Jogador[] temp = ler();
	    for(int i = 0; i<3922; i++)
	    {
		    if(temp[i].getId()==x)
		    {
			    return temp[i].getNome();
		    }
	    }
	    return temp[0].getNome();
    }
    /** 
     * Metódo iterativo para ler o arquivo de jogadores.
     * @return array de jogadores preenchido.
     */
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
	   // jogador[i].setNome(jogador[i].getNome().replace('*', ' '));
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
    /**
     * Metódo para clonar um jogador.
     * @param jogador Jogador a ser clonado.
     * @return temp Jogador clonado.
     */
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
/**
 * Classe No da Arvore
 */
class No
{
	No[] prox;
	char letra;
	boolean folha;
/**
 * Construtor sem parametros
 */
 public No()
{
	this(' ');
}
/**
 * Construtor completo.
 * @param esq Ponteiro para o No esquerdo.
 * @param dir Ponteiro para o No direito.
 * @param elemento Jogador a ser colocado no No.
 */
public No(char letra)
{
	prox = new No[255];
	for(int i = 0; i<255; i++)
        prox[i] = null;
	this.letra = letra;
	folha = false;
}
}
/**
 * Classe ArvoreBinaria
 */
class ArvoreBinaria
{
	No raiz;
	/**
	 * Construtor sem parametros
	 */
	public ArvoreBinaria()
	{
		raiz = new No();
	}
	/**
	 * Metódo inicializador da recursividade do método inserir.
	 * @param elemento Jogador a ser inserido.
	 */
	void inserir(String s) throws Exception
	{
              inserir(raiz, s, 0);
	}
	/**
	 * Metódo recursivo de inserção na Arvore Binária.
	 * @param i No atual.
	 * @param elemento Jogador a ser inserido.
	 * @return No atual para montar a arvore automaticamente.
	 */
	void inserir(No i, String s, int index) throws Exception
	{
             if(i.prox[s.charAt(index)] == null)
	     {
		     i.prox[s.charAt(index)] = new No(s.charAt(index));
		     if(index == s.length()-1)
		     {
			     i.prox[s.charAt(index)].folha = true;
		     }
	             else
		     {
			     inserir(i.prox[s.charAt(index)], s, index+1);
		     }	     
	     }
	     else if(i.prox[s.charAt(index)].folha == false && index <s.length()-1)
	     {
		     inserir(i.prox[s.charAt(index)], s, index+1);
	     }
	     else
	     {

	     }

	}
	void mostrar()
	{
		mostrar(raiz, "");
	}
	void mostrar(No no, String s)
	{
		if(no.folha == true)
		{
			System.out.println(s+no.letra);
		}
		else
		{
			for(int i = 0; i<255; i++)
			{
				if(no.prox[i] != null)
				{
					mostrar(no.prox[i], s+no.letra);
				}
			}
		}
	}
	/**
	 * Metódo inicializador da recursividade do método pesquisar.
	 * @param elemento String a ser pesquisa na Árvore Binária.
	 * @return <code>true<\code> caso o elemento seja encontrado
	 * <code>false<\code> caso não seja encontrado.
	 */
	boolean pesquisar(String elemento)

	{
		System.out.print(elemento);
		return pesquisar(raiz, elemento, 0);
	}
	/**
	 * Metódo recursivo de pesquisa na Árvore Binária.
	 * @param i No atual.
	 * @param elemento String a ser procurada.
	 * @return <code>true<\code> caso o elemento seja encontrado
	 * <code>false<\code> caso não seja encontrado.
	 */
	boolean pesquisar(No i, String elemento, int index)
	{
		boolean resp;
		if(i.prox[elemento.charAt(index)]== null)
		{
			resp = false;
		}
		else if(index == elemento.length()-1)
				{
					resp = i.prox[elemento.charAt(index)].folha = true;
				}
		else if(index < elemento.length()-1)
	        {
			resp = pesquisar(i.prox[elemento.charAt(index)], elemento, index+1);
		}
		else
			resp = false;
		return resp;
	}


void mostrar2(No raiz) throws Exception
	{
		for(int i =0; i<255; i++)
			if(raiz.prox[i]!= null)
			{
		mostrar2(raiz.prox[i], "");
			}
	}
	void mostrar2(No no, String s) throws Exception
	{
		if(no.folha == true)
		{
			inserir(s+no.letra);
		}
		else
		{
			for(int i = 0; i<255; i++)
			{
				if(no.prox[i] != null)
				{
					mostrar2(no.prox[i], s+no.letra);
				}
			}
		}
	}
}
/**
 * Classe com o metódo main
 */
class TP04Q06 extends Jogador
{
	 public static void main(String args[]) throws Exception
  {
	   String temp;
	   ArvoreBinaria ab = new ArvoreBinaria();
	   ArvoreBinaria ab2 = new ArvoreBinaria();
	   int i = 0;
	    while(true)
	    {
		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
                   else if(Integer.parseInt(temp) <3922)
		   {
			   ab.inserir(PesquisaId(Integer.parseInt(temp)));
		   }

             }
	    while(true)
	    {
		    temp = MyIO.readLine();
		    if(temp.equals("FIM"))
			    break;
		    else if(Integer.parseInt(temp) < 3922)
		    {
			    ab2.inserir(PesquisaId(Integer.parseInt(temp)));
			    i++;
		    }

	    }
            for(int j = 0; j<i; j++)
	    {
                  ab.mostrar2(ab2.raiz);
	    }
	    while(true)
	    {
		    temp = MyIO.readLine();
		    if(temp.equals("FIM"))
			    break;
		    else if(ab.pesquisar(temp))
			    System.out.println( " SIM");
		    else
			    System.out.println( " NAO");
	    }
	   // ab.mostrar();



  }
}

