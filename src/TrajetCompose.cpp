#include "TrajetCompose.h"

TrajetCompose::TrajetCompose(const TrajetCompose &autreTrajet)
    : Trajet((Trajet)autreTrajet), nb_trajets(autreTrajet.nb_trajets) {
#ifdef MAP
  cout << "Construction par copie de TrajetCompose" << endl;
#endif
  delete[] trajets;
  trajets = new Trajet[MAX_TRAJET_SIZE];

  for (unsigned int i = 0; i < nb_trajets; i++)
    trajets[i] = autreTrajet.trajets[i];
}

TrajetCompose::TrajetCompose(const char *titre, const char *villeArrivee,
                             const char *villeDepart,
                             const EMoyenTransport moyenTransport,
                             Trajet *trajets, unsigned int nb_trajets)
    : Trajet(titre, villeArrivee, villeDepart, moyenTransport),
      nb_trajets(nb_trajets) {
#ifdef MAP
  cout << "Construction de TrajetCompose" << endl;
#endif
  this->trajets = new Trajet[MAX_TRAJET_SIZE];

  for (unsigned int i = 0; i < this->nb_trajets; i++)
    this->trajets[i] = trajets[i];
}

TrajetCompose::~TrajetCompose() {
#ifdef MAP
  cout << "Destruction de TrajetCompose" << endl;
#endif
  delete[] trajets;
}
