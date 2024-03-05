
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
    public static void println(String x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }
}
class Palindromo
{
    

    public static boolean ispalin(String s) 
    {    
	   int tam = s.length();
	   String s2 = new String();
         for(int i = 0; i<tam; i++)
	 { 
            char temp = s.charAt(tam-1-i);
            s2 = s2 + temp;
          }
	 for(int i = 0; i<tam; i++)
	 {
		 if (s.charAt(i) == s2.charAt(i))
				 {
				 }
		else
		    return false;
         }
	 return true;
    }
    public static void main (String[] args)
    {
      boolean status = true;
      while (status)
      {
	      String s = MyIO.readLine();
	      if(s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M' && s.length()== 3)
	      {
		      break;
	      }
         
              if(ispalin(s) == true)
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
