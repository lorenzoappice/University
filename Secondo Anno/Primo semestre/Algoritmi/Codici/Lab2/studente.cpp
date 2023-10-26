#include "studente.h"


using namespace std;
int setMatricola(studente *s,int mat) {
        if (mat > 255312 && mat < 499999)
        {
        s->matricola = mat;
        return 1;
        }
        else
        {
                cout << "Matricola non valida" << endl;
                return 0;
        }
}
int setNome(studente *s,char * n) {
       if (strlen(n) > 30) {
        cout << "Nome troppo lungo" << endl;
        return 0;
       }
       else 
       {
        s->nome = n;
        return 1;
       }
}
int setCognome(studente *s,char * c) {
       if (strlen(c) > 30) {
        cout << "Cognome troppo lungo" << endl;
        return 0;
       }
       else 
       {
        s->cognome = c;
        return 1;
       }
}
int setEta(studente *s,int e) {
        if (e >12 && e < 105)
        {
        s-> eta = e;
        return 1;
        }
        else
        {
                cout << "Eta non valida" << endl;
                return 0;
        }
}

char * getNome(studente *s) {
        return (s->nome);
}
char * getCognome(studente *s) {
        return (s->cognome);
}
int getMatricola(studente *s) {
        return (s->matricola);
}
int getEta(studente *s) {
        return (s->eta);
}