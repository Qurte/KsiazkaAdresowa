#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PanelLogowania.h"

using namespace std;
struct Przyjaciel
{
    int id;
    int idUzytkownika;
    string imie,nazwisko,email,nrTelefonu,adres;

};
struct Uzytkownik
{
    int idUzytkownika;
    string login, haslo;
};
int wczytajDaneZPliku (vector<Przyjaciel> &przyjaciele, int idUzytkownika)
{
    fstream BazaZnajomych;
    string liniaOdczytywanaZPliku;
    string buforDanych, imie, nazwisko, email, nrTelefonu, adres;
    int id;
    int idUzytkownikaWPliku;
    int dlugoscLinii;
    int nrWystapieniaKreski = 1;
    int nrLinii = 1;
    int pozycjaKreski = 0;
    int nrPrzyjaciela = 0;
    int nrPrzyjacielaUzytkownika = przyjaciele.size();
    BazaZnajomych.open("ListaZnajomych.txt",ios::in);
    if(BazaZnajomych.good() == false)
    {
        return 0;
    }
    while(getline(BazaZnajomych,liniaOdczytywanaZPliku))
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
                    id = atoi(buforDanych.c_str());
                    break;
                 case 2:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    idUzytkownikaWPliku = atoi(buforDanych.c_str());
                    break;
                case 3:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i+1;
                    imie = buforDanych;
                    break;
                case 4:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    nazwisko = buforDanych;
                    break;
                case 5:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    email = buforDanych;
                    break;
                case 6:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    nrTelefonu = buforDanych;
                    break;
                case 7:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    adres = buforDanych;
                    break;
                }
                nrWystapieniaKreski ++;
            }
        }
        if (idUzytkownikaWPliku == idUzytkownika)
        {
            przyjaciele.push_back(Przyjaciel());
            przyjaciele[nrPrzyjacielaUzytkownika].id = id;
            przyjaciele[nrPrzyjacielaUzytkownika].idUzytkownika = idUzytkownika;
            przyjaciele[nrPrzyjacielaUzytkownika].imie = imie;
            przyjaciele[nrPrzyjacielaUzytkownika].nazwisko = nazwisko;
            przyjaciele[nrPrzyjacielaUzytkownika].email = email;
            przyjaciele[nrPrzyjacielaUzytkownika].nrTelefonu = nrTelefonu;
            przyjaciele[nrPrzyjacielaUzytkownika].adres = adres;
            nrPrzyjacielaUzytkownika++;
        }
        pozycjaKreski = 0;
        nrWystapieniaKreski = 1;
        nrPrzyjaciela ++;
    }
    BazaZnajomych.close();
    return nrPrzyjaciela;

}
int wczytajDaneZPliku (vector<Uzytkownik> &uzytkownicy)
{
    fstream BazaUzytkownikow;
    string liniaOdczytywanaZPliku;
    string buforDanych;
    int dlugoscLinii;
    int nrWystapieniaKreski = 1;
    int nrLinii = 1;
    int pozycjaKreski = 0;
    int nrUzytkownika = 0;
    BazaUzytkownikow.open("ListaUzytkownikow.txt",ios::in);
    if(BazaUzytkownikow.good() == false)
    {
        return 0;
    }
    while(getline(BazaUzytkownikow,liniaOdczytywanaZPliku))
    {
        uzytkownicy.push_back(Uzytkownik());
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
                    uzytkownicy[nrUzytkownika].idUzytkownika = atoi(buforDanych.c_str());
                    break;
                case 2:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i+1;
                    uzytkownicy[nrUzytkownika].login = buforDanych;
                    break;
                case 3:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    uzytkownicy[nrUzytkownika].haslo = buforDanych;
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
    return nrUzytkownika;

}
int dodajPrzyjacielaDoBazy(vector<Przyjaciel> &przyjaciele,int IloscZnajomych, int idUzytkownika)
{
    string imie, nazwisko, email, nrTelefonu, adres;
    int id = IloscZnajomych + 1;
    if (IloscZnajomych == przyjaciele.size())
    {
        bool CzyZnalazlo = false;
        for (int i = 0; i < IloscZnajomych; i++)
        {
            for (int j = 0; j <= IloscZnajomych; j++)
            {
                if(przyjaciele[j].id == i+1)
                {
                    CzyZnalazlo = true;
                    break;
                }
                else
                    CzyZnalazlo = false;
            }
            if (CzyZnalazlo == false)
            {
                id = i+1;
                break;
            }
        }
    }

    cout << "podaj imie znajomego" << endl;
    cin >> imie;

    cout << "podaj nazwisko znajomego" << endl;
    cin >> nazwisko;

    cout << "podaj email znajomego" << endl;
    cin >> email;

    cout << "podaj nr. telefonu znajomego" << endl;
    cin >> nrTelefonu;
    cin.ignore();

    cout << "podaj adres znajomego" << endl;
    getline(cin,adres);

    int IloscZnajomychUTegoUzytkownika = przyjaciele.size();
    przyjaciele.push_back(Przyjaciel());
    przyjaciele[IloscZnajomychUTegoUzytkownika].id =  id;
    przyjaciele[IloscZnajomychUTegoUzytkownika].idUzytkownika =  idUzytkownika;
    przyjaciele[IloscZnajomychUTegoUzytkownika].imie =  imie;
    przyjaciele[IloscZnajomychUTegoUzytkownika].nazwisko = nazwisko;
    przyjaciele[IloscZnajomychUTegoUzytkownika].email = email;
    przyjaciele[IloscZnajomychUTegoUzytkownika].nrTelefonu = nrTelefonu;
    przyjaciele[IloscZnajomychUTegoUzytkownika].adres = adres;

    fstream BazaZnajomych;
    BazaZnajomych.open("ListaZnajomych.txt",ios::out | ios::app);
    BazaZnajomych << id << "|";
    BazaZnajomych << idUzytkownika << "|";
    BazaZnajomych << imie << "|";
    BazaZnajomych << nazwisko << "|";
    BazaZnajomych << email << "|";
    BazaZnajomych << nrTelefonu << "|";
    BazaZnajomych << adres << "|";
    BazaZnajomych << endl;
    BazaZnajomych.close();
    cout << "Przyjaciel pomyslnie zapisany" << endl;
    Sleep(1500);
    return IloscZnajomych+1;

}
void wyszukajPoImieniu(vector<Przyjaciel> &przyjaciele,int iloscZnajomych)
{
    int IloscZnalezionychOsob = 0;
    string imie;
    cout << "Podaj imie: ";
    cin >> imie;
    for(int i = 0; i < iloscZnajomych; i++)
    {
        if(przyjaciele[i].imie == imie)
        {
            IloscZnalezionychOsob++;
            cout << "Id: " << przyjaciele[i].id << endl;
            cout << "Imie: " << przyjaciele[i].imie << endl;
            cout << "Nazwisko: " << przyjaciele[i].nazwisko << endl;
            cout << "email: " << przyjaciele[i].email << endl;
            cout << "Nr. telefonu: " << przyjaciele[i].nrTelefonu << endl;
            cout << "Adres: " << przyjaciele[i].adres << endl << endl;
        }
    }
    if(IloscZnalezionychOsob == 0)
    {
        cout << "Nie masz znajomych o podanym imieniu" << endl;
    }
    system("pause");
}
void wyszukajPoNazwisku(vector<Przyjaciel> &przyjaciele,int iloscZnajomych)
{
    int IloscZnalezionychOsob = 0;
    string nazwisko;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    for(int i = 0; i < iloscZnajomych; i++)
    {
        if(przyjaciele[i].nazwisko == nazwisko)
        {
            IloscZnalezionychOsob++;
            cout << "Id: " << przyjaciele[i].id << endl;
            cout << "Imie: " << przyjaciele[i].imie << endl;
            cout << "Nazwisko: " << przyjaciele[i].nazwisko << endl;
            cout << "email: " << przyjaciele[i].email << endl;
            cout << "Nr. telefonu: " << przyjaciele[i].nrTelefonu << endl;
            cout << "Adres: " << przyjaciele[i].adres << endl << endl;
        }
    }
    if(IloscZnalezionychOsob == 0)
    {
        cout << "Nie masz znajomych o podanym nazwisku" << endl;
    }
    system("pause");
}
void wyszukajPrzyjaciela(vector<Przyjaciel> &przyjaciele,int iloscZnajomych)
{
    cout << "wyszukaj po: " << endl;
    cout << "1. Imieniu" << endl;
    cout << "2. Nazwisku" << endl;

    char wybor;
    cin >> wybor;
    switch (wybor)
    {
    case '1':
    {
        wyszukajPoImieniu(przyjaciele,iloscZnajomych);
    }
    break;
    case '2':
    {
        wyszukajPoNazwisku(przyjaciele,iloscZnajomych);
    }
    break;
    default:
        cout << "Nie podales zadnej opcji z Menu" << endl;
        break;
    }
}
void wyswietlWszystkichZnajomych(vector<Przyjaciel> &przyjaciele)
{
    int iloscZnajomych = przyjaciele.size();
    for(int i = 0; i < iloscZnajomych; i++)
    {
        cout << "Id: " << przyjaciele[i].id << endl;
        cout << "Imie: " << przyjaciele[i].imie << endl;
        cout << "Nazwisko: " << przyjaciele[i].nazwisko << endl;
        cout << "email: " << przyjaciele[i].email << endl;
        cout << "Nr. telefonu: " << przyjaciele[i].nrTelefonu << endl;
        cout << "Adres: " << przyjaciele[i].adres << endl << endl;
    }
    system("pause");
}
void edytujDaneZnajomego (vector<Przyjaciel> &przyjaciele, int idUzytkownika)
{
    int id;
    int idPrzyjacielaWPliku;
    int idUzytkownikaWPliku;
    int dlugoscLinii;
    int nrPrzyjaciela;
    int iloscZnajomych = przyjaciele.size() - 1;
    int IloscZnalezionychOsob = 0;
    char wybor;
    cout << "podaj Id znajomego: ";
    cin >> id;
    for(int i = 0; i < iloscZnajomych; i++)
    {
        if(przyjaciele[i].id == id)
        {
            IloscZnalezionychOsob++;
            cout << "Id: " << przyjaciele[i].id << endl;
            cout << "Imie: " << przyjaciele[i].imie << endl;
            cout << "Nazwisko: " << przyjaciele[i].nazwisko << endl;
            cout << "email: " << przyjaciele[i].email << endl;
            cout << "Nr. telefonu: " << przyjaciele[i].nrTelefonu << endl;
            cout << "Adres: " << przyjaciele[i].adres << endl << endl;
            nrPrzyjaciela = i;
        }
    }
    if(IloscZnalezionychOsob == 0)
    {
        cout << "Nie masz znajomych o podanym nr Id" << endl;
        Sleep(1500);
    }
    else
    {
        cout << "Ktora dane chcesz edytowac? " << endl;
        cout << "1. Imie" << endl;
        cout << "2. Nazwisko" << endl;
        cout << "3. Email" << endl;
        cout << "4. Nr. telefonu" << endl;
        cout << "5. Adres" << endl;
        cin>>wybor;

        switch(wybor)
        {
        case '1':
        {
            string noweImie;
            cout << "Podaj nowe imie: " << endl;
            cin>>noweImie;
            przyjaciele[nrPrzyjaciela].imie = noweImie;
            break;
        }
        case '2':
        {
            string noweNazwisko;
            cout << "Podaj nowe Nazwisko: " << endl;
            cin>>noweNazwisko;
            przyjaciele[nrPrzyjaciela].nazwisko = noweNazwisko;
            break;
        }
        case '3':
        {
            string nowyEmail;
            cout << "Podaj nowy email: " << endl;
            cin>>nowyEmail;
            przyjaciele[nrPrzyjaciela].email = nowyEmail;
            break;
        }
        case '4':
        {
            string nowyNrTelefonu;
            cout << "Podaj nowy nr. telefonu: " << endl;
            cin>>nowyNrTelefonu;
            przyjaciele[nrPrzyjaciela].nrTelefonu = nowyNrTelefonu;
            break;
        }

        case '5':
        {
            string nowyAdres;
            cout << "Podaj nowy adres: " << endl;
            cin>>nowyAdres;
            przyjaciele[nrPrzyjaciela].adres = nowyAdres;
            break;
        }
        }
        fstream BazaZnajomych;
        BazaZnajomych.open("ListaZnajomych.txt",ios::in);
        string liniaOdczytywanaZPliku, buforDanych;
        string imie, nazwisko, email, nrTelefonu, adres;
        int nrWystapieniaKreski = 1;
        int pozycjaKreski = 0;
        while(getline(BazaZnajomych,liniaOdczytywanaZPliku))
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
                        idPrzyjacielaWPliku = atoi(buforDanych.c_str());
                        break;
                    case 2:
                        buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                        pozycjaKreski = i + 1;
                        idUzytkownikaWPliku = atoi(buforDanych.c_str());
                        break;
                    case 3:
                        buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                        pozycjaKreski = i+1;
                        imie = buforDanych;
                        break;
                    case 4:
                        buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                        pozycjaKreski = i + 1;
                        nazwisko = buforDanych;
                        break;
                    case 5:
                        buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                        pozycjaKreski = i + 1;
                        email = buforDanych;
                        break;
                    case 6:
                        buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                        pozycjaKreski = i + 1;
                        nrTelefonu = buforDanych;
                        break;
                    case 7:
                        buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                        pozycjaKreski = i + 1;
                        adres = buforDanych;
                        break;
                    }
                    nrWystapieniaKreski ++;
                }
            }
            fstream BazaZnajomychTymczasowa;
            BazaZnajomychTymczasowa.open("ListaZnajomych_Tymczasowa.txt",ios::out | ios::app);
            if (id == idPrzyjacielaWPliku)
            {
                BazaZnajomychTymczasowa << przyjaciele[nrPrzyjaciela].id << "|";
                BazaZnajomychTymczasowa << przyjaciele[nrPrzyjaciela].idUzytkownika << "|";
                BazaZnajomychTymczasowa << przyjaciele[nrPrzyjaciela].imie << "|";
                BazaZnajomychTymczasowa << przyjaciele[nrPrzyjaciela].nazwisko << "|";
                BazaZnajomychTymczasowa << przyjaciele[nrPrzyjaciela].email << "|";
                BazaZnajomychTymczasowa << przyjaciele[nrPrzyjaciela].nrTelefonu << "|";
                BazaZnajomychTymczasowa << przyjaciele[nrPrzyjaciela].adres << "|";
                BazaZnajomychTymczasowa << endl;
            }
            else
            {
                BazaZnajomychTymczasowa << idPrzyjacielaWPliku << "|";
                BazaZnajomychTymczasowa << idUzytkownikaWPliku<< "|";
                BazaZnajomychTymczasowa << imie << "|";
                BazaZnajomychTymczasowa << nazwisko << "|";
                BazaZnajomychTymczasowa << email << "|";
                BazaZnajomychTymczasowa << nrTelefonu << "|";
                BazaZnajomychTymczasowa << adres << "|";
                BazaZnajomychTymczasowa << endl;
            }
            BazaZnajomychTymczasowa.close();
            pozycjaKreski = 0;
            nrWystapieniaKreski = 1;
        }
        BazaZnajomych.close();
        remove("ListaZnajomych.txt");
        rename("ListaZnajomych_Tymczasowa.txt", "ListaZnajomych.txt");
        cout << "Edycja znajomego przebiegla pomyslnie " << endl;
        Sleep(1500);
    }
}
int usunZnajomego (vector<Przyjaciel> &przyjaciele, int iloscZnajomych, int idUzytkownika)
{
    int id;
    char takLubNie;
    int nrPrzyjaciela;
    int IloscZnalezionychOsob;
    cout << "podaj Id znajomego ktorego chcesz usunac: ";
    cin >> id;
    for(int i=0; i < iloscZnajomych; i++)
    {
        if(przyjaciele[i].id == id)
        {
            IloscZnalezionychOsob++;
            cout << "Id: " << przyjaciele[i].id << endl;
            cout << "Imie: " << przyjaciele[i].imie << endl;
            cout << "Nazwisko: " << przyjaciele[i].nazwisko << endl;
            cout << "email: " << przyjaciele[i].email << endl;
            cout << "Nr. telefonu: " << przyjaciele[i].nrTelefonu << endl;
            cout << "Adres: " << przyjaciele[i].adres << endl << endl;
            nrPrzyjaciela = i;
        }
    }
    if(IloscZnalezionychOsob == 0)
    {
        cout << "Nie masz znajomych o podanym nr Id" << endl;
    }
    else
    {
        cout << "Czy napewno chcesz usunac tego znajmoego? wybierz <t/n>" << endl;
        cin >> takLubNie;
        if(takLubNie == 'n')
            return iloscZnajomych;
        else if (takLubNie == 't')
        {
            auto itr = przyjaciele.begin() + id - 1;
            int dlugoscLinii;
            int idPrzyjacielaWPliku;
            int idUzytkownikaWPliku;
            iloscZnajomych -= 1;
            fstream BazaZnajomych;
            BazaZnajomych.open("ListaZnajomych.txt",ios::in);
            string liniaOdczytywanaZPliku, buforDanych;
            string imie, nazwisko, email, nrTelefonu, adres;
            int nrWystapieniaKreski = 1;
            int pozycjaKreski = 0;
            while(getline(BazaZnajomych,liniaOdczytywanaZPliku))
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
                            idPrzyjacielaWPliku = atoi(buforDanych.c_str());
                            break;
                        case 2:
                            buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                            pozycjaKreski = i + 1;
                            idUzytkownikaWPliku = atoi(buforDanych.c_str());
                            break;
                        case 3:
                            buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                            pozycjaKreski = i+1;
                            imie = buforDanych;
                            break;
                        case 4:
                            buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                            pozycjaKreski = i + 1;
                            nazwisko = buforDanych;
                            break;
                        case 5:
                            buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                            pozycjaKreski = i + 1;
                            email = buforDanych;
                            break;
                        case 6:
                            buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                            pozycjaKreski = i + 1;
                            nrTelefonu = buforDanych;
                            break;
                        case 7:
                            buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                            pozycjaKreski = i + 1;
                            adres = buforDanych;
                            break;
                        }
                        nrWystapieniaKreski ++;
                    }
                }
                fstream BazaZnajomychTymczasowa;
                BazaZnajomychTymczasowa.open("ListaZnajomych_Tymczasowa.txt",ios::out | ios::app);
                if (id == idPrzyjacielaWPliku)
                {

                }
                else
                {
                    BazaZnajomychTymczasowa << idPrzyjacielaWPliku << "|";
                    BazaZnajomychTymczasowa << idUzytkownikaWPliku<< "|";
                    BazaZnajomychTymczasowa << imie << "|";
                    BazaZnajomychTymczasowa << nazwisko << "|";
                    BazaZnajomychTymczasowa << email << "|";
                    BazaZnajomychTymczasowa << nrTelefonu << "|";
                    BazaZnajomychTymczasowa << adres << "|";
                    BazaZnajomychTymczasowa << endl;
                }
                BazaZnajomychTymczasowa.close();
                pozycjaKreski = 0;
                nrWystapieniaKreski = 1;
            }
            BazaZnajomych.close();
            przyjaciele.erase(itr);
            remove("ListaZnajomych.txt");
            rename("ListaZnajomych_Tymczasowa.txt", "ListaZnajomych.txt");

            cout << "usuwanie znajomego przebieg³o pomyslnie" << endl;
            Sleep(1500);
            return iloscZnajomych;

        }
        else
            cout << "nie podales zadnej z opcji" << endl;
    }
}
int zarejestruj (vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    PanelLogowania rejestrujacyUzytkownik;
    rejestrujacyUzytkownik.zarejestruj(iloscUzytkownikow);

    uzytkownicy.push_back(Uzytkownik());
    uzytkownicy[iloscUzytkownikow].idUzytkownika = rejestrujacyUzytkownik.idUzytkownika;
    uzytkownicy[iloscUzytkownikow].login = rejestrujacyUzytkownik.login;
    uzytkownicy[iloscUzytkownikow].haslo = rejestrujacyUzytkownik.haslo;

    return iloscUzytkownikow +1;
}
void zaloguj (vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    PanelLogowania logujacyUzytkownik;
    logujacyUzytkownik.zaloguj(iloscUzytkownikow);
    char wybor;
    int idUzytkownika = logujacyUzytkownik.idUzytkownika;

    if (logujacyUzytkownik.czyZalogowano == true)
    {
        vector <Przyjaciel> przyjaciele;
            int IloscZnajomych = 0;
            IloscZnajomych = wczytajDaneZPliku(przyjaciele, idUzytkownika);
            char wybor;
         while (1)
            {
                system("cls");
                cout << "*************** MENU GLOWNE ***************" << endl;
                cout << "1. Zapisz znajomego" << endl;
                cout << "2. Wyszukaj znajomego" << endl;
                cout << "3. Wyswietl wszystkich znajomych" << endl;
                cout << "4. Edytuj dane znajomego" << endl;
                cout << "5. Usun znajomego" << endl;
                cout << "6. Wyloguj" << endl;
                cin >> wybor;

                switch(wybor)
                {
                case '1':
                    IloscZnajomych = dodajPrzyjacielaDoBazy(przyjaciele, IloscZnajomych, idUzytkownika);
                    break;
                case '2':
                    wyszukajPrzyjaciela(przyjaciele, IloscZnajomych);
                    break;
                case '3':
                    wyswietlWszystkichZnajomych(przyjaciele);
                    break;
                case '4':
                    edytujDaneZnajomego(przyjaciele, idUzytkownika);
                    break;
                case '5':
                    IloscZnajomych = usunZnajomego(przyjaciele, IloscZnajomych, idUzytkownika);
                    break;
                case '6':
                    return;
                    break;
                default:
                    cout << "Nie podales zadnej opcji z Menu" << endl;
                    break;
                }
            }
    }
    else
    {
        cout << "Logowanie nie powiodlo sie " << endl;
        Sleep(1500);
    }
}
int main()
{
    vector <Uzytkownik> uzytkownicy;
    char wybor;
    int iloscUzytkownikow = 0;
    iloscUzytkownikow = wczytajDaneZPliku(uzytkownicy);


    while (1)
    {
        system ("cls");
        cout << "1. Logowanie" << endl;
        cout << "2. Rejestracja" << endl;
        cout << "3. Zamknij program" << endl;
        cin >> wybor;
        switch(wybor)
        {
        case '1':
            zaloguj(uzytkownicy, iloscUzytkownikow);
            break;
        case '2':
            iloscUzytkownikow = zarejestruj(uzytkownicy, iloscUzytkownikow);
            break;
        case '3':
            exit(0);
            break;
        default:
            cout << "Nie podales zadnej opcji z Menu" << endl;
            break;
        }

    }
    return 0;
}
