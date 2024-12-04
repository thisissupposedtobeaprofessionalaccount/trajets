#include "Catalogue.h"
#include "MoyenTransport.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
using namespace std;

int main ()
{
  Catalogue catalogue;
  TrajetSimple nouveauTrajetSimple ("mon trajet", "a", "b",  helicoptere);
  TrajetCompose nouveauTrajetComp ("mon trajet compose", "c", "d",  voiture  , nullptr, 0 );
  catalogue.ajouterTrajet(nouveauTrajetComp);

  Trajet* trajets = catalogue.getTrajets();
  cout << trajets[0].getTitre() << endl;
  cout << trajets[0].getVilleDepart() << endl;
  cout << trajets[0].getVilleArrivee() << endl;
  cout << (trajets[0].getMoyenTransport() == voiture ? "v" : "caca") << endl;

}
