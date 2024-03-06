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
// funcao que troca as letras sorteadas, sendo a primeira a ser substituida e a segunda a que substitui
  static String Sorteio(String frase, char[] letra)
   {

	  int tam = frase.length();
	  char[] temp = new char[tam];
          for(int i = 0; i<tam; i++)
	  {
//caso a primeira letra seja igual a do array ela e substituida pela segunda letra
		  if(frase.charAt(i) == letra[0])
		  {
                    temp[i] = letra[1];

		  }
// senao apenas copia igual esta no array
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
//criando um gerador de numero aleatorio dentro do main para evitar de sempre ser as mesmas letras
	   Random gerador = new Random();
	   gerador.setSeed(4);
	   char[] letra = new char[2];
	   boolean status = true;
// while com condicao = true ate que chegue na condicao com o break
	   while(status)
	   {

	   String frase = MyIO.readLine();
	   letra[0] = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
	   letra[1] = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
	   if(frase.charAt(0) == 'F' && frase.charAt(1) == 'I' && frase.charAt(2) == 'M' && frase.length()==3)
	   {
		   break;
	   }
//chamando o sorteador e imprimindo o resultado
	   MyIO.println(Sorteio(frase, letra));
	   }
   }
}
