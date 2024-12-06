#include "Catalogue.h"
#include "ListeChainee.h"
#include "MoyenTransport.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

int main() {
//  Catalogue catalogue = Catalogue();
//  TrajetSimple nouveauTrajetSimple("mon trajet", "a", "b", helicoptere);
//  TrajetSimple nouveauTrajetSimple2("mon trajet", "b", "c", helicoptere);
//
//  TrajetCompose nouveauTrajetComp("mon trajet compose", "a", "c", voiture);
//  nouveauTrajetComp.ajouterEtape(nouveauTrajetSimple2);
//  catalogue.ajouterTrajet(nouveauTrajetSimple);
//  catalogue.ajouterTrajet(nouveauTrajetComp);

//  catalogue.getTrajets()[1].afficher();

 ListeChainee liste; 

 liste.afficher();
 liste.insertAtTail(10);
 liste.insertAtTail(12);
 liste.insertAtTail(16);
 liste.insertAtTail(7);
 liste.insertAtTail(15);
 liste.afficher();

 liste.deleteCell(10);
 liste.afficher();


}
