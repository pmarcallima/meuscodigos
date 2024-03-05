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
	    jogador[i].setNome(jogador[i].getNome().replace('*', ' '));
	    jogador[i].setNome(jogador[i].getNome().replace((char)39, ' '));
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
	No esq;
	No dir;
	int elemento;
	No2 outro;
/**
 * Construtor sem parametros
 */
 public No()
{
	this(null, null, 0, null);
}
/**
 * Construtor com um parametro.
 * @param elemento Jogador a ser colocado no No.
 */
 public No(int elemento)
{
	this(null, null, elemento, null);
}
/**
 * Construtor completo.
 * @param esq Ponteiro para o No esquerdo.
 * @param dir Ponteiro para o No direito.
 * @param elemento Jogador a ser colocado no No.
 * @param outro raiz da Arvore dentro do No.
 */
public No(No esq, No dir, int elemento, No2 outro)
{
	this.esq = esq;
	this.dir = dir;
	this.elemento = elemento;
	this.outro = outro;
}
}
/**
 * Classe No2 da ArvoreSecundária
 */
class No2
{
	No2 esq;
	No2 dir;
	Jogador elemento;
/**
 * Construtor sem parametros
 */
 public No2()
{
	this(null, null, null);
}
/**
 * Construtor com um parametro.
 * @param elemento Jogador a ser colocado no No2.
 */
 public No2(Jogador elemento)
{
	this(null, null,  elemento);
}
/**
 * Construtor completo.
 * @param esq Ponteiro para o No2 esquerdo.
 * @param dir Ponteiro para o No2 direito.
 * @param elemento Jogador a ser colocado no No2.
 */
public No2(No2 esq, No2 dir, Jogador elemento)
{
	this.esq = esq;
	this.dir = dir;
	this.elemento = elemento;
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
		this(null);
	}
	/**
	 * Construtor com um parametro
	 * @param raiz Raiz da arvore
	 */
	public ArvoreBinaria(No raiz)
	{
		this.raiz = raiz;
	}
	/**
	 * Metódo inicializador da recursividade do método inserir.
	 * @param elemento Jogador a ser inserido.
	 */
	void inserir(int elemento) throws Exception
	{
              raiz = inserir(raiz, elemento);
	}
	/**
	 * Metódo recursivo de inserção na Arvore Binária.
	 * @param i No atual.
	 * @param elemento Jogador a ser inserido.
	 * @return No atual para montar a arvore automaticamente.
	 */
	No inserir(No i, int elemento) throws Exception
	{
		if(i == null)
		{
			i = new No(elemento);
		}
		else if(i.elemento > elemento)
			{
					i.esq = inserir(i.esq, elemento);
			}
		else if(i.elemento< elemento)
			{
				i.dir = inserir(i.dir, elemento);
			}
		else
		{
			throw new Exception("Elemento ja existente!");
		}
		 return i;
	}
	/**
	 * Metódo inicializador da recursividade do método inserir.
	 * @param elemento Jogador a ser inserido.
	 */
	void inserirJogador(Jogador elemento) throws Exception
	{
              inserirJogador(raiz, elemento);
	}
	/**
	 * Metódo recursivo de inserção na Arvore Binária.
	 * @param i No atual.
	 * @param elemento Jogador a ser inserido.
	 * @return No atual para montar a arvore automaticamente.
	 */
	No inserirJogador(No i, Jogador elemento) throws Exception
	{

		if(elemento.getAltura()%15== i.elemento)
		{
			i.outro = inserirSecundaria(i.outro, elemento);
		}
		else if(elemento.getAltura()%15<i.elemento)
			{
				inserirJogador(i.esq, elemento);
			}
		else if(elemento.getAltura()%15>i.elemento)
			{
				inserirJogador(i.dir, elemento);
			}
		else
		{
			throw new Exception("Elemento ja existente!");
		}
		return i;
	
	}
        No2 inserirSecundaria(No2 i, Jogador elemento)
	{
	     if(i == null)
	     {
		     i = new No2(elemento);
	     }	     
	     else if(elemento.getNome().compareTo(i.elemento.getNome())<0)
	     {
		     i.esq = inserirSecundaria(i.esq, elemento);
	     }
	     else if(elemento.getNome().compareTo(i.elemento.getNome())>0)
	     {
		     i.dir = inserirSecundaria(i.dir, elemento);
	     }
	     return i;
	}
	/**
	 * Metódo inicializador da recursividade do método pesquisar.
	 * @param elemento String a ser pesquisa na Árvore Binária.
	 * @return <code>true<\code> caso o elemento seja encontrado
	 * <code>false<\code> caso não seja encontrado.
	 */
	boolean pesquisar(String nome)
	{
		System.out.print(nome+" raiz ");
		return pesquisar(raiz, nome);
	}
	boolean pesquisar(No i, String nome)
	{
		boolean resp = false;
		if(i!=null)
		{
			resp = pesquisarArvoreSecundaria(i.outro,nome);
			System.out.print("esq ");
			resp = pesquisar(i.esq,nome);
			System.out.print("dir ");
			resp = pesquisar(i.dir, nome);
		}
		return resp;
	}
	/**
	 
	 * Metódo recursivo de pesquisa na Árvore Binária.
	 * @param i No atual.
	 * @param elemento String a ser procurada.
	 * @return <code>true<\code> caso o elemento seja encontrado
	 * <code>false<\code> caso não seja encontrado.
	 */
	boolean pesquisarArvoreSecundaria(No2 i, String elemento)
	{
		boolean resp;
		if(i== null)
		{
			resp = false;
		}
		else if(i.elemento.getNome().compareTo(elemento)==0)
				{
					resp = true;
				}
		else if(i.elemento.getNome().compareTo(elemento)>0)
		{
			System.out.print("ESQ ");
			resp = pesquisarArvoreSecundaria(i.esq, elemento);
		}
		else
		{
			System.out.print("DIR ");
			resp = pesquisarArvoreSecundaria(i.dir, elemento);
		}
		return resp;
	}
	boolean mostrar(String nome)
	{
		System.out.print(nome+" raiz ");
		return mostrar(raiz, nome);
	}
	boolean mostrar(No i, String nome)
	{
		boolean resp = false;
		if(i!= null)
		{
		resp = mostrar(i.outro, nome);
		if(!resp)
		{
		System.out.print("esq ");
		resp = mostrar(i.esq, nome);
		}
		if(!resp)
		{
		System.out.print("dir ");
		resp = mostrar(i.dir, nome);
		}
		}
		return resp;
	}
	boolean mostrar(No2 i, String nome)
	{
		boolean resp = false;
		if(i!=null)
		{
			if(i.elemento.getNome().compareTo(nome) == 0)
				resp = true;
			else 
			{
		//	System.out.print("ESQ ");
		        if(!resp)
			{
	                System.out.print("ESQ ");
			resp = mostrar(i.esq, nome);
			}
		        if(!resp)
			{
		//	System.out.print("DIR ");
		        System.out.print("DIR ");
			resp = mostrar(i.dir, nome);
			}
			}
		}
		return resp;
	}
}
/**
 * Classe com o metódo main
 */
class TP04Q02 extends Jogador
{
	 public static void main(String args[]) throws Exception
  {
	   String temp;
	   ArvoreBinaria ab = new ArvoreBinaria();
	   int i = 0;
	   ab.inserir(7);
	   ab.inserir(3);
	   ab.inserir(11);
	   ab.inserir(1);
	   ab.inserir(5);
	   ab.inserir(9);
	   ab.inserir(12);
	   ab.inserir(0);
	   ab.inserir(2);
	   ab.inserir(4);
	   ab.inserir(6);
	   ab.inserir(8);
	   ab.inserir(10);
	   ab.inserir(13);
	   ab.inserir(14);
	   while(true)
	    {
		   temp =  MyIO.readLine();
		   if(temp.equals("FIM"))
				   break;
                   else if(Integer.parseInt(temp) <3922)
		   {
			   ab.inserirJogador(PesquisaId(Integer.parseInt(temp))); 
			   i++;
		   }

             }
	    while(true)
	    {
		    temp = MyIO.readLine();
		    if(temp.equals("FIM"))
			    break;
		    else if(ab.mostrar(temp))
			    System.out.println("SIM");
		    else
			    System.out.println("NAO");
	    }

  }
}

