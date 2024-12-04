#include "Catalogue.h"
#include "Trajet.h"
#include <iostream>

Catalogue::Catalogue() : nbTrajets(0) { trajets = new Trajet[MAX_TRAJET_NB]; }
Trajet *Catalogue::getTrajets() const { return trajets; }
unsigned int Catalogue::getNbTrajets() const { return nbTrajets; }
Catalogue::~Catalogue() { delete[] trajets; }
int Catalogue::ajouterTrajet(const Trajet &nouveauTrajet) {
  if (nbTrajets + 1 < MAX_TRAJET_NB) {
    trajets[nbTrajets++] = nouveauTrajet;
    return 1;
  }
  return 0;
}
