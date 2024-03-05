class PrincipalPilha
{
	public static void main (String args[])
	{
		int num,cont= 0, i=0;
		Arq.openRead("pilhas.dat");
		while(Arq.hasNext() == true)
		{
			Arq.readLine();
			cont++;
		}
		String[] temp= new String[cont];
		Arq.close();
	        num = MyIO.readInt();
		while(num !=4)
			Arq.openRead("pilhas.dat");
		{
			while (Arq.hasNext() == true)
		{
                 temp[i] =  Arq.readLine();
		 i++;
		}
		 int tam = temp.length;
		 MyIO.print("    1 Inserir  2 Remover  3 Listar  4 Sair");
                Arq.close();
		if( num == 1)
		{
			Arq.openWrite("pilhas.dat");
			MyIO.println("Digite a frase a ser inserida");
                   String str = MyIO.readLine();
		   temp[i]= str;
		   for(i = 0; i<tam+1; i++)
		   {
			   Arq.println(temp[i]);
		   }
		   Arq.close();
		   
		}
		else if( num == 2)
		{
			for(i = 0; i<tam; i++)
			{
				MyIO.println(temp[i]);
			}
			String o = MyIO.readLine();
			int a = MyIO.readInt();
			Arq.openWrite("pilhas.dat");
			for(i = 0; i<tam; i++)
			{
				if(temp[i].equals(a))
				{
					i++;
				}
				Arq.println(temp[i]);
			}
			Arq.close();
		}

		
		else if (num == 3)
		{
			for(int j = 0; j<tam; j++)
			{
				MyIO.println(temp[j]);
			}
		}
	}	
}
}


