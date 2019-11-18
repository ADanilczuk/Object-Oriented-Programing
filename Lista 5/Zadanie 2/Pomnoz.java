// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Klasa
// 2018-03-29

// Klasa implementująca operację mnożenia
// podklasa klasy Węzeł
public class Pomnoz extends Wezel
{
	// Konstruktor przypisujący czynnikom podane wartości
    public Pomnoz(Wyrazenie a, Wyrazenie b)
    {
        lewe = a;
        prawe = b;
    }
    
	// Nadpisanie metody oblicz() dla klasy Pomnóż,
	// czyli implementacja dodawania
    @Override
    public int oblicz() 
    {
        return lewe.oblicz() * prawe.oblicz();
    }
    
	// Nadpisanie metody wypisz() dla klasy Pomnóż,
	// czyli implementacja zapisu mnożenia
    @Override
    public String wypisz()()
    {
        return "(" + lewe.wypisz() + "*" + prawe.wypisz() + ")";
    }
}
