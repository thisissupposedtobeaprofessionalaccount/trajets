#include "Catalogue.h"
#include "ListeChainee.h"
#include "MoyenTransport.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

int main() {
  Catalogue catalogue = Catalogue();
  TrajetSimple nouveauTrajetSimple("mon trajet", "a", "b", helicoptere);
  TrajetSimple nouveauTrajetSimple2("mon trajet2", "a", "b", helicoptere);
  TrajetCompose nouveauTrajetCompose("mon trajet compose", "x", "y",
                                     helicoptere);
  TrajetCompose nouveauTrajetCompose2("mon trajet compose 222222", "v", "p",
                                     helicoptere);
  nouveauTrajetCompose.ajouterEtape(&nouveauTrajetSimple);
  nouveauTrajetCompose.ajouterEtape(&nouveauTrajetSimple2);
  nouveauTrajetCompose2.ajouterEtape(&nouveauTrajetSimple);
  nouveauTrajetCompose2.ajouterEtape(&nouveauTrajetSimple2);
  nouveauTrajetCompose.ajouterEtape(&nouveauTrajetCompose2);

  catalogue.ajouterTrajet(&nouveauTrajetSimple);
  catalogue.ajouterTrajet(&nouveauTrajetCompose);
  catalogue.getTrajets().afficher();
}
