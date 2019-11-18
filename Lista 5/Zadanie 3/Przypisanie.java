

// Klasa reprezentująca przypisanie zmiennej jakiejś 
// wartości wymagającej obliczenia 
// Podklasa klasy Wyrażenie z zadania 2

public class Przypisanie extends Wyrazenie
{
    Zmienna zmienna;
    Wyrazenie wartosc;
	
	// Konstruktor pól przypisujący im przekazane wartości
    public Przypisanie(Zmienna zmienna, Wyrazenie wartosc)
    {
        this.zmienna = zmienna;
        this.wartosc = wartosc;
    }
	
	// Nadpisanie metody oblicz() dla klasy Przypisanie,
	// czyli implementacja zwracania zmiennej z przypisaną 
	// jej wyliczoną wartością
    @Override
    public int oblicz() 
    {
        int obliczona = wartosc.oblicz();
        pamiec.put(zmienna.nazwa,obliczona);
        return obliczona;
    }
	
	// Nadpisanie metody wypisz() dla klasy Przypisanie,
	// czyli implementacja wyświetlania przypisania zmiennej jej wartści
    @Override
    public String wypisz()
    {
        return "(" + zmienna.wypisz() + "=" + wartosc.wypisz() + ")";
    }
}
