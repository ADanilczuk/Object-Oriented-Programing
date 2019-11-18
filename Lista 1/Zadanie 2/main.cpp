/*
    Alicja Danilczuk
    Programowanie Obiektowe
    Program Ulamki
    lista 1
    2018-03-01
*/

#include <cstdio>
#include "funkcje.h"


int main()
{
    Fraction u1, u2;
    Fraction* u3;
    printf("Wpisz licznik pierwszego ulamka ");
    scanf("%d",&u1.l);
    printf("Wpisz mianownik pierwszego ulamka ");
    scanf("%d",&u1.m);
    printf("Wpisz licznik drugiego ulamka ");
    scanf("%d",&u2.l);
    printf("Wpisz mianownik drugiego ulamka ");
    scanf("%d",&u2.m);
    printf("\n\n Wyniki po przeprowadzeniu operacji: \n");

    u3 = dodawanie(u1, u2);
    printf("Dodawanie: %d/%d\n", u3->l, u3->m);

    u3 = mnozenie(u1, u2);
    printf("Mnozenie: %d/%d\n", u3->l, u3->m);

    u3 = odejmowanie(u1, u2);
    printf("Odejmowanie: %d/%d\n", u3->l, u3->m);

    u3 = dzielenie(u1, u2);
    if (u2.l!=0) printf("Dzielenie: %d/%d\n", u3->l, u3->m);

    dodawanie_r(u1, u2);
    printf("Suma z referencja: %d/%d\n", u2.l, u2.m);

    odejmowanie_r(u1, u2);
    printf("Odejmowanie z referencja: %d/%d\n", u2.l, u2.m);

    mnozenie_r(u1, u2);
    printf("Mnozenie z referencja: %d/%d\n", u2.l, u2.m);

    dzielenie_r(u1, u2);
    if (u2.l!=0) printf("Dzielenie z referencja: %d/%d\n", u2.l, u2.m);

    getchar();
    return 0;
}

