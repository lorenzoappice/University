#include <stdio.h>
#include <stdlib.h>
struct Lezione{

	char Materia[25];
	char Aula[2];
	float OrarioInizio;
	float OrarioFine;
};

struct Orario{

	int R;
	int C;
	struct Lezione Tabella[50][50];
};
void scrivilezione(struct Orario Orario1,int ora, int giorno, Lezione NuovaLezione){


}
struct Orario InserimentoOrario(){
	printf("Indicami La materia \n"); fflush(stdout);
	//scanf("%c",&.Materia);
	printf("Indicami l'aula della materia:\n"); fflush(stdout);
    //scanf("%c",&S1.Aula);
	printf("Indicami L'orario di inizio della materia: \n"); fflush(stdout);
	//scanf("%c",&S1.OrarioInizio);
	printf("Indicami L'orario di fine della materia: \n"); fflush(stdout);
    //scanf("%c",&S1.OrarioFine);
	return Orario;
}

#define R 10
#define C 5
int main(void) {

	return EXIT_SUCCESS;
}
