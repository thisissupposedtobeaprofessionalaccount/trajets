/*************************************************************************
                           Cell  -  description
                             -------------------
    début                : 26/11/2024
    copyright            : (C) 2024 par Dan Maria-Andrada et Marin Hugo
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Cell> (fichier Cell.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cell.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int Cell::getData() const
// Algorithme :
//
{
    return data;
} //----- Fin de getData

void Cell::setData(int d)
// Algorithme :
//
{
    data = d;
} //----- Fin de setData

Cell* Cell::getNext() const
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
Cell::Cell ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
    data = 0;
    next = nullptr;
} //----- Fin de Cell

Cell::Cell (int value) //: data(value)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
    this->data = value;
    this->next = nullptr;
} //----- Fin de Cell

Cell::~Cell()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cell>" << endl;
#endif
} //----- Fin de ~Cell

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
