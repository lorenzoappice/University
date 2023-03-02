#include <stdio.h>
#include <stdlib.h>
void inputfile(FILE *fp);
void outputfile(FILE *fp);
void counterwords(FILE *fp);
void charcounter(FILE *fp);
int main(void) {
	setbuf(stdin, NULL);
	FILE *file_write, *file_read,*file_counter,*file_counter2;
	char scelta;
	int casi=1;
	do {
		printf("\nIndicami la scelta che vuoi fare:\n");
		printf("1- Inserisci nel file una stringa.\n");
		printf("2- Visualizza contenuto File.\n");
		printf("3- Conta parole,caratteri e righe del file.\n");
		printf("4- Cancellazione contenuto File.\n");
		printf("0- Exit\n");
		scanf(" %c", &scelta);
		if(scelta =='1')
		{
			system("cls");
			file_write = fopen("C:/Users/Lorenzo/OneDrive/Desktop/Appunti/Programmazione/eclipse-workspace/Es2 file/Debug/Es2.txt", "a+");
			inputfile(file_write);
			fclose(file_write);
		}
		else if (scelta == '2')
		{
			system("cls");
			file_read = fopen("C:/Users/Lorenzo/OneDrive/Desktop/Appunti/Programmazione/eclipse-workspace/Es2 file/Debug/Es2.txt", "r");
			outputfile(file_read);
			fclose(file_read);
		}
		else if (scelta == '3')
		{
			system("cls");
			file_counter= fopen("C:/Users/Lorenzo/OneDrive/Desktop/Appunti/Programmazione/eclipse-workspace/Es2 file/Debug/Es2.txt","r");
			counterwords(file_counter);
			fclose(file_counter);
			file_counter2= fopen("C:/Users/Lorenzo/OneDrive/Desktop/Appunti/Programmazione/eclipse-workspace/Es2 file/Debug/Es2.txt","r");
		    charcounter(file_counter2);
		    fclose(file_counter2);
				}
		else if (scelta == '4')
		{
			system("cls");
			FILE*file_del= fopen("C:/Users/Lorenzo/OneDrive/Desktop/Appunti/Programmazione/eclipse-workspace/Es2 file/Debug/Es2.txt","w");
			fclose(file_del);
			//printf("Cancellazione non disponibile per il momento!!\n");
		}
		else if (scelta == '0')
		{
			casi=0;
		}
		else
		{
			casi=0;
		}
	} while(casi != 0);
	system("pause");
	return EXIT_SUCCESS;
}
void counterwords(FILE *fp){
	int n_par=0;//intero che conta le parole del testo.
	int fine_parola=0; //0 se parola terminata, 1 parola non terminata
	char c=fgetc(fp);
	while (c != EOF)
	{
		if((c==' '||c=='.'||c==','||c==';'||c=='\n') && fine_parola==1)
		{
			fine_parola=0;
			n_par=n_par+1;
		}
		else if(c!=' '||c!='.'||c!=','||c!=';'||c!='\n')
		{
			fine_parola=1;
		}
		c=fgetc(fp);
	}
	if(fine_parola==1)
	{
		n_par=n_par+1;
	}
	printf("\nLe parole in totale nel file sono: %d\n ", n_par);
	 return;
}
/*
fopen()- crea un nuovo file o apri un file esistente
fclose()- chiude un file
getc()- legge un carattere da un file
putc()- scrive un carattere in un file
fscanf()- legge un insieme di dati da un file
fprintf()- scrive un insieme di dati in un file
getw()- legge un numero intero da un file
putw()- scrive un numero intero in un file
fseek()- imposta la posizione sul punto desiderato
ftell()- fornisce la posizione corrente nel file
rewind()- imposta la posizione al punto iniziale
feof()- 0 se non è stata raggiunta la fine del file , diverso da 0 se raggiunta la fine.
 */
void charcounter(FILE *fp){
	if(fp!=NULL)
	{
    int num_chars=0;
    char c=fgetc(fp);
   do
    	{
	   num_chars=num_chars+1;
	   if(c== ' '||c=='\n')
	   {
		   num_chars=num_chars-1;
	   }
    	 c=fgetc(fp);
    	} while(!feof(fp));

    printf("Il file contiene %d caratteri.\n", num_chars);
	}
	else
	{
		printf("[!] Errore durante l'apertura del file!");
	}
	return;
}
void inputfile(FILE *fp) {
	char stringa[50];
	printf("\n-----------------------------------------\n");
	if (fp != NULL) {
		printf("[+] File aperto con successo!\n");
		printf("Indicami cosa vuoi inserire nel file:\n");
		fflush(stdin);
		gets(stringa);
		fprintf(fp,"\n%s", stringa);
		printf("[+] Scrittura effettuata!\n");
	} else {
		printf("[!] Errore durante l'apertura del file!");
	}
	printf("\n-----------------------------------------\n");
	return;
}
void outputfile(FILE *fp) {
	char stringa[50];
	printf("\n-----------------------------------------\n");
	if (fp !=NULL) {
		printf("[+] File aperto con successo per la lettura!\n");
			while (!feof(fp))
			{
			fgets(stringa, 50, fp);
			printf("%s",stringa);
			fflush(stdout);
			}
	} else
	{
		printf("[!] Errore durante l'apertura del file per la lettura!");
	}
	printf("\n-----------------------------------------\n");
	return;
}
