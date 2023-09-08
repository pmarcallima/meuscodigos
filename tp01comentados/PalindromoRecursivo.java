

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
class PalindromoRecursivo
{
//funcao que inicializa a recursividade   
    static boolean ispalin(String s)
    {
	    return ispalin(s, 0);
    }
//funcao que recebe como parametro uma string e um inteiro e retorna um booleano true caso a string seja um palindromo
    public static boolean ispalin(String s, int i) 
    {    
	 int tam = s.length()-1;
//condicao de parada	 
		 if(i==tam)
	 {
		 return true;
	 }	 
         if( s.charAt(i) == s.charAt(tam-i))
	 {
		return true && ispalin(s, i+1);
	 }
	 else 
		 return false; 
          }
    public static void main (String[] args)
    {
      boolean status = true;
// while com condicao = true ate que o if com um break tenha sua condicao atendida
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
