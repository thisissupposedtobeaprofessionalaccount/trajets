#include "TrajetCompose.h"
#include <iostream>

void TrajetCompose::afficher() const {
  Trajet::afficher();

  for (unsigned int i = 0; i < nb_trajets; i++) {
    std::cout << "Trajet intermediaires n°" << i << std::endl;
    steps->afficher();
  }
}

TrajetCompose::TrajetCompose(const TrajetCompose &autreTrajet)
    : Trajet((Trajet)autreTrajet), nb_trajets(autreTrajet.nb_trajets) {
#ifdef MAP
  cout << "Construction par copie de TrajetCompose" << endl;
#endif
  delete[] steps;
  steps = new Trajet[MAX_TRAJET_SIZE];

  for (unsigned int i = 0; i < nb_trajets; i++)
    steps[i] = autreTrajet.steps[i];
}

TrajetCompose::TrajetCompose(const char *titre, const char *villeArrivee,
                             const char *villeDepart,
                             const EMoyenTransport moyenTransport)
    : Trajet(titre, villeArrivee, villeDepart, moyenTransport) {
#ifdef MAP
  cout << "Construction de TrajetCompose" << endl;
#endif
}

TrajetCompose::~TrajetCompose() {
#ifdef MAP
  cout << "Destruction de TrajetCompose" << endl;
#endif
  delete[] steps;
}
