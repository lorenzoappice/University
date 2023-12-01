#include "studente.h"
#include "esame.h"
using namespace std;
int main() {
    studente studente1;
    int voto_esame;
    for (int i=0;i<5;i++){
        cout << "Dammi il voto dell'esame num "<< i+1 << ":" << endl;
        cin >> voto_esame;
        studente1.setVEsame(voto_esame,i);
     }
    cout << "Media di studente1 "<< " " << studente1.getMedia() << endl;
    studente1.PrintStudente();
    return 0;

}