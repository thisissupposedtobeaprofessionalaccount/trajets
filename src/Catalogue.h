/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 03/12/24
*************************************************************************/

//---------- Interface de la classe <> (fichier Catalogue.h) ----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

#include "Trajet.h"
#include "ListeChainee.h"

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

  bool ajouterTrajet(const Trajet &nouveauTrajet);

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

  ListeChainee<Trajet>& getTrajets() const;

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
  ListeChainee<Trajet> trajets;
};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // CATALOGUE_H
