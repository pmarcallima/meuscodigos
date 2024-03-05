using System;
using System.Collections;

//Faça uma classe Fila contendo um atributo do tipo ArrayList, os métodos inserir, remover e mostrar os elementos da sua fila.
class Fila
{
    ArrayList arrayList;
    public Fila()
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
        for (int i = 0; i < tam; i++)
        {
            Console.Write(arrayList[i]);
        }
    }
}
class ExercicioComplementarU02S01EC01
{
    public static void Main(string[] args)
    {
        Fila a = new Fila();
        a.Inserir(4);
        a.Inserir(10);
        a.Mostrar();
    }
}
