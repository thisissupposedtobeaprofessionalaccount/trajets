#include "Catalogue.h"
#include "Trajet.h"

Catalogue::Catalogue() {
#ifdef MAP
  std::cout << "Construction de Catalogue" << std::endl;
#endif
}

const ListeChainee& Catalogue::getTrajets() const { return trajets; }

Catalogue::~Catalogue() {
#ifdef MAP
  std::cout << "Destruction de Catalogue" << std::endl;
#endif
}

bool Catalogue::ajouterTrajet(  Trajet *nouveauTrajet) {
  trajets.insertAtTail(nouveauTrajet);
  return 1;
}

bool Catalogue::supprimerTrajetParTitre(const char* titre) {
  return trajets.deleteCell(Trajet(titre));
}
