#include <iostream>
#include "PanelLogowania.h"
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void PanelLogowania::zarejestruj(int iloscUzytkownikow)
{
    cout << "podaj login: " << endl;
    cin >> login;
    fstream BazaUzytkownikow;
    string liniaOdczytywanaZPliku;
    string buforDanych;
    int dlugoscLinii;
    int nrWystapieniaKreski = 1;
    int nrLinii = 1;
    int pozycjaKreski = 0;
    int nrUzytkownika = 0;
    bool CzyPowtorzylo;
    while (CzyPowtorzylo)
    {
        CzyPowtorzylo = false;
        BazaUzytkownikow.open("ListaUzytkownikow.txt",ios::in);
        while(getline(BazaUzytkownikow,liniaOdczytywanaZPliku))
        {
            dlugoscLinii = liniaOdczytywanaZPliku.length();
            for (int i = 0; i < dlugoscLinii; i++)
            {
                if (liniaOdczytywanaZPliku[i] == '|')
                {
                    switch(nrWystapieniaKreski)
                    {
                    case 1:
                        pozycjaKreski = i + 1;
                        break;
                    case 2:
                        buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                        pozycjaKreski = i+1;
                        if (buforDanych == login)
                        {
                            cout << "Taki login juz istnieje, wprowadz inny login: " << endl;
                            cin >> login;
                            CzyPowtorzylo = true;
                        }
                        break;
                    case 3:
                        pozycjaKreski = i + 1;
                        break;
                    }
                    nrWystapieniaKreski ++;
                }
            }
            pozycjaKreski = 0;
            nrWystapieniaKreski = 1;
            nrUzytkownika ++;
        }
        BazaUzytkownikow.close();
    }



    cout << "Podaj haslo: " << endl;
    cin >> haslo;
    idUzytkownika = iloscUzytkownikow + 1;

    fstream Plik;
    Plik.open("ListaUzytkownikow.txt",ios::out | ios::app);
    Plik << idUzytkownika << "|";
    Plik << login << "|";
    Plik << haslo << "|" << endl;
    Plik.close();

    cout << "Rejsetracja przebiegla pomyslnie" << endl;
    Sleep(1500);
}
void PanelLogowania::zaloguj(int iloscUzytkownikow)
{
    czyZalogowano = false;
    string hasloUzytkownika;
    cout << "Podaj login: " << endl;
    cin >> login;
    fstream BazaUzytkownikow;
    string liniaOdczytywanaZPliku;
    string buforDanych;
    int dlugoscLinii;
    int nrWystapieniaKreski = 1;
    int nrLinii = 1;
    int pozycjaKreski = 0;
    int nrUzytkownika = 0;
    bool CzyPowtorzylo = false;;
    bool pobierzHaslo = false;

    BazaUzytkownikow.open("ListaUzytkownikow.txt",ios::in);
    while(getline(BazaUzytkownikow,liniaOdczytywanaZPliku))
    {
        dlugoscLinii = liniaOdczytywanaZPliku.length();
        for (int i = 0; i < dlugoscLinii; i++)
        {
            if (liniaOdczytywanaZPliku[i] == '|')
            {
                switch(nrWystapieniaKreski)
                {
                case 1:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    break;
                case 2:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i+1;
                    if (buforDanych == login)
                    {
                        for (int j = 0; j < dlugoscLinii; j++)
                        {
                            if (liniaOdczytywanaZPliku[i] == '|')
                            {
                                buforDanych = liniaOdczytywanaZPliku.substr(0,j);
                                idUzytkownika = atoi(buforDanych.c_str());
                            }
                        }
                        CzyPowtorzylo = true;
                        pobierzHaslo = true;
                    }
                    break;
                case 3:
                    if (pobierzHaslo == true)
                    {
                        hasloUzytkownika = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                        pobierzHaslo = false;
                    }
                    pozycjaKreski = i + 1;
                    break;
                }
                nrWystapieniaKreski ++;
            }
        }
        pozycjaKreski = 0;
        nrWystapieniaKreski = 1;
        nrUzytkownika ++;
    }
    BazaUzytkownikow.close();
    if (CzyPowtorzylo == false)
    {
        cout << "taki uzytkownik nie istnieje" << endl;
        Sleep(1500);
        return;
    }
    else
    {
        cout << "Podaj haslo: " << endl;
        cin >> haslo;
        if (haslo != hasloUzytkownika)
        {
            cout << "Haslo nie poprawne " << endl;
            Sleep(1500);
            return;
        }
        else
        {
            czyZalogowano = true;
            cout << "prawidlowe haslo, Logowanie przebieglo pomyslnie " << endl;
            Sleep(1500);
        }
    }


}

