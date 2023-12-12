DROP DATABASE IF EXISTS testateGiornalistiche_Appice;
CREATE DATABASE IF NOT EXISTS testateGiornalistiche_Appice;
USE testateGiornalistiche_Appice;

CREATE TABLE redazioni (
idRedazione char(4) PRIMARY KEY,
nomeComitato char(10),
citta char(8),
indirizzoWeb varchar(100)   -- ho lasciato var char per questo colonne perchè la in genere gli indirizzi web variano molto per dimensione
);

CREATE TABLE testate (
idTestata char(4) PRIMARY KEY,
nome char(20),
redazione char(4),
FOREIGN KEY (redazione)
REFERENCES redazioni (idRedazione)
);


CREATE TABLE redattori (
idRedattori char(3) PRIMARY KEY,
cognome char(10),
nome char(8),
via char(15),
citta char(15),
provincia char(2),
CAP char(5),
email varchar(50)  -- ho lasciato var char per questo colonne perchè la in genere la mail varia molto per dimensione
);


CREATE TABLE redazRedat (
idRedazione char(4),
idRedattori char(3),
PRIMARY KEY (idRedazione, idRedattori),

FOREIGN KEY (idRedazione)
REFERENCES redazioni (idRedazione),
FOREIGN KEY (idRedattori)
REFERENCES  redattori (idRedattori)
);

CREATE TABLE categorie (
nomeCategoria char(10) PRIMARY KEY,
categoriaPadre char(10),
FOREIGN KEY (categoriaPadre)
REFERENCES categorie (nomeCategoria)
);

CREATE TABLE inserzioni (
codice char(6) PRIMARY KEY,
testo text,
categoria char(10),
FOREIGN KEY (categoria)
REFERENCES categorie (nomeCategoria)
);

CREATE TABLE instest (
idInserzione char(6),
idTestata char(4),
PRIMARY KEY (idInserzione, idTestata),
FOREIGN KEY (idInserzione)
REFERENCES inserzioni (codice),
FOREIGN KEY (idTestata)
REFERENCES testate (idTestata)
);

CREATE TABLE aziende (
idAzienda char(6) PRIMARY KEY,
nomeAzienda char(40),
referente char(40),
telefono char(11),
citta char(15),
provincia char(2),
CAP char(5),       
CapitaleSociale int
);

CREATE TABLE insaz (
idAzienda char(6) ,
idInserzione char(6),
PRIMARY KEY (idAzienda, idInserzione),
FOREIGN KEY (idAzienda)
REFERENCES aziende (idAzienda),
FOREIGN KEY (idInserzione)
REFERENCES inserzioni (codice)
);

CREATE TABLE privati (
idPrivato char(3) PRIMARY KEY,
cognome char(10),
nome char(8),
via char(15),
citta char(15),
provincia char(2),
CAP char(5),
email varchar(50) -- ho lasciato var char per questo colonne perchè la in genere la mail varia molto per dimensione
);

CREATE TABLE inspriv (
idPrivato char(6) ,
idInserzione char(6) ,
PRIMARY KEY (idPrivato, idInserzione),
FOREIGN KEY (idPrivato)
REFERENCES privati (idPrivato),
FOREIGN KEY (idInserzione)
REFERENCES inserzioni (codice)
);

-- oltre a qualche errore di sintassi, non ho riscontrato problemi nella creazione delle tabelle con i rispettivi vincoli.
INSERT INTO redazioni
VALUES ('abc1','Comitato1','Roma','www.comitato1.it');
INSERT INTO redazioni
VALUES ('abc2','Comitato2','Milano','www.comitato2.it');
INSERT INTO redazioni
VALUES ('abc3','Comitato3','Napoli','www.comitato3.it');
SELECT * FROM redazioni;

INSERT INTO testate
VALUES ('abc1','Testata1','abc1');
INSERT INTO testate
VALUES ('abc2','Testata2','abc2');
INSERT INTO testate
VALUES ('abc3','Testata3','abc3');
SELECT * FROM testate;

ALTER TABLE privati 
MODIFY COLUMN nome char(30);
ALTER TABLE privati 
MODIFY COLUMN cognome char(30);
DESCRIBE privati; 


CREATE TABLE citta (
CAP char(5) PRIMARY KEY,
citta char(15),
provincia char(2)
);
DESCRIBE citta;

/* "modificare le tabelle in cui è presente l'attributo città in modo che abbiano una chiave esterna alla tabella città al posto dei tre attributi separati";
   cancello prima gli attributi provincia e citta nelle altre tabelle e lascio la colonna CAP come chiave esterna
*/
-- ho avuto difficoltà a capire questo punto della traccia perchè non sapevo se dover cancellare le colonne provincia e citta e lasciare CAP come chiave esterna
-- oppure se creare una nuova colonna idcitta che fa da chiave esterna a CAP in tabella citta. Ho optato per la prima soluzione.
-- REDAZIONI
ALTER TABLE redazioni
DROP COLUMN citta;

ALTER TABLE redazioni
ADD COLUMN CAP char(5) AFTER nomeComitato;

ALTER TABLE redazioni
ADD FOREIGN KEY (CAP)
REFERENCES citta (CAP);
-- REDATTORI
ALTER TABLE redattori
DROP COLUMN citta,
DROP COLUMN provincia;

ALTER TABLE redattori
ADD FOREIGN KEY (CAP)
REFERENCES citta (CAP);

-- AZIENDE
ALTER TABLE aziende
DROP COLUMN citta,
DROP COLUMN provincia;

ALTER TABLE aziende
ADD FOREIGN KEY (CAP)
REFERENCES citta (CAP);

-- PRIVATI
ALTER TABLE privati
DROP COLUMN citta,
DROP COLUMN provincia;

ALTER TABLE privati
ADD FOREIGN KEY (CAP)
REFERENCES citta (CAP);

/* inserire nel database tanti comitati di redazioni quante sono le testate di giornale inserite;
inserire nel database un numero di persone che compongono i comitati di redazione, tenendo conto che qualche redattore può far parte di più comitati;
modificare la tabella categorie in modo che la chiave primaria sia idCategoria anziché nomeCategoria;
inserire le categorie e ognuna con un diverso numero di sottocategorie (es. affitti e vendite sono sottocategorie di case);
inserire nelle tabelle almeno 10 inserzioni di privati e 10 inserzioni di aziende;
verificare che i dati siano stati inseriti correttamente, in particolare fare interrogazioni semplici (scrivendo SELECT * FROM nomeTabella;) sulle tabelle in cui inserite i dati non appena avete finito l'inserimento;
*/

