#include <cstring>
#if !defined(MOYENTRANSPORT_H)
#define MOYENTRANSPORT_H
enum EMoyenTransport { bus, tramway, voiture, avion, bateau, helicoptere, multiple};
EMoyenTransport depuisChaine(const char *chaine);
const char *versChaine(EMoyenTransport moyenTransport);
#endif
