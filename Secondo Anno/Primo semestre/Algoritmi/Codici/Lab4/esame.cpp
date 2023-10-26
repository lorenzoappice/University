#include "esame.h"


esame::esame () {

}

esame::esame(string nome_esame) {
    setEsame(nome_esame);  
}

esame::esame(string nome_esame,int voto) {
    setEsame(nome_esame);
    setVoto(voto);
}

string esame::getEsame() {
    return esame;
}
void esame::setEsame(string nome_esame) {
    esame = nome_esame;
}
int esame::getVoto() {
    return voto_esame;
}
void esame::setVoto(int voto) {
    voto_esame = voto;
    sostenuto = true;
}
bool esame::isSostenuto() {
    return sostenuto;
}