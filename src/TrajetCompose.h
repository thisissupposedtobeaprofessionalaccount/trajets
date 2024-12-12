/*************************************************************************
                           TrajetCompose -  description
                             -------------------
    début                : 03/12/24
*************************************************************************/

//---------- Interface de la classe <> (fichier TrajetCompose.h) ----------------
#include "Catalogue.h"
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

#define MAX_TRAJET_SIZE 5
#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  void afficher(const  char * prefix = "" ) const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  void ajouterEtape( Trajet * nouvelleEtape);
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

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
  TrajetCompose(const TrajetCompose &autreTrajet);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  TrajetCompose(const char *titre, const char *villeArrivee,
                const char *villeDepart, const EMoyenTransport moyenTransport);
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~TrajetCompose();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  // will become a linked list 
  ListeChainee etapes;
  unsigned int nb_trajets;
};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJETCOMPOSE_H
