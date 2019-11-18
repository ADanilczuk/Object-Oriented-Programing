#include "Menu.hpp"
#include "posilki.hpp"


int Menu::ustaw_kalorie_kobieta(int a)
{
    switch (a)
    {
        case 1: return 2600;
        case 2: return 2200;
        case 3: return 2600;
        case 4: return 3100;
        case 5: return 2100;
        default:
        {
            cout<<"Niepoprawne dane\n";
            break;
        }
    }
    return 0;
}

int Menu::ustaw_kalorie_mezczyzna(int a)
{
    switch (a)
    {
        case 1: return 3400;
        case 2: return 2500;
        case 3: return 3000;
        case 4: return 3700;
        case 5: return 2200;
        default:
        {
            cout<<"Niepoprawne dane\n";
            break;
        }
    }
    return 0;
}

void Menu::ustaw_kalorie()
{
    system("CLS");
    int a,b;
    cout<<"\nNa początek musisz ustawić dzienną ilość kalorii. Wybierz jak chcesz to zrobić\n\n";
    cout<<" 1 - Ustaw kalorie sam\n";
    cout<<" 2 - Skorzystaj z pomocy\n";
    cout<<" 3 - Wyjdź z programu \n\n";
    cin>>a;
    switch (a)
    {
        case 1:
        {
            cout<<"\nPodaj dzienną ilość kalorii\n";
            cin>>b;
            this->max_kcal = b;
            Sleep(100);
            break;
        }
        case 2:
        {
            system("CLS");
            cout<<"\n Witaj w pomocy. Wybierz swoją płeć\n\n";
            cout<<" 1 - Kobieta\n";
            cout<<" 2 - Mezczyzna\n\n";
            cin>>b;
            system("CLS");

            cout<<"Wybierz opcję, która najlepiej odzwierciedla ciebie\n\n";
            cout<<" 1 - 13-20 lat\n";
            cout<<" 2 - 21-59 lat, praca lekka\n";
            cout<<" 3 - 21-59 lat, praca umiarkowana\n";
            cout<<" 4 - 21-59 lat, praca ciężka\n";
            cout<<" 5 - Powyżej 60 lat\n\n";
            cin>>a;

            if (b==1)
            {
                this->max_kcal= ustaw_kalorie_kobieta(a);
                cout<<"\nSugerowana dla Ciebie ilość kalorii to: "<<this->max_kcal<<endl;
                Sleep(1500);
                break;
            }
            if (b==2)
            {
                this->max_kcal= ustaw_kalorie_mezczyzna(a);
                cout<<"\nSugerowana dla Ciebie ilość kalorii to: "<<this->max_kcal<<endl;
                Sleep(1500);
                break;
            }
            else {cout<<"Niepoprawne dane"; break;}
        }
        case 3:
        {
            exit (EXIT_FAILURE);
        }
        default:
        {
            cout<<"\nNiepoprawne dane";
            break;
        }
    }
    if (this->max_kcal <1000)
    {
        cout<<"Ta ilość kalorii jest zbyt mała by utworzyć z niej zdrowy jadłospis.\n";
        cout<<"Spróbuj przejść proces ustawiania ponownie.\n";
        Sleep(3000);
        this->ustaw_kalorie();
    }
    return;
}


int Menu::okno_wejscia()
{
    int a;
    system("CLS");
    cout<<"\nWybierz co chcesz zrobić:\n\n";
    cout<<" 1 - Pracuj nad jadłospisem \n";
    cout<<" 2 - Losuj cały jadłospis \n";
    cout<<" 3 - Wyswietl dzisiejszy jadłospis \n";
    cout<<" 4 - Wyjdź z programu \n\n";
    cin>>a;
    return a;
}

void Menu::wejscie()
{
    cout<<endl;
    int wybor=1;
    while (wybor != 4)
    {
        wybor = okno_wejscia();
        switch (wybor)
        {
            case 1:
            {
                this->wybor_posilku();
                break;
            }
            case 2:
            {
                this->losuj_jadlospis();
                cout<<"\nWylosowano jadłospis";
                Sleep(1000);
                break;
            }
            case 3:
            {
                this->wyswietl_jadlospis();
                cout<<"\nAby wrócić do poprzedniego okna wciśnij dowolny przycisk\n";
                system("PAUSE");
                break;
            }
            case 4:
            {
                break;
               // exit (EXIT_FAILURE);
            }
            default:
            {
                cout<<"Niepoprawne dane\n";
                break;
            }
        }
    }
    return;
}


int Menu::okno_wyboru_czynnosci()
{
    system("CLS");
    int a;
    cout<<"\nWybierz czynność, któr¹ chcesz wykonać:\n\n";
    cout<<" 1 - Losuj danie \n";
    cout<<" 2 - Wybierz danie z listy \n";
    cout<<" 3 - Dodaj nowe danie do listy \n";
    cout<<" 4 - Wróć do okna wyboru posiłku \n";
    cout<<" 5 - Wyjdź z programu \n\n";
    cin>>a;
    return a;
}

void Menu::wybor_czynnosci(Posilek *p)
{
    int wybor= 1;
    Posilek* x;
    while (wybor != 4)
    {
        wybor=okno_wyboru_czynnosci();
        switch (wybor)
        {
            case 1:
            {
                x= p->losuj(this->max_kcal, 2);
                dodaj_do_listy(x);
                break;
            }
            case 2:
            {
                x= p->wybierz(this->max_kcal);
                dodaj_do_listy(x);
                break;
            }
            case 3:
            {
                p->dodaj_nowe();
                Sleep(2000);
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                exit (EXIT_FAILURE);
            }
            default:
            {
                cout<<"Niepoprawne dane\n";
                break;
            }
        }
    }
    return;
}

int Menu::okno_wyboru_posilku()
{
    system("CLS");
    int a;
    cout<<"\nWybierz posiłek, który chcesz edytować:\n\n";
    cout<<" 1 - Śniadanie \n";
    cout<<" 2 - Drugie śniadanie \n";
    cout<<" 3 - Obiad \n";
    cout<<" 4 - Przekąska \n";
    cout<<" 5 - Kolacja \n";
    cout<<" 6 - Wróć do wyboru funkcji głównych \n";
    cout<<" 7 - Wyjdź z programu \n\n";
    cin>>a;
    return a;
}

void Menu::wybor_posilku()
{
    system("CLS");
    cout<<endl;
    Posilek *wsk;
    int wybor=1;
    while (wybor != 6)
    {
       wybor=okno_wyboru_posilku();
        switch (wybor)
        {
            case 1:
            {
                cout<<"\tŚniadanie\n\n";
                Sniadanie p;
                wsk=dynamic_cast<Posilek*>(&p);
                this->wybor_czynnosci(wsk);
                break;
            }
           case 2:
            {
                cout<<"\tDrugie śniadanie\n\n";
                Drugie_sniadanie p;
                wsk=dynamic_cast<Posilek*>(&p);
                this->wybor_czynnosci(wsk);
                break;
            }
            case 3:
            {
                cout<<"\tObiad\n\n";
                Obiad p;
                wsk=dynamic_cast<Posilek*>(&p);
                this->wybor_czynnosci(wsk);
                break;
            }
            case 4:
            {
                cout<<"\tPrzekąska\n\n";
                Przekaska p;
                wsk=dynamic_cast<Posilek*>(&p);
                wybor_czynnosci(wsk);
                break;
            }
            case 5:
            {
                cout<<"\tKolacja\n\n";
                Kolacja p;
                wsk=dynamic_cast<Posilek*>(&p);
                wybor_czynnosci(wsk);
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                exit (EXIT_FAILURE);
            }
            default:
            {
                cout<<"Niepoprawne dane\n";
                break;
            }
        }
    }
    return;
}
