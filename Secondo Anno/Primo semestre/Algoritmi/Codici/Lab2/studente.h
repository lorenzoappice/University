#ifndef _STUDENTE
#define _STUDENTE
#include <iostream>
#include "string.h"
using namespace std;
struct tipostudente{
    int matricola;
    string nome;
    string cognome;
    int eta;
};
typedef struct tipostudente studente;

/* funzioni per l'inserimento dei valori degli elementi della struttura */
int setMatricola(studente *s,int mat);
int setNome(studente *s,string n);
int setCognome(studente *s,string c);
int setEta(studente *s,int e);

/* funzioni per ottenere i valori degli elementi della struttura */
string getNome(studente *s);
string  getCognome(studente *s);
int getMatricola(studente *s);
int getEta(studente *s);
#endif /* _STUDENTE */