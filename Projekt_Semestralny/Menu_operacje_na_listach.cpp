#include "Menu.hpp"
#include "posilki.hpp"

void Menu::usuwanie_listy()
{
    list<Posilek*> ls= this->lista;
    list<Posilek*>::iterator i;

    for(i=ls.begin(); i!=ls.end(); i++)
     {
         delete &*i;
     }
}

void Menu::dodaj_do_listy(Posilek* d)
{
    string m= d->posilek;
    list<Posilek*> ls = this->lista;
    list<Posilek*>::iterator i;
    int n=1,k=1;

    if (m=="Sniadanie")k=1;
    if (m=="Drugie sniadanie") k=2;
    if (m=="Obiad")k=3;
    if (m=="Przekaska")k=4;
    if (m=="Kolacja")k=5;

    switch (k)
    {
        case 1:
        {
            i=ls.begin();
            Posilek* wsk= *i;
            *i= new Sniadanie(d->nazwa, d->kalorie);
            delete &wsk;
            break;
        }
        case 2:
        {
            for(i=ls.begin(); i!=ls.end(); i++)
            {
                if(n==2) break;
                n++;
            }
            Posilek* wsk= *i;
           cout<<"  ";
            *i= new Drugie_sniadanie(d->nazwa, d->kalorie);
            delete &wsk;
           cout<<"  ";

            break;
        }
        case 3:
        {
            for(i=ls.begin(); i!=ls.end(); i++)
            {
                if(n==3) break;
                n++;
            }
            Posilek* wsk= *i;
            *i= new Obiad(d->nazwa, d->kalorie);
            delete &wsk;
            break;
        }
        case 4:
        {
            for(i=ls.begin(); i!=ls.end(); i++)
            {
                if(n==4) break;
                n++;
            }
            Posilek* wsk= *i;
            *i= new Przekaska(d->nazwa, d->kalorie);
            delete &wsk;
            break;
        }
        case 5:
        {
            for(i=ls.begin(); i!=ls.end(); i++)
            {
                if(n==5) break;
                n++;
            }
            Posilek* wsk= *i;
            *i= new Kolacja(d->nazwa, d->kalorie);
            delete &wsk;
            break;
        }
    }
    this->lista = ls;
    return;
}

void Menu::wyswietl_jadlospis()
{
    int suma=0;
    list<Posilek*> ls= this->lista;
    list<Posilek*>::iterator i;
    for(i=ls.begin(); i!=ls.end(); i++)
     {
        cout<<(*i)<<endl;
        suma+=(*i)->kalorie;
     }
     cout<<"\n Calkowita ilosc kilokalorii w jadlospisie: "<<suma<<endl;
    return;
}

void Menu::losuj_jadlospis()
{
    Sniadanie *a = new Sniadanie("",0);
    dodaj_do_listy(a->losuj(this->max_kcal, 7));

    Drugie_sniadanie *b= new Drugie_sniadanie("",0);
    this->dodaj_do_listy(b->losuj(this->max_kcal, 7));

    Obiad *c= new Obiad("",0);
    this->dodaj_do_listy(c->losuj(this->max_kcal, 7));

    Przekaska *d= new Przekaska("",0);
    this->dodaj_do_listy(d->losuj(this->max_kcal, 7));

    Kolacja *e= new Kolacja("",0);
    this->dodaj_do_listy(e->losuj(this->max_kcal, 7));

}

void Menu::uzupelnij_liste()
{
    Posilek *wsk;

    Sniadanie *a = new Sniadanie("",0);
    wsk=dynamic_cast<Posilek*>(a);
    this->lista.push_back(wsk);

    Drugie_sniadanie *b= new Drugie_sniadanie("",0);
    wsk=dynamic_cast<Posilek*>(b);
    this->lista.push_back(wsk);

    Obiad *c= new Obiad("",0);
    wsk=dynamic_cast<Posilek*>(c);
    this->lista.push_back(wsk);

    Przekaska *d= new Przekaska("",0);
    wsk=dynamic_cast<Posilek*>(d);
    this->lista.push_back(wsk);

    Kolacja *e= new Kolacja("",0);
    wsk=dynamic_cast<Posilek*>(e);
    this->lista.push_back(wsk);

    return;
}
