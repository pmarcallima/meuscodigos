
import java.util.Scanner;

 class palindromo
{
    
     
    public static boolean ispalin(String op) 
    {
        int j = 0;       
       int tam = op.length();
       char[] a = op.toCharArray();
       char[] b = new char[tam];
       
       for(int i = tam-1; i>=0; i--)
       {
         
          b[j] = a[i];
          j++;
       }
       String res = String.valueOf(b);
       if(res.compareTo(op)== 0)
     {
      return true;
     }
     else
     {
      return false;
     }   
          }
    public static void main (String[] args)
    {
       String op;
       Scanner scanner = new Scanner (System.in);
      op = scanner.nextLine();
      while (!op.equals("FIM"))
      {
         
              if(ispalin(op) == true)
            {
               System.out.println("SIM");
         }
         else
         {
            System.out.println("NAO"); 
         }
         op = scanner.nextLine();
       }  
         scanner.close();
   }
}