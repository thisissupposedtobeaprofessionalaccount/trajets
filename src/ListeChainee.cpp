/*************************************************************************
                           Liste Chainee  -  description
                             -------------------
    début                : 26/11/2024
    copyright            : (C) 2024 par Dan Maria-Andrada et Marin Hugo
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp)
//------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cell.h"
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Cell *ListeChainee::getHead() const
// Algorithme :
//
{
  return head;
} //----- Fin de getHead

void ListeChainee::setHead(Cell *h)
// Algorithme :
//
{
  head = h;
} //----- Fin de setHead

void ListeChainee::afficher()
// Algorithme:
//
{
  Cell *temp = head;

  if (head == nullptr) {
    std::cout << "List is empty" << std::endl;
    return;
  }

  while (temp != nullptr) {
    std::cout << temp->getData() << " ";
    temp = temp->getNext();
  }
    std::cout <<std::endl;

} //----- Fin d'Afficher

void ListeChainee::insertAtTail(int value)
// Algorithme :
//
{
  Cell *newCell = new Cell(value);
  if (head == nullptr) {
    setHead(newCell);
    return;
  }
  Cell *temp = head;
  while (temp->getNext() != nullptr) {
    temp = temp->getNext();
  }
  temp->setNext(newCell);
} //----- Fin d'insertAtTail

void ListeChainee::insertAtHead(int value)
// Algorithme :
//
{
  Cell *newCell = new Cell(value);
  newCell->setNext(head);
  head = newCell;
} //----- Fin d'insertAtHead

int ListeChainee::deleteCell(int value)
// Algorithme :
{
  if (head == nullptr)
    return 0;
  if (head->getData() == value) {
    Cell* tmp = head;
    head = tmp->getNext();
    delete tmp;
    return 1;
  }

  Cell *current = head;
  while (current->getNext() != nullptr && current->getNext()->getData() != value) {
    current = current->getNext();
  }

  if (current->getNext() == nullptr)
    return 0;

  Cell * toDelete = current->getNext();
  Cell *after = toDelete->getNext();
  current->setNext(after);
  delete toDelete;

  return 1;
} //----- Fin de deleteCell

void ListeChainee::freeList()
// Algorithme :
// While the list is not empty we store the current head, move the head to the
// next node and then free the current node
{
  Cell *temp;
  while (head != nullptr) {
    temp = head;
    head = head->getNext();
    delete temp;
  }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/*Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =*/

//-------------------------------------------- Constructeurs - destructeur
ListeChainee::ListeChainee()
    : head(nullptr)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ListeChainee

ListeChainee::~ListeChainee()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
  freeList();
} //----- Fin de ~ListeChainee

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
