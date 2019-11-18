// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Klasa
// 2018-03-29

// Klasa implementująca stałe 
// podklasa klasy Wyrażenie

public class Stala extends Wyrazenie
{
    int wartosc;
	
	// Konstruktor przypisujący stałej podaną wartość
    public Stala(int wartosc)
    {
        this.wartosc = wartosc;
    }

	// Nadpisanie metody oblicz() dla klasy Stała,
	// czyli implementacja zwracania wartości stałych
    @Override
    public int oblicz() 
    {
        return wartosc;
    }
	
	// Nadpisanie metody wypisz() dla klasy Stała,
	// czyli implementacja zapisu stałych
    @Override
    public String wypisz()
	{
        return String.valueOf(wartosc);
    }
}
