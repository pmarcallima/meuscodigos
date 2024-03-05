class Prova
{
	static int[] vetorOrdenado(int[] vetA, int[] vetB)
	{
		int index = 0;
		int ordenado[] = new int[vetA.length + vetB.length];
		int i = vetA.length-1;
		int j = vetB.length-1;
		while(i>=0 && j >= 0)
		{
                     if(vetA[i] < vetB[j])
		     {
			     ordenado[index] = vetA[i];
			     index++;
			     i--;
		     }
		     else if(vetB[j] < vetA[i])
		     {
			     ordenado[index] = vetB[j];
			     index++;
			     j--;
		     }
		     else
		     {
			     ordenado[index] = vetA[i];
			     index++;
			     i--;
		     }
		}
		while(i >= 0)
		{
			ordenado[index] = vetA[i];
			index++;
			i--;
		}
		while(j >= 0)
		{
			ordenado[index] = vetB[j];
			j--;
			index++;
		}
		return ordenado;
	}
	public static void main(String args[])
	{
		int a[] = new int[7];
		a[0] = 15;
		a[1] = 10;
		a[2] = 8;
		a[3] = 5;
		a[4] = 3;
		a[5] = 2;
		a[6] = 1;
		int b[] = new int[6];
		b[0] = 22;
		b[1] = 21;
		b[2] = 14;
		b[3] = 12;
		b[4] = 8;
		b[5] = 5;
		int[] ordenado = vetorOrdenado(a, b);
		for(int i = 0; i<13; i++)
			System.out.println(ordenado[i]);
	}
}
