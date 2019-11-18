// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L4, z2
// Program wypisuj�cy liczby pierwsze
// Program zawieraj�cy klasy
// 2018-03-22



using System;
using System.Collections.Generic;
using System.Text;

namespace zadanie2
{
    using System.Collections;
    class PrimeCollection : IEnumerable
    {

        int najwieksza_liczba;

        public PrimeCollection(int max)
        {
            najwieksza_liczba = max;
        }

        public IEnumerator GetEnumerator()
        {
            return new Primes(najwieksza_liczba);
        }
    }

    //Klasa wykorzystuj�ca wbudowany interfejs IEnumerator
    class Primes : IEnumerator
    {
        int licznik;
        int najwieksza_liczba;
        public Primes(int max)
        {
            licznik = 1;
            najwieksza_liczba = max;
        }

        //Metoda przechodz�ca do nast�pnej liczby naturalnej
        public bool MoveNext()
        {
            licznik++;
            while (!Sprawdz_pierwszosc(licznik))
            { licznik++; }
            return licznik < najwieksza_liczba;
        }

        //Metoda sparwdzaj�ca czy liczba i jest pierwsza
        public bool Sprawdz_pierwszosc(int i)
        {
            int a = 2;
            while (a < Math.Sqrt(i))
            {
                if (i % a == 0) return false;
                a++;
            }
            return true;
        }

        //Metoda wypisuj�ca licznik, czyli liczb� pierwsz�
        public object Current
        {
            get
            {
                return licznik;
            }

        }

        //Metoda resetuj�ca kolekcj� (ustawia licznik 
        //na t� sam� warto�� pocz�tkow� co w konstruktorze)
        public void Reset()
        {
            licznik = 1;
        }
    }
}
