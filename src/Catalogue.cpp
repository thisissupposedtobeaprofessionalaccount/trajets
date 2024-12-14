#include "Catalogue.h"
#include "Trajet.h"

Catalogue::Catalogue() {
#ifdef MAP
  std::cout << "Construction de Catalogue" << std::endl;
#endif
}

void Catalogue::rechercheSimple(const char *villeDepart,
                                const char *villeArrivee) const {
  ListeChainee *trouvailles =
      trajets.rechercheSimple(villeDepart, villeArrivee);
  if (trouvailles->getTete() == nullptr)

    std::cout << "Aucun trajet du catalogue ne correspond à la recherche :("
              << std::endl;

  else {
    std::cout << "Voici les trajets correspondant au termes de la recherche :"
              << std::endl;
    trouvailles->afficher();
  }

  delete trouvailles;
}

void Catalogue::afficher() const {
  if (trajets.getTete() == nullptr)
    std::cout << "\033[33mAucun trajet dans le catalogue.\033[0m" << std::endl;
  trajets.afficher();
}
const ListeChainee &Catalogue::getTrajets() const { return trajets; }

Catalogue::~Catalogue() {
#ifdef MAP
  std::cout << "Destruction de Catalogue" << std::endl;
#endif
}

bool Catalogue::ajouterTrajet(Trajet *nouveauTrajet) {
  trajets.insererEnQueue(nouveauTrajet);
  std::cout << "\033[32mLe trajet a été ajouté avec succès.\033[0m" << std::endl;
  return 1;
}

bool Catalogue::supprimerTrajetParTitre(const char *titre) {
  return trajets.supprimerCell(Trajet(titre));
}
