
#include "posilki.hpp"

// Przeciazanie operatora wyswietlania
ostream & operator<< (ostream &wyj, Posilek* s)
{
    wyj << s->posilek<<": "<< s->nazwa <<"  zawiera "<<s->kalorie<<" kcal";
    return wyj;
}

int Posilek::ilosc_kalorii(string linia)
{
    int kcal=0, j=0;
    string cyfra;
    while(linia[j]!=';')
    {
        cyfra= linia[j];
        kcal=kcal*10 + atoi(cyfra.c_str());
        j++;
    }
    return kcal;
}

string Posilek::nazwa_dania(string linia)
{
    int j;
    string nazwa="";
    for (j=0;linia[j]!=';';j++) {}
    j+=2;
    while(linia[j]!=';')
    {
        nazwa+=linia[j];
        j++;
    }
    return nazwa;
}

// Metody klas pochodnych

Posilek* Sniadanie::losuj(int calkowita_ilosc,int x)
{
    int max_kcal = (calkowita_ilosc*30)/100;
    ifstream spis;
    string linia;
    int indeks, i=1, zakres=0;

    srand(time(NULL));
    indeks=rand();

    while(true)
    {
        spis.open("Bazy_danych/Sniadania.txt", ios::in);
        if(spis.good())
        {
            while(!spis.eof())
            {
                getline(spis, linia);
                if (i==indeks)
                {
                    zakres=1;
                    break;
                }
                i++;
            }
            spis.close();
        }
        if (zakres==1)
        {
            if (ilosc_kalorii(linia)<=max_kcal) break;
            indeks = rand()%indeks;
            zakres=0;
        }
        else
        {
            indeks = rand()%i+1;
        }
        i=1;
    }
    if (x!=7)
    {
        cout<<"\n\tDo jadlospisu dodano: "<<this->nazwa_dania(linia);
        cout<<".\n\tZawiera: "<< ilosc_kalorii(linia)<<" kcal."<<endl;
        cout<<"\nJesli chcesz losowac ponownie wpisz 1, jesli nie wpisz 2\t";
        cin>>x;
        if(x==1) this->losuj(calkowita_ilosc,2);
    }
    Sniadanie *a = new Sniadanie(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
    Posilek *wsk;
    wsk=dynamic_cast<Posilek*>(a);
    return wsk;
}


Posilek* Sniadanie::wybierz(int calkowita_ilosc)
{
    fstream spis;
    string linia,kcal="", nazwa="";
    string wszystkie[100];
    int i=1, nr, wybor=0, max_kcal;
    max_kcal= (calkowita_ilosc*30)/100;

    spis.open("Bazy_danych/Sniadania.txt", ios::in);
    if(spis.good() == true)
    {
        while(!spis.eof())
        {
            getline(spis, linia);
            wszystkie[i]=linia;
            cout<<" "<<i<<". "<<this->nazwa_dania(wszystkie[i])<<" - ";
            cout<<this->ilosc_kalorii(wszystkie[i])<<" kcal"<<endl;
            i++;
        }
        spis.close();
    }
    while (wybor==0)
    {
        cout<<"\n\nSugerowana ilosc kalorii jaka powinno zawierac twoje sniadanie";
        cout<<" to mniej niz "<<max_kcal<<".";
        cout<<"\nKtore danie chcesz wybrac? \n\n Wpisz numer \t";
        cin>>nr;
        linia=wszystkie[nr];

        if(this->ilosc_kalorii(linia) > max_kcal)
        {
            cout<<"\n Jestes pewien, ze chcesz wybrac danie o tak duzej ilosci kalorii?";
            cout<<"Sugerowana ilosc na ten posilek to "<< max_kcal <<"kcal.\n Tak- 1\nNie- 0\n\t";
            cin>>i;
            if (i!=0&&i!=1) cout<<"Niepoprawna odpowiedz, sprobuj wybrac jeszcze raz";
            else wybor=i;
        }
        else wybor=1;
    }
        Sniadanie *a = new Sniadanie(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
        Posilek *wsk;
        wsk=dynamic_cast<Posilek*>(a);
        return wsk;
}


void Sniadanie::dodaj_nowe()
{
    string nazwa, kalorie, linia, nowa_linia;
    int licznik=0;
    ifstream lista_1;
    ofstream lista_2;

    cout<<"Podaj nazwe swojego dania \t";
    cin.get();
    getline(cin, nazwa);
    cout<<"\nPodaj ilosc kalorii \t";
    cin>>kalorie;

    nowa_linia= kalorie + "; " + nazwa + ";";

    lista_1.open("Bazy_danych/Sniadania.txt", ios::in);
    lista_2.open("Bazy_danych/Sniadania_2.txt", ios::out);
    if(lista_1.good() == true)
     {
        getline(lista_1, linia);
        if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << nowa_linia;
                    lista_2 <<endl<< linia;
                    licznik=1;
                }
        else lista_2 << linia;
        while(!lista_1.eof())
        {
            getline(lista_1, linia);
            if (licznik==0)
            {
                if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << endl<< nowa_linia;
                    lista_2 << endl<< linia;
                    licznik=1;
                }
            }
            else lista_2 << endl<< linia;
        }
        lista_1.close();
        lista_2.close();
    }
    remove("Bazy_danych/Sniadania.txt");
    rename("Bazy_danych/Sniadania_2.txt","Bazy_danych\\Sniadania.txt");
    return;
}

//------------------------------


Posilek* Drugie_sniadanie::losuj(int calkowita_ilosc,int x)
{
    int max_kcal = (calkowita_ilosc*10)/100;
    ifstream spis;
    string linia;
    int indeks, i=1, zakres=0;

    srand(time(NULL));
    indeks=rand();

    while(true)
    {
        spis.open("Bazy_danych/Drugie_sniadania.txt", ios::in);
        if(spis.good())
        {
            while(!spis.eof())
            {
                getline(spis, linia);
                if (i==indeks)
                {
                    zakres=1;
                    break;
                }
                i++;
            }
            spis.close();
        }
        if (zakres==1)
        {
            if (ilosc_kalorii(linia)<=max_kcal) break;
            indeks = rand()%indeks;
            zakres=0;
        }
        else
        {
            indeks = rand()%i+1;
        }
        i=1;
    }
    if (x!=7)
    {
        cout<<"\n\tDo jadlospisu dodano: "<<this->nazwa_dania(linia);
        cout<<".\n\tZawiera: "<< ilosc_kalorii(linia)<<" kcal."<<endl;
        cout<<"\nJesli chcesz losowac ponownie wpisz 1, jesli nie wpisz 2\t";
        cin>>x;
        if(x==1) this->losuj(calkowita_ilosc,2);
    }
    Drugie_sniadanie *a = new Drugie_sniadanie(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
    Posilek *wsk;
    wsk=dynamic_cast<Posilek*>(a);
    return wsk;
}


Posilek* Drugie_sniadanie::wybierz(int calkowita_ilosc)
{
    fstream spis;
    string linia,kcal="", nazwa="";
    string wszystkie[100];
    int i=1, nr, wybor=0, max_kcal;
    max_kcal= (calkowita_ilosc*30)/100;

    spis.open("Bazy_danych/Drugie_sniadania.txt", ios::in);
    if(spis.good() == true)
    {
        while(!spis.eof())
        {
            getline(spis, linia);
            wszystkie[i]=linia;
            cout<<" "<<i<<". "<<this->nazwa_dania(wszystkie[i])<<" - ";
            cout<<this->ilosc_kalorii(wszystkie[i])<<" kcal"<<endl;
            i++;
        }
        spis.close();
    }
    while (wybor==0)
    {
        cout<<"\n\nSugerowana ilosc kalorii jaka powinno zawierac twoje drugie sniadanie";
        cout<<" to mniej niz "<<max_kcal<<".";
        cout<<"\nKtore danie chcesz wybrac? \n\n Wpisz numer \t";
        cin>>nr;
        linia=wszystkie[nr];

        if(this->ilosc_kalorii(linia) > max_kcal)
        {
            cout<<"\n Jestes pewien, ze chcesz wybrac danie o tak duzej ilosci kalorii?";
            cout<<"Sugerowana ilosc na ten posilek to "<< max_kcal <<"kcal.\n Tak- 1\nNie- 0\n\t";
            cin>>i;
            if (i!=0&&i!=1) cout<<"Niepoprawna odpowiedz, sprobuj wybrac jeszcze raz";
            else wybor=i;
        }
        else wybor=1;
    }
        Drugie_sniadanie *a = new Drugie_sniadanie(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
        Posilek *wsk;
        wsk=dynamic_cast<Posilek*>(a);
        return wsk;
}


void Drugie_sniadanie::dodaj_nowe()
{
    string nazwa, kalorie, linia, nowa_linia;
    int licznik=0;
    ifstream lista_1;
    ofstream lista_2;

    cout<<"Podaj nazwê swojego dania \t";
    cin.get();
    getline(cin, nazwa);
    cout<<"\nPodaj iloœæ kalorii \t";
    cin>>kalorie;

    nowa_linia= kalorie + "; " + nazwa + ";";

    lista_1.open("Bazy_danych/Drugie_sniadania.txt", ios::in);
    lista_2.open("Bazy_danych/Drugie_sniadania_2.txt", ios::out);
    if(lista_1.good() == true)
     {
        getline(lista_1, linia);
        if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << nowa_linia;
                    lista_2 <<endl<< linia;
                    licznik=1;
                }
        else lista_2 << linia;
        while(!lista_1.eof())
        {
            getline(lista_1, linia);
            if (licznik==0)
            {
                if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << endl<< nowa_linia;
                    lista_2 << endl<< linia;
                    licznik=1;
                }
            }
            else lista_2 << endl<< linia;
        }
        lista_1.close();
        lista_2.close();
    }
    remove("Bazy_danych/Drugie_sniadania.txt");
    rename("Bazy_danych/Drugie_sniadania_2.txt","Bazy_danych\\Drugie_sniadania.txt");
    return;
}

//------------------------------


Posilek* Obiad::losuj(int calkowita_ilosc,int x)
{
    int max_kcal = (calkowita_ilosc*35)/100;
    ifstream spis;
    string linia;
    int indeks, i=1, zakres=0;

    srand(time(NULL));
    indeks=rand();

    while(true)
    {
        spis.open("Bazy_danych/Obiady.txt", ios::in);
        if(spis.good())
        {
            while(!spis.eof())
            {
                getline(spis, linia);
                if (i==indeks)
                {
                    zakres=1;
                    break;
                }
                i++;
            }
            spis.close();
        }
        if (zakres==1)
        {
            if (ilosc_kalorii(linia)<=max_kcal) break;
            indeks = rand()%indeks;
            zakres=0;
        }
        else
        {
            indeks = rand()%i+1;
        }
        i=1;
    }
    if (x!=7)
    {
        cout<<"\n\tDo jadlospisu dodano: "<<this->nazwa_dania(linia);
        cout<<".\n\tZawiera: "<< ilosc_kalorii(linia)<<" kcal."<<endl;
        cout<<"\nJesli chcesz losowac ponownie wpisz 1, jesli nie wpisz 2\t";
        cin>>x;
        if(x==1) this->losuj(calkowita_ilosc,2);
    }
    Obiad *a = new Obiad(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
    Posilek *wsk;
    wsk=dynamic_cast<Posilek*>(a);
    return wsk;
}


Posilek* Obiad::wybierz(int calkowita_ilosc)
{
    fstream spis;
    string linia,kcal="", nazwa="";
    string wszystkie[100];
    int i=1, nr, wybor=0, max_kcal;
    max_kcal= (calkowita_ilosc*35)/100;

    spis.open("Bazy_danych/Obiady.txt", ios::in);
    if(spis.good() == true)
    {
        while(!spis.eof())
        {
            getline(spis, linia);
            wszystkie[i]=linia;
            cout<<" "<<i<<". "<<this->nazwa_dania(wszystkie[i])<<" - ";
            cout<<this->ilosc_kalorii(wszystkie[i])<<" kcal"<<endl;
            i++;
        }
        spis.close();
    }
    while (wybor==0)
    {
        cout<<"\n\nSugerowana ilosc kalorii jakie powinien zawierac twoj obiad";
        cout<<" to mniej niz "<<max_kcal<<".";
        cout<<"\nKtore danie chcesz wybrac? \n\n Wpisz numer \t";
        cin>>nr;
        linia=wszystkie[nr];

        if(this->ilosc_kalorii(linia) > max_kcal)
        {
            cout<<"\n Jestes pewien, ze chcesz wybrac danie o tak duzej ilosci kalorii?";
            cout<<"Sugerowana ilosc na ten posilek to "<< max_kcal <<"kcal.\n Tak- 1\nNie- 0\n\t";
            cin>>i;
            if (i!=0&&i!=1) cout<<"Niepoprawna odpowiedz, sprobuj wybrac jeszcze raz";
            else wybor=i;
        }
        else wybor=1;
    }
        Obiad *a = new Obiad(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
        Posilek *wsk;
        wsk=dynamic_cast<Posilek*>(a);
        return wsk;
}


void Obiad::dodaj_nowe()
{
    string nazwa, kalorie, linia, nowa_linia;
    int licznik=0;
    ifstream lista_1;
    ofstream lista_2;

    cout<<"Podaj nazwe swojego dania \t";
    cin.get();
    getline(cin, nazwa);
    cout<<"\nPodaj ilosc kalorii \t";
    cin>>kalorie;

    nowa_linia= kalorie + "; " + nazwa + ";";

    lista_1.open("Bazy_danych/Obiady.txt", ios::in);
    lista_2.open("Bazy_danych/Obiady_2.txt", ios::out);
    if(lista_1.good() == true)
     {
        getline(lista_1, linia);
        if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << nowa_linia;
                    lista_2 <<endl<< linia;
                    licznik=1;
                }
        else lista_2 << linia;
        while(!lista_1.eof())
        {
            getline(lista_1, linia);
            if (licznik==0)
            {
                if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << endl<< nowa_linia;
                    lista_2 << endl<< linia;
                    licznik=1;
                }
            }
            else lista_2 << endl<< linia;
        }
        lista_1.close();
        lista_2.close();
    }
    remove("Bazy_danych/Obiady.txt");
    rename("Bazy_danych/Obiady_2.txt","Bazy_danych\\Obiady.txt");
    return;
}

//------------------------------


Posilek* Przekaska::losuj(int calkowita_ilosc,int x)
{
    int max_kcal = (calkowita_ilosc*10)/100;
    ifstream spis;
    string linia;
    int indeks, i=1, zakres=0;

    srand(time(NULL));
    indeks=rand();

    while(true)
    {
        spis.open("Bazy_danych/Przekaski.txt", ios::in);
        if(spis.good())
        {
            while(!spis.eof())
            {
                getline(spis, linia);
                if (i==indeks)
                {
                    zakres=1;
                    break;
                }
                i++;
            }
            spis.close();
        }
        if (zakres==1)
        {
            if (ilosc_kalorii(linia)<=max_kcal) break;
            indeks = rand()%indeks;
            zakres=0;
        }
        else
        {
            indeks = rand()%i+1;
        }
        i=1;
    }
    if (x!=7)
    {
        cout<<"\n\tDo jadlospisu dodano: "<<this->nazwa_dania(linia);
        cout<<".\n\tZawiera: "<< ilosc_kalorii(linia)<<" kcal."<<endl;
        cout<<"\nJesli chcesz losowac ponownie wpisz 1, jesli nie wpisz 2\t";
        cin>>x;
        if(x==1) this->losuj(calkowita_ilosc,2);
    }
    Przekaska *a = new Przekaska(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
    Posilek *wsk;
    wsk=dynamic_cast<Posilek*>(a);
    return wsk;
}


Posilek* Przekaska::wybierz(int calkowita_ilosc)
{
    fstream spis;
    string linia,kcal="", nazwa="";
    string wszystkie[100];
    int i=1, nr, wybor=0, max_kcal;
    max_kcal= (calkowita_ilosc*30)/100;

    spis.open("Bazy_danych/Przekaski.txt", ios::in);
    if(spis.good() == true)
    {
        while(!spis.eof())
        {
            getline(spis, linia);
            wszystkie[i]=linia;
            cout<<" "<<i<<". "<<this->nazwa_dania(wszystkie[i])<<" - ";
            cout<<this->ilosc_kalorii(wszystkie[i])<<" kcal"<<endl;
            i++;
        }
        spis.close();
    }
    while (wybor==0)
    {
        cout<<"\n\nSugerowana ilosc kalorii jaka powinna zawierac twoja przekaska";
        cout<<" to mniej niz "<<max_kcal<<".";
        cout<<"\nKtore danie chcesz wybrac? \n\n Wpisz numer \t";
        cin>>nr;
        linia=wszystkie[nr];

        if(this->ilosc_kalorii(linia) > max_kcal)
        {
            cout<<"\n Jestes pewien, ze chcesz wybrac danie o tak duzej ilosci kalorii?";
            cout<<"Sugerowana ilosc na ten posilek to "<< max_kcal <<"kcal.\n Tak- 1\nNie- 0\n\t";
            cin>>i;
            if (i!=0&&i!=1) cout<<"Niepoprawna odpowiedz, sprobuj wybrac jeszcze raz";
            else wybor=i;
        }
        else wybor=1;
    }
        Przekaska *a = new Przekaska(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
        Posilek *wsk;
        wsk=dynamic_cast<Posilek*>(a);
        return wsk;
}


void Przekaska::dodaj_nowe()
{
    string nazwa, kalorie, linia, nowa_linia;
    int licznik=0;
    ifstream lista_1;
    ofstream lista_2;

    cout<<"Podaj nazwe swojego dania \t";
    cin.get();
    getline(cin, nazwa);
    cout<<"\nPodaj ilosc kalorii \t";
    cin>>kalorie;

    nowa_linia= kalorie + "; " + nazwa + ";";

    lista_1.open("Bazy_danych/Przekaski.txt", ios::in);
    lista_2.open("Bazy_danych/Przekaski_2.txt", ios::out);
    if(lista_1.good() == true)
     {
        getline(lista_1, linia);
        if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << nowa_linia;
                    lista_2 <<endl<< linia;
                    licznik=1;
                }
        else lista_2 << linia;
        while(!lista_1.eof())
        {
            getline(lista_1, linia);
            if (licznik==0)
            {
                if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << endl<< nowa_linia;
                    lista_2 << endl<< linia;
                    licznik=1;
                }
            }
            else lista_2 << endl<< linia;
        }
        lista_1.close();
        lista_2.close();
    }
    remove("Bazy_danych/Przekaski.txt");
    rename("Bazy_danych/Przekaski_2.txt","Bazy_danych\\Przekaski.txt");
    return;
}

//------------------------------

Posilek* Kolacja::losuj(int calkowita_ilosc,int x)
{
    int max_kcal = (calkowita_ilosc*20)/100;
    ifstream spis;
    string linia;
    int indeks, i=1, zakres=0;

    srand(time(NULL));
    indeks=rand();

    while(true)
    {
        spis.open("Bazy_danych/Kolacje.txt", ios::in);
        if(spis.good())
        {
            while(!spis.eof())
            {
                getline(spis, linia);
                if (i==indeks)
                {
                    zakres=1;
                    break;
                }
                i++;
            }
            spis.close();
        }
        if (zakres==1)
        {
            if (ilosc_kalorii(linia)<=max_kcal) break;
            indeks = rand()%indeks;
            zakres=0;
        }
        else
        {
            indeks = rand()%i+1;
        }
        i=1;
    }
    if (x!=7)
    {
        cout<<"\n\tDo jadlospisu dodano: "<<this->nazwa_dania(linia);
        cout<<".\n\tZawiera: "<< ilosc_kalorii(linia)<<" kcal."<<endl;
        cout<<"\nJesli chcesz losowac ponownie wpisz 1, jesli nie wpisz 2\t";
        cin>>x;
        if(x==1) this->losuj(calkowita_ilosc,2);
    }
    Kolacja *a = new Kolacja(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
    Posilek *wsk;
    wsk=dynamic_cast<Posilek*>(a);
    return wsk;
}


Posilek* Kolacja::wybierz(int calkowita_ilosc)
{
    fstream spis;
    string linia,kcal="", nazwa="";
    string wszystkie[100];
    int i=1, nr, wybor=0, max_kcal;
    max_kcal= (calkowita_ilosc*30)/100;

    spis.open("Bazy_danych/Kolacje.txt", ios::in);
    if(spis.good() == true)
    {
        while(!spis.eof())
        {
            getline(spis, linia);
            wszystkie[i]=linia;
            cout<<" "<<i<<". "<<this->nazwa_dania(wszystkie[i])<<" - ";
            cout<<this->ilosc_kalorii(wszystkie[i])<<" kcal"<<endl;
            i++;
        }
        spis.close();
    }
    while (wybor==0)
    {
        cout<<"\n\nSugerowana ilosc kalorii jaka powinna zawierac twoja kolacja";
        cout<<" to mniej niz "<<max_kcal<<".";
        cout<<"\nKtore danie chcesz wybrac? \n\n Wpisz numer \t";
        cin>>nr;
        linia=wszystkie[nr];

        if(this->ilosc_kalorii(linia) > max_kcal)
        {
            cout<<"\n Jestes pewien, ze chcesz wybrac danie o tak duzej ilosci kalorii?";
            cout<<"Sugerowana ilosc na ten posilek to "<< max_kcal <<"kcal.\n Tak- 1\nNie- 0\n\t";
            cin>>i;
            if (i!=0&&i!=1) cout<<"Niepoprawna odpowiedz, sprobuj wybrac jeszcze raz";
            else wybor=i;
        }
        else wybor=1;
    }
        Kolacja *a = new Kolacja(this->nazwa_dania(linia), this->ilosc_kalorii(linia));
        Posilek *wsk;
        wsk=dynamic_cast<Posilek*>(a);
        return wsk;
}


void Kolacja::dodaj_nowe()
{
    string nazwa, kalorie, linia, nowa_linia;
    int licznik=0;
    ifstream lista_1;
    ofstream lista_2;

    cout<<"Podaj nazwe swojego dania \t";
    cin.get();
    getline(cin, nazwa);
    cout<<"\nPodaj ilosc kalorii \t";
    cin>>kalorie;

    nowa_linia= kalorie + "; " + nazwa + ";";

    lista_1.open("Bazy_danych/Kolacje.txt", ios::in);
    lista_2.open("Bazy_danych/Kolacje_2.txt", ios::out);
    if(lista_1.good() == true)
    {
        getline(lista_1, linia);
        if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << nowa_linia;
                    lista_2 <<endl<< linia;
                    licznik=1;
                }
        else lista_2 << linia;
        while(!lista_1.eof())
        {
            getline(lista_1, linia);
            if (licznik==0)
            {
                if (this->ilosc_kalorii(linia)>atoi(kalorie.c_str()))
                {
                    lista_2 << endl<< nowa_linia;
                    lista_2 << endl<< linia;
                    licznik=1;
                }
            }
            else lista_2 << endl<< linia;
        }
        lista_1.close();
        lista_2.close();
    }
    remove("Bazy_danych\\Kolacje.txt");
    rename("Bazy_danych\\Kolacje_2.txt","Bazy_danych\\Kolacje.txt");
    return;
}

//------------------------------
//-------------
