class Ler10
{
	public static void main (String args[])
	{
		int maior = MyIO.readInt();
			for(int i = 1; i<10; i++)
		{
			int temp = MyIO.readInt();
			if(temp > maior)
			{
				maior = temp;
			}
		}
		MyIO.println(maior);
	}
}

