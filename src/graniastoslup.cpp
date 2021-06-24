#pragma once

#include "brylageo.hh"

/*!
 * \file
 * \brief Plik zawiera definicję klasy graniastoslupa
 */

class graniastoslup : public brylageo
{
public:
  bool ZbudujRotor(unsigned int Numer_Rotora, double Kat_Obrotu, vector3d VekTrans);
  void ObrocRotor(unsigned int Numer_Rotora, double Kat_Obrotu);
};