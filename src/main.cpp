#include "Catalogue.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include <cstdio>
#include <cstring>

static TrajetSimple *questionnaireTrajetSimple(bool estEtape = false) {
  char *titre = new char[MAX_STRING_SIZE],
       *villeArrivee = new char[MAX_STRING_SIZE],
       *villeDepart = new char[MAX_STRING_SIZE],
       *moyenTransport = new char[MAX_STRING_SIZE];

  std::cout << "Entrez le nom " << (estEtape ? "de l'étape " : "du trajet ")
            << ":" << std::endl;
  fgets(titre, MAX_STRING_SIZE, stdin);
  std::cout << "Entrez la ville de depart :" << std::endl;
  fgets(villeDepart, MAX_STRING_SIZE, stdin);

  std::cout << "Entrez la ville d'arrivée :" << std::endl;
  fgets(villeArrivee, MAX_STRING_SIZE, stdin);

  std::cout << "Entrez le moyen de transport ([voiture], bus, tramway, avion, "
               "bateau, helicoptere) :"
            << std::endl;
  fgets(moyenTransport, MAX_STRING_SIZE, stdin);
  EMoyenTransport mt = depuisChaine(moyenTransport);

  TrajetSimple *nouveauTrajetSimple =
      new TrajetSimple(titre, villeDepart, villeArrivee, mt);

  delete[] titre;
  delete[] villeArrivee;
  delete[] villeDepart;
  delete[] moyenTransport;

  return nouveauTrajetSimple;
}

static TrajetCompose *questionnaireTrajetCompose(bool estEtape = false) {
  char *titre = new char[MAX_STRING_SIZE],
       *villeDepart = new char[MAX_STRING_SIZE],
       *villeArrivee = new char[MAX_STRING_SIZE],
       *moyenTransport = new char[MAX_STRING_SIZE];
  std::cout << "Entrez le nom du trajet :" << std::endl;
  fgets(titre, MAX_STRING_SIZE, stdin);

  std::cout << "Entrez la ville de depart :" << std::endl;
  fgets(villeDepart, MAX_STRING_SIZE, stdin);

  TrajetCompose *nouveauTrajetCompose =
      new TrajetCompose(titre, villeDepart, villeArrivee, voiture);

  int reponse = 0;
  bool quitter = false;
  bool auMoinsUneEtape = false;

  while (quitter == false) {
    std::cout << "Veuillez choisir une option :\n1. Clore le "
                 "trajet.\n2. Ajouter un trajet intérmediaire simple."
              << std::endl;

    std::cin >> reponse;
    std::cin.ignore();

    switch (reponse) {
    case 1: {
      if (auMoinsUneEtape) {
        quitter = true;
        break;
      }

      std::cout << "Entrez la ville d'arrivée :" << std::endl;
      fgets(villeArrivee, MAX_STRING_SIZE, stdin);
      nouveauTrajetCompose->setVilleArrivee(villeArrivee);

      std::cout << "Entrez le moyen de transport ([voiture], bus, tramway, "
                   "avion, bateau, helicoptere) :"
                << std::endl;
      fgets(moyenTransport, MAX_STRING_SIZE, stdin);
      EMoyenTransport mt = depuisChaine(moyenTransport);
      nouveauTrajetCompose->setMoyenTransport(mt);

      quitter = true;
      break;
    }
    case 2:
      switch (
          nouveauTrajetCompose->ajouterEtape(questionnaireTrajetSimple(true))) {
      case SUCCES_AJOUT_ETAPE:
        std::cout << "\033[32mL'étape a été ajoutée avec succès.\033[0m"
                  << std::endl;
        auMoinsUneEtape = true;
        break;
      case ERREUR_PREMIERE_ETAPE:
        std::cout
            << "\033[31mErreur lors de l'ajout d'une étape : la première étape "
               "d'un trajet doit avoir la même ville de départ que celle "
               "spécifiée dans le trajet. L'étape n'a pas été ajoutée.\033[0m"
            << std::endl;
        break;
      case ERREUR_ETAPES_INTERMEDIAIRES:
        std::cout << "\033[31mErreur lors de l'ajout d'une étape : une étape "
                     "intérmediaire doit avoir la même ville de départ que la "
                     "ville d'arrivée de l'étape précédente. L'étape n'a pas "
                     "été ajoutée.\033[0m"
                  << std::endl;
        break;
      }
      break;
    default:
      break;
    }
  }

  delete[] titre;
  delete[] villeDepart;
  delete[] villeArrivee;
  delete[] moyenTransport;

  return nouveauTrajetCompose;
}

int main() {
  Catalogue catalogue = Catalogue();

  bool quitter = false;
  int reponse;

  while (quitter == false) {
    std::cout << std::endl
              << "Veuillez choisir une option :\n1. Afficher le catalogue de "
                 "trajets.\n2. Ajouter un trajet simple.\n3. Ajouter un trajet "
                 "composé\n4. Recherche simple de trajet.\n\033[31m9. Quitter.\033[0m"
              << std::endl;

    std::cin >> reponse;
    std::cin.ignore();

    switch (reponse) {
    case 0:
      break;
    case 1:
      catalogue.afficher();
      break;
    case 2:
      catalogue.ajouterTrajet(questionnaireTrajetSimple());
      break;
    case 3:
      catalogue.ajouterTrajet(questionnaireTrajetCompose());
      break;
    case 4: {
      char *rechercheDepart = new char[MAX_STRING_SIZE];
      char *rechercheArrivee = new char[MAX_STRING_SIZE];

      std::cout << "Bienvenue dans la recherche simple de trajet." << std::endl;

      std::cout << "Veuillez entrez une ville de depart" << std::endl;
      fgets(rechercheDepart, MAX_STRING_SIZE, stdin);

      std::cout << "Veuillez entrez une ville d'arrivée" << std::endl;
      fgets(rechercheArrivee, MAX_STRING_SIZE, stdin);

      catalogue.rechercheSimple(rechercheDepart, rechercheArrivee);

      delete[] rechercheDepart;
      delete[] rechercheArrivee;
      break;
    }
    case 9:
      quitter = true;
      break;

    default:
      std::cout << "Veuillez entrer une réponse valide." << std::endl;
      break;
    }
  }
  return 0;
}
