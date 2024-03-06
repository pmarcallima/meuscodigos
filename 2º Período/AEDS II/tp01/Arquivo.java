
import java.io.*;
import java.nio.charset.*;
import java.util.Formatter;
import java.util.Scanner;
import java.io.File;
import java.io.RandomAccessFile;

class MyIO {

   private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
   private static String charset = "ISO-8859-1";

   public static void setCharset(String charset_){
      charset = charset_;
      in = new BufferedReader(new InputStreamReader(System.in, Charset.forName(charset)));
   }

  public static void println(float x){
      try {
         PrintStream out = new PrintStream(System.out, true, charset);
         out.println(x);
      }catch(UnsupportedEncodingException e){ System.out.println("Erro: charset invalido"); }
   }
 public static double readDouble(){
      double d = -1;
      try{
         d = Double.parseDouble(readString().trim().replace(",","."));
      }catch(Exception e){}
      return d;
   }
 public static float readFloat(){
      return (float) readDouble();
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
}
class Arq
{
   private static String nomeArquivo = "";
   private static String charsetArquivo = "ISO-8859-1";
   private static boolean write = false, read = false;
   private static Formatter saida = null;
   private static Scanner entrada = null;

	public static boolean openWrite(String nomeArq, String charset) {
      boolean resp = false;
      close();
		try{
		   saida = new Formatter(nomeArq, charset);
         nomeArquivo = nomeArq;
         resp = write = true;
		}  catch (Exception e) {}
      return resp;
   }

	public static boolean openWrite(String nomeArq) {

      return openWrite(nomeArq, charsetArquivo);
   }
        public static void close() {
      if(write == true){
         saida.close();
      }
      if(read == true){
         entrada.close();
      }
      write = read = false;
      nomeArquivo = "";
      charsetArquivo = "ISO-8859-1";
      }
      public static void print(float x){
      if(write == true){
	   	saida.format( "%f", x);
      }
      }
      public static void println(float x){
      if(write == true){
		   saida.format( "%f\n", x);
      }
   }
   
   public static String readString(){
      String resp = "";
		try{
         resp = entrada.next();
		}  catch (Exception e) { System.out.println(e.getMessage()); }
      return resp;
	}
}

class Arquivo
{
	public static void main (String args[]) throws Exception
	{
			
	   int n = MyIO.readInt();
	   RandomAccessFile raf = new RandomAccessFile("a.txt", "rw");
	   for(int i = 0; i<n; i++)
	   {
           float real = MyIO.readFloat();
	 
	   raf.writeFloat(real);
	   }
	   raf.close();
	   raf = new RandomAccessFile("a.txt", "r");
                    	long tam = raf.length()-4;
			raf.seek(tam);
		
		while(raf.getFilePointer()>0)
	       {	
		      int i; 
		       float temp = raf.readFloat();
		      i = (int)temp;

		      float temp2 = temp - i;
		     if(temp2 > 0)
		     {
			     System.out.println(i);
		     } 
		    else
		                System.out.println(temp);
				    
		     
	             tam = tam - 4;
     
                     raf.seek(tam);
	       }
                
		
		
		if(raf.getFilePointer()==0)
		{
		  MyIO.println(raf.readFloat());
		}
		

		   
		   raf.close();
		  
	   

	}
}
