#include "Trajet.h"

char *Trajet::getTitre() const { return titre; }
char *Trajet::getVilleArrivee() const { return villeArrivee; }
char *Trajet::getVilleDepart() const { return villeDepart; }
EMoyenTransport Trajet::getMoyenTransport() const { return moyenTransport; }

Trajet &Trajet::operator=(const Trajet &autre) {
  this->titre = new char[MAX_STRING_SIZE];
  this->villeArrivee = new char[MAX_STRING_SIZE];
  this->villeDepart = new char[MAX_STRING_SIZE];

  // copie de titre
  unsigned int count = 0;

  while (autre.titre[count] != '\0' && count < MAX_STRING_SIZE - 1) {
    this->titre[count] = autre.titre[count];
    count++;
  }

  // copie de villeArrivee
  count = 0;

  while (autre.villeArrivee[count] != '\0' && count < MAX_STRING_SIZE - 1) {
    this->villeArrivee[count] = autre.villeArrivee[count];
    count++;
  }

  // copie de villeDepart
  count = 0;

  while (autre.villeDepart[count] != '\0' && count < MAX_STRING_SIZE - 1) {
    this->villeDepart[count] = autre.villeDepart[count];
    count++;
  }

  this->moyenTransport = autre.moyenTransport;

  return *this;
}

Trajet::Trajet(const Trajet &autre) { *this = autre; }

Trajet::Trajet(const char *titre, const char *villeArrivee,
               const char *villeDepart, const EMoyenTransport moyenTransport) {
  this->titre = new char[MAX_STRING_SIZE];
  this->villeArrivee = new char[MAX_STRING_SIZE];
  this->villeDepart = new char[MAX_STRING_SIZE];

  // copie de titre
  unsigned int count = 0;

  while (titre[count] != '\0' && count < MAX_STRING_SIZE - 1) {
    this->titre[count] = titre[count];
    count++;
  }

  // copie de villeArrivee
  count = 0;

  while (villeArrivee[count] != '\0' && count < MAX_STRING_SIZE - 1) {
    this->villeArrivee[count] = villeArrivee[count];
    count++;
  }

  // copie de villeDepart
  count = 0;

  while (villeDepart[count] != '\0' && count < MAX_STRING_SIZE - 1) {
    this->villeDepart[count] = villeDepart[count];
    count++;
  }

  this->moyenTransport = moyenTransport;
}

Trajet::~Trajet() {
  delete[] titre;
  delete[] villeArrivee;
  delete[] villeDepart;
}
