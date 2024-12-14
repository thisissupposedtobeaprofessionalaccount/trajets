#include "ListeChainee.h"

ListeChainee *ListeChainee::rechercheSimple(const char *villeDepart,
                                            const char *villeArrivee) const {
  Trajet aTrouver = Trajet("", villeDepart, villeArrivee, voiture);

  Cell *courante = tete;
  ListeChainee *listeResultat = new ListeChainee;
  Trajet* aAjouter;

  while (courante != nullptr) {
    if (*courante->getDonnee() == aTrouver) {
      aAjouter = new Trajet(*courante->getDonnee());
      listeResultat->insererEnQueue(aAjouter);
    }
    courante = courante->getSuivante();
  }

  return listeResultat;
}

const Cell *ListeChainee::getTete() const
// Algorithme :
//
{
  return tete;
} //----- Fin de getHead

void ListeChainee::setTete(Cell *h)
// Algorithme :
//
{
  tete = h;
} //----- Fin de setHead

void ListeChainee::afficher(const char *prefix) const
// Algorithme:
//
{
  Cell *courante = tete;

  if (tete == nullptr) {
    return;
  }

  while (courante != nullptr) {
    courante->getDonnee()->afficher(prefix);
    courante = courante->getSuivante();
  }

} //----- Fin d'Afficher

void ListeChainee::insererEnQueue(Trajet *valeur)
// Algorithme :
{
  Cell *newCell = new Cell(valeur);
  if (tete == nullptr) {
    setTete(newCell);
    return;
  }
  Cell *temp = tete;
  while (temp->getSuivante() != nullptr) {
    temp = temp->getSuivante();
  }
  temp->setSuivante(newCell);
} //----- Fin d'insertAtTail

void ListeChainee::insererEnTete(Trajet *value)
// Algorithme :
//
{
  Cell *newCell = new Cell(value);
  newCell->setSuivante(tete);
  tete = newCell;
} //----- Fin d'insertAtHead

int ListeChainee::supprimerCell(const Trajet &value)
// Algorithme :
{
  if (tete == nullptr)
    return 0;
  if (*tete->getDonnee() == value) {
    Cell *tmp = tete;
    tete = tmp->getSuivante();
    delete tmp;
    return 1;
  }

  Cell *courante = tete;
  while (courante->getSuivante() != nullptr &&
         *courante->getSuivante()->getDonnee() != value) {
    courante = courante->getSuivante();
  }

  if (courante->getSuivante() == nullptr)
    return 0;

  Cell *aSupprimer = courante->getSuivante();
  Cell *suivante = aSupprimer->getSuivante();
  courante->setSuivante(suivante);
  delete aSupprimer;

  return 1;
} //----- Fin de deleteCell

int ListeChainee::supprimerToutesCell(const Trajet &value) {
  if (tete == nullptr)
    return 0;
  Cell *previous = tete;
  Cell *current = tete->getSuivante();

  while (current != nullptr) {
    if (current->getDonnee()->getTitre() == value.getTitre()) {
      previous->setSuivante(current->getSuivante());
      delete current;
    }
    current = previous->getSuivante()->getSuivante();
    previous = previous->getSuivante();
  }

  return 1;
}

void ListeChainee::libererListe()
// Algorithme :
// While the list is not empty we store the current head, move the head to the
// next node and then free the current node
{
  Cell *temp;
  while (tete != nullptr) {
    temp = tete;
    tete = tete->getSuivante();
    // Liberer le Trajet présent dans la cellule.
    delete temp->getDonnee();
    // Liberer la cellule.
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
    : tete(nullptr)
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
  libererListe();
} //----- Fin de ~ListeChainee

//-------------------------------- Autres definitions dependantes de
//<ListeChainee>
