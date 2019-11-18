//Alicja Danilczuk
//Pracownia PO, czwartek, s. 108
//L3, z2
//Program implementuj¹cy s³ownik
//Program z klasami
//2018-03-15

using System;
using System.Collections.Generic;
using System.Text;

namespace z2
{
    // Klasa tworz¹ca poszczególne elementy s³ownika
    // gdzie klucze mog¹ byæ porównywane ze sob¹
    public class element<K, V> where K : IComparable<K>
    {
        public K keys;
        public V values;
        public element<K, V> next;

        // Konstruktor ustawiaj¹cy wartoœci pocz¹tkowe na null
        public element()
        {
            next = null;
            keys = default(K);
            values = default(V);
        }
    }

    // Klasa tworz¹ca s³ownik
    // gdzie klucze mog¹ byæ porównywane ze sob¹
    public class Slownik<K, V> where K : IComparable<K>
    {

        element<K, V> head;
       
        // Konstruktor tworz¹cy pierwszy element s³ownika
        public Slownik()
        {
            head = null;
        }

        // Metoda dodaj¹ca element do s³ownika i 
        // dodatkowo zapisuj¹ca go jako head
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

        // Metoda wyszukuj¹ca w s³owniku element o podanym kluczu
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

        // Metoda usuwaj¹ca ze s³ownika element o podanym kluczu
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


        // Metoda wyœwietlaj¹ca wszystkie has³a ze s³ownika
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
