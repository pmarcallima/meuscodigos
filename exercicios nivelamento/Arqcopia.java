class Arqcopia
{
	public static void main (String args[])
	{
		Arq.openRead("exemplo.txt");
                String str = Arq.readAll();
		MyIO.println(str);
		Arq.close();
		Arq.openWrite("copia.txt");
		Arq.print(str);

	}
}

