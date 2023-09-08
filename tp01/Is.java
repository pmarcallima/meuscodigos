import java.io.*;
import java.nio.charset.*;
import java.util.Random;

class MyIO {

   private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
   private static String charset = "ISO-8859-1";

   public static void setCharset(String charset_){
      charset = charset_;
      in = new BufferedReader(new InputStreamReader(System.in, Charset.forName(charset)));
   }
   public static void println(String x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }
   public static void print(String x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.print(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
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
}
class Is
{
	static boolean vogais(String frase) 
	{
          int tam = frase.length();
	  for(int i = 0; i < tam ; i++)
	  {
		 char temp = frase.charAt(i);
		 if(temp !='a' && temp != 'A' && temp != 'e' && temp != 'E' && temp != 'i' && temp != 'I' && temp != 'o' && temp != 'O' && temp != 'u' && temp != 'U')
		 {
			 return false;
		 } 
	  }
          return true;

	}
	static boolean consoantes(String frase)
	{
		int tam = frase.length();
		for(int i = 0; i<tam; i++)
		{
			char temp = frase.charAt(i);
				if(temp == 'a'|| temp == 'A' || temp == 'E' || temp == 'e'|| temp == 'i'|| temp == 'I'|| temp == 'o'|| temp == 'O'|| temp == 'U'|| temp == 'u'|| temp == '0'|| temp == '1'|| temp == '2'|| temp == '3'|| temp == '4'|| temp == '5'|| temp == '6'|| temp == '7'|| temp == '8'|| temp == '9'|| temp == '.'|| temp == ',')
				{
					return false;
				}
		}
              return true;
	}
       static boolean numInt(String frase)
       {
	       int cont = 0;
	     	       int contsinal = 0;
	       int tam = frase.length();
	       for(int i = 0; i<tam; i++)
	       {
                       char temp = frase.charAt(i);
		       if(temp == '0' || temp == '1'|| temp == '2'|| temp == '3'|| temp == '4'|| temp == '5'|| temp =='6'|| temp == '7'|| temp == '8'|| temp == '9')
			     {
				   cont++;

			     }
                   
	       }
	       if(cont == tam)
		     {
			     return true;
		     }
	       else
		       return false;
       }

       static boolean numReal(String frase)
       {
	       int cont = 0;
	       int contsinal = 0;
	       int tam = frase.length();
	       for(int i = 0; i<tam; i++)
	       {
                       char temp = frase.charAt(i);
		       if(temp == '0' || temp == '1'|| temp == '2'|| temp == '3'|| temp == '4'|| temp == '5'|| temp =='6'|| temp == '7'|| temp == '8'|| temp == '9')
			     {
				   cont++;

			     }
		       else if( temp == '.' || temp == ',')
		       {
			       contsinal++;
			       cont++;
		       }
		                          
	       }
	       if(cont == tam && contsinal <=1)
		     {
			     return true;
		     }
	       else
		       return false;
       }



	public static void main (String args[])
	{
		boolean status = true;
		while(status)
		{
		String s =MyIO.readLine();
		if( s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M' && s.length() == 3)
		{
			break;
		}	
		boolean[] resp = new boolean[4];
		resp[0] = vogais(s);
		resp[1] = consoantes(s);
		resp[2] = numInt(s);
		resp[3] = numReal(s);
		for(int i =0; i<3; i++)
		{
		if(resp[i] == true)
		{
			MyIO.print("SIM ");
		}
		else
			MyIO.print("NAO ");
		}
                 if(resp[3] == true)
		 {
			 MyIO.println("SIM");

		}
		else
		{
			MyIO.println("NAO");
	}
  }
}
}
