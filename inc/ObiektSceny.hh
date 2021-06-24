#pragma once

#include "Vector3d.hh"
#include "matrix.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \file
 * \brief Ten plik zawiera definicję klasy Obiekt
 */

class Obiekt
{
protected:
    std::string NazwaWzorcowego;
    std::string NazwaWyjsciowego;

public:
    
    virtual void InfoObiektu(){};

    virtual std::string dajNazweWyjsciowego() { return NazwaWzorcowego; };
    virtual std::string dajNazweWzorcowego() { return NazwaWyjsciowego; };
    
};