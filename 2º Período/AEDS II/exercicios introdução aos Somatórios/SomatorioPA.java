class SomatorioPA
{
  public static int somatorio(int a, int b, int n)
  {
	  int p = (a+(a+(n*b)))*(n+1)/2;
	  return p;
  }
	public static void main (String args[])
	{
             int a = MyIO.readInt();
	     int b = MyIO.readInt();
	     int n = MyIO.readInt();
	     int res = somatorio(a, b , n);
	     MyIO.println(res);
	}
}

