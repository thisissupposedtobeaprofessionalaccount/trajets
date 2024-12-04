#include "TrajetCompose.h"

TrajetCompose::TrajetCompose(const TrajetCompose &autreTrajet)
    : Trajet((Trajet)autreTrajet), nb_trajets(autreTrajet.nb_trajets) {
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
  this->trajets = new Trajet[MAX_TRAJET_SIZE];

  for (unsigned int i = 0; i < this->nb_trajets; i++)
    this->trajets[i] = trajets[i];
}

TrajetCompose::~TrajetCompose() { delete[] trajets; }

