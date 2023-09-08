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
class AlgebraBooleanaRecursiva
{
	static String TrocarLetra(String s, int n)
	{
		return TrocarLetra (s, n, 0);
	}
	static String TrocarLetra(String s, int n, int i)
	{
           int tam = s.length();
	   String s2 = new String();
	   if(i== tam)
	   {

		   return s2;
	   }
	     
           char A, B, C= 0;
           	    
	   A = s.charAt(0);
	   B = s.charAt(1);
	   if(i < n)
	   {
		   i = n;
	   }
	   if(n==3)
	   {
		   C = s.charAt(2);
	   }
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
		
 	    return s2+TrocarLetra(s, n, i+1);
	   
	}
      static String TrocarExpressao(String s)
      {
	      return TrocarExpressao(s, s.length());
      }
      static String TrocarExpressao(String s, int i)
	{
		int tam = s.length();
          if(tam ==1)
	  {
		 return s;
	  }

          
	
	s = not(s);

        s= and(s);


        s = or(s);


	 return   TrocarExpressao(s, i-1);
	}
        static String RemoverEspaco(String s)
        {
		return RemoverEspaco(s, 0);
        }
	static String RemoverEspaco(String s, int i)
	{
		char temp;
		int tam = s.length();
		String resp = new String();
		if(i == tam)
		{
			return resp;
		}
	
				temp = s.charAt(i);
			if(temp==' ')
			{
                           
			}
			else
				resp =resp+ temp;
	       
		return resp +RemoverEspaco(s, i+1);
	}
	static String and(String s2)
	{
		return and(s2, 0);
	}
	static String and(String s2, int i)
	{
		char temp;
		String s3 = new String();
            	int tam = s2.length();
		if(i == tam)
		{
			return s3;
		}
				temp = s2.charAt(i);
				 if(temp == 'a' && s2.charAt(i+1)=='n' && s2.charAt(i+2) == 'd' && s2.charAt(i+3)=='(' && (s2.charAt(i+4)=='1' || s2.charAt(i+4) == '0') && s2.charAt(i+7) == ',')
			{
				   if(s2.charAt(i+4)=='1' && s2.charAt(i+6) == '1')
				{
				
					s3= s3+ "and(1";
					i = i + 6;
								}
			           else 
				{
					s3= s3+"and(0";
					i = i + 6;
								}
			}
				else if(temp == 'a' && s2.charAt(i+1)=='n' && s2.charAt(i+2) == 'd' && s2.charAt(i+3)=='(' && (s2.charAt(i+4)=='1' || s2.charAt(i+4) == '0') && (s2.charAt(i+6)== '1'|| s2.charAt(i+6) == '0'))
						{
				   if(s2.charAt(i+4)=='1' && s2.charAt(i+6) == '1')
				{
				
					s3= s3+ "1";
					i = i + 7;
								}
			           else 
				{
					s3= s3+"0";
					i = i + 7;
								}

			}		
			else 
			{
				s3 = s3+temp;
			}
	
		
		
                return s3+ and(s2, i+1);

	}
	static String or(String s)
	{
		return or(s, 0);
	}
	static String or(String s, int i)
	{
		char temp;
		String s2 = new String();
		int tam = s.length();
		if(i == tam)
		{
			return s2;
		}
			temp = s.charAt(i);
			if(temp == 'o' && s.charAt(i+1) == 'r' && s.charAt(i+2) == '(' && (s.charAt(i+3) == '1' || s.charAt(i+3)=='0') && s.charAt(i+6) == ',')
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
			else
			  s2 = s2+temp;
		
	
		return s2 + or(s, i+1);
	}

	static String not(String s)
	{
		return not(s, 0);
	}
	static String not(String s, int i)
	
             	{
		int tam = s.length();
		String s2 = new String();
		if(i  > tam)
		{
			i = 0;
		}
		if(i == tam)
		{
			return s2;
		}
		char temp;

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
			else s2 = s2+temp;
		
		
	
		return s2 + not(s, i+1);
	}
	static boolean Resultado (String s, int n)
	{
	   
	   
	   s = RemoverEspaco(s);
	   s = TrocarLetra(s, n);
	    s = TrocarExpressao(s);
	    System.out.println(s);
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
