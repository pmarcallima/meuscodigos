import java.util.Random;
class ArvoreBinaria
{
	No raiz;
   ArvoreBinaria()
   {
	   raiz = null;
   }
   void inserir(int x) throws Exception 
   {
        raiz = inserir(x, raiz);
   }
   No inserir(int x, No i) throws Exception
   {
	   if(i == null)
		 i = new No(x);
	   else if(x< i.elemento)
		   i.esq = inserir(x, i.esq);
	   else if(x>i.elemento)
		   i.dir = inserir(x, i.dir);
	   else
		   throw new Exception("Erro!");
        return i;
	   
   }
   void inserirPai(int x) throws Exception
   {
	   if(raiz == null)
		  raiz = new No(x);
	   else if(x< raiz.elemento)
		   inserirPai(x, raiz.esq, raiz);
	   else if(x>raiz.elemento)
		   inserirPai(x, raiz.dir, raiz);
	   else 
		   throw new Exception("Erro!");
	
   }
   void inserirPai(int x, No i, No pai) throws Exception
   {
	   if(i == null)
		   if(x<pai.elemento)
			   pai.esq = new No(x);
	           else
			   pai.dir = new No(x);
	   else if( x<i.elemento)
		   inserirPai(x, i.esq, i);
	   else if(x> i.elemento)
		   inserirPai(x, i.dir, i);
	   else
		   throw new Exception("Erro!");


   }
   boolean pesquisa(int x)
   {
	   return pesquisa(x, raiz);
   }
   boolean pesquisa(int x, No i)
   {
	   boolean resp;
           if(i == null)
	           resp = false;
	   else if(i.elemento == x)
		   resp = true;
	   else if(x<i.elemento)
	           resp = pesquisa(x, i.esq);
	   else 
		   resp = pesquisa(x, i.dir);
           return resp;
   }
   void caminhar()
   {
	   caminharCentral(raiz);
   }
   void caminharCentral(No i)
   {
       if(i != null)
       {
	       caminharCentral(i.esq);
	       System.out.println(i.elemento);
	       caminharCentral(i.dir);
       }
   }
   void caminharPre(No i)
   {
	   if(i != null)
	   {
		   System.out.println(i.elemento);
		   caminharPre(i.esq);
		   caminharPre(i.dir);
	   }
   }
   void caminharPos(No i)
   {
	   if(i!= null)
	   {
		   caminharPos(i.esq);
		   caminharPos(i.dir);
		   System.out.println(i.elemento);
           } 
   }
   int getAltura()
   {
	  return getAltura(raiz, 0);
   }
   int getAltura(No i, int altura)
   {
	   if(i ==null)
		 altura--;
	   else
	   {
		 int alturaEsq=  getAltura(i.esq, altura+1);
	        int alturaDir = getAltura(i.dir, altura+1);
		altura = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
           }
	   return altura;
   }
   int getSoma()
   {
	   return getSoma(raiz);
   }
   int getSoma(No i)
    {
	    int soma = 0;
	    if(i!=null)
	    {
		    soma = i.elemento + getSoma(i.esq) + getSoma(i.dir);
	    }
	    return soma;
    }
   int getPar()
   {
	   return getPar(raiz);
   }
   int getPar(No i)
   {
	   int par = 0;
	   if(i != null)
	   {
		   if(i.elemento % 2 == 0)
			   par++;
		   par = par + getPar(i.esq) + getPar(i.dir);
	   }
	   return par;
   }
   static boolean ehIgual(ArvoreBinaria a, ArvoreBinaria b)
   {
            return ehIgual(a.raiz, b.raiz);

   }
   static boolean ehIgual(No i, No j)
   {
	   boolean resp = true;
	   if(i!= null && j != null)
	   {
	    resp = (i.elemento == j.elemento) && ehIgual(i.dir, j.dir) && ehIgual(i.esq, j.esq);
	   }
	   else if(i == null && j == null)
	   {
		   resp =  true;
	   }
	   else
		   resp = false;
	   return resp;

   }
   boolean div11()
   {
	   return div11(raiz);
   }
   boolean div11(No i)
   {
	  boolean resp = false;
          if(i!=null)
	  {
		 resp = (i.elemento % 11 == 0) ? true : false || div11(i.esq) || div11(i.dir);
	  }
	  return resp;

   }
   int getMaior()
   { 

	  int resp = -1;
   if(raiz != null)
   {
   No i = raiz;
   while(i.dir != null)
   {
	   i = i.dir;
   }
   resp = i.elemento;
   }
   return resp;
   
   }
   int getMenor()
   {
	   int resp = -1;
	   if(raiz != null)
	   {
		   No i;
		   for(i = raiz; i.esq!= null; i = i.esq);
		   resp = i.elemento;
	   }
	   return resp;
   }
   No toAB(Celula i, CelulaDupla j) throws Exception
   {
	   No resp = null;
	   i = i.prox;
	   j = j.prox;
	   while(i != null && j!=null)
	   {
               resp = inserir(i.elemento, resp);
	       resp = inserir(j.elemento, resp);
	       i = i.prox;
	       j = j.prox;
	   }
	   while(i != null)
	   {
		   resp = inserir(i.elemento, resp);
		   i = i.prox;
	   }
	   while(j !=null )
	   {
		   resp = inserir(j.elemento,resp);
		   j = j.prox;
	   }
	   return resp;

   }
   int remover(int x)
   {
        return remover(raiz, x);
   }
   int remover(No i, x)
   {

   }
   public static void main(String args[]) throws Exception
   {
	   ArvoreBinaria b = new ArvoreBinaria();
	   ArvoreBinaria a = new ArvoreBinaria();
	   Random rand = new Random(5);
	   for(int i =0; i<100000; i++)
	   {
		   int x = rand.nextInt(Integer.MAX_VALUE);
		   if(!b.pesquisa(x))
				   {
		  b.inserir(x);
				   }
	           System.out.println("Total:"+i+" Log:"+(int)(Math.log(x)/Math.log(2))+" Altura:"+b.getAltura());
		  
	   }
	   b.caminhar();
	   System.out.println(b.getPar());
	 //  b.caminhar();
	 //  b.caminharPre(b.raiz);
	 //  b.caminharPos(b.raiz);
	  if(a.div11())
		  System.out.println("ACHEI");
   }
}
