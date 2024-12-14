#include "TrajetSimple.h"
#include <iostream>

TrajetSimple::TrajetSimple(const TrajetSimple &autreTrajet)
    : Trajet((Trajet)autreTrajet) {
#ifdef MAP
  std::cout << "Construction par copie de TrajetSimple" << std::endl;
#endif
}

TrajetSimple::TrajetSimple(const char *titre, const char *villeDepart,
                           const char *villeArrivee,
                           const EMoyenTransport moyenTransport)
    : Trajet(titre, villeDepart, villeArrivee, moyenTransport) {
#ifdef MAP
  std::cout << "Construction de TrajetSimple" << std::endl;
#endif
}

void TrajetSimple::afficher(const char *prefix) const {
  std::cout << prefix << "Trajet Simple : " << titre << std::endl;
  std::cout << prefix << "Ville de depart : " << villeDepart << std::endl;
  std::cout << prefix << "Ville d'arrivee : " << villeArrivee << std::endl;
  std::cout << prefix << "Moyen de transport : " << versChaine(moyenTransport) << std::endl;
  std::cout << prefix << "-----------" << std::endl;
}

TrajetSimple::~TrajetSimple() {
#ifdef MAP
  std::cout << "Destruction de TrajetSimple" << std::endl;
#endif
}
