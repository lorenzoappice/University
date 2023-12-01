#ifndef _ESAME_H
#define _ESAME_H

#include <iostream>
#include <string>

using namespace std;

class esame {
public:
    esame();
    esame(string);
    esame(string, int);
    string getEsame();
    void setEsame(string);
    int getVoto();
    void setVoto(int);
    bool isSostenuto();

private:
    string nome_esame;
    bool sostenuto = false;
    int voto_esame;
};

#endif // _ESAME_H
