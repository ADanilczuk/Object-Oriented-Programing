/*
    Alicja Danilczuk
    Programowanie Obiektowe
    Tablica indeksowana
    lista 1
    2018-03-01
*/


#ifndef funkcje.h
#define funkcje.h

#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct str_
{
    int indeks;
    int val;
    struct str_* nast;
} str;

str *nm=NULL;
str *head=NULL;

str *utworz(int i,int w)
{
    str *nowy= (str *)malloc(sizeof(str));
    nowy->indeks=i;
    nowy->val=w;
    nowy->nast=NULL;
    return nowy;
}

void czyszczenie()
{
    cout<<"\n By przjesc dalej wcisnij ENTER\n"<<endl;
    cin.sync();cin.get();
    system("CLS");
    return;
}

void wstaw(str *nowy)
{
    int i=nowy->indeks;

    if (head==NULL)
    {
        nm=nowy;
        head=nowy;
        return;
    }

    if (nm->indeks>i)
    {
        nowy->nast=nm;
        nm=nowy;
        return;
    }

    head=nm;
    while (head->nast!=NULL)
     {
          if (head->indeks==i||head->nast->indeks==i)
         {
            cout<<"element o danym indeksie juz istnieje, ten zostanie wiec pominiety\n";
            return;
         }
         if (head->indeks<i&&head->nast->indeks>i)
         {
            nowy->nast=head->nast;
            head->nast=nowy;
            return;
         }
         else   head=head->nast;
     }

     head->nast=nowy;
     head=nm;
    return;
}

void wyswietl()
{
    if (head==NULL) return;
    head=nm;

    if (head->nast==NULL)
    {
        cout<<head->indeks;
        cout<<" Wartosc="<<head->val;
        return;
    }
    do
    {
        cout<<"\n"<<head->indeks;
        cout<<" Wartosc="<<head->val;

        if (head->nast!=NULL) head=head->nast;

    } while ((head->nast)!=NULL);

    cout<<"\n"<<head->indeks;
    cout<<" Wartosc="<<head->val;
    return;
}

void w_wybrany(int i)
{
    head=nm;
    while (head->indeks!=i&&head->nast!=NULL)
    {
        head=head->nast;
    }
    if (head->nast!=NULL) cout<<"Wartosc elementu o wybranym indeksie jest rowna "<<head->val;
    else cout<<"Nie ma elementu o podanym indeksie";
    return;
}

#endif // FUNKCJE
