#include "Catalogue.h"
#include "MoyenTransport.h"
#include "TrajetSimple.h"

int main ()
{
  Catalogue catalogue = Catalogue();
  TrajetSimple nouveauTrajetSimple ("mon trajet", "a", "b",  helicoptere);
  //TrajetCompose nouveauTrajetComp ("mon trajet compose", "c", "d",  voiture  , nullptr, 0 );
  catalogue.ajouterTrajet(nouveauTrajetSimple);
}
