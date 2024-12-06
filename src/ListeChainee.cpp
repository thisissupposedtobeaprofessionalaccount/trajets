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

template <typename T> 
Cell<T> *ListeChainee<T>::getHead() const
// Algorithme :
//
{
  return head;
} //----- Fin de getHead

template <typename T> 
void ListeChainee<T>::setHead(Cell<T> *h)
// Algorithme :
//
{
  head = h;
} //----- Fin de setHead

template <typename T> 
void ListeChainee<T>::afficher()
// Algorithme:
//
{
  Cell<T> *temp = head;

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

template <typename T> 
void ListeChainee<T>::insertAtTail(T value)
// Algorithme :
//
{
  Cell<T> *newCell = new Cell(value);
  if (head == nullptr) {
    setHead(newCell);
    return;
  }
  Cell<T> *temp = head;
  while (temp->getNext() != nullptr) {
    temp = temp->getNext();
  }
  temp->setNext(newCell);
} //----- Fin d'insertAtTail

template <typename T> 
void ListeChainee<T>::insertAtHead(T value)
// Algorithme :
//
{
  Cell<T> *newCell = new Cell<T>(value);
  newCell->setNext(head);
  head = newCell;
} //----- Fin d'insertAtHead

template <typename T> 
int ListeChainee<T>::deleteCell(T value)
// Algorithme :
{
  if (head == nullptr)
    return 0;
  if (head->getData() == value) {
    Cell<T>* tmp = head;
    head = tmp->getNext();
    delete tmp;
    return 1;
  }

  Cell<T> *current = head;
  while (current->getNext() != nullptr && current->getNext()->getData() != value) {
    current = current->getNext();
  }

  if (current->getNext() == nullptr)
    return 0;

  Cell<T> * toDelete = current->getNext();
  Cell<T> *after = toDelete->getNext();
  current->setNext(after);
  delete toDelete;

  return 1;
} //----- Fin de deleteCell

template <typename T> 
void ListeChainee<T>::freeList()
// Algorithme :
// While the list is not empty we store the current head, move the head to the
// next node and then free the current node
{
  Cell<T> *temp;
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
template <typename T> 
ListeChainee<T>::ListeChainee()
    : head(nullptr)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ListeChainee

template <typename T> 
ListeChainee<T>::~ListeChainee()
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
