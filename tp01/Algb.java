import java.io.*;
import java.nio.charset.*;

class MyIO {

   private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
   private static String charset = "ISO-8859-1";

   public static void setCharset(String charset_){
      charset = charset_;
      in = new BufferedReader(new InputStreamReader(System.in, Charset.forName(charset)));
   }
public static String readLine(){
      String s = "";
      char tmp;
      try{
         do{
            tmp = (char)in.read();
            if(tmp != '\n' && tmp != 13){
               s += tmp;
            }
         }while(tmp != '\n');
      }catch(IOException ioe){
         System.out.println("lerPalavra: " + ioe.getMessage());
      }

      return s;
}
 public static int readInt(){
      int i = -1;
      try{
         i = Integer.parseInt(readString().trim());
      }catch(Exception e){}
      return i;
   }
public static String readString(){
      String s = "";
      char tmp;
      try{
         do{
            tmp = (char)in.read();
            if(tmp != '\n' && tmp != ' ' && tmp != 13){
               s += tmp;
            }
         }while(tmp != '\n' && tmp != ' ');
      }catch(IOException ioe){
         System.out.println("lerPalavra: " + ioe.getMessage());
      }
      return s;
   }
 public static void println(int x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }
}
class AlgebraBooleana
{
	static String TrocarLetra(String s, int n)
	{
           int tam = s.length();
	   String s2= new String();	   
           char A, B, C= 0;
	   A = s.charAt(0);
	   B = s.charAt(1);
	   if(n==3)
	   {
		   C = s.charAt(2);
		   
	   }
	   for(int i = n; i<tam; i++)
	   {
		   char temp = s.charAt(i);
		   if(temp == 'A')
				   {
                                    s2 = s2+ A;
		       		   }
		   else if(temp == 'B')
				   {
					   s2 = s2+ B;
				   }
		   else if(temp == 'C')
			   {
				   s2 = s2+C;
			   }
		   else
			   s2 = s2 +temp;
		
 	   }
	 	   return s2;
	   
	}
		
            static String TrocarExpressao(String s)
	{
		int tam = s.length();
		String s2 = new String();
		int i = 3;
                while(i >1)

{   		int tam = s.length();
		char temp;
			for(int i = 0; i<tam; i++)
	 {
			 temp = s.charAt(i);
			if(temp == 'n' && s.charAt(i+1)=='o' && s.charAt(i+2) == 't' && s.charAt(i+3)=='(' && (s.charAt(i+4)=='1' || s.charAt(i+4) == '0') && s.charAt(i+5) == ')' )
			{
				if(s.charAt(i+4)=='1')
						{
							s2 = s2 + '0';
							i = i+5;
												}
						else if( s.charAt(i+4) == '0')
						{
							s2 = s2 + '1';
							i = i+5;
												}
					
					
			}
		       else if(temp == 'o' && s.charAt(i+1) == 'r' && s.charAt(i+2) == '(' && (s.charAt(i+3) == '1' || s.charAt(i+3)=='0') && s.charAt(i+6) == ',')
					{
						if(s.charAt(i+3) == '1' || s.charAt(i+5) == '1')
						{
							s2 = s2+ "or(1";
							i = i+5;
						}
						else
						{
							s2 = s2+ "or(0";
							i = i+5;
                                                }
					}

		       else if(temp == 'o' && s.charAt(i+1) == 'r' && s.charAt(i+2) == '(' && (s.charAt(i+3) == '1' || s.charAt(i+3)=='0'))
					{
						if(s.charAt(i+3) == '1' || s.charAt(i+5) == '1')
						{
							s2 = s2+ '1';
							i = i+6;
						}
						else
						{
							s2 = s2+ '0';
							i = i+6;
                                                }
					}
			else if(temp == 'a' && s1.charAt(i+1)=='n' && s1.charAt(i+2) == 'd' && s1.charAt(i+3)=='(' && (s1.charAt(i+4)=='1' || s1.charAt(i+4) == '0') && s1.charAt(i+7) == ',')
			{
				   if(s1.charAt(i+4)=='1' && s1.charAt(i+6) == '1')
				{
				
					s1= s1+ "and(1";
					i = i + 6;
								}
			           else 
				{
					s1= s1+"and(0";
					i = i + 6;
								}
			}
				else if(temp == 'a' && s1.charAt(i+1)=='n' && s1.charAt(i+2) == 'd' && s1.charAt(i+3)=='(' && (s1.charAt(i+4)=='1' || s1.charAt(i+4) == '0'))
			{
				   if(s.charAt(i+4)=='1' && s.charAt(i+6) == '1')
				{
				
					s2= s2+ "1";
					i = i + 7;
								}
			           else 
				{
					s2= s2+"0";
					i = i + 7;
								}

			}
			else s2 = s2+temp;
		
		}
  
	}

	 return s2;
	}

		
	static boolean Resultado (String s, int n)
	{
	   
	   
	   s = RemoverEspaco(s);
	   s = TrocarLetra(s, n);
	    s = TrocarExpressao(s);
	   if(s.charAt(0) == '0')
	   return false;
	   else
		   return true;
	}
	public static void main(String args[])
	{
		boolean status = true;
		while(status)
		{
                  int n = MyIO.readInt();
	          if(n == 0)
		  {
			  break;
		  }
			 
		  String s = MyIO.readLine();
                  if(Resultado(s,n) == false)
		  {
			  MyIO.println(0);
		  }
		  else
		  {
				  MyIO.println(1);
		  }
		 }
		 
	}
}
