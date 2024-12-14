#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include <cstring>
#include <iostream>

void TrajetCompose::afficher(const char *prefix) const {
  std::cout << prefix << "Trajet Composé : " << titre << std::endl;
  std::cout << prefix << "Ville de depart : " << villeDepart << std::endl;
  std::cout << prefix << "Ville d'arrivee : " << villeArrivee << std::endl;
  std::cout << prefix << "Moyen de transport : " << versChaine(moyenTransport)
            << std::endl;

  if (etapes.getTete()) {
    unsigned int count = 0;
    char current = prefix[0];
    while (current != '\0') {
      count++;
      current = prefix[count];
    }
    char *nouveauPrefix = new char[count + 1];
    for (unsigned int i = 0; i < count; i++) {
      nouveauPrefix[i] = prefix[i];
    }
    nouveauPrefix[count] = '\t';

    std::cout << prefix << "Trajets intermediaires : " << std::endl;
    etapes.afficher(nouveauPrefix);
  }
  std::cout << prefix << "-----------" << std::endl;
}

TrajetCompose::TrajetCompose(const TrajetCompose &autreTrajet)
    : Trajet((Trajet)autreTrajet) {
#ifdef MAP
  std::cout << "Construction par copie de TrajetCompose" << std::endl;
#endif
}

TrajetCompose::TrajetCompose(const char *titre, const char *villeDepart,
                             const char *villeArrivee,
                             const EMoyenTransport moyenTransport)
    : Trajet(titre, villeDepart, villeArrivee, moyenTransport) {
#ifdef MAP
  std::cout << "Construction de TrajetCompose" << std::endl;
#endif
}

ECodeErreurTrajetCompose TrajetCompose::ajouterEtape(TrajetSimple *nouvelleEtape) {
  // S'il s'agit de la première étape ajoutée.
  if (etapes.getTete() == nullptr) {
    // Contrainte : la ville de départ de la nouvelle etape doit être identique
    // à la ville de départ du trajet.
    if (strcmp(villeDepart, nouvelleEtape->getVilleDepart()) != 0) {
      return ERREUR_PREMIERE_ETAPE;
    }

    moyenTransport = nouvelleEtape->getMoyenTransport();
    etapes.insererEnQueue(nouvelleEtape);
    setVilleArrivee(nouvelleEtape->getVilleArrivee());

    return SUCCES_AJOUT_ETAPE;
  }

  // Contrainte : la ville de départ du nouveau trajet doit être identique à la
  // ville d'arrivée de l'etape precedente.
  if (strcmp(nouvelleEtape->getVilleDepart(),
             etapes.getDerniereCell()->getDonnee()->getVilleArrivee()) != 0)
    return ERREUR_ETAPES_INTERMEDIAIRES;

  if (nouvelleEtape->getMoyenTransport() != moyenTransport)
    moyenTransport = multiple;

  etapes.insererEnQueue(nouvelleEtape);
  setVilleArrivee(nouvelleEtape->getVilleArrivee());
  
  return SUCCES_AJOUT_ETAPE;
}

TrajetCompose::~TrajetCompose() {
#ifdef MAP
  std::cout << "Destruction de TrajetCompose" << std::endl;
#endif
}
