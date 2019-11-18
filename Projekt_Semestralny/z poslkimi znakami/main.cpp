#include "Menu.hpp"
#include "posilki.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <list>
#include <windows.h>


using namespace std;

int main()
{
    // Dopuszczanie mo¿liwoœci wyœwietlania polskich znaków w konsoliœ
    setlocale(LC_ALL, "polish");


    cout<<"\tWitaj w programie ¿yJEMy\n";
    Sleep(1000);

    Menu menu;
    menu.uzupelnij_liste();
    menu.ustaw_kalorie();

    menu.wejscie();

    menu.usuwanie_listy();
    return 0;
}
