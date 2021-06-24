#pragma once

#include "Vector3d.hh"
#include "matrix.hh"
#include "Obiekt.hh"
#include "lacze_do_gnuplota.hh"


class brylageo: public Obiekt
{
protected:
/*! 
* \brief Skala figury w postaci wektora
*/
vector3d skala,trans;
std::vector<vector3d> wierzcholki;

double Orientacji_stopnie;

unsigned int NumerWierzcholka;
unsigned int NumerBryly;

public:

/*!
 * \brief Konstruktor bezparamereyczny klasy brylageo
 * ustawia nazwy na null
 * skale na 1,1,1
 */
brylageo();
/*!
 * \brief Konstruktor paramereyczny klasy brylageo
 *      \param[in] polozenie- Vector3D zawierajacy polozenie bryly
 *      \param[in] kat - kat orientacji bryly 
 *      \param[in] skala -  skala z klasy brylageo
 *      \post Ustawia nazwy na odpowiednie podane przez uzytkownika
 */
brylageo(vector3d polozenie,double kat,const vector3d skala2);
/*!
 *  \brief Metoda zapisujaca skale                                            
 *                                                     
 *      \param[in] skala - Vector3D zawierajacy skale                                                                 
 *                                                                        
 *     \post Zmiana skali na te podana przez uzytkownika                                
 */
void skaluj(vector3d &skala);
/*!
 *  \brief Metoda zapisujaca nazwe pliku wzorcowego bryly                                            
 *                                                                    
 *      \param[in] nazwa1 - nazwa pliku                                                     
 *                                                                        
 *     \post Zmiana NazwaPlikubryluWzorc na ta podana przez uzytkownika                                
 */
void pobierz_nazwe_wzorca(const std::string &nazwa1);
/*!
 *  \brief Metoda zapisujaca nazwe pliku finalnej bryly                                            
 *                                                                    
 *      \param[in] nazwa2 - nazwa pliku  bryly finalnej                                                   
 *                                                                        
 *     \post Zmiana NazwaPlikubryluWzorc na ta podana przez uzytkownika                                
 */
void pobierz_nazwe_final(const std::string &nazwa2);

bool wczytajbryle();
bool zapiszbryle();
/*!
 * \brief Dokonuje rotacji wzgledem OZ
 *
 * Przeksztalca \p x i \p y dokonujac obrot o zadany kat.
 * 
 * \param[in] KatObrotu_st - kat obrotu
 * \param[in,out] Polozenie - wspolrzedne punktu
 */
void ObrocWzgledemOsiOZ(double KatObrotu_st, vector3d &Polozenie);
void TransformujWspolrzednePunktu(vector3d &Polozenie);

void Skaluj(vector3d &Polozenie);
/*!
 *  \brief Metoda ustawiajaca kat orientacji                                           
 *  \param[in] kat kat orientacji                                                                                              
 */
void ustaw_kat(double kat){Orientacji_stopnie=kat;};
/*!
 *  \brief Metoda ustawiajaca wektor translacji                                            
 *     \param[in] Polozenie wektor translacji                                                                                              
 */
void ustaw_trans(vector3d Polozenie){trans=Polozenie;};
/*!
 *  \brief Metoda zwracajaca wektor translacji                                            
 *     \return wektor translacji                                                                                              
 */
vector3d daj_trans(){return trans;}
};