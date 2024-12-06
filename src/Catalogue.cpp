#include "Catalogue.h"
#include "Trajet.h"
#include <iostream>

Catalogue::Catalogue() {
#ifdef MAP
  cout << "Construction de Catalogue" << endl;
#endif
}

ListeChainee<Trajet> Catalogue::getTrajets() const { return trajets; }


Catalogue::~Catalogue() {
#ifdef MAP
  cout << "Destruction de Catalogue" << endl;
#endif
}

int Catalogue::ajouterTrajet(const Trajet &nouveauTrajet) {
  trajets.insertAtTail(nouveauTrajet);
}

int Catalogue::supprimerTrajet(const char* titre) {
  trajets.deleteCell(Trajet(titre));
}
