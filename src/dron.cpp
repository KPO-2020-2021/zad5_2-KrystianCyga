#include "../inc/dron.hh"

#define FOLDER_WLASCIWY "BrylyWzorcowe/"
#define FOLDER_ROBOCZY "datasets/"
#define WZORZEC_SZESCIAN "BrylyWzorcowe/szescian.dat"
#define WZORZEC_ROTOR "BrylyWzorcowe/graniastoslup6.dat"
#define TRASA_PRZELOTU "../datasets/trasa_przelotu.dat"

bool Dron::ZbudujDrona()
{

  static double KatObrotuRotora_st = 0;
  vector3d VekTrans[4];
  vector3d Pocz_Podniesienie;

  VekTrans[0][0] = 5;
  VekTrans[0][1] = 4;
  VekTrans[0][2] = 5;

  VekTrans[1][0] = 5;
  VekTrans[1][1] = -4;
  VekTrans[1][2] = 5;

  VekTrans[2][0] = -5;
  VekTrans[2][1] = 4;
  VekTrans[2][2] = 5;

  VekTrans[3][0] = -5;
  VekTrans[3][1] = -4;
  VekTrans[3][2] = 5;

  Pocz_Podniesienie[0] = 0;
  Pocz_Podniesienie[1] = 0;
  Pocz_Podniesienie[2] = 2;

  if (czy_aktywny == false)
  {
    if (!Korpus.ZbudujKorpus(Orientacja_drona, Pocz_Podniesienie))
      return false;
  }
  for (int Numer_rot = 0; Numer_rot < 4; ++Numer_rot)
  {
    if (!Rotor[Numer_rot].ZbudujRotor(Numer_rot, KatObrotuRotora_st, VekTrans[Numer_rot]))
      return false;
  }

  czy_aktywny = true;
  KatObrotuRotora_st += 15;

  return true;
}

bool Dron::owektor(unsigned int numer_drona)
{
  if (!ZbudujDrona())
    return false;

  std::string wzorzec_folder = FOLDER_WLASCIWY;
  std::string sciezka_korpusu = wzorzec_folder + "Dron_" + std::to_string(numer_drona) + "_Korpus_.dat";

  Korpus.ustaw_kat(Orientacja_drona);
  Korpus.ustaw_trans(PolozenieD);
  Korpus.pobierz_nazwe_final(sciezka_korpusu);
  if (!Korpus.zapiszbryle())
    return false;

  for (int numer_rotora = 0; numer_rotora < 4; ++numer_rotora)
  {
    Rotor[numer_rotora].ustaw_kat(Orientacja_drona);
    Rotor[numer_rotora].ustaw_trans(PolozenieD);
    std::string sciezka_rotora = wzorzec_folder + "Dron_" + std::to_string(numer_drona) + "_Rotor_" + std::to_string(numer_rotora) + ".dat";
    Rotor[numer_rotora].pobierz_nazwe_final(sciezka_rotora);
    if (!Rotor[numer_rotora].zapiszbryle())
      return false;
  }
  return true;
}

