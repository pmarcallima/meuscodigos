import java.util.*;

class FilaRecreio
{

	void sort()
	{
	}
	public static void main (String args[])
	{
		int n;
		n = MyIO.readInt();
	        for(int i =0; i<n; i++)
		{
			int m = MyIO.readInt();
			int[] array = new int[m];
			String temp = MyIO.readLine();
			String[] token = temp.split(" ", m);
			int[] arraytmp = new int[m];
			for(int j = 0; j<m; j++)
			{
				
 				arraytmp[j] = array[j] = Integer.parseInt(token[j]);
				
			}
	
			   int maior;
			   int alternador = 0;
			   int cont = 0;
                         for(int k = 0; k<m; k++)
			 {
				 maior = k;
				 for(int f = k+1; f<m; f++)
				 {
                                     if(array[maior] < array[f])
				     {
					     maior = f;
				     } 
				 }
				 int tmp = array[k];
				 array[k] = array[maior];
				 array[maior] = tmp;
			 }
			 for(int x =0; x<m; x++)
			 {
				 if(arraytmp[x] == array[x])
				 {
					 cont++;
				 }
			 }
                        MyIO.println(cont);			 
			
		}
	}
}
