#include "MoyenTransport.h"
#include <iostream>

EMoyenTransport depuisChaine(const char *chaine) {
  std::cout << chaine << std::endl;
  if (strcmp(chaine, "bus\n") == 0)
    return bus;
  if (strcmp(chaine, "tramway\n") == 0)
    return tramway;
  if (strcmp(chaine, "avion\n") == 0)
    return avion;
  if (strcmp(chaine, "bateau\n") == 0)
    return bateau;
  if (strcmp(chaine, "helicoptere\n") == 0)
    return helicoptere;
  return voiture;
}

const char *versChaine(EMoyenTransport moyenTransport) {
  switch (moyenTransport) {
  case bus:
    return "bus";
  case tramway:
    return "tramway";
  case voiture:
    return "voiture";
  case avion:
    return "avion";
  case bateau:
    return "bateau";
  case helicoptere:
    return "helicoptere";
  case multiple:
    return "multiple";
  }
}
