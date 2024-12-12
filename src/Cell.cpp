#include "Cell.h"
#include <iostream>

Trajet *Cell::getData() const
// Algorithme :
//
{
  return data;
} //----- Fin de getData

void Cell::setData( Trajet *d)
// Algorithme :
//
{
  data = d;
} //----- Fin de setData

Cell *Cell::getNext() const
// Algorithme :
//
{
  return next;
} //----- Fin de getNext

void Cell::setNext(Cell *n)
// Algorithme :
//
{
  next = n;
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
  data = 0;
  next = nullptr;
} //----- Fin de Cell

Cell::Cell( Trajet *value) //: data(value)
// Algorithme :
//
{
#ifdef MAP
  std::cout << "Appel au constructeur de <Cell>" << std::endl;
#endif

  this->data = value;
  this->next = nullptr;
} //----- Fin de Cell

Cell::~Cell()
// Algorithme :
//
{
#ifdef MAP
  std::cout << "Appel au destructeur de <Cell>" << std::endl;
#endif
} //----- Fin de ~Cell
