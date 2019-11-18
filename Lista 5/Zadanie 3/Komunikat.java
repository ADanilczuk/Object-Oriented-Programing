
// Klasa reprezentująca wypisanie komunikatu na konsolę
// Podklasa klasy Wyrażenie z zadania 2

public class Komunikat extends Wyrazenie
{
    Wyrazenie wyrazenie;
	
	// Konstruktor przypisujący polu przesłane wyrażenie
    public Komunikat(Wyrazenie wyrazenie)
    {
        this.wyrazenie = wyrazenie;
    }
	
	
	// Nadpisanie metody oblicz() dla klasy Komunikat,
	// czyli implementacja wyświetlania zawartości wyrażenia na konsoli
    @Override
    public int oblicz() 
    {
        System.out.print(wyrazenie.wypisz());
        return -1;
    }

}
