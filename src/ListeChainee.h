/*************************************************************************
                           Liste Chainee  -  description
                             -------------------
    debut                : 26/11/2024
    copyright            : (C) 2024 par Dan Maria-Andrada et Marin Hugo
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Liste Chainee> (fichier ListeChainee.h)
//----------------
#include <iostream>
#if !defined(LISTECHAINEE_H)
#define LISTECHAINEE_H

#include "Cell.h"

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Liste Chainee>
//
//
//------------------------------------------------------------------------

template <typename T>
class ListeChainee {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Methodes publiques
  // type Methode ( liste des parametres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  Cell<T> *getHead() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  void afficher();
  // Mode d'emploi:
  //  Firstly checks if the list is NULL
  //  While the list is not NULL it prints the value of the element then it goes
  //  to the next position
  // Contrat:
  //

  void insertAtTail(T value);
  // Mode d'emploi:
  //  creates a new node of the value, makes the head of the list be the new
  //  node and then t
  // Contrat:
  //
  void insertAtHead(T value);
  // Mode d'emploi:
  //  creates a new node of the value, makes the head of the list be the new
  //  node and then t
  // Contrat:
  //

  int deleteCell(T value);
  // Mode d'emploi:
  //  checks if list is empty then checks if the node we want to delete is the
  //  first node if not, we check while the list is not NULL we also check if
  //  the element has not been found at all
  // Contrat:
  //

  int deleteAllCell(T value);
  // Mode d'emploi:
  //  checks if list is empty then checks if the node we want to delete is the
  //  first node if not, we check while the list is not NULL we also check if
  //  the element has not been found at all
  // Contrat:

  //-------------------------------------------- Constructeurs - destructeur
  ListeChainee();
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~ListeChainee();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Methodes protegees
  void setHead(Cell<T> *h);
  // Mode d'emploi :
  //
  // Contrat :
  //
  void freeList();
  // Mode d'emploi:
  //  frees the entire linked list
  // Contrat:
  //


  //----------------------------------------------------- Attributs proteges
  Cell<T> *head;
};

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
    std::cout << *temp->getData() << " ";
    temp = temp->getNext();
  }
    std::cout <<std::endl;

} //----- Fin d'Afficher

template <typename T> 
void ListeChainee<T>::insertAtTail(T value)
// Algorithme :
{
  Cell<T> *newCell = new Cell<T>(value);
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
  if (*head->getData() == value) {
    Cell<T>* tmp = head;
    head = tmp->getNext();
    delete tmp;
    return 1;
  }

  Cell<T> *current = head;
  while (current->getNext() != nullptr && *current->getNext()->getData() != value) {
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
int ListeChainee<T>::deleteAllCell(T value){
  if (head == nullptr) return 0;
  Cell<T> *previous = head;
  Cell<T> *current = head->getNext();

  while(current != nullptr){
    if (current == value){
      previous->setNext(current->getNext());
      delete current;
    }
    current = previous->getNext()->getNext();
    previous = previous->getNext();
  }

  return 1;
}


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

//-------------------------------- Autres definitions dependantes de
//<ListeChainee>

#endif // LISTECHAINEE_H
