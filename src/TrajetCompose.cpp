#include "TrajetCompose.h"
#include <cstring>
#include <iostream>

void TrajetCompose::afficher(const char *prefix) const {
  std::cout << prefix << "Trajet Composé : " << titre << std::endl;
  std::cout << prefix << "Ville de depart : " << villeDepart << std::endl;
  std::cout << prefix << "Ville d'arrivee : " << villeArrivee << std::endl;
  std::cout << prefix << "Moyen de transport : " << versChaine(moyenTransport) << std::endl;

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

void TrajetCompose::ajouterEtape(Trajet *nouvelleEtape) {
  if(nouvelleEtape->getMoyenTransport() != moyenTransport)
    moyenTransport = multiple;
  etapes.insererEnQueue(nouvelleEtape);
  setVilleArrivee(nouvelleEtape->getVilleArrivee());
}

TrajetCompose::~TrajetCompose() {
#ifdef MAP
  std::cout << "Destruction de TrajetCompose" << std::endl;
#endif
}
