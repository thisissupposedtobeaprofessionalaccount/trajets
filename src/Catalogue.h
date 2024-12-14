/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 03/12/24
*************************************************************************/

//---------- Interface de la classe <> (fichier Catalogue.h) ----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

#include "ListeChainee.h"
#include "Trajet.h"

#define MAX_TRAJET_NB 5

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Catalogue {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  void rechercheSimple(const char *villeDepart,
                                 const char *villeArrivee) const;
  void afficher() const;
  bool ajouterTrajet(Trajet *nouveauTrajet);

  // Mode d'emploi :
  //
  // Contrat :
  //

  bool supprimerTrajetParTitre(const char *titre);
  //  type Méthode ( liste des paramètres );
  //  Mode d'emploi :
  //
  //  Contrat :
  //

  const ListeChainee &getTrajets() const;

  //------------------------------------------------- Surcharge d'opérateurs
  // Trajet & operator = ( const Trajet & autreTrajet );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  Catalogue();
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Catalogue();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  ListeChainee trajets;
};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // CATALOGUE_H
