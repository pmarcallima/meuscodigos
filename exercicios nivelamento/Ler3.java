class Ler3
{
	public static void main (String args[])
	{
		
	 int maior = 	MyIO.readInt();
	 int menor = maior;
	     for(int i = 0; i<2; i++)
	     {
		    int temp = MyIO.readInt();
		    if( temp > maior)
			   {
				   maior = temp;
			   }
		    if(temp <menor)
		    {
			    menor = temp;
		    }
	     }
	     MyIO.println(menor);
	     MyIO.println(maior);
	}
}
