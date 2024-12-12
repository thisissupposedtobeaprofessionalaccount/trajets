#include "Trajet.h"
#include <iostream>

const char *Trajet::getTitre() const { return titre; }
const char *Trajet::getVilleArrivee() const { return villeArrivee; }
const char *Trajet::getVilleDepart() const { return villeDepart; }
EMoyenTransport Trajet::getMoyenTransport() const { return moyenTransport; }

bool Trajet::operator==(const Trajet &autre) {
  char current_this = this->titre[0];
  char current_autre = autre.titre[0];
  int count = 0;

  while (current_this != '\0' && current_autre != '\0') {
    if (current_this != current_autre)
      return false;
    count++;
    current_this = this->titre[count];
    current_autre = autre.titre[count];
  }
  return true;
}

bool Trajet::operator!=(const Trajet &autre) {
  char current_this = this->titre[0];
  char current_autre = autre.titre[0];
  int count = 0;

  while (current_this != '\0' && current_autre != '\0') {
    if (current_this != current_autre)
      return true;
    count++;
    current_this = this->titre[count];
    current_autre = autre.titre[count];
  }
  return false;
}

Trajet &Trajet::operator=(const Trajet &autre) {
  delete[] titre;
  delete[] villeArrivee;
  delete[] villeDepart;
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

Trajet::Trajet(const Trajet &autre) {
#ifdef MAP
  std::cout << "Construction par copie de Trajet" << std::endl;
#endif

  *this = autre;
}

Trajet::Trajet(const char *titre, const char *villeDepart,
               const char *villeArrivee, const EMoyenTransport moyenTransport) {
#ifdef MAP
  std::cout << "Construction de Trajet" << std::endl;
#endif
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
#ifdef MAP
  std::cout << "Destruction de Trajet" << std::endl;
#endif
  delete[] titre;
  delete[] villeArrivee;
  delete[] villeDepart;
}

void Trajet::afficher(const char * prefix ) const {
  std::cout <<prefix<< "Trajet : " << titre << std::endl;
  std::cout <<prefix<< "Ville de depart : " << villeDepart << std::endl;
  std::cout <<prefix<< "Ville d'arrivee : " << villeArrivee << std::endl;
  std::cout <<prefix<< "Moyen de transport : " << "TODO" << std::endl;
}
