#include "Trajet.h"
#include <iostream>

char *Trajet::getTitre() const { return titre; }
char *Trajet::getVilleArrivee() const { return villeArrivee; }
char *Trajet::getVilleDepart() const { return villeDepart; }
EMoyenTransport Trajet::getMoyenTransport() const { return moyenTransport; }


bool Trajet::operator==(const Trajet &autre){
  return this->titre;
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
  cout << "Construction par copie de Trajet" << endl;
#endif

  *this = autre;
}

Trajet::Trajet(const char *titre, const char *villeArrivee,
               const char *villeDepart, const EMoyenTransport moyenTransport) {
#ifdef MAP
  cout << "Construction de Trajet" << endl;
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
  cout << "Destruction de Trajet" << endl;
#endif
  delete[] titre;
  delete[] villeArrivee;
  delete[] villeDepart;
}

void Trajet::afficher() const {
  std::cout << "Trajet : " << titre << std::endl;
  std::cout << "Ville d'arrivee : " << villeArrivee << std::endl;
  std::cout << "Ville de depart : " << villeArrivee << std::endl;
  std::cout << "Moyen de transport : " << villeArrivee << std::endl;
}
