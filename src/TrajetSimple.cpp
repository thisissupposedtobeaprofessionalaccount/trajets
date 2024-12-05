#include "TrajetSimple.h"
#include <iostream>

TrajetSimple::TrajetSimple(const TrajetSimple &autreTrajet)
    : Trajet((Trajet)autreTrajet) {
#ifdef MAP
  cout << "Construction par copie de TrajetSimple" << endl;
#endif
}

TrajetSimple::TrajetSimple(const char *titre, const char *villeArrivee,
                           const char *villeDepart,
                           const EMoyenTransport moyenTransport)
    : Trajet(titre, villeArrivee, villeDepart, moyenTransport) {
#ifdef MAP
  cout << "Construction de TrajetSimple" << endl;
#endif
}

void TrajetSimple::afficher() const {
  Trajet::afficher();
  std::cout << "Ville d'arrivee : " << villeArrivee << std::endl;
  std::cout << "Ville de depart : " << villeArrivee << std::endl;
  std::cout << "Moyen de transport : " << villeArrivee << std::endl;
}

TrajetSimple::~TrajetSimple() {
#ifdef MAP
  cout << "Destruction de TrajetSimple" << endl;
#endif
}
