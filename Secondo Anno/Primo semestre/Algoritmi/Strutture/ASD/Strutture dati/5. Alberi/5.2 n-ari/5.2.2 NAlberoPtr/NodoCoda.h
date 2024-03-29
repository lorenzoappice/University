/*
  Nome: NodoCoda.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo della coda
*/

#ifndef NODOCODA_H
#define NODOCODA_H
#include "NodoNPtr.h"

typedef nodoN elemCoda;

class NodoCoda {
public:
   NodoCoda(); // costruttore standard
   NodoCoda(elemCoda);  // costruttore che inizializza l'etichetta
   ~NodoCoda(); // distruttore
   
   elemCoda getEtichetta();
   void setEtichetta(elemCoda);
   
private:
   elemCoda etichetta;
};

#endif
