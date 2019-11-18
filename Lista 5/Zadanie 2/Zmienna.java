// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L5, z2
// Klasa
// 2018-03-29

// Klasa implementująca zmienne
// podklasa klasy Wyrażenie

public class Zmienna extends Wyrazenie
{
    String nazwa;
	
	// Konstruktor przypisujący zmiennej podaną wartość
    public Zmienna(String nazwa)
    {
        this.nazwa = nazwa;
    }

	// Nadpisanie metody oblicz() dla klasy Zmienna,
	// czyli implementacja wywoływania nazw zmiennych
    @Override
    public int oblicz() 
    {
        return (int)Wyrazenie.pamiec.get(nazwa);
    }
	
	// Nadpisanie metody wypisz() dla klasy Zmienna
	// czyli implementacja zapisu zmiennych
    @Override
    public String wypisz()
    {
        return nazwa;
    }
}
