/**
 * Classe jogador
 */
class Jogador {
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
    public Jogador() {

    }

    /**
     * Construtor completo.
     *
     * @param id               Id do jogador.
     * @param nome             Nome do jogador.
     * @param altura           Altura do jogador.
     * @param peso             Peso do jogador.
     * @param universidade     Universidade do Jogador.
     * @param anoNascimento    Ano de nascimento do Jogador.
     * @param cidadeNascimento Cidade de nascimento do Jogador.
     * @param estadoNascimento Estado de nascimento do Jogador.
     */
    public Jogador(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
            String cidadeNascimento, String estadoNascimento) {
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
    void setId(int id) {
        this.id = id;
    }

    void setNome(String nome) {
        this.nome = nome;
    }

    void setAltura(int altura) {
        this.altura = altura;
    }

    void setPeso(int peso) {
        this.peso = peso;
    }

    void setUniversidade(String universidade) {
        this.universidade = universidade;
    }

    void setAnoNascimento(int anoNascimento) {
        this.anoNascimento = anoNascimento;
    }

    void setCidadeNascimento(String cidadeNascimento) {
        this.cidadeNascimento = cidadeNascimento;
    }

    void setEstadoNascimento(String estadoNascimento) {
        this.estadoNascimento = estadoNascimento;
    }

    /**
     * Metódos getters
     */
    int getId() {
        return id;
    }

    String getNome() {
        return nome;
    }

    int getAltura() {
        return altura;
    }

    int getPeso() {
        return peso;
    }

    String getUniversidade() {
        return universidade;
    }

    int getAnoNascimento() {
        return anoNascimento;
    }

    String getCidadeNascimento() {
        return cidadeNascimento;
    }

    String getEstadoNascimento() {
        return estadoNascimento;
    }

    /**
     * Metódo iterativo para pesquisar um jogador
     *
     * @param x Id do jogador a se pesquisar.
     * @return temp Jogador com o id x.
     */
    static Jogador PesquisaId(int x) {
        Jogador[] temp = ler();
        for (int i = 0; i < 3922; i++) {
            if (temp[i].getId() == x) {
                return temp[i];
            }
        }
        return temp[0];
    }

    static Jogador PesquisaNome(String nome) {
        Jogador[] temp = ler();
        for (int i = 0; i < 3922; i++) {
            if (temp[i].getNome().compareTo(nome) == 0) {
                return temp[i];
            }
        }
        return temp[0];
    }

    /**
     * Metódo iterativo para ler o arquivo de jogadores.
     *
     * @return array de jogadores preenchido.
     */
    static Jogador[] ler() {
        Arq.openRead("/tmp/players.csv");
        Jogador[] jogador = new Jogador[3922];
        int i = 0;
        Arq.readLine();
        while (Arq.hasNext()) {
            jogador[i] = new Jogador();
            String jog = Arq.readLine();
            String[] temp = new String[8];
            temp = jog.split(",", 8);
            jogador[i].setId(Integer.parseInt(temp[0]));
            jogador[i].setNome(temp[1]);
            jogador[i].setNome(jogador[i].getNome().replace('*', ' '));
            jogador[i].setAltura(Integer.parseInt(temp[2]));
            jogador[i].setPeso(Integer.parseInt(temp[3]));
            jogador[i].setUniversidade(temp[4]);
            jogador[i].setAnoNascimento(Integer.parseInt(temp[5]));
            jogador[i].setCidadeNascimento(temp[6]);
            jogador[i].setEstadoNascimento(temp[7]);

            // Ifs para lidar com campos vazios
            if (temp[4].isEmpty())
                jogador[i].setUniversidade("nao informado");
            if (temp[6].isEmpty())
                jogador[i].setCidadeNascimento("nao informado");
            if (temp[7].isEmpty())
                jogador[i].setEstadoNascimento("nao informado");
            i++;
        }
        Arq.close();
        return jogador;

    }

    /**
     * Metódo para clonar um jogador.
     *
     * @param jogador Jogador a ser clonado.
     * @return temp Jogador clonado.
     */
    static Jogador clonej(Jogador jogador) {

        String temp;
        Jogador clone = new Jogador();
        temp = Integer.toString(jogador.getId());
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

        return clone;
    }
}

class Hash {
    Jogador tabela[];
    int m, m1, m2, reserva;
    final int NULO = -1;

    public Hash() {
        this(21, 9);
    }

    public Hash(int m1, int m2) {
        this.m1 = m1;
        this.m2 = m2;
        this.m = m1 + m2;
        this.tabela = new Jogador[this.m];
        for (int i = 0; i < m; i++) {
            tabela[i] = null;
        }
        reserva = 0;
    }

    public int h(Jogador elemento) {
        return elemento.getAltura() % m1;
    }

    public int reh(int elemento) {
        return ++elemento % m;
    }

    public boolean inserir(Jogador elemento) {
        boolean resp = false;
        if (elemento != null) {
            int pos = h(elemento);
            if (tabela[pos] == null) {
                tabela[pos] = elemento;
                resp = true;
            } else if (reserva < m2) {
                tabela[m1 + reserva] = elemento;
                reserva++;
                resp = true;
            }
        }
        return resp;
    }

    public boolean pesquisar(Jogador elemento) {
        boolean resp = false;
        int pos = h(elemento);
        if (tabela[pos] != null && tabela[pos].getNome().compareTo(elemento.getNome()) == 0) {
            resp = true;
        } else {
            for (int i = 0; i < reserva; i++) {
                if (tabela[m1 + 1] != null && tabela[m1 + i].getNome().compareTo(elemento.getNome()) == 0) {
                    resp = true;
                    i = reserva;
                }
            }
        }
        return resp;
    }
}

/**
 * Classe com o metódo main
 */
class TP04Q07 extends Jogador {
    public static void main(String args[]) throws Exception {
        String temp;
        Hash hash = new Hash();
        int i = 0;
        while (true) {
            temp = MyIO.readLine();
            if (temp.equals("FIM"))
                break;
            else if (Integer.parseInt(temp) < 3922) {
                hash.inserir(PesquisaId(Integer.parseInt(temp)));
                i++;
            }

        }
        while (true) {
            temp = MyIO.readLine();
            if (temp.equals("FIM"))
                break;
            else if (hash.pesquisar(PesquisaNome(temp)))
                System.out.println(temp + " SIM");
            else
                System.out.println(temp + " NAO");
        }

    }
}
