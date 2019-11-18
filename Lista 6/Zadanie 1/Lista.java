// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L6, z1
// Klasa
// 2018-04-12


import java.io.Serializable;

// Klasa tworz¹ca listê, wyorzystuj¹ca
// interfejs Serializable
@SuppressWarnings("serial")
public class Lista<T> extends Element<T> implements Serializable 
{

    
    public Element<T> ostatni;
    public Element<T> pierwszy;

    // Konstruktor kolekcji ustawiaj¹cy pola listy na null
    public Lista() 
    {
        this.pierwszy = null;
        this.ostatni  = null;
    }

    // Metoda dodaj¹ca element na koniec listy
    public void DodajNaKoniec (T nowy) 
    {
        Element<T> element = new Element<T>(nowy);
        if(this.pierwszy == null) 
        {
            this.pierwszy = element;
            this.ostatni  = element;
        }
        else 
        {
            this.ostatni.next = element;
            element.prev = this.ostatni;
            this.ostatni = element;
        }
    }

 // Metoda dodaj¹ca element na poczatek listy
    public void DodajNaPoczatek(T nowy)
    {
        Element<T> element = new Element<T>(nowy);
        if(this.pierwszy == null) 
        {
            this.pierwszy = element;
            this.ostatni  = element;
        }
        else 
        {
            this.pierwszy.prev = element;
            element.next = this.pierwszy;
            this.pierwszy = element;
        }
    }

    // Metoda usuwaj¹ca element z koñca listy
    public Element<T> UsunZKonca()
    {
        if(pierwszy!=null)
        {
            if(pierwszy.next!=null)
            {
                Element<T> tmp = this.ostatni;
                this.ostatni = this.ostatni.prev;
                this.ostatni.next = null;
                return tmp;
            }
            else
            {
                Element<T> tmp = this.ostatni;
                this.pierwszy = null;
                this.ostatni  = null;
                return tmp;
            }
        }
        System.out.println("Lista pusta!");
        return null;
    }

    // Metoda usuwaj¹ca element z pocz¹tku listy
    public Element<T> UsunZPoczatku()
    {
        if(pierwszy!=null)
        {
            if(this.pierwszy.next!=null)
            {
                Element<T> tmp = this.pierwszy;
                this.pierwszy = this.pierwszy.next;
                this.pierwszy.prev = null;
                return tmp;
            }
            else 
            {
                Element<T> tmp = this.pierwszy;
                this.pierwszy = null;
                this.ostatni  = null;
                return tmp;
            }
        }
        System.out.println("Lista pusta!");
        return null;
    }

    // Metoda sprawdzaj¹ca czy lista jest pusta
    public boolean CzyPusta()
    {
        if(pierwszy == null)
            return true;
        return false;
    }

    // Metoda wypisuj¹ca wszystkie elementy listy
    public void wypisz()
    {
        if(!CzyPusta()){
            Element<T> tmp = this.pierwszy;
            while(tmp.next!=null)
            {
                System.out.print(tmp.values);
                System.out.print("   ");
                tmp = tmp.next;
            }
            System.out.println(this.ostatni.values);
        }
        else
            System.out.println("Lista pusta!");
    }

}