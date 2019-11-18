

// Klasa reprezentująca instrukcję warunkową
// Podklasa klasy Wyrażenie z zadania 2

public class Warunek extends Wyrazenie
{
    Wyrazenie warunek;
    Wyrazenie gdyTrue;
    Wyrazenie gdyFalse;
	
	// Konstruktor pól przypisujący im przekazane wartości
    public Warunek(Wyrazenie warunek, Wyrazenie gdyTrue, Wyrazenie gdyFalse)
    {
        this.warunek = warunek;
        this.gdyTrue = gdyTrue;
        this.gdyFalse = gdyFalse;
    }
	
	// Nadpisanie metody oblicz() dla klasy Warunek,
	// czyli instrukcja działania programu w chwili spełnienia
	// bądź nie spełnienia warunku
    @Override
    public int oblicz() 
    {
        if(warunek.oblicz() != 0)
        {
            return gdyTrue.oblicz();
        }
        else
        {
            if(gdyFalse == null)
            {
                return -1;
            }
            else
            {
                return gdyFalse.oblicz();
            }
        }
    }
	
	// Nadpisanie metody wypisz() dla klasy Warunek,
	// czyli implementacja wypisywania instrukcji warunkowej
    @Override
    public String wypisz()
    {
        if(gdyFalse != null) {
            return "(" + "if " + warunek.wypisz() + gdyTrue.wypisz() + " else " + gdyFalse.wypisz() + ")";
        }
        else{
            return "(" + "if " + warunek.wypisz() + gdyTrue.wypisz() + ")";
        }
    }
}
