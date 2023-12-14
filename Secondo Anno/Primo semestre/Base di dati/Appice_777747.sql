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


INSERT INTO citta
VALUES ('70125','Roma','RM'); 
INSERT INTO citta
VALUES ('00010','Bari','BA');
INSERT INTO citta
VALUES ('70126','Lecce','LE');
/* qui vado ad aggiornare la tabella redazioni il campo CAP sennò risulterà NOT NULL
   dato che l'inserimento è stato fatto prima */
   
UPDATE redazioni
SET CAP = '70125'
WHERE idRedazione = 'abc1';
UPDATE redazioni
SET CAP = '00010'
WHERE idRedazione = 'abc2';
UPDATE redazioni
SET CAP = '70126'
WHERE idRedazione = 'abc3';


INSERT INTO redattori 
VALUES ('001','Rossi','Mario','Via Roma','70125','amariorossi@gmail.com');
INSERT INTO redattori 
VALUES ('002','Bianchi','Mario','Via Bari','00010','mariobianchi@gmail.com');
INSERT INTO redattori 
VALUES ('003','Gialli','Luca','Via Lecce','70126','giallilucagmail.com');

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
INSERT INTO inserzioni  VALUES ('I70126', 'Descrizione inserzione casaz 1', 'Case');
INSERT INTO inserzioni  VALUES ('I00002', 'Descrizione inserzione azienda 2', 'Affitti');
INSERT INTO inserzioni  VALUES ('I00003', 'Descrizione inserzione azienda 3', 'Vendite');
INSERT INTO inserzioni  VALUES ('I00004', 'Descrizione inserzione  azienda 4 modic', 'Moto');
INSERT INTO inserzioni  VALUES ('I00005', 'Descrizione inserzione azienda 5', 'Benzina');
INSERT INTO inserzioni  VALUES ('I00006', 'Descrizione modic inserzione azienda 6', 'Diesel');
INSERT INTO inserzioni  VALUES ('I00007', 'Descrizione inserzione vend azienda 7', 'Moto');
INSERT INTO inserzioni  VALUES ('I00008', 'Descrizione inserzione azienda 8', 'Benzina');
INSERT INTO inserzioni  VALUES ('I00009', 'Descrizione inserzione azienda 9', 'Diesel');
INSERT INTO inserzioni  VALUES ('I00010', 'Descrizione inserzione casaz 10 vendo', 'Case');
-- inserizioni per i privati
INSERT INTO inserzioni  VALUES ('P70126', 'Descrizione vend inserzione casap 1', 'Case');
INSERT INTO inserzioni  VALUES ('P00002', 'Descrizione inserzione priv 2', 'Affitti');
INSERT INTO inserzioni  VALUES ('P00003', 'Descrizione inserzione priv 3', 'Vendite');
INSERT INTO inserzioni  VALUES ('P00004', 'Descrizione vend  inserzione modic  priv 4', 'Moto');
INSERT INTO inserzioni  VALUES ('P00005', 'Descrizione inserzione priv 5', 'Benzina');
INSERT INTO inserzioni  VALUES ('P00006', 'Descrizione inserzione priv 6', 'Diesel');
INSERT INTO inserzioni  VALUES ('P00007', 'Descrizione inserzione priv 7', 'Moto');
INSERT INTO inserzioni  VALUES ('P00008', 'Descrizione inserzione priv 8', 'Benzina');
INSERT INTO inserzioni  VALUES ('P00009', 'Descrizione inserzione priv 9', 'Diesel');
INSERT INTO inserzioni  VALUES ('P00010', 'Descrizione inserzione casap 10', 'Case');

INSERT INTO aziende 
VALUES ('070126','Azienda1','Referente1','3335563333','70125', 10000);
INSERT INTO aziende 
VALUES ('000002','Azienda2','Referente2','3333333344','00010', 11000);
INSERT INTO aziende 
VALUES ('000003','Azienda3','Referente3','5563333355','70126', 19000000);

INSERT INTO privati VALUES ('PPP001', 'Prossi', 'Michaur', 'Via Roma 1', '70125', 'michele.rossi@email.com');
INSERT INTO privati VALUES ('PPP002', 'Bianchi', 'Laura', 'Via Bari 2', '00010', 'alaura.bianchi@email.com');
INSERT INTO privati VALUES ('PPP003', 'Verdi', 'Giuseppe', 'Via Lecce 3', '70126', 'giuseppe.verdi@email.com');

INSERT INTO insaz 
VALUES ('070126','I70126');
INSERT INTO insaz 
VALUES ('070126','I00002');
INSERT INTO insaz 
VALUES ('070126','I00003');
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


INSERT INTO inspriv  VALUES ('PPP001','P70126');
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

ALTER TABLE testate ADD FOREIGN KEY (redazione)
REFERENCES redazioni (idRedazione) ON DELETE CASCADE ON UPDATE CASCADE;

/* ALTER TABLE inspriv ADD FOREIGN KEY (idInserzione)
REFERENCES inserzioni (codice) ON DELETE NOT NULL ON UPDATE NOT NULL; 
   Questo non è possibile farlo dato che una chiave primaria non può avere valore null 
   di conseguenza ho commentato la query che ho usato.
*/ 

SELECT nome FROM testate;
SELECT * FROM redattori;
SELECT cognome, nome FROM redattori;
SELECT cognome, nome , email FROM redattori;
SELECT * FROM redattori WHERE email LIKE 'a%';  
SELECT * FROM redattori WHERE email LIKE '%@%';
SELECT * FROM redattori WHERE email NOT LIKE '%@%';
SELECT nomeComitato, indirizzoWeb FROM redazioni WHERE indirizzoWeb IS NOT NULL;
SELECT testo, codice FROM inserzioni  WHERE categoria = 'Case';
SELECT codice,testo FROM inserzioni WHERE testo LIKE '%casa%';
SELECT codice,testo FROM inserzioni WHERE testo LIKE '%casa%' AND testo LIKE '%vend%';
SELECT codice,testo FROM inserzioni WHERE testo LIKE '%modic%';
SELECT * FROM privati;
SELECT * FROM privati WHERE CAP = '70125' OR CAP = '70126';
SELECT * FROM aziende WHERE telefono LIKE '%556%';


/* in questo esercizio ho avuto difficoltà nel punto dove dovessi modificare le tabelle con l'attributo città 
   E anche al punto dove bisognava modificare la tabella categoria  con idCategoria perchè non avevo capito la traccia 
   Spero che sia corretto come l'ho interpretata. 
   Non ho fatto errori di sintassi, sono dovuto andare a rivedere la parte del CASCADE dato che non me lo ricordavo.*/

-- da 21 a 38 esercitazione 3
SELECT nomeAzienda FROM aziende;
ALTER TABLE aziende ADD COLUMN annoFondazione int AFTER nomeAzienda;
UPDATE aziende SET annoFondazione = 1979
WHERE idAzienda = '070126';
UPDATE aziende SET annoFondazione = 1998
WHERE idAzienda = '000002';
UPDATE aziende SET annoFondazione = 1999
WHERE idAzienda = '000003';



SELECT nomeAzienda FROM aziende WHERE annoFondazione < 1980;
SELECT nomeAzienda FROM aziende WHERE annoFondazione > 1998;
SELECT nomeAzienda FROM aziende WHERE annoFondazione BETWEEN 1980 AND 1998;
ALTER TABLE privati ADD COLUMN civico int AFTER via;
UPDATE privati SET civico = 21
WHERE idPrivato = 'PPP001';
UPDATE privati SET civico = 22
WHERE idPrivato = 'PPP002';
UPDATE privati SET civico = 13
WHERE idPrivato = 'PPP003';
ALTER TABLE privati ADD COLUMN eta int AFTER nome;
UPDATE privati SET eta = 29
WHERE idPrivato = 'PPP001';
UPDATE privati SET eta = 31
WHERE idPrivato = 'PPP002';
UPDATE privati SET eta = 32
WHERE idPrivato = 'PPP003';
INSERT INTO privati VALUES ('PPP004', 'Rossi', 'Michele',22 ,'Via Lecce 3',18, '70126', 'Rossi.Michele@email.com');
INSERT INTO privati VALUES ('PPP005', 'Gialli', 'Arnold',22 ,'Via Lecce 3',18, '70126', 'Gialli.Arnold@email.com');

SELECT idPrivato,cognome,nome,eta,via,civico,CAP,email FROM privati;
SELECT nome,cognome,civico FROM privati WHERE civico > 20;
SELECT nome,cognome,civico FROM privati WHERE civico BETWEEN 10 AND 15;
SELECT nome,cognome,via,civico,CAP as Codice_Avviamento_Postale FROM privati WHERE civico BETWEEN 15 AND 30;
SELECT nomeAzienda,CapitaleSociale,CapitaleSociale/2 as Plafond_max_disponibile FROM aziende;
SELECT eta,nome FROM privati WHERE eta < 30;
SELECT nomeComitato FROM redazioni WHERE nomeComitato LIKE "%m%t%"; -- non ho nomecomitato senza m e t come sotto stringa quindi mi da tutti e 3 i comitati.
CREATE TABLE PrivatiGiovani AS SELECT * FROM privati WHERE eta <30; -- ho un avuto dei dubbi su fare queste due query e ho lasciato cosi confrontandomi con i compagni di corso.
-- INSERT INTO PrivatiGiovani Select * FROM privati WHERE eta < 30;


UPDATE PrivatiGiovani SET cognome = "Rossi" WHERE cognome LIKE "P%";
UPDATE PrivatiGiovani SET nome = "Arnold" WHERE nome LIKE "%aur%";

SELECT cognome,nome as NICK,eta FROM privati WHERE nome = "Arnold";  
SELECT CONCAT(cognome,nome) as Pilota, eta FROM privati WHERE cognome = "Rossi";
SELECT * FROM aziende WHERE telefono LIKE "080%"; -- non ho aziende con telefono che inizia con 000 quindi non mi da nessun azienda con questa SELECT.

/* PrivatiGiovani non dovrebbe contenere i vincoli di integrità interrelazionali mi è rimasto questo dubbio alla riga 393 ,
 oltre questo ho riscontrato un problema col CONCAT.(perchè non ricordavo come si facesse),l'ho risolto.
     */

-- Esercitazione numero 4
ALTER TABLE aziende ADD COLUMN civico int AFTER CAP;  -- Mi sono accorto che mancavano i civici nelle aziende leggendo il primo punto alla traccia
UPDATE aziende SET civico = 21
WHERE idAzienda = '070126';
UPDATE aziende SET civico = 22
WHERE idAzienda = '000002';
UPDATE aziende SET civico = 13
WHERE idAzienda = '000003';

SELECT nomeAzienda,civico FROM aziende WHERE civico > 15;
SELECT nomeAzienda,annoFondazione FROM aziende WHERE annoFondazione < 1980;
SELECT nomeAzienda FROM aziende WHERE annoFondazione BETWEEN 1980 AND 1998;
SELECT codice,testo,categoria FROM inserzioni;
SELECT * FROM insaz;
-- PRODOTTO CARTESIANO  (ho dovuto modificare la consegna da qui perchè il prodotto cartesiano l'avevo fatto utilizzando il cross join, il quale è molto simile ma non era richiesto nell'esercizio, me ne sono accorto solo dopo)
SELECT insaz.idInserzione,aziende.nomeAzienda,aziende.referente,aziende.telefono FROM insaz,aziende WHERE insaz.idAzienda = aziende.idAzienda; 
SELECT inserzioni.codice,inserzioni.testo,inserzioni.categoria, aziende.nomeAzienda,aziende.referente,aziende.telefono FROM inserzioni,aziende,insaz WHERE insaz.idAzienda = aziende.idAzienda AND insaz.idInserzione = inserzioni.codice;
SELECT pubblicazioni.codice,pubblicazioni.testo,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni AS pubblicazioni,aziende AS elenco_aziende,insaz AS IA WHERE IA.idAzienda = elenco_aziende.idAzienda AND IA.idInserzione = pubblicazioni.codice;
SELECT pubblicazioni.codice AS codice_articolo,pubblicazioni.testo AS descrzione,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni AS pubblicazioni,aziende AS elenco_aziende,insaz AS IA WHERE IA.idAzienda = elenco_aziende.idAzienda AND IA.idInserzione = pubblicazioni.codice;
SELECT pubblicazioni.codice AS codice_articolo,pubblicazioni.testo AS descrzione,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni AS pubblicazioni,aziende AS elenco_aziende,insaz AS IA WHERE IA.idAzienda = elenco_aziende.idAzienda AND IA.idInserzione = pubblicazioni.codice AND elenco_aziende.capitaleSociale > 18000000;
SELECT nome FROM privati;
-- è stata modificata anche questo perchè nella consegna prima della modifica non prendevo tutti i nomi , ho risolto in questo modo.
SELECT DISTINCT nome FROM redattori UNION
SELECT DISTINCT nome FROM privati UNION
SELECT DISTINCT nomeAzienda AS nome FROM aziende UNION
SELECT DISTINCT nomeComitato AS nome FROM redazioni UNION
SELECT DISTINCT nome FROM testate UNION
SELECT DISTINCT idCategoria AS nome FROM categorie;

-- Da 45-48 col NATURAL JOIN (anche questo ho dovuto modificare perchè avevo usato in moodo sbagliato il NATURAL JOIN)

SELECT insaz.idInserzione,aziende.nomeAzienda,aziende.referente,aziende.telefono FROM insaz NATURAL JOIN aziende;
SELECT inserzioni.codice,inserzioni.testo,inserzioni.categoria, aziende.nomeAzienda,aziende.referente,aziende.telefono FROM inserzioni NATURAL JOIN aziende NATURAL JOIN insaz WHERE insaz.idInserzione = inserzioni.codice;
SELECT pubblicazioni.codice,pubblicazioni.testo,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni as pubblicazioni NATURAL JOIN aziende AS elenco_aziende NATURAL JOIN insaz AS IA WHERE IA.idInserzione = pubblicazioni.codice;
SELECT pubblicazioni.codice AS codice_articolo,pubblicazioni.testo AS descrzione,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni AS pubblicazioni NATURAL JOIN aziende AS elenco_aziende NATURAL JOIN insaz AS IA WHERE IA.idInserzione = pubblicazioni.codice;
SELECT pubblicazioni.codice AS codice_articolo,pubblicazioni.testo AS descrzione,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni AS pubblicazioni NATURAL JOIN aziende AS elenco_aziende NATURAL JOIN insaz AS IA WHERE elenco_aziende.capitaleSociale > 18000000 AND IA.idInserzione = pubblicazioni.codice;

-- Da 45-48 col JOIN (anche questo ho dovuto modificare perchè avevo usato in moodo sbagliato il JOIN)
SELECT insaz.idInserzione,aziende.nomeAzienda,aziende.referente,aziende.telefono FROM insaz JOIN aziende ON insaz.idAzienda = aziende.idAzienda;
SELECT inserzioni.codice,inserzioni.testo,inserzioni.categoria, aziende.nomeAzienda,aziende.referente,aziende.telefono FROM inserzioni JOIN aziende  JOIN insaz ON insaz.idInserzione = inserzioni.codice AND insaz.idAzienda = aziende.idAzienda;
SELECT pubblicazioni.codice,pubblicazioni.testo,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni as pubblicazioni JOIN aziende AS elenco_aziende JOIN insaz AS IA ON IA.idInserzione = pubblicazioni.codice AND IA.idAzienda = elenco_aziende.idAzienda;
SELECT pubblicazioni.codice AS codice_articolo,pubblicazioni.testo AS descrzione,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni AS pubblicazioni JOIN aziende AS elenco_aziende  JOIN insaz AS IA ON IA.idAzienda = elenco_aziende.idAzienda AND IA.idInserzione = pubblicazioni.codice;
SELECT pubblicazioni.codice AS codice_articolo,pubblicazioni.testo AS descrzione,pubblicazioni.categoria, elenco_aziende.nomeAzienda,elenco_aziende.referente,elenco_aziende.telefono FROM inserzioni AS pubblicazioni JOIN aziende AS elenco_aziende JOIN insaz AS IA ON elenco_aziende.capitaleSociale > 18000000 AND IA.idInserzione = pubblicazioni.codice;

SELECT insaz.idInserzione,aziende.nomeAzienda,aziende.referente,aziende.telefono FROM insaz,aziende WHERE insaz.idAzienda = aziende.idAzienda ORDER BY aziende.telefono ASC; 
SELECT insaz.idInserzione,aziende.nomeAzienda,aziende.referente,aziende.telefono FROM insaz,aziende WHERE insaz.idAzienda = aziende.idAzienda ORDER BY aziende.telefono DESC;

SELECT aziende.*,citta.CAP FROM aziende,citta WHERE aziende.CAP = citta.CAP;

SELECT aziende.*,citta.citta FROM aziende, citta WHERE aziende.CAP = citta.CAP;
SELECT privati.*,citta.CAP FROM privati,citta WHERE privati.CAP = citta.CAP;

SELECT privati.*,citta.* FROM privati,citta WHERE privati.CAP = citta.CAP;
-- visualizzare l'elenco delle città e per ogni città, nome dell'azienda che ha sede nella città,
--  nome e cognome dei privati che risiedono nella città (fare attenzione a non visualizzare due volte le stesse informazioni);
    

-- visualizzare i privati che hanno un cognome iniziante con la lettera P oppure con la lettera A, indicando i codici delle inserzioni che questi hanno fatto
SELECT privati.nome,privati.cognome,privati.idPrivato,inspriv.idInserzione FROM privati  NATURAL JOIN inspriv WHERE privati.cognome LIKE 'P%' OR privati.cognome LIKE 'A%';
