#include "../inc/brylageo.hh"
#define ILOSC_WIERZ_LINII_TWORZACEJ 4

#define FOLDER_WLASCIWY "BrylyWzorcowe/"
#define FOLDER_ROBOCZY "datasets/"
#define WZORZEC_SZESCIAN "BrylyWzorcowe/szescian.dat"
#define WZORZEC_ROTOR "BrylyWzorcowe/graniastoslup6.dat"
#define LICZBA_ROTOROW 4

brylageo::brylageo(){
    skala[0] = 1;
    skala[1] = 1;
    skala[2] = 2;
}

brylageo::brylageo(vector3d polozenie,double kat,const vector3d skala2)
{
    skala = skala2;
    trans = polozenie;
    Orientacji_stopnie = kat;
}

void brylageo::skaluj(vector3d &skala2){
  skala2[0] *= skala[0];
  skala2[1] *= skala[1];
  skala2[2] *= skala[2];
}

void brylageo::ObrocWzgledemOsiOZ(double kat, vector3d &Polozenie)
{
  vector3d wynik;
  double rad = kat * M_PI / 180;
  wynik[0] = Polozenie[0] * cos(rad) - Polozenie[1] * sin(rad);
  wynik[1] = Polozenie[0] * sin(rad) + Polozenie[1] * cos(rad);
  Polozenie[0] = wynik[0];
  Polozenie[1] = wynik[1];
}