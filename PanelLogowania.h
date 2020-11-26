#include <iostream>
#include <vector>

using namespace std;

class PanelLogowania
{
    public:
    string login, haslo;
    int idUzytkownika;
    bool czyZalogowano;
    void zarejestruj (int);
    void zaloguj (int);
};
