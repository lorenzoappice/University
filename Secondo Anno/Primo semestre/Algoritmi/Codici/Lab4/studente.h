#ifndef _STUDENTE_H
#define _STUDENTE_H

#include <iostream>
#include <string>
#include "esame.h"
#include <vector>
using namespace std;
class studente {
    public:
        studente();
        studente(string nome1,string nome2,string nome3,string nome4,string nome5);
        void setMatricola(int matricola);
        void setNome(string nome);
        string getMatricola();
        string getNome();
        int getNumEsami();
        void setEsame(int Voto,int i);
        int getVotoEsame(int i);
        string getNomeEsame(int i);
        bool isSostenuto(int i);
        float getMedia();
        void printstudente();
    private:
        const int numesami = 5;
        string matricola;
        string nome;
        vector <esame> esami;

};

#endif // _STUDENTE_H