//Alicja Danilczuk
//Pracownia PO, czwartek, s. 108
//L3, z2
//Program implementuj�cy s�ownik
//Program z klasami
//2018-03-15

using System;
using System.Collections.Generic;
using System.Text;

namespace z2
{
    // Klasa tworz�ca poszczeg�lne elementy s�ownika
    // gdzie klucze mog� by� por�wnywane ze sob�
    public class element<K, V> where K : IComparable<K>
    {
        public K keys;
        public V values;
        public element<K, V> next;

        // Konstruktor ustawiaj�cy warto�ci pocz�tkowe na null
        public element()
        {
            next = null;
            keys = default(K);
            values = default(V);
        }
    }

    // Klasa tworz�ca s�ownik
    // gdzie klucze mog� by� por�wnywane ze sob�
    public class Slownik<K, V> where K : IComparable<K>
    {

        element<K, V> head;
       
        // Konstruktor tworz�cy pierwszy element s�ownika
        public Slownik()
        {
            head = null;
        }

        // Metoda dodaj�ca element do s�ownika i 
        // dodatkowo zapisuj�ca go jako head
        public void Dodaj(K key, V val)
        {
            element<K, V> obiekt = head ;
            element<K, V > new_one = new element<K, V>();
            while (obiekt != null)
            {
                if (key.CompareTo(obiekt.keys) == 0)
                    throw new System.ArgumentException();
                obiekt = obiekt.next;
            }

            new_one.keys = key;
            new_one.values = val;
            new_one.next = head;
            head = new_one;
        }

        // Metoda wyszukuj�ca w s�owniku element o podanym kluczu
        public void Wyszukaj(K key)
        {
            element<K, V> obiekt = head;
            while (obiekt != null)
            {
                if (key.CompareTo(obiekt.keys) == 0)
                {
                    Console.WriteLine("Klucz " + obiekt.keys + " wartosc " + obiekt.values);
                    Console.Read();
                    return;
                }
                obiekt = obiekt.next;
            }

            throw new System.ArgumentException("Nie ma elementu o tym kluczu");
        }

        // Metoda usuwaj�ca ze s�ownika element o podanym kluczu
        public void Usun(K key)
        {
            element<K, V> obiekt = head;
           
            if (key.CompareTo(obiekt.keys) == 0)
            {
                head = obiekt.next;
                return;
            }
            element<K, V> obiekt2 = obiekt.next;
            while (obiekt2 != null)
            {
                if (key.CompareTo(obiekt2.keys) == 0)
                {
                    obiekt.next = obiekt2.next;
                    return;
                }
                obiekt = obiekt2;
                obiekt2 = obiekt2.next;
            }
            throw new System.ArgumentException("Nie ma elementu o tym kluczu");
        }


        // Metoda wy�wietlaj�ca wszystkie has�a ze s�ownika
        public void wyswietl()
        {
            element<K, V> obiekt = head;
            while (obiekt.next != null)
            {
                Console.WriteLine("klucz " + obiekt.keys + " wartosc " + obiekt.values);
                obiekt = obiekt.next;
            }
            Console.WriteLine("klucz " + obiekt.keys + " wartosc " + obiekt.values);
            return;
        }
    }
}
