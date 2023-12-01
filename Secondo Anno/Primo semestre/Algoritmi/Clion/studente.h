#ifndef _STUDENTE_H
#define _STUDENTE_H

#include <iostream>
#include <string>
#include "esame.h"

using namespace std;
class studente {
    public:
        studente();
        void setMatricola(string);
        void setNome(string);
        string getNome();
        string getMatricola();
        void setVEsame(int,int);
        double getMedia();
        void PrintStudente();
    private:
        string Matricola;
        string Nome;
        esame esami[5];
};

#endif // _STUDENTE_H