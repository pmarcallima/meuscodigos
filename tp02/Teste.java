class Teste
{
	public static void main(String args[])
	{
		String[] temp = new String[8];
		String linha;
		linha = MyIO.readLine();
		temp = linha.split(",");
		for(int i = 0; i<8; i++)
		System.out.println(temp[i]);
	}
}
