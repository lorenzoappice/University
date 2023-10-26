#ifndef _STUDENTE
#define _STUDENTE
#include "string.h"
#include <iostream>

struct tipostudente{
	int matricola;
	char * nome;
	char * cognome;
    int eta;
};
typedef struct tipostudente studente;

/* funzioni per l'inserimento dei valori degli elementi della struttura */
int setMatricola(studente *s,int mat);
int setNome(studente *s,char * n);
int setCognome(studente *s,char *c);
int setEta(studente *s,int e);

/* funzioni per ottenere i valori degli elementi della struttura */
char * getNome(studente *s);
char * getCognome(studente *s);
int getMatricola(studente *s);
int getEta(studente *s);
#endif /* _STUDENTE */