
   import java.io.*;
   import java.nio.charset.*;

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
/* funcao que recebe uma string como parametro e inicializa a recursividade
 */
  class CiframentoCesarRecursivo{
	static String Cifra(String cod)
	{
		 return Cifra(cod, 0);
	}
//funcao que recebe uma string e um inteiro como parametro e retorna uma string codificada pelo Ciframento de Cesar
 static String Cifra(String cod, int i)
   {
	   
	   int tam = cod.length();
	   char[] temp = new char[tam];
	   String resp= new String();
	   if(i>=tam)
	   
	   {
	          
		   return resp;
	   }
	   else 
	   {
//manipulacao de char utilizando o codigo ASCII, sendo +3 a chave, como definido pelo exercicio		   
		    temp[i] =(char)(cod.charAt(i)+3);
		    resp += temp[i];
	            return (String)(resp+ Cifra(cod, 1+i));
	   }
   }
   public static void main(String args[])
   {
	   boolean status = true;
//while com condicao = true ate que o if com break tenha sua condicao atendida
	   while(status)
           {
	           String s = MyIO.readLine();
                   if(s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M' && s.length() == 3)
                   {
                         break;	
                   } 
	           String newS = Cifra(s);
                   MyIO.println(newS);
	 
	 
	  }
   }
}
