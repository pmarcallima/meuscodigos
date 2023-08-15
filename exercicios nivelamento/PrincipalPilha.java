class PrincipalPilha
{
	public static void main (String args[])
	{
		int num, i=0;
		String[] temp= new String[20];
	        num = MyIO.readInt();
		Arq.openRead("pilhas.dat");
			while (Arq.hasNext() == true)
		{
                 temp[i] =  Arq.readLine();
		 i++;
		}

		if( num == 1)
		{
			MyIO.println("Digite a frase a ser inserida");
                   String str = MyIO.readLine();
		   temp[i]= str;
		}
		else if( num == 2)
		{
			int a = MyIO.readInt();
			temp[a] = "";

		}
		else if (num == 3)
		{
			int tam = temp.length;
			for(int j = 0; j<tam; j++)
			{
				MyIO.println(temp[j]);
			}
		}	
}
}


