// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Program g³ówny
// 2018-03-29


public class Main 
{
    public static void main(String[] args) 
    {
		   
		   // Program licz¹cy silniê 
		   
		    Stala jedynka = new Stala (1);
		    
		    // Stworzenie nowej zmiennej 
	        Zmienna wynik = new Zmienna ("wynik");
	        Wyrazenie.pamiec.put("wynik", 1);
	        
	        // Stworzenie nowej zmiennej 
	        Zmienna it = new Zmienna("it");
	        Wyrazenie.pamiec.put("it", 5);

	        
	        Pomnoz mnozenie = new  Pomnoz(wynik, it );
	        Odejmij odejmowanie = new Odejmij(it, jedynka);
	        
	        // W ka¿dej pêtli bêdziemy przypisywaæ iteratorowi it wartoœæ it-1
	        Wyrazenie warunekPetli = new Przypisanie(it, odejmowanie);
	        
	        // W ka¿dej pêtli bêdziemy przypisywaæ wynikowi
	        // kolejne mno¿enia go ze zmniejszaj¹cym siê iteratorem
	        Wyrazenie cialoPetli = new Przypisanie(wynik, mnozenie );

	        System.out.print("warunek petli" + warunekPetli.wypisz()+"!=0 \n");
	        System.out.print("cialo petli" + cialoPetli.wypisz() + "\n");

	        System.out.print(" \n");
	        // Pêtla wykonuje siê dopóki warunek jest ró¿ny od 0
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
	 		   System.out.println("Nie mo¿na dzieliæ przez 0!");
	 	   }
	        
	       
    }
}
