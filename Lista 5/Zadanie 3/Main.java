// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Program g��wny
// 2018-03-29


public class Main 
{
    public static void main(String[] args) 
    {
		   
		   // Program licz�cy silni� 
		   
		    Stala jedynka = new Stala (1);
		    
		    // Stworzenie nowej zmiennej 
	        Zmienna wynik = new Zmienna ("wynik");
	        Wyrazenie.pamiec.put("wynik", 1);
	        
	        // Stworzenie nowej zmiennej 
	        Zmienna it = new Zmienna("it");
	        Wyrazenie.pamiec.put("it", 5);

	        
	        Pomnoz mnozenie = new  Pomnoz(wynik, it );
	        Odejmij odejmowanie = new Odejmij(it, jedynka);
	        
	        // W ka�dej p�tli b�dziemy przypisywa� iteratorowi it warto�� it-1
	        Wyrazenie warunekPetli = new Przypisanie(it, odejmowanie);
	        
	        // W ka�dej p�tli b�dziemy przypisywa� wynikowi
	        // kolejne mno�enia go ze zmniejszaj�cym si� iteratorem
	        Wyrazenie cialoPetli = new Przypisanie(wynik, mnozenie );

	        System.out.print("warunek petli" + warunekPetli.wypisz()+"!=0 \n");
	        System.out.print("cialo petli" + cialoPetli.wypisz() + "\n");

	        System.out.print(" \n");
	        // P�tla wykonuje si� dop�ki warunek jest r�ny od 0
	        Petla silnia = new Petla(warunekPetli,cialoPetli);
	        Komunikat wypiszSilnie = new Komunikat(silnia);

	        try 
	        {
	            int cos = wypiszSilnie.oblicz();
	            System.out.print(" \n");
	            System.out.println(silnia.oblicz());

	        }
	        catch (IllegalArgumentException err)
	 	   {
	 		   System.out.println("Nie mo�na dzieli� przez 0!");
	 	   }
	        
	       
    }
}
