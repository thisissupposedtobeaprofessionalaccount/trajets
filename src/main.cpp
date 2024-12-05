#include "Catalogue.h"
#include "MoyenTransport.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

int main() {
  Catalogue catalogue = Catalogue();
  TrajetSimple nouveauTrajetSimple("mon trajet", "a", "b", helicoptere);
  TrajetSimple nouveauTrajetSimple2("mon trajet", "b", "c", helicoptere);

  Trajet list[] = {TrajetSimple("mon trajet", "a", "c", helicoptere),
                   TrajetSimple("mon trajet", "b", "c", helicoptere)};
  TrajetCompose nouveauTrajetComp("mon trajet compose", "a", "c", voiture, list,
                                  2);
  catalogue.ajouterTrajet(nouveauTrajetSimple);
  catalogue.ajouterTrajet(nouveauTrajetComp);

  catalogue.getTrajets()[1].afficher();
}
