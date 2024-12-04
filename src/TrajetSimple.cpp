#include "TrajetSimple.h"

TrajetSimple::TrajetSimple(const TrajetSimple &autreTrajet)
    : Trajet((Trajet)autreTrajet) {}

TrajetSimple::TrajetSimple(const char *titre, const char *villeArrivee,
                           const char *villeDepart,
                           const EMoyenTransport moyenTransport)
    : Trajet(titre, villeArrivee, villeDepart, moyenTransport) {}

TrajetSimple::~TrajetSimple() {}
