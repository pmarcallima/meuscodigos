#include <iostream>
#include <string.h>
#include <string>
#include <ctype.h>
#include <exception>

using namespace std;
//OBS GERAIS: FOI UTILIZADO O METODO EXECAO PARA RESOLVER O PROBLEMA DE LOOP WHILE INFINITO QUANDO DIGITADA UMA LETRA E TENTAR ATRIBUI-LA A UMA VARIAVEL INT
//Classe que define os atributos do veiculo em strings
class Carro
{
private:
    string placa;
    string modelo;
    string marca;
    string ano;
    string preco;
    string tipo;
    string obs;
public:
    //Construtor default
    Carro() {}
    //Construtor com todos os parametros
    Carro (string placa, string modelo, string marca, string ano, string preco, string tipo, string obs)
    {
        this->placa = placa;
        this->modelo = modelo;
        this->marca = marca;
        this->ano = ano;
        this->preco = preco;
        this->tipo = tipo;
        this->obs = obs;
    }
    //Destruidor do objeto Carro
    ~Carro()
    {

    }

    //funcao para conseguir a placa do veiculo
    string getplacas()
    {
        return placa;
    }
    //funcao para imprimir um veiculo na tela
    void imprimir()
    {
        cout<<"placa: "<<placa <<endl;
        cout<<"modelo: "<<modelo <<endl;
        cout<<"marca: "<<marca<<endl;
        cout<<"ano: "<<ano <<endl;
        cout<<"preco:RS "<<preco<<endl;
        cout<<"tipo: "<<tipo <<endl;
        cout<<"observacoes: "<<obs <<"\n"<<endl;
    }
    //metodo set para atribuir os atributos do veiculo
    void settudo(string placa, string modelo, string marca, string ano, string preco, string tipo, string obs)
    {
        this->placa = placa;
        this->modelo = modelo;
        this->marca = marca;
        this->ano = ano;
        this->preco = preco;
        this->tipo = tipo;
        this->obs = obs;
    }
    //funcao para escrever os veiculos ou o veiculo no arquivo
    void escreverArq()
    {
        FILE *veiculos;
        veiculos = fopen("veiculos.txt", "a");
        fprintf(veiculos, "%s;", placa.c_str());
        fprintf(veiculos, "%s;", modelo.c_str());
        fprintf(veiculos, "%s;", marca.c_str());
        fprintf(veiculos, "%s;", ano.c_str());
        fprintf(veiculos, "%s;", preco.c_str());
        fprintf(veiculos, "%s;", tipo.c_str());
        fprintf(veiculos, "%s;\n", obs.c_str());
        fclose(veiculos);
    }
    //funcao para atribuir por passagem por referencia os atributos do veiculo que recebe como parametro a quantidade de carros (l) e o ponteiro *carros
    void getCarros(int l, Carro *carros)
    {
        char temp[100],p1[8];
        string att[7], p, linhas;
        int i = -1, c = 0, tam, cont2 = 0;
        FILE *veiculos;
        veiculos= fopen("veiculos.txt", "r");
        while(fscanf(veiculos, "%[^;]", temp)!= EOF)
        {
            fgetc(veiculos);
            if( i == -1)
            {
                linhas = temp;
            }
            if( i == 0)
            {
                tam = strlen(temp);
                for (int m = 0 ; m< tam; m++)
                {
                    if (isspace(temp[m]))
                        cont2++;

                }
                p1[0]= temp[cont2+0];
                p1[1]= temp[cont2+1];
                p1[2]= temp[cont2+2];
                p1[3]= temp[cont2+3];
                p1[4]= temp[cont2+4];
                p1[5]= temp[cont2+5];
                p1[6]= temp[cont2+6];
                p1[7]= temp[cont2+7];
                p1[8]= {'\0'};
                p =p1;
                cont2 = 0;

            }
            else
            {
                att[i] = temp;
            }
            i = i + 1;
            if(i == 7)
            {
                (carros+c)->settudo(p,att[1],att[2],att[3],att[4],att[5],att[6]);
                i = 0;
                c = c+ 1;
            }

        }
        fclose(veiculos);
    }
};
//funcao para cadastrar um novo veiculo que recebe como parametro a quantidade de carros (l)
void cadastrarCarros(int l)
{
    string temp[7];
    Carro *carros = new Carro [l];
    carros->getCarros(l, carros);
    int num = 0, f, t = 0, encontrado = 0, cont = 0;
    do
    {
        cout<<"digite a placa"<<endl;
        cin>>temp[0];
        encontrado = 0;
        for(cont = 0; cont<l; cont++)
        {
            //metodo para conferir se a placa existe no arquivo
            if ((carros+cont)->getplacas()== temp[0])


            {
                encontrado = 1;
                cout<<"placa ja existente"<<endl<<endl;


            }

        }
        //metodo para conferir e avisar sobre o tamanho da placa invalido
        if(temp[0].size()!=7)
        {
            cout<<"tamanho de placa invalido"<<endl<<endl;
        }
    }
    while (temp[0].size()!= 7 || encontrado ==1);
    cout<<"digite o modelo"<<endl;
    cin>> temp[1];
    cout<<"digite a marca"<<endl;
    cin>> temp[2];
    cout<<"digite o ano"<<endl;
    cin>> temp[3];
    cout<<"digite o preco"<<endl;
    cin>> temp[4];
    cout<<"escolha o tipo\n1-Carro \n2-Moto"<<endl;
    cin>> t;
    if (t==1)
    {
        temp[5] = "Carro";
    }
    else if(t==2)
    {
        temp[5]= "Moto";
    }
    else if(t==0)
    {
        return throw exception();
    }
    cout<<"possui alguma observacao\n 1-Sim \n 2-Nao"<<endl;
    do
    {

        cin>>num;
        if(num == 1)
        {
            cout<<"Digite a observacao(sem espacos)"<<endl;
            cin >> temp[6];
        }
        else if (num == 2)
        {
            temp[6] = ' ';
        }
        else if(num==0)
        {
            return throw exception();
        }

    }
    while ( num != 1 && num != 2);

    Carro carro(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6]);
    FILE *veiculos;
    cout<<"veiculo cadastrado:"<<endl<<endl;
    carros->getCarros(l, carros);
    veiculos= fopen("veiculos.txt", "w");
    f = l+1;
    //metodo para digitar o numero de carros no inicio do arquivo
    fprintf(veiculos, "%d;\n", f);
    fclose(veiculos);
    carro.imprimir();
    for(int cont = 0; cont<l; cont++)
    {
        (carros+cont)->escreverArq();
    }
    veiculos = fopen("veiculos.txt", "a");
    carro.escreverArq();
    fclose(veiculos);

}
//funcao para pesquisar os carros no arquivo que recebe como parametro o numero de carros (l)
void pesquisarCarros(int l)
{
    char n[8];
    string att[7], p, linhas;
    int  encontrado = 0;
    Carro *carros = new Carro [l];
    carros->getCarros(l, carros);
    cout<<endl<<"digite a placa do veiculo desejado"<<endl;
    do
    {
        cin>>n;
if(strlen(n)!=7)
     {
         cout<<endl<<"tamanho de placa invalido"<<endl;
     }
    }

    //verificacao do tamanho da placa
    while (strlen(n)!= 7);
    for (int cont = 0; cont<l; cont++)
    {


        //metodo para conferir se a placa digitada existe no arquivo
        if ((carros+cont)->getplacas()== n)
        {
            cout<<endl<<"veiculo encontrado"<<endl<<endl;
            (carros+cont)->imprimir();
            encontrado = 1;

        }

    }
    if(encontrado == 0)
    {
        cout<<endl<<"veiculo nao encontrado"<<endl<<endl;
    }
}
//funcao que lista os carros
void listarCarros(int l)
{
    string att[7], p, num;
    Carro *carros = new Carro [l];
    carros->getCarros(l, carros);
    for(int i = 0; i<l; i++)
    {
        (carros+i)->imprimir();
    }
}

//funcao que delete um carro
void deletCarros(int l)
{
    char  n[8];
    string att[7], p ;
    int  encontrado = 0, f = l, om = -1, s;
    Carro *carros = new Carro [l];
    FILE *veiculos;
    carros->getCarros(l, carros);
    cout<<endl<<"Digite a placa do veiculo a ser excluido"<<endl;
    do
    {
        cin>>n;

    }
    //verificacao do tamanho da placa
    while (strlen(n)!= 7);
    for (int cont = 0; cont<l; cont++)
    {
        //metodo para conferir se a placa existe no arquivo
        if ((carros+cont)->getplacas()== n)
        {
            cout<<endl<<"veiculo encontrado"<<endl<<endl;
            cout<<"deseja realmente deletar o seguinte veiculo:"<<endl<<endl;
            (carros+cont)->imprimir();
            encontrado = 1;
            cout<<"1-Sim \n2-Nao"<<endl<<endl;
            cin>>s;
            if( s== 1)
            {
                om = cont;
                f = l-1;
            }
            else if(s==0)
            {
                return throw exception();
            }
            veiculos= fopen("veiculos.txt", "w");
            fprintf(veiculos, "%d;\n", f);
            fclose(veiculos);


        }
    }
    for(int cont = 0; cont<l; cont++)
    {
        //metodo para pular o veiculo deletado na hora de escrever no arquivo
        if(cont != om)
        {
            (carros+cont)->escreverArq();
        }
        else
        {
            cout<<"veiculo deletado"<<endl<<endl;
        }
    }
    delete[] carros;
    if(encontrado == 0)
    {
        cout<<"veiculo nao encontrado"<<endl<<endl;
    }
}
//funcao que edita um carro
void editarCarros(int l)
{
    char n[8];
    string att[7], p, linhas;
    int num = 0, f = l, t= 0, encontrado = 0;
    FILE *veiculos;
    Carro *carros = new Carro [l];
    carros->getCarros(l, carros);
    do
    {
        cout<<"digite a placa do veiculo a ser editado"<<endl;
        cin>>n;
        if(strlen(n)!=7)
        {
            cout<<endl<<"tamanho de placa invalido"<<endl;
        }

    }
    //metodo para conferir o tamanho do placa
    while (strlen(n)!= 7);
    for (int cont = 0; cont<l; cont++)
    {

        p = (carros+cont)->getplacas();
        //comparacao para conferir se a placa digitada existe no arquivo
        if (p == n)
        {
            encontrado = 1;
            cout<<"veiculo encontrado"<<endl<<endl;
            cout<<"digite o modelo"<<endl;
            cin>> att[1];
            cout<<"digite a marca"<<endl;
            cin>> att[2];
            cout<<"digite o ano"<<endl;
            cin>> att[3];
            cout<<"digite o preco"<<endl;
            cin>> att[4];
            cout<<"Escolha o tipo\n1-Carro \n2-Moto"<<endl;
            cin>> t;
            if (t==1)
            {
                att[5] = "Carro";
            }
            else if(t==2)
            {
                att[5]= "Moto";
            }
            else if(t==0)
            {
                return throw exception();
            }
            cout<<"possui alguma observacao\n1-Sim \n2-Nao"<<endl;
            cin>> num;
            do
            {
                try
                {
                    if(num == 1)
                    {
                        cout<<endl<<"Digite a observacao(sem espacos)"<<endl;
                        cin >> att[6];
                        (carros+cont)->settudo(p, att[1],att[2],att[3],att[4],att[5], att[6]);
                        cout<<"veiculo editado"<<endl;
                    }
                    else if (num == 2)
                    {
                        att[6] = ' ';
                        (carros+cont)->settudo(p, att[1],att[2],att[3],att[4],att[5], att[6]);
                        cout<<"veiculo editado"<<endl;
                    }
                    else if (num == 0)
                    {
                        return throw exception();
                    }
                    else
                    {
                        cout<<"opcao invalida"<<endl<<endl;
                    }

                }
                catch (exception& e)
                {
                    return throw;
                }
            }

            while ( num != 1 && num != 2);
        }

    }
    //metodo para digitar o numero de carros no inicio do arquivo
    veiculos= fopen("veiculos.txt", "w");
    fprintf(veiculos, "%d;\n", f);
    fclose(veiculos);
    if(encontrado == 0)
    {
        cout<<endl<<"veiculo nao encontrado"<<endl<<endl;
    }
    for(int cont = 0; cont<l; cont++)
    {
        (carros+cont)->escreverArq();
    }
    delete[] carros;
}
//funcao para conseguir as linhas totais do arquivo, retornando com -1 para nao contar a primeira linha que nao possui um carro
int getlinhas()
{
    FILE *veiculos;
    int cont = 0;
    veiculos= fopen("veiculos.txt", "r");
    while (!feof(veiculos))
    {
        char letra;
        letra = fgetc(veiculos);
        if (letra == '\n')
        {
            cont = cont + 1;
        }
    }
    fclose(veiculos);
    return cont-1;
}
//metodo main
int main()
{
    int num = 0;
    try
    {
        int l = getlinhas();
        //while para repetir o programa ate que o usuario digite 6 (sair) ou ocorra uma execao
        while(num!=6)
        {
            cout<<"Escolha uma opcao:\n1-Listar\n2-Pesquisar\n3-Cadastrar\n4-Editar\n5-Excluir\n6-Sair\n";
            cin>>num;
            if(num == 1)
            {
                l = getlinhas();
                listarCarros(l);
            }
            else if(num == 2)
            {
                pesquisarCarros(l);
            }
            else if(num == 3)
            {
                cadastrarCarros(l);
                l = getlinhas();
            }
            else if(num == 4)
            {
                editarCarros(l);
            }
            else if(num == 5)
            {
                deletCarros(l);
                l = getlinhas();
            }
            else if(num == 6)
            {
                cout<<"Obrigado por utilizar o servico"<<endl;
                break;
            }
            else if(num == 0)
            {
                throw exception();
            }
            else
            {
                cout<<endl<<"Opcao invalida"<<endl<<endl;
            }


        }
    }
    catch (exception& e)
    {
        cout <<endl<< "excecao ocorreu: letra ou '0' digitados ao inves de um numero valido" << endl;
        return -1;
    }
    return 0;
}


