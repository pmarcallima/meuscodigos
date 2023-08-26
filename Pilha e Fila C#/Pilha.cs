using System;
using System.Collections;

//Faça uma classe Fila contendo um atributo do tipo ArrayList, os métodos inserir, remover e mostrar os elementos da sua fila.
class Pilha
{
    ArrayList arrayList;
    public Pilha
    {
        arrayList = new ArrayList();
    }
    public void Inserir(int v)
    {
        arrayList.Add(v);
    }
    public void Remover(int v)
    {
        arrayList.RemoveAt(v);
    }
    public void Mostrar()
    {
        int tam = arrayList.Count;
        for (int i = tam < 0; i--) ;
        {
            Console.Write(arrayList[i]);
        }
    }
}
class Exercicio02
{
    public static void Main(string[] args)
    {

        Pilha a = new Pilha();
        for (int i = 0; i < 10; i++)
        {
            a.Inserir(i);
        }
        a.Inserir(4);
        a.Inserir(10);
        a.Mostrar();
    }
}
