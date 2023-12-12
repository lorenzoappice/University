DROP DATABASE IF EXISTS testateGiornalistiche_Appice;
CREATE DATABASE IF NOT EXISTS testateGiornalistiche_Appice;
USE testateGiornalistiche_Appice;

CREATE TABLE redazioni (
idRedazione char(4) PRIMARY KEY,
nomeComitato char(10),
citta char(8),
indirizzoWeb varchar(100)   -- ho lasciato var char per questa colonna perchè genere gli indirizzi web variano molto per dimensione
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
email varchar(50)  -- ho lasciato var char per questa colonna perchè genere la mail varia molto per dimensione
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
idPrivato char(6) PRIMARY KEY,  -- ho notato che idPrivato qui era di 3 char mentre in inspriv è di 6 quindi ho deciso di lasciare 6 in privati.
cognome char(10),
nome char(8),
via char(15),
citta char(15),
provincia char(2),
CAP char(5),
email varchar(50) -- ho lasciato var char per questa colonna perchè in genere la mail varia molto per dimensione
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
VALUES ('abc2','Comitato2','Bari','www.comitato2.it');
INSERT INTO redazioni
VALUES ('abc3','Comitato3','Lecce','www.comitato3.it');

INSERT INTO testate
VALUES ('abc1','Testata1','abc1');
INSERT INTO testate
VALUES ('abc2','Testata2','abc2');
INSERT INTO testate
VALUES ('abc3','Testata3','abc3');

ALTER TABLE privati 
MODIFY COLUMN nome char(30);
ALTER TABLE privati 
MODIFY COLUMN cognome char(30);


CREATE TABLE citta (
CAP char(5) PRIMARY KEY,
citta char(15),
provincia char(2)
);

/* "modificare le tabelle in cui è presente l'attributo città in modo che abbiano una chiave esterna alla tabella città al posto dei tre attributi separati";
   cancello prima gli attributi provincia e citta nelle altre tabelle e lascio la colonna CAP come chiave esterna
*/
-- ho avuto difficoltà a capire questo punto della traccia perchè non sapevo se dover cancellare le colonne provincia e citta e lasciare CAP come chiave esterna
-- oppure se creare una nuova colonna idcitta che fa da chiave esterna a CAP in tabella citta. Ho optato per la prima soluzione.
-- REDAZIONI
ALTER TABLE redazioni
RENAME COLUMN citta TO CAP;
ALTER TABLE redazioni
MODIFY COLUMN CAP char(5);

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
modificare la tabella categorie in modo che la chiave primaria sia idCategoria anziché nomeCategoria;
inserire le categorie e ognuna con un diverso numero di sottocategorie (es. affitti e vendite sono sottocategorie di case);
inserire nelle tabelle almeno 10 inserzioni di privati e 10 inserzioni di aziende;
verificare che i dati siano stati inseriti correttamente, in particolare fare interrogazioni semplici (scrivendo SELECT * FROM nomeTabella;) sulle tabelle in cui inserite i dati non appena avete finito l'inserimento;
*/
INSERT INTO citta
VALUES ('00100','Roma','RM'); 
INSERT INTO citta
VALUES ('00010','Bari','BA');
INSERT INTO citta
VALUES ('00001','Lecce','LE');

INSERT INTO redattori 
VALUES ('001','Rossi','Mario','Via Roma','00100','mariorossi@gmail.com');
INSERT INTO redattori 
VALUES ('002','Bianchi','Mario','Via Bari','00010','mariobianchi@gmail.com');
INSERT INTO redattori 
VALUES ('003','Gialli','Luca','Via Lecce','00001','gialliluca@gmail.com');

INSERT INTO redazRedat
VALUES ('abc1','001');
INSERT INTO redazRedat
VALUES ('abc3','001');
INSERT INTO redazRedat
VALUES ('abc2','002');
INSERT INTO redazRedat
VALUES ('abc1','002');
INSERT INTO redazRedat
VALUES ('abc3','003');

/* modificare la tabella categorie in modo che la chiave primaria sia idCategoria anziché nomeCategoria; 
   In questo alter table non ho capito se dovessi semplicemente cambiare il nomecategoria in IdCategoria oppure creare una colonna 
   IdCategoria dentro categorie togliendo il pk da nomecategoria ed assegnarlo ad IdCategoria.
   Ho scelto la prima opzione, ovvero rinomino nomecategoria in IdCategoria perchè non sono riuscito a fare la seconda opzione.
*/
ALTER TABLE categorie
RENAME COLUMN nomeCategoria TO idCategoria;

INSERT INTO categorie
VALUES ('Case','Case');
INSERT INTO categorie
VALUES ('Affitti','Case');
INSERT INTO categorie
VALUES ('Vendite','Case');

INSERT INTO categorie
VALUES ('Moto','Moto');
INSERT INTO categorie
VALUES ('Benzina','Moto');
INSERT INTO categorie
VALUES ('Diesel','Moto');
-- inserizioni per aziende
INSERT INTO inserzioni  VALUES ('I00001', 'Descrizione inserzione azienda 1', 'Case');
INSERT INTO inserzioni  VALUES ('I00002', 'Descrizione inserzione azienda 2', 'Affitti');
INSERT INTO inserzioni  VALUES ('I00003', 'Descrizione inserzione azienda 3', 'Vendite');
INSERT INTO inserzioni  VALUES ('I00004', 'Descrizione inserzione azienda 4', 'Moto');
INSERT INTO inserzioni  VALUES ('I00005', 'Descrizione inserzione azienda 5', 'Benzina');
INSERT INTO inserzioni  VALUES ('I00006', 'Descrizione inserzione azienda 6', 'Diesel');
INSERT INTO inserzioni  VALUES ('I00007', 'Descrizione inserzione azienda 7', 'Moto');
INSERT INTO inserzioni  VALUES ('I00008', 'Descrizione inserzione azienda 8', 'Benzina');
INSERT INTO inserzioni  VALUES ('I00009', 'Descrizione inserzione azienda 9', 'Diesel');
INSERT INTO inserzioni  VALUES ('I00010', 'Descrizione inserzione azienda 10', 'Case');
-- inserizioni per i privati
INSERT INTO inserzioni  VALUES ('P00001', 'Descrizione inserzione priv 1', 'Case');
INSERT INTO inserzioni  VALUES ('P00002', 'Descrizione inserzione priv 2', 'Affitti');
INSERT INTO inserzioni  VALUES ('P00003', 'Descrizione inserzione priv 3', 'Vendite');
INSERT INTO inserzioni  VALUES ('P00004', 'Descrizione inserzione priv 4', 'Moto');
INSERT INTO inserzioni  VALUES ('P00005', 'Descrizione inserzione priv 5', 'Benzina');
INSERT INTO inserzioni  VALUES ('P00006', 'Descrizione inserzione priv 6', 'Diesel');
INSERT INTO inserzioni  VALUES ('P00007', 'Descrizione inserzione priv 7', 'Moto');
INSERT INTO inserzioni  VALUES ('P00008', 'Descrizione inserzione priv 8', 'Benzina');
INSERT INTO inserzioni  VALUES ('P00009', 'Descrizione inserzione priv 9', 'Diesel');
INSERT INTO inserzioni  VALUES ('P00010', 'Descrizione inserzione priv 10', 'Case');

INSERT INTO aziende 
VALUES ('000001','Azienda1','Referente1','3333333333','00100', 10000);
INSERT INTO aziende 
VALUES ('000002','Azienda2','Referente2','3333333344','00010', 11000);
INSERT INTO aziende 
VALUES ('000003','Azienda3','Referente3','3333333355','00001', 11100);

INSERT INTO privati VALUES ('PPP001', 'Rossi', 'Michele', 'Via Roma 1', '00100', 'michele.rossi@email.com');
INSERT INTO privati VALUES ('PPP002', 'Bianchi', 'Laura', 'Via Bari 2', '00010', 'laura.bianchi@email.com');
INSERT INTO privati VALUES ('PPP003', 'Verdi', 'Giuseppe', 'Via Lecce 3', '00001', 'giuseppe.verdi@email.com');

INSERT INTO insaz 
VALUES ('000001','I00001');
INSERT INTO insaz 
VALUES ('000001','I00002');
INSERT INTO insaz 
VALUES ('000001','I00003');
INSERT INTO insaz 
VALUES ('000002','I00004');
INSERT INTO insaz 
VALUES ('000002','I00005');
INSERT INTO insaz 
VALUES ('000002','I00006');
INSERT INTO insaz 
VALUES ('000003','I00007');
INSERT INTO insaz 
VALUES ('000003','I00008');
INSERT INTO insaz 
VALUES ('000003','I00009');
INSERT INTO insaz 
VALUES ('000003','I00010');


INSERT INTO inspriv  VALUES ('PPP001','P00001');
INSERT INTO inspriv  VALUES ('PPP001','P00002');
INSERT INTO inspriv  VALUES ('PPP001','P00003');
INSERT INTO inspriv  VALUES ('PPP002','P00004');
INSERT INTO inspriv  VALUES ('PPP002','P00005');
INSERT INTO inspriv  VALUES ('PPP002','P00006');
INSERT INTO inspriv  VALUES ('PPP003','P00007');
INSERT INTO inspriv  VALUES ('PPP003','P00008');
INSERT INTO inspriv  VALUES ('PPP003','P00009');
INSERT INTO inspriv  VALUES ('PPP003','P00010');

-- Ho preferito creare altre 10 diverse inserzioni solo per i privati invece di usare le stesse, per ordine mio personale.
 SELECT * FROM inserzioni;
 SELECT * FROM privati;
 SELECT * FROM aziende;
 SELECT * FROM insaz;
 SELECT * FROM inspriv;
SELECT * FROM citta;
SELECT * FROM redattori;
SELECT * FROM redazRedat;
SELECT * FROM categorie;
SELECT * FROM testate;
SELECT * FROM redazioni; -- da aggiornare il CAP dato che risulta NULL /OPPURE NOME DELLA CITTA'.