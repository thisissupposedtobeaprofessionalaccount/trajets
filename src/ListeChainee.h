/*************************************************************************
                           Liste Chainee  -  description
                             -------------------
    debut                : 26/11/2024
    copyright            : (C) 2024 par Dan Maria-Andrada et Marin Hugo
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Liste Chainee> (fichier ListeChainee.h)
//----------------
#if !defined(LISTECHAINEE_H)
#define LISTECHAINEE_H

#include <iostream>
#include "Cell.h"

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Liste Chainee>
//
//
//------------------------------------------------------------------------

class ListeChainee {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Methodes publiques
  // type Methode ( liste des parametres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  ListeChainee *rechercheSimple(const char *villeDepart,
                           const char *villeArrivee) const;
  const Cell *getTete() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  void afficher(const char *prefix = "") const;
  // Mode d'emploi:
  //  Firstly checks if the list is NULL
  //  While the list is not NULL it prints the value of the element then it goes
  //  to the next position
  // Contrat:
  //

  void insererEnQueue(Trajet *valeur);
  // Mode d'emploi:
  //  creates a new node of the value, makes the head of the list be the new
  //  node and then t
  // Contrat:
  //
  void insererEnTete(Trajet *valeur);
  // Mode d'emploi:
  //  creates a new node of the value, makes the head of the list be the new
  //  node and then t
  // Contrat:
  //

  int supprimerCell(const Trajet &valeur);
  // Mode d'emploi:
  //  checks if list is empty then checks if the node we want to delete is the
  //  first node if not, we check while the list is not NULL we also check if
  //  the element has not been found at all
  // Contrat:
  //

  int supprimerToutesCell(const Trajet &valeur);
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
  void setTete(Cell *h);
  // Mode d'emploi :
  //
  // Contrat :
  //
  void libererListe();
  // Mode d'emploi:
  //  frees the entire linked list
  // Contrat:
  //

  //----------------------------------------------------- Attributs proteges
  Cell *tete;
};

#endif // LISTECHAINEE_H
