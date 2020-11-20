#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct Przyjaciel
{
    int id;
    string imie,nazwisko,email,nrTelefonu,adres;

};
int wczytajDaneZPliku (vector<Przyjaciel> &przyjaciele)
{
    fstream BazaZnajomych;
    string liniaOdczytywanaZPliku;
    string buforDanych;
    int dlugoscLinii;
    int nrWystapieniaKreski = 1;
    int nrLinii = 1;
    int pozycjaKreski = 0;
    int nrPrzyjaciela = 0;
    BazaZnajomych.open("ListaZnajomych.txt",ios::in);
    if(BazaZnajomych.good() == false)
    {
        return 0;
    }
    while(getline(BazaZnajomych,liniaOdczytywanaZPliku))
    {
        przyjaciele.push_back(Przyjaciel());
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
                    przyjaciele[nrPrzyjaciela].id = atoi(buforDanych.c_str());
                    break;
                case 2:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i+1;
                    przyjaciele[nrPrzyjaciela].imie = buforDanych;
                    break;
                case 3:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    przyjaciele[nrPrzyjaciela].nazwisko = buforDanych;
                    break;
                case 4:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    przyjaciele[nrPrzyjaciela].email = buforDanych;
                    break;
                case 5:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    przyjaciele[nrPrzyjaciela].nrTelefonu = buforDanych;
                    break;
                case 6:
                    buforDanych = liniaOdczytywanaZPliku.substr(pozycjaKreski,i - pozycjaKreski);
                    pozycjaKreski = i + 1;
                    przyjaciele[nrPrzyjaciela].adres = buforDanych;
                    break;
                }
                nrWystapieniaKreski ++;
            }
        }
        pozycjaKreski = 0;
        nrWystapieniaKreski = 1;
        nrPrzyjaciela ++;
    }
    BazaZnajomych.close();
    return nrPrzyjaciela;

}
int dodajPrzyjacielaDoBazy(vector<Przyjaciel> &przyjaciele,int IloscZnajomych)
{
    string imie, nazwisko, email, nrTelefonu, adres;
    int id = IloscZnajomych + 1;
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

    przyjaciele.push_back(Przyjaciel());
    przyjaciele[IloscZnajomych].id =  id;
    przyjaciele[IloscZnajomych].imie =  imie;
    przyjaciele[IloscZnajomych].nazwisko = nazwisko;
    przyjaciele[IloscZnajomych].email = email;
    przyjaciele[IloscZnajomych].nrTelefonu = nrTelefonu;
    przyjaciele[IloscZnajomych].adres = adres;

    fstream BazaZnajomych;
    BazaZnajomych.open("ListaZnajomych.txt",ios::out | ios::app);
    BazaZnajomych << id << "|";
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
void wyswietlWszystkichZnajomych(vector<Przyjaciel> &przyjaciele,int iloscZnajomych)
{
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
void edytujDaneZnajomego (vector<Przyjaciel> &przyjaciele, int iloscZnajomych)
{
    int id;
    int IloscZnalezionychOsob;
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
        }
    }
    if(IloscZnalezionychOsob == 0)
    {
        cout << "Nie masz znajomych o podanym nr Id" << endl;
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

        id-=1;
        switch(wybor)
        {
        case '1':
        {
            string noweImie;
            cout << "Podaj nowe imie: " << endl;
            cin>>noweImie;
            przyjaciele[id].imie = noweImie;
            break;
        }
        case '2':
        {
            string noweNazwisko;
            cout << "Podaj nowe Nazwisko: " << endl;
            cin>>noweNazwisko;
            przyjaciele[id].nazwisko = noweNazwisko;
            break;
        }
        case '3':
        {
            string nowyEmail;
            cout << "Podaj nowy email: " << endl;
            cin>>nowyEmail;
            przyjaciele[id].email = nowyEmail;
            break;
        }
        case '4':
        {
            string nowyNrTelefonu;
            cout << "Podaj nowy nr. telefonu: " << endl;
            cin>>nowyNrTelefonu;
            przyjaciele[id].nrTelefonu = nowyNrTelefonu;
            break;
        }

        case '5':
        {
            string nowyAdres;
            cout << "Podaj nowy adres: " << endl;
            cin>>nowyAdres;
            przyjaciele[id].adres = nowyAdres;
            break;
        }
        }
        fstream BazaZnajomych;
        BazaZnajomych.open("ListaZnajomych.txt",ios::out);
        for (int i = 0; i < iloscZnajomych; i++)
        {
            BazaZnajomych << przyjaciele[i].id << "|";
            BazaZnajomych << przyjaciele[i].imie << "|";
            BazaZnajomych << przyjaciele[i].nazwisko << "|";
            BazaZnajomych << przyjaciele[i].email << "|";
            BazaZnajomych << przyjaciele[i].nrTelefonu << "|";
            BazaZnajomych << przyjaciele[i].adres << "|";
            BazaZnajomych << endl;
        }
        BazaZnajomych.close();
    }
}
int usunZnajomego (vector<Przyjaciel> &przyjaciele, int iloscZnajomych)
{
    int id;
    char takLubNie;
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
            przyjaciele.erase(itr);
            iloscZnajomych -= 1;
            fstream BazaZnajomych;
            BazaZnajomych.open("ListaZnajomych.txt",ios::out);
            for (int i = 0; i < iloscZnajomych; i++)
            {
                BazaZnajomych << przyjaciele[i].id << "|";
                BazaZnajomych << przyjaciele[i].imie << "|";
                BazaZnajomych << przyjaciele[i].nazwisko << "|";
                BazaZnajomych << przyjaciele[i].email << "|";
                BazaZnajomych << przyjaciele[i].nrTelefonu << "|";
                BazaZnajomych << przyjaciele[i].adres << "|";
                BazaZnajomych << endl;
            }
            BazaZnajomych.close();
            return iloscZnajomych;

        }
        else
            cout << "nie podales zadnej z opcji" << endl;
    }
}
int main()
{
    vector <Przyjaciel> przyjaciele;
    char wybor;
    int IloscZnajomych = 0;
    IloscZnajomych = wczytajDaneZPliku(przyjaciele);

    while (1)
    {
        system("cls");
        cout << "*************** MENU GLOWNE ***************" << endl;
        cout << "1. Zapisz znajomego" << endl;
        cout << "2. Wyszukaj znajomego" << endl;
        cout << "3. Wyswietl wszystkich znajomych" << endl;
        cout << "4. Edytuj dane znajomego" << endl;
        cout << "5. Usun znajomego" << endl;
        cout << "6. Wyjdz" << endl;
        cin >> wybor;

        switch(wybor)
        {
        case '1':
            IloscZnajomych = dodajPrzyjacielaDoBazy(przyjaciele, IloscZnajomych);
            break;
        case '2':
            wyszukajPrzyjaciela(przyjaciele, IloscZnajomych);
            break;
        case '3':
            wyswietlWszystkichZnajomych(przyjaciele, IloscZnajomych);
            break;
        case '4':
            edytujDaneZnajomego(przyjaciele, IloscZnajomych);
            break;
        case '5':
            IloscZnajomych = usunZnajomego(przyjaciele, IloscZnajomych);
            break;
        case '6':
            exit(0);
            break;
        default:
            cout << "Nie podales zadnej opcji z Menu" << endl;
            break;
        }
    }
    return 0;
}
