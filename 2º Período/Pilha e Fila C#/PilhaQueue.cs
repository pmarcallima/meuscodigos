using System;
using System.Collections;
using System.Security.Cryptography;

class Pilha
{
    Queue p1, p2;
    public Pilha()
    {
        p1 = new Queue();
        p2 = new Queue();
    }
    public void Inserir(int v)
    {
        p1.Enqueue(v);
    }

    public int Remover()
    {
        while (p1.Count > 1)
        {
            p2.Enqueue(p1.Dequeue());
        }
        int resp = (int)p1.Dequeue();
        while (p2.Count > 0)
        {
            p1.Enqueue(p2.Dequeue());
        }
        return resp;
    }


    public void Mostrar()
    {
        object[] array = p1.ToArray();
        for (int i = (p1.Count) - 1; i >= 0; i--)
        {
            Console.WriteLine(array[i]);
        }
    }



}
class Exercicio03
{
    public static void Main(string[] args)
    {
        Pilha a = new Pilha();

        for (int i = 0; i < 10; i++)
        {
            a.Inserir(i);
        }
        Console.WriteLine(a.Remover());
        a.Inserir(10);
        Console.WriteLine(a.Remover());
        a.Inserir(11);
        Console.WriteLine(a.Remover());
        a.Inserir(12);

        a.Mostrar();
    }
}
