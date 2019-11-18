// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Klasa
// 2018-03-29

// Klasa implementująca operację odejmowania
// podklasa klasy Węzeł
public class Odejmij extends Wezel
{
	
	// Konstruktor przypisujący odjemnej i odjemnikowi
	// podane wartości
	public Odejmij(Wyrazenie a, Wyrazenie b)
    {
        lewe = a;
        prawe = b;
    }
	
	// Nadpisanie metody oblicz() dla klasy Odejmij,
	// czyli implementacja odejmowania
    @Override
    public int oblicz() 
    {
        return lewe.oblicz()- prawe.oblicz();
    }
	
	// Nadpisanie metody wypisz() dla klasy Odejmij,
	// czyli implementacja zapisu odejmowania
    @Override
    public String wypisz()
    {
        return "(" + lewe.wypisz() + "-" + prawe.wypisz() + ")";
    }
}
