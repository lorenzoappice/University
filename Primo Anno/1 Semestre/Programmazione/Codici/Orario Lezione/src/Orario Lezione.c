#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define righe 5
#define colonne 8
struct Lezione {
	char materia[25];
	char aula[25];
	char orainizio[25];
	char orafine[25];
	char giorno[15];
};
struct Lezione Orario[righe][colonne];
char day[15];
char oraini[25];
void CaricaOrario () {
	int i = 0;
	int j = 0;
	while (i < colonne){
		while (j < righe){
				if (j==0) {
					strcpy(Orario[j][i].giorno, "lunedi");
					strcpy(day, "lunedi");
				} else if (j==1){
					strcpy(Orario[j][i].giorno, "martedi");
					strcpy(day, "martedi");
				} else if (j==2){
					strcpy(Orario[j][i].giorno, "mercoledi");
					strcpy(day, "mercoledi");
				} else if (j==3){
					strcpy(Orario[j][i].giorno, "giovedi");
					strcpy(day, "giovedi");
				} else if (j==4){
					  strcpy(Orario[j][i].giorno, "venerdi");
					  strcpy(day, "venerdi");
				}if (i==0) {
							strcpy(Orario[j][i].orainizio, "8:30");
							strcpy(Orario[j][i].orafine, "9:20");
							strcpy(oraini, "8:30/9:20");
						} else if (i==1) {
							strcpy(Orario[j][i].orainizio, "9:20");
							strcpy(Orario[j][i].orafine, "10:10");
							strcpy(oraini, "9:20/10:10");
						} else if (i==2) {
							  strcpy(Orario[j][i].orainizio, "10:10");
							  strcpy(Orario[j][i].orafine, "11:00");
							  strcpy(oraini, "10:10/11:00");
						} else if (i==3) {
							  strcpy(Orario[j][i].orainizio, "11:00");
							  strcpy(Orario[j][i].orafine, "11:50");
							  strcpy(oraini, "11:00/11:50");
						} else if (i==4) {
							  strcpy(Orario[j][i].orainizio, "11:50");
							  strcpy(Orario[j][i].orafine, "12:40");
							  strcpy(oraini, "11:50/12:40");
						} else if (i==5) {
							  strcpy(Orario[j][i].orainizio, "12:40");
							  strcpy(Orario[j][i].orafine, "13:30");
							  strcpy(oraini, "12:40/13:30");
						} else if (i==6) {
							  strcpy(Orario[j][i].orainizio, "13:30");
							  strcpy(Orario[j][i].orafine, "14:20");
							  strcpy(oraini, "13:30/14:20");
						} else if (i==7) {
							  strcpy(Orario[j][i].orainizio, "14:20");
							  strcpy(Orario[j][i].orafine, "17:40");
							  strcpy(oraini, "14:20/17:40");
						}
			printf ("Inserire materia della lezione per il giorno %s alle ore %s: \n" , day, oraini );
			fflush(stdin);
			scanf("%20[^\n]", Orario[j][i].materia);
			printf ("Inserire aula della lezione per il giorno %s alle ore %s: \n" , day, oraini );
			fflush(stdin);
			scanf("%20[^\n]", Orario[j][i].aula);
			printf("%s", Orario[j][i].materia);
			printf(" %s", Orario[j][i].aula);
			printf(" %s", Orario[j][i].orainizio);
			printf(" %s", Orario[j][i].orafine);
			printf(" %s \n", Orario[j][i].giorno);
			j=j+1;
		}
		j = 0;
		i=i+1;
	}
    system("pause");
}
void StampaOrario () {
	printf ("\n");
	int i = 0;
	int j = 0;
	while (i < righe){
		while (j < colonne){
			printf("%s", Orario[i][j].materia);
			printf(" %s", Orario[i][j].aula);
			printf(" %s", Orario[i][j].orainizio);
			printf(" %s", Orario[i][j].orafine);
			printf(" %s \n", Orario[i][j].giorno);
			j=j+1;
		}
		i=i+1;
		j = 0;
	}
	printf ("\n");
	system ("pause");
}
void ConsultaGiorno (){
	int y;
	int i = 0;
	printf ("SELEZIONARE IL GIORNO DELLA SETTIMANA  \n:");
	printf ("0 per lunedi' \n:");
	printf ("1 per martedi' \n:");
	printf ("2 per mercoledi' \n:");
	printf ("3 per giovedi' \n:");
	printf ("4 per venerdi' \n:");
	scanf ("%d", & y);
	while (i < colonne){
		  			printf(" %s", Orario[y][i].materia);
		  			printf(" %s", Orario[y][i].aula);
		  			printf(" %s", Orario[y][i].orainizio);
					printf(" %s", Orario[y][i].orafine);
					printf(" %s", Orario[y][i].giorno);
					printf(" \n");
				i=i+1;
		}

}

void ConsultaOra (){
	int y;
	int i = 0;
	printf ("SELEZIONARE L'ORA DELLA SETTIMANA\n:");
	printf ("0 per 8:30/9:20 \n:");
	printf ("1 per 9:20/10:10 \n:");
	printf ("2 per 10:10/11:00 \n:");
	printf ("3 per 11:00/11:50 \n:");
	printf ("4 per 11:50/12:40 \n:");
	printf ("5 per 12:40/13:30 \n:");
	printf ("6 per 13:30/14:20 \n:");
	printf ("7 per 14:20/17:40 \n:");
	scanf ("%d", & y);
	while (i < righe){
		  			printf(" %s", Orario[i][y].materia);
		  			printf(" %s", Orario[i][y].aula);
		  			printf(" %s", Orario[i][y].orainizio);
					printf(" %s", Orario[i][y].orafine);
					printf(" %s", Orario[i][y].giorno);
					printf(" \n");
				i=i+1;
						}

}
void AccediOra(){
			int i = 0;
			int j = 0;
			int po ;
			while (i < righe){
				while (j < colonne){
					printf("%s", Orario[i][j].materia);
					printf(" %s", Orario[i][j].aula);
					printf(" %s", Orario[i][j].orainizio);
					printf(" %s", Orario[i][j].orafine);
					printf(" %s \n", Orario[i][j].giorno);
					printf ("Vuoi modificare questo record?\n 1: si \n");
					scanf ("%d", &po);
					 if (po == 1) {
						system ("pause");
						printf ("Inserire materia della lezione per il giorno %s alle ore %s: \n" , day, oraini );
						fflush(stdin);
						scanf("%20[^\n]", Orario[j][i].materia);
						printf ("Inserire aula della lezione per il giorno %s alle ore %s: \n" , day, oraini );
						fflush(stdin);
						scanf("%20[^\n]", Orario[j][i].aula);
					 }
						j=j+1;
				}
				i=i+1;
				j = 0;
			}
}
int main(void) {
	int p;
	printf ("\t\t\t BENVENUTO NELLA GESTIONE DELL'ORARIO \t\t\t\n");
	CaricaOrario();
	while (p != 0){
			printf ("1:SOVRASCRIVI ORARIO \n");
			printf ("2:STAMPA ORARIO \n");
			printf ("3:CONSULTARE GIORNO SPECIFICO \n");
			printf ("4:CONSULTARE ORA SPECIFICA \n");
			printf ("5:PER MODIFICARE UNA COMPONENTE DEL RECORD \n");
			printf ("SELEZIONARE LA SCELTA:");
			scanf ("%d", & p);
			if (p == 1) {
				CaricaOrario();
			} else if (p==2) {
				StampaOrario();
			} else if (p==3) {
				 ConsultaGiorno();
			} else if (p==4) {
				 ConsultaOra();
			} else if (p==5) {
				AccediOra();
			}
	}
    system("pause");
	return EXIT_SUCCESS;
}
