#ifndef POSILKI_HPP_INCLUDED
#define POSILKI_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <list>
#include <windows.h>


using namespace std;

class Posilek
{
 public:
    string posilek;
    string nazwa;
    int kalorie;

    friend ostream & operator<< (ostream &wyj, Posilek* s);

    Posilek() =default;
    Posilek(string a,string b,int k): posilek(a), nazwa(b), kalorie(k){};

    virtual Posilek* losuj(int, int) =0;
    virtual Posilek* wybierz(int) =0;
    virtual void dodaj_nowe() =0;
    int ilosc_kalorii(string);
    string nazwa_dania(string);
};


// Klasy pochodne

class Sniadanie : public Posilek
{
public:
    Sniadanie(): Posilek("Sniadanie","",0) {};
    Sniadanie(string b,int c): Posilek("Sniadanie",b,c){};

    virtual Posilek* losuj(int,int);
    virtual Posilek* wybierz(int);
    virtual void dodaj_nowe();
};


class Drugie_sniadanie : public Posilek
{
public:
    Drugie_sniadanie(): Posilek("Drugie sniadanie","",0) {}
    Drugie_sniadanie(string b,int c): Posilek("Drugie sniadanie",b,c){}

    virtual Posilek* losuj(int,int );
    virtual Posilek* wybierz(int);
    virtual void dodaj_nowe();
};


class Obiad : public Posilek
{
public:
    Obiad(): Posilek("Obiad","",0) {};
    Obiad(string b,int c): Posilek("Obiad",b,c){};

    virtual Posilek* losuj(int,int);
    virtual Posilek* wybierz(int);
    virtual void dodaj_nowe();
};


class Przekaska : public Posilek
{
public:
    Przekaska(): Posilek("Przekaska","",0) {};
    Przekaska(string b,int c): Posilek("Przekaska",b,c){};

    virtual Posilek* losuj(int,int);
    virtual Posilek* wybierz(int);
    virtual void dodaj_nowe();
};


class Kolacja : public Posilek
{
public:
    Kolacja(): Posilek("Kolacja","",0) {};
    Kolacja(string b,int c): Posilek("Kolacja",b,c){};

    virtual Posilek* losuj(int,int);
    virtual Posilek* wybierz(int);
    virtual void dodaj_nowe();
};

#endif // POSILKI_HPP_INCLUDED
