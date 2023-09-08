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
  class CiframentoCesar{

   static String Cifra(String cod)
   {
	   int tam = cod.length();
	   char[] temp= new char[tam];
	   for(int i = 0; i<tam; i++)
	   {

		   char res = (char)(cod.charAt(i)+3);
		   temp[i] = res;
	   }
	   cod = new String(temp);
	return cod;

   }
   public static void main(String args[])
   {
	 boolean status = true;
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
