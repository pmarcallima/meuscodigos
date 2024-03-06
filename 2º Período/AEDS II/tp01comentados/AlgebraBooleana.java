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
	/* funcao que troca as letras de acordo com a quantidade presente na expressao
	 primeiro atribuindo os valores inseridos na string a elas e depois, quando retornar 
	 a string trocada, seu for começa em n para poder apagar esses numeros do inicio da 
	 string */
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
	   //for comecando em n
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
	/*funcao que chama os metodos de resolucao booleana ate a string chegar a um 
	  tamanho 1, ou seja, ser 1 ou 0 */
	static String TrocarExpressao(String s)
	{
          while(s.length()> 1)

           {   
	
 	      s = not(s);
              s= and(s);
              s = or(s);    	
	   }

	  return s;
	}
	/* funcao que pega a string e remove os espacos presentes nela para facilitar 
	sua leitura */
	static String RemoverEspaco(String s)
	{
		char temp;
		int tam = s.length();
		String resp = new String();
		for(int i =0; i<tam; i++)
		{
			temp = s.charAt(i);
			//quando for espaco em branco pula esse ponto
			if(temp==' ')
			{
                           
			}
			else
				resp =resp+ temp;
		}
		return resp;
	}
/* funcao que resolve toda string que possuir and e valores entre parenteses em seguida
*/
        static String and(String s2)
	{
		char temp;
		String s3 = new String();
            	int tam = s2.length();
		for(int i = 0; i<tam; i++)
		{
		     temp = s2.charAt(i);
//compara caso seja um and que possui 3 valores dentro e pula o que deve ser removido na escrita e retorna o que deve ser escrito
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
/*compara caso seja um and com 2 valores dentro e pula a parte que deve ser removida da escrita e retorna o que deve ser escrito*/
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
	
		
		}
                return s3;

	}
	//funcao que resolve todos os casos em que se possui um or
	static String or(String s)
	{
		char temp;
		String s2 = new String();
		int tam = s.length();
		for(int i = 0; i<tam; i++)
		{
			temp = s.charAt(i);
// compara a situacao do or pula a parte que deve ser removida e retorna o que deve ser escrito no lugar
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
		}
	
		return s2;
	}

	
	static String not(String s)
	
        {
		int tam = s.length();
		char temp;
		String s2 = new String();
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
							i = i+5;												        }
					
					
			}
			else s2 = s2+temp;
		
	         }
	
		 return s2;
	}
//funcao booleana que retorna o resultado final da string, ou seja, quando seu tamanho for 1, se esta escrito 1 ou 0
	static boolean Resultado (String s, int n)
	{
//chama as expressoes necessaria
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
//while com condicao = true ate que chegue na condicao que possui um break
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
