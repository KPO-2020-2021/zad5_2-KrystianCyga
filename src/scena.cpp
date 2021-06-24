#include "../inc/Scena.hh"

#include <algorithm>
#include <vector>
#include <memory>

#define FOLDER_WLASCIWY "BrylyWzorcowe/"
#define FOLDER_ROBOCZY "datasets/"
#define TRASA_PRZELOTU "dat/trasa_przelotu.dat"

bool Scena::wybierz_drona(int numer_drona, PzG::LaczeDoGNUPlota &Lacze)
{

    double Kat;
    int odleglosc;

    std::cout << "Podaj kat lotu drona: ";
    std::cin >> Kat;
    std::cout << std::endl
              << "Podaj odleglosc lotu drona: ";
    std::cin >> odleglosc;
    std::cout << std::endl;

    return Uzyj_drona(numer_drona, Kat, odleglosc, Lacze);
}

bool Scena::Zapis_drona(unsigned int numer_drona, vector3d &polozenie)
{
    Dron newDron;
    std::shared_ptr<Dron> ptrDron = std::make_shared<Dron>();

    ptrDron->Ustaw_polozenie(polozenie);
    newDron.Ustaw_polozenie(polozenie);
    ptrDron->Ustaw_kat(0);
    newDron.Ustaw_kat(0);
    Drony.push_back(newDron);
    Drony[numer_drona].ZbudujDrona();
    Przeszkody.push_back(ptrDron);

    if (!Drony[numer_drona].owektor(numer_drona))
        return false;
    return true;
}

bool Scena::Uzyj_drona(unsigned int numer_drona, double kat, unsigned int odleglosc, PzG::LaczeDoGNUPlota &Lacze)
{
    std::string wlasciwy = FOLDER_WLASCIWY;
    std::string roboczy = FOLDER_ROBOCZY;
    for (unsigned int index = 0; index < liczba_dronow; ++index)
    {
        std::string sciezka_korpusu = wlasciwy + "Dron_" + std::to_string(index) + "_Korpus_.dat";
        const char *ptr_sciezka_korpusu = sciezka_korpusu.c_str();
        Lacze.DodajNazwePliku(ptr_sciezka_korpusu);
        for (int id_rotora = 0; id_rotora < 4; ++id_rotora)
        {
            std::string sciezka_rotora = wlasciwy + "Dron_" + std::to_string(index) + "_Rotor_" + std::to_string(numer_drona) + ".dat";
            const char *ptr_sciezka_rotora = sciezka_rotora.c_str();
            Lacze.DodajNazwePliku(ptr_sciezka_rotora);
        }
    }

    if (!Drony[numer_drona].owektor(numer_drona))
        return false;
    Lacze.Rysuj();

    if (!Drony[numer_drona].LotDrona(kat, 50, odleglosc, numer_drona, Lacze))
        return false;
    return true;
}

void Scena::Dodaj_Przeszkody(PzG::LaczeDoGNUPlota &Lacze)
{

    int wybor;
    vector3d pozycja, skala;
    double kat = 0;
    std::shared_ptr<brylageo> ptr_bryla;

    std::cout << "Jaka przeszkode chcialbys dodac?" << std::endl;
    std::cout << "1. Gora z ostrym szczytem" << std::endl;
    std::cout << "2. Gora z grania" << std::endl;
    std::cout << "3. Wyzyna ze stokiem" << std::endl
              << std::endl;
    std::cin >> wybor;
    std::cout << "Podaj współrzędne OX, OY, OZ przeszkody:" << std::endl
              << std::endl;
    std::cin >> pozycja;
    std::cout << "Podaj skale przeszkody OX, OY, OZ :" << std::endl
              << std::endl;
    std::cin >> skala;

    switch (wybor)
    {
    case 1:
        ptr_bryla = std::make_shared<stozek>(Lacze, pozycja, kat, skala);
        break;
    case 2:
        ptr_bryla = std::make_shared<gran_bryla>(Lacze, pozycja, kat, skala);
        break;
    case 3:
        ptr_bryla = std::make_shared<wyzyna>(Lacze, pozycja, kat, skala);
        break;

    default:
        std::cout << "Wybrales bledna opcje - sprobuj jeszcze raz" << std::endl;
        break;
    }
    Przeszkody.push_front(ptr_bryla);
    Lacze.Rysuj();
}

void Scena::Usun_Przeszkody(PzG::LaczeDoGNUPlota &Lacze)
{

    std::list<std::shared_ptr<Obiekt>> ptr_przeszkody;
    std::shared_ptr<Obiekt> ptrBryla = std::make_shared<Obiekt>();
    ptr_przeszkody = Przeszkody;
    long unsigned int wybor;
    std::cout << "Wybierz figure do usuniecia : " << std::endl;
    for (int i = 0; i < (int)Przeszkody.size(); i++)
    {
        std::cout << i + 1 << ". ";
        ptrBryla = ptr_przeszkody.front();
        ptrBryla.get()->InfoObiektu();
        ptr_przeszkody.pop_front();
    }
    ptr_przeszkody = Przeszkody;
    std::cout << std::endl;
    std::cin >> wybor;

    for (long unsigned int index = 1; index < wybor; index++)
    {
        ptr_przeszkody.pop_front();
    }
    Przeszkody.remove(ptr_przeszkody.front());
    Lacze.UsunNazwePliku(ptr_przeszkody.front().get()->dajNazweWyjsciowego());
    Lacze.Rysuj();
    remove(ptr_przeszkody.front().get()->dajNazweWyjsciowego().c_str());
}

int Scena::Menu(PzG::LaczeDoGNUPlota &Lacze)
{
    Lacze.Rysuj();
    return 1;
}
