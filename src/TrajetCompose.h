/*************************************************************************
                           TrajetCompose -  description
                             -------------------
    début                : 03/12/24
*************************************************************************/

//---------- Interface de la classe <> (fichier TrajetCompose.h)
//----------------
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H



enum ECodeErreurTrajetCompose {
  SUCCES_AJOUT_ETAPE,
// code d'erreur caractérisant une première étape dont la ville de départ est
// différente de la ville de départ du trajet.
  ERREUR_PREMIERE_ETAPE,
// code d'erreur caractérisant une étape intermediaire dont la ville de départ
// est differente de la ville d'arrivée de l'étape precedente.
  ERREUR_ETAPES_INTERMEDIAIRES
};

#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"

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

  void afficher(const char *prefix = "") const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  ECodeErreurTrajetCompose ajouterEtape(TrajetSimple *nouvelleEtape);
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

  TrajetCompose(const char *titre, const char *villeDepart,
                const char *villeArrivee, const EMoyenTransport moyenTransport);
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
};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJETCOMPOSE_H
