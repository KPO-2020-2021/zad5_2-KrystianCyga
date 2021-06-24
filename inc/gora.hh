#pragma once

#include "brylageo.hh"

/*!
 * \file
 * \brief Ten plik zawiera definicję klasy Gora
 */

class gora : public brylageo
{
public:
    bool ZbudujGore();

    gora(){};

    gora(PzG::LaczeDoGNUPlota &Lacze, vector3d PolBryly, double newKatOrientacji_st, vector3d newSkala) : brylageo(PolBryly, newKatOrientacji_st, newSkala)
    {
        ZbudujGore();
        NazwaWyjsciowego = dajNazweWyjsciowego();
        const char *ptrNazwa = NazwaWyjsciowego.c_str();
        Lacze.DodajNazwePliku(ptrNazwa);
        ++NumerBryly;
    }

    void WyswietlInfo();
};