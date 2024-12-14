/*************************************************************************
                           Cell  -  description
                             -------------------
    debut                : 26/11/2024
    copyright            : (C) 2024 par Dan Maria-Andrada et Marin Hugo
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Cell> (fichier Cell.h) ----------------
#if !defined(CELL_H)
#define CELL_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Cell>
//
//
//------------------------------------------------------------------------

class Cell {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Methodes publiques
  // type Methode ( liste des parametres );
  // Mode d'emploi :
  //
  // Contrat :
  //
  Trajet *getDonnee() const;
  // Mode d'emploi :
  //
  //

  void setData( Trajet *d);
  // Mode d'emploi :
  //
  // Contrat :
  //

  Cell *getSuivante() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  void setSuivante(Cell *n);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  Cell();
  // Mode d'emploi :
  //
  // Contrat :
  //

  Cell( Trajet *value);
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Cell();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Methodes protegees

  //----------------------------------------------------- Attributs proteges
  Trajet *donnee;
  Cell *suivante;
};

//-------------------------------- Autres definitions dependantes de <Cell>

#endif // CELL_H
