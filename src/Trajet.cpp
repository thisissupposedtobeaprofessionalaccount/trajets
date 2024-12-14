#include "Trajet.h"
#include <cstring>
#include <iostream>

void Trajet::setTitre(const char *titre) {
  strcpy(this->titre, titre);
}
void Trajet::setVilleDepart(const char *villeDepart) {
  strcpy(this->villeDepart, villeDepart);
}
void Trajet::setVilleArrivee(const char *villeArrivee) {
  strcpy(this->villeArrivee, villeArrivee);
}
void Trajet::setMoyenTransport(EMoyenTransport moyenTransport) {
  this->moyenTransport = moyenTransport;
}

const char *Trajet::getTitre() const { return titre; }
const char *Trajet::getVilleArrivee() const { return villeArrivee; }
const char *Trajet::getVilleDepart() const { return villeDepart; }
EMoyenTransport Trajet::getMoyenTransport() const { return moyenTransport; }

bool Trajet::operator==(const Trajet &autre) {
  return strcmp(this->villeDepart, autre.villeDepart) == 0 &&
         strcmp(this->villeArrivee, autre.villeArrivee) == 0;
}

bool Trajet::operator!=(const Trajet &autre) {
  return strcmp(this->villeDepart, autre.villeDepart) != 0 &&
         strcmp(this->villeArrivee, autre.villeArrivee) != 0;
}

Trajet &Trajet::operator=(const Trajet &autre) {
  delete[] titre;
  delete[] villeDepart;
  delete[] villeArrivee;
  this->titre = new char[MAX_STRING_SIZE];
  this->villeDepart = new char[MAX_STRING_SIZE];
  this->villeArrivee = new char[MAX_STRING_SIZE];

  strcpy(this->titre, autre.titre);
  strcpy(this->villeDepart, autre.villeDepart);
  strcpy(this->villeArrivee, autre.villeArrivee);
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

  strcpy(this->titre, titre);
  strcpy(this->villeDepart, villeDepart);
  strcpy(this->villeArrivee,villeArrivee);
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

void Trajet::afficher(const char *prefix) const {
  std::cout << prefix << "Trajet : " << titre << std::endl;
  std::cout << prefix << "Ville de depart : " << villeDepart << std::endl;
  std::cout << prefix << "Ville d'arrivee : " << villeArrivee << std::endl;
  std::cout << prefix << "Moyen de transport : " << versChaine(moyenTransport) << std::endl;
}
