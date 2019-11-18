//Alicja Danilczuk
//Pracownia PO, czwartek, s. 108
//L3, z1
//Program tworz¹cy moj¹ w³asn¹ listê
//Program zawieraj¹cy klasê
//2018-03-15

using System;

namespace zadanie1
{
    public class Lista<T>
    {
       public T values;
       public Lista<T> next = null;
       public Lista<T> prev = null;

        //Metoda dodaj¹ca element na pocz¹tek listy
        public void Add_begin(T val)
        {
            Lista<T> actual = this;
            if (actual.prev==null)
            {
            	actual.values=val;
            }
            Lista<T> new_one = null;
            while (actual.prev != null)
            {
                actual = actual.prev;
            }
            new_one.next = actual;
            new_one.values = val;
            actual.prev = new_one;
        }

        //Metoda dodaj¹ca element na koniec listy
        public void Add_end(T val)
        {
            Lista<T> actual = this;
            Lista<T> new_one = null;
            while (actual.next != null)
            {
                actual = actual.next;
            }
            new_one.prev = actual;
            new_one.value = val;
            actual.next = new_one;
        }
        
        //Metoda sprawdzaj¹ca czy lista jest pusta
        public bool Test_if_empty()
   		 {
        Lista<T> actual = this;
        if (actual.next == null && actual.prev == null && actual.values == null)
            return true;
        else return false;
        }

        //Metoda wyœwietlaj¹ca listê
        public void Show()
        {
            Lista<T> actual = this;
            int i = 1;
            while (actual.prev != null)
            {
                actual = actual.prev;
            }
            while (actual.next != null)
            {
                Console.WriteLine(i + ". " + actual.values);
                actual = actual.next;
                i++;
            }
            return;
        }

    }

    
}

