#include "Catalogue.h"
#include "Trajet.h"

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
  return 1;
}

int Catalogue::supprimerTrajetParTitre(const char* titre) {
  return trajets.deleteCell(Trajet(titre));
}
