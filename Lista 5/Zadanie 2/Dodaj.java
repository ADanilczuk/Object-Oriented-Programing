// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Klasa
// 2018-03-29

// Klasa implementująca operację dodawania
// podklasa klasy Węzeł
public class Dodaj extends Wezel
{
	// Konstruktor przypisujący składnikom podane wartości
    public Dodaj(Wyrazenie a, Wyrazenie b)
    {
        lewe = a;
        prawe = b;
    }
    
	// Nadpisanie metody oblicz() dla klasy Dodaj,
	// czyli implementacja dodawania
    @Override
    public int oblicz() 
    {
        return lewe.oblicz() + prawe.oblicz();
    }
    
	// Nadpisanie metody wypisz() dla klasy Dodaj,
	// czyli implementacja zapisu dodawania
    @Override
    public String wypisz()
    {
        return "(" + lewe.wypisz() + "+" + prawe.wypisz() + ")";
    }
    
}
