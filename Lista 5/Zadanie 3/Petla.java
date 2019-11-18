

// Klasa reprezentująca pętle w programie
// Podklasa klasy Wyrażenie z zadania 2

public class Petla extends Wyrazenie
{
    Wyrazenie warunek;
    Wyrazenie cialoPetli;
	
	// Konstruktor pól przypisujący im przekazane wartości
    public Petla(Wyrazenie warunek, Wyrazenie cialoPetli)
    {
        this.warunek = warunek;
        this.cialoPetli = cialoPetli;
    }
	
	// Nadpisanie metody oblicz() dla klasy Pętla,
	// czyli implementacja wyliczania wartości wyrażenia 
	// w ciele pętli do czasu spełnienia warunku
    @Override
    public int oblicz() 
    {
        int wynik = 0;
        wynik = cialoPetli.oblicz();
        while(warunek.oblicz() != 0)
        {
            wynik = cialoPetli.oblicz();
        }

        return wynik;
    }
	
	// Nadpisanie metody wypisz() dla klasy Pętla,
	// czyli implementacja wyświetlania instrukcji pętli
    @Override
    public String wypisz()
    {
       return "(while " + warunek.wypisz() + " do " + cialoPetli.wypisz() + ")";
    }
}
