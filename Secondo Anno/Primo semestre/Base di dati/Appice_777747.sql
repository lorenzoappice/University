DROP DATABASE IF EXISTS testateGiornalistiche_Appice;
CREATE DATABASE IF NOT EXISTS testateGiornalistiche_Appice;
USE testateGiornalistiche_Appice;

CREATE TABLE redazioni (
idRedazione char(4) PRIMARY KEY,
nomeComitato char(10),
citta char(8),
indirizzoWeb varchar(50)   -- char perchè non si sa il limite di lunghezza dell'indirizzo web quindi ho preferito lasciare libertà
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
email varchar(50)  -- char perchè non si sa il limite di lunghezza della mail quindi ho preferito lasciare libertà
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
categoriaPadre char(10)
);

CREATE TABLE inserzioni (
codice char(6) PRIMARY KEY,
testo char,
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
email varchar(50) -- char perchè non si sa il limite di lunghezza della mail quindi ho preferito lasciare libertà
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