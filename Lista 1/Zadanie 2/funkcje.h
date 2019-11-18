/*
    Alicja Danilczuk
    Programowanie Obiektowe
    Program Ulamki
    lista 1
    2018-03-01
*/

#ifndef FUNKCJE.h
#define FUNKCJE.h

#include <cstdio>

typedef struct
{
    int l;
    int m;
}Fraction;


int NWD(int x, int y)
{
    if (y != 0) return NWD(y, x%y);
    return x;
}

void skracanie(Fraction &z)
{
    if (z.m == 0) { printf("Dzielenie przez 0"); return; }
    int l = z.l, m = z.m;
    z.l = l / NWD(l, m);
    z.m = m / NWD(l, m);
    if (z.m < 0) { z.l = -z.l; z.m = -z.m; }
}

int wsp_m(Fraction x, Fraction y)
{
    int a=x.m*y.m;
    return a;
}

Fraction* dodawanie(Fraction x, Fraction y)
{
    Fraction z;
    z.l = x.l*y.m + y.l*x.m;
    z.m = wsp_m(x,y);
    skracanie(z);
    return &z;
}

Fraction* mnozenie(Fraction x, Fraction y)
{
    Fraction z;
    z.l = x.l * y.l;
    z.m = wsp_m(x,y);
    skracanie(z);
    return &z;
}


Fraction* odejmowanie(Fraction x, Fraction y)
{
    Fraction z;
    z.l = x.l*y.m - y.l*x.m;
    z.m = wsp_m(x,y);
    skracanie(z);
    return &z;
}

Fraction* dzielenie(Fraction x, Fraction y)
{
    if (y.m == 0 || y.l == 0) { printf("Nie wolno dzielic przez 0!\n"); return 0; }
    Fraction z;
    int l, m;
    z.l = x.l * y.m;
    z.m = x.m * y.l;
    skracanie(z);
    return &z;
}

void dodawanie_r(Fraction x, Fraction &y)
{
    int l = x.l*y.m + y.l*x.m;
    int m =wsp_m(x,y);
    y.l = l;
    y.m = m;
    skracanie(y);
}

void mnozenie_r(Fraction x, Fraction &y)
{
    int l = x.l * y.l;
    int m = wsp_m(x,y);
    y.l = l;
    y.m = m;
    skracanie(y);
}

void odejmowanie_r(Fraction x, Fraction &y)
{
    int l = x.l*y.m - y.l*x.m;
    int m = wsp_m(x,y);
    y.l = l;
    y.m = m;
    skracanie(y);
}

void dzielenie_r(Fraction x, Fraction &y)
{
    if (y.m == 0 || y.l == 0) { printf("Nie wolno dzielic przez 0!\n"); return; }
    int l = x.l * y.m;
    int m = x.m * y.l;
    y.l = l;
    y.m = m;
    skracanie(y);
}

#endif
