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
class AlteracaoAleatoria
{

  static String Sorteio(String frase, char[] letra)
   {
	 
	  int tam = frase.length();	 
	  char[] temp = new char[tam];	
          for(int i = 0; i<tam; i++)
	  {
		  if(frase.charAt(i) == letra[0])
		  {
                    temp[i] = letra[1];
		 
		  }
		  else
		  {
			    temp[i]= frase.charAt(i);
		  }
	  }
	  String resp = new String(temp);
	  return resp;
   }
   public static void main (String args[])
   {
	   Random gerador = new Random();
	   gerador.setSeed(4);
	   char[] letra = new char[2];
	   boolean status = true;
	   while(status)
	   {
	      
	   String frase = MyIO.readLine();
	   letra[0] = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
	   letra[1] = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
	   if(frase.charAt(0) == 'F' && frase.charAt(1) == 'I' && frase.charAt(2) == 'M' && frase.length()==3)
	   {
		   break;
	   }
	   MyIO.println(Sorteio(frase, letra));
	   }
   }
}
