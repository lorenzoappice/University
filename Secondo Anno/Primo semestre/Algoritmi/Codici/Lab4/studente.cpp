#include "studente.h"
using namespace std;
studente::studente() {

}
studente::studente(string nome1,string nome2,string nome3,string nome4,string nome5) {
    //imposta in nomi dei 5 esami usando i parametri nome1, ... e i rispettivi flag sostenuto a false  

}
void studente::setMatricola(int matricola_studente) {
    matricola = matricola_studente;
}
void studente::setNome(string nome_studente) {
    nome = nome_studente;
}
string studente::getNome() {
    return nome;
}
string studente::getMatricola() {
    return matricola;
}
int studente::getNumEsami() {
    return esami;
}
void studente::setEsame(int Voto,int i) {
    //imposta il voto dell'esame i-esimo
    if (esami.size() < numesami) {
        esami[i].voto_esame = Voto;
        esami[i].sostenuto = true;
    } 
}
int studente::getVotoEsame(int i) {
    //prende il voto dell'esame i-esimo
    return esami[i].voto_esame;
}
string studente::getNomeEsame(int i) {
    //prende il nome dell'esame i-esimo
    return esami[i].esame;
}
bool studente::isSostenuto(int i) {
    //controlla se l'esame i-esimo è stato sostenuto
    return esami[i].sostenuto;
}
float studente::getmedia() {
    //calcola la media dei voti
    int media = 0;
    for (int i = 0; i < numesami; i++) {
        media += esami[i].voto_esame;
    }
    media = media / numesami;
    return media;
}
void studente::printstudente() {

}