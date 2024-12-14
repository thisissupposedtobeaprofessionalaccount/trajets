#include "Cell.h"

Trajet *Cell::getDonnee() const
// Algorithme :
//
{
  return donnee;
} //----- Fin de getData

void Cell::setData( Trajet *d)
// Algorithme :
//
{
  donnee = d;
} //----- Fin de setData

Cell *Cell::getSuivante() const
// Algorithme :
//
{
  return suivante;
} //----- Fin de getNext

void Cell::setSuivante(Cell *n)
// Algorithme :
//
{
  suivante = n;
} //----- Fin de setNext

//------------------------------------------------- Surcharge d'opérateurs
/*Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =*/

//-------------------------------------------- Constructeurs - destructeur
Cell::Cell()
// Algorithme :
//
{
#ifdef MAP
  std::cout << "Appel au constructeur de <Cell>" << std::endl;
#endif
  donnee = 0;
  suivante = nullptr;
} //----- Fin de Cell

Cell::Cell( Trajet *valeur) //: data(value)
// Algorithme :
//
{
#ifdef MAP
  std::cout << "Appel au constructeur de <Cell>" << std::endl;
#endif

  this->donnee = valeur;
  this->suivante = nullptr;
} //----- Fin de Cell

Cell::~Cell()
// Algorithme :
//
{
#ifdef MAP
  std::cout << "Appel au destructeur de <Cell>" << std::endl;
#endif
} //----- Fin de ~Cell
