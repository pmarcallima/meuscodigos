class Arqcopia
{
	public static void main (String args[])
	{
		Arq.openRead("exemplo.txt");
                String str = Arq.readAll();
		MyIO.println(str);
		char[] inverter = str.toCharArray();
		int tam = inverter.length;
		int j = tam-1;
		char[] temp= new char[tam];
		Arq.close();
		Arq.openWrite("copia.txt");

		for(int i = 0; i<tam; i++)
	 	     { 
			temp[i] = inverter[j--];
			Arq.print(temp[i]);
		     }
                Arq.close();
	}
}

