#pragma once

#include "brylageo.hh"

/*!
 * \file
 * \brief Plik zawiera definicję klasy Gora
 */

class gora : public brylageo
{
public:
    bool ZbudujGore();

    gora(){};

    gora(PzG::LaczeDoGNUPlota &Lacze, vector3d polozenie, double kat_orien, vector3d Skala) : brylageo(polozenie, kat_orien, Skala)
    {
        ZbudujGore();
        NazwaWyjsciowego = dajNazweWyjsciowego();
        const char *ptrNazwa = NazwaWyjsciowego.c_str();
        Lacze.DodajNazwePliku(ptrNazwa);
        ++NumerBryly;
    }

    void WyswietlInfo();
};