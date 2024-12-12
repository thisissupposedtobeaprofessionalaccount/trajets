/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 26/11/2024
*************************************************************************/

//---------- Interface de la classe <> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

#define MAX_STRING_SIZE 64
#include "MoyenTransport.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Trajet {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  const char *getTitre() const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  const char *getVilleArrivee() const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  const char *getVilleDepart() const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  EMoyenTransport getMoyenTransport() const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual void afficher() const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------- Surcharge d'opérateurs
  bool operator==(const Trajet &autre);
  // Mode d'emploi :
  //
  // Contrat :
  //

  bool operator!=(const Trajet &autre);
  // Mode d'emploi :
  //
  // Contrat :
  //

  Trajet &operator=(const Trajet &autreTrajet);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  Trajet(const Trajet &autreTrajet);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  Trajet(const char *titre = "", const char *villeArrivee = "",
         const char *villeDepart = "",
         const EMoyenTransport moyenTransport = voiture);
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Trajet();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  char *titre;
  char *villeArrivee;
  char *villeDepart;
  EMoyenTransport moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de Trajet

#endif // TRAJET_H
