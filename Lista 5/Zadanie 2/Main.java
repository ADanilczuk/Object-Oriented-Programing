// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Program g³ówny
// 2018-03-29



public class Main 
{
    public static void main(String[] args) 
    {

	   try
	   {
		   Wyrazenie wyr = new Pomnoz(new Stala(2), new Stala(5));
		    Wyrazenie.pamiec.put("q", 4);
		    Wyrazenie wyr2 = new Odejmij(new Zmienna("q"), wyr);
		    
	        System.out.println(wyr.toString());
	        System.out.println(wyr.oblicz());
	        
	        System.out.println(wyr2.toString());
	        System.out.println(wyr2.oblicz());
	        
	        
	        Wyrazenie wyr3 = new Dodaj(new Stala(2), new Stala(5));
	        System.out.println(wyr3.toString());
	        System.out.println(wyr3.oblicz());
	        
	        
	        Wyrazenie wyr4 = new Podziel(new Stala(2), new Stala(5));
	        System.out.println(wyr4.toString());
	        System.out.println(wyr4.oblicz());
	        
	        Wyrazenie wyr5 = new Podziel(new Stala(6), new Stala(2));
	        System.out.println(wyr5.toString());
	        System.out.println(wyr5.oblicz());
	        
	        
	        Wyrazenie wyr6 = new Podziel(new Stala(6), new Stala(0));
	        System.out.println(wyr6.toString());
	        System.out.println(wyr6.oblicz());
	   }
	   catch (IllegalArgumentException err)
	   {
		   System.out.println("Nie mo¿na dzieliæ przez 0!");
	   }
    }

}
