#include "ListeChainee.h"

const Cell *ListeChainee::getHead() const
// Algorithme :
//
{
  return head;
} //----- Fin de getHead


void ListeChainee::setHead( Cell *h)
// Algorithme :
//
{
  head = h;
} //----- Fin de setHead


void ListeChainee::afficher(const char * prefix) const 
// Algorithme:
//
{
  Cell *current = head;

  if (head == nullptr) {
    return;
  }

  while (current != nullptr) {
    current->getData()->afficher(prefix);
    current = current->getNext();
  }

} //----- Fin d'Afficher


void ListeChainee::insertAtTail( Trajet* value)
// Algorithme :
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


void ListeChainee::insertAtHead( Trajet* value)
// Algorithme :
//
{
  Cell *newCell = new Cell(value);
  newCell->setNext(head);
  head = newCell;
} //----- Fin d'insertAtHead


int ListeChainee::deleteCell(const Trajet& value)
// Algorithme :
{
  if (head == nullptr)
    return 0;
  if (*head->getData() == value) {
    Cell* tmp = head;
    head = tmp->getNext();
    delete tmp;
    return 1;
  }

  Cell *current = head;
  while (current->getNext() != nullptr && *current->getNext()->getData() != value) {
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


int ListeChainee::deleteAllCell(const Trajet& value){
  if (head == nullptr) return 0;
  Cell *previous = head;
  Cell *current = head->getNext();

  while(current != nullptr){
    if (current->getData()->getTitre() == value.getTitre()){
      previous->setNext(current->getNext());
      delete current;
    }
    current = previous->getNext()->getNext();
    previous = previous->getNext();
  }

  return 1;
}



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
  std::cout << "Appel au constructeur de <ListeChainee>" << std::endl;
#endif
} //----- Fin de ListeChainee


ListeChainee::~ListeChainee()
// Algorithme :
//
{
#ifdef MAP
  std::cout << "Appel au destructeur de <ListeChainee>" << std::endl;
#endif
  freeList();
} //----- Fin de ~ListeChainee

//-------------------------------- Autres definitions dependantes de
//<ListeChainee>

