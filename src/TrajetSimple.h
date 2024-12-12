/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 03/12/24
*************************************************************************/

//---------- Interface de la classe <> (fichier TrajetSimple.h) ----------------
#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  virtual void afficher(const char * prefix = "") const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //


  //------------------------------------------------- Surcharge d'opérateurs
  // Xxx & operator = ( const Xxx & unXxx );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  TrajetSimple(const TrajetSimple &autreTrajet);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

    TrajetSimple(const char *titre, const char *villeArrivee, const char *villeDepart,
         const EMoyenTransport moyenTransport);
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~TrajetSimple();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJETSIMPLE_H
