// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Klasa
// 2018-03-29

// Klasa implementuj¹ca operacjê dzielenia
// podklasa klasy Wêze³
public class Podziel extends Wezel
{
	// Konstruktor przypisuj¹cy dzielnej i dzielnikowi
	//	podane wartoœci
    public Podziel(Wyrazenie a, Wyrazenie b)
    {
        lewe = a;
        prawe = b;
    }
    
    // Nadpisanie metody oblicz() dla klasy Podziel,
	// czyli implementacja dzielenia
    @Override
    public int oblicz()
    {
        int praweObliczone = prawe.oblicz();
        if (praweObliczone == 0)
        {
            throw new IllegalArgumentException("Nie mo¿na dzieliæ przez 0");
        }
        return lewe.oblicz()/ praweObliczone;
    }
    
	// Nadpisanie metody wypisz() dla klasy Podziel,
	// czyli implementacja zapisu dzielenia
    @Override
    public String wypisz()()
    {
        return "(" + lewe.wypisz() + "/"  + prawe.wypisz() + ")";
    }

}
