#include "studente.h"
using namespace std;
studente::studente() {
    //imposta in nomi dei 5 esami usando i parametri nome1, ... e i rispettivi flag sostenuto a false  
    esami[0].setEsame("A");
    esami[1].setEsame("B");
    esami[2].setEsame("C");
    esami[3].setEsame("D");
    esami[4].setEsame("E");
}

void studente::setMatricola(string matricola_studente) {
    Matricola = matricola_studente;
}
void studente::setNome(string nome_studente) {
    Nome = nome_studente;
}
string studente::getNome() {
    return Nome;
}
string studente::getMatricola() {
    return Matricola;
}

void studente::setVEsame(int Voto,int i) {
    //imposta il voto dell'esame i-esimo
    esami[i-1].setVoto(Voto);

}
double studente::getMedia() {
    //restituisce media degli esami sostenuti
    double Media = 0;
    int c = 0;
    for (int i=0;i<5; i++) {
        if(esami[i].isSostenuto())
        {
            c++;
            Media += esami[i].getVoto();
        }
    }
    return Media/c;
}

void studente::PrintStudente() {
    for (int i=0;i<5;i++)
        if (esami[i].isSostenuto())
        {
            cout << esami[i].getEsame() << " " << esami[i].getVoto() << endl;
        }
}