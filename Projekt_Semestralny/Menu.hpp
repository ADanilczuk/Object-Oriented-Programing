#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "posilki.hpp"

class Menu final
{
public:
    int max_kcal;
    list<Posilek*> lista;

    Menu() = default;

    void ustaw_kalorie();
    int ustaw_kalorie_kobieta(int a);
    int ustaw_kalorie_mezczyzna(int a);

    int okno_wejscia();
    int okno_wyboru_posilku();
    int okno_wyboru_czynnosci();
    void wejscie();
    void wybor_posilku();
    void wybor_czynnosci(Posilek*);

    void uzupelnij_liste();
    void dodaj_do_listy(Posilek*);
    void wyswietl_jadlospis();
    void losuj_jadlospis();
    void usuwanie_listy();
    void wyczysc();
};

#endif // MENU_HPP_INCLUDED
