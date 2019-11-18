/*
    Alicja Danilczuk
    Programowanie Obiektowe
    Tablica indeksowana
    lista 1
    2018-03-01
*/

#include <iostream>
#include <cstdio>
#include "funkcje.h"

using namespace std;

int main()
{
    str *tab;
    int i,w, ilosc,licznik=0;
    cout<< "Podaj ile wartosci chcesz wpisac do tablicy (maksymalnie 100) ";
    cin>>ilosc;
    while (ilosc>licznik)
    {
        cout<< "Wpisz indeks ktory chcesz nadac elementowi" << endl;
        cin>> i;
        cout<< "Wpisz wartosc ktora ma przechowywac tablica" << endl;
        cin>> w;
        tab=utworz(i,w);
        wstaw(tab);
        licznik++;
    }
    czyszczenie();

    cout<<"Wpisz numer indeksu elementu ktory chcesz wyswietlic"<<endl;
    cin>>i;
    w_wybrany(i);

    czyszczenie();
    cout<<"\nOto wszystkie elementy wpisane do tablicy\n";
    wyswietl();
    return 0;
}
