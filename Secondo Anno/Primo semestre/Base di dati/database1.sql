-- mysqlsh
-- \c root@localhost
-- \sql 

DROP DATABASE IF EXISTS dbinf23;
CREATE DATABASE IF NOT EXISTS dbinf23;
USE dbinf23; 
CREATE TABLE Impiegati (
  matricola char(7) PRIMARY KEY,
  nome char(30),
  cognome char(30),
  reparto char(18)
);

DESCRIBE Impiegati;

CREATE TABLE Reparti (
	cod_reparto char(18),
	nome_reparto varchar (25),
	num_dipendenti int,
  CONSTRAINT PRIMARY KEY (cod_reparto),
  CHECK (num_dipendenti > 0 AND num_dipendenti < 50)
);

DESCRIBE Reparti;
 
ALTER TABLE Impiegati  
ADD FOREIGN KEY (reparto)
REFERENCES Reparti (cod_reparto)
ON DELETE CASCADE
ON UPDATE CASCADE;

INSERT INTO Reparti VALUES ('hr','Personale',15);
INSERT INTO Reparti VALUES ('pr','Produzione',44);

INSERT INTO Impiegati VALUES ('111111','Mario','Rossi','hr'),
('111112','Luci','Verdi','hr'),
('111113','Rocco','Gialli','pr'),
 ('111114','Michelle','Bianchi','pr');
INSERT INTO Impiegati (matricola,cognome,reparto) 
VALUES ('111115','Blu','hr');


-- SHOW TABLES;
-- DESCRIBE Impiegati;
-- DESCRIBE Reparti;
-- SELECT * from Impiegati;
-- SELECT * from Reparti;

CREATE TABLE Impiegatipr (
  matricola char(7) PRIMARY KEY,
  cognome char(30),
  nome char(30),
  reparto char(8),
  CONSTRAINT chiaveesternareparti_FK
  FOREIGN KEY (reparto) REFERENCES Reparti (cod_reparto)
  ON DELETE CASCADE
  ON UPDATE CASCADE
);


INSERT INTO Impiegatipr
SELECT * FROM Impiegati
WHERE reparto = 'pr';

SELECT * FROM Impiegati;
SELECT * FROM Reparti;
SELECT * FROM Impiegatipr;

ALTER TABLE Impiegati
ADD COLUMN daeliminare char(35) AFTER matricola,
ADD COLUMN eliminodipiu char(35) AFTER daeliminare;

ALTER TABLE Impiegati
ADD COLUMN (col1 char(35),col2 char(35));
DESCRIBE Impiegati;

ALTER TABLE Impiegati
DROP COLUMN daeliminare,
DROP COLUMN eliminodipiu,
DROP COLUMN col1,
DROP COLUMN col2;
DESCRIBE Impiegati;

SELECT DISTINCT reparto FROM Impiegati ORDER BY reparto DESC;
-- NON ABUSARE DI DISTINCT;
-- INSERT reparti VALUES ('sr','Produzione',0);
-- UPDATE Impiegati SET cognome = "Rossini"
-- WHERE cognome = "Rossi";
-- SELECT * FROM Impiegati;

-- DELETE FROM Reparti;
UPDATE Reparti
SET cod_reparto = "HumanResources"
WHERE cod_reparto = "hr";
SELECT * from Impiegati;
SELECT * from Impiegatipr;

SELECT i.cognome as Cognome,i.nome as Nome 
FROM impiegati i
WHERE i.cognome = "Gialli";

SELECT nome_reparto, num_dipendenti/2 as Dipendenti_rimasti FROM Reparti;

CREATE TABLE esami (
  nome_esame char(35),
  cfu_esame int,
  voto_esame int,
  lode bool
);

INSERT INTO esami VALUES ('ASD',9,20,0);
INSERT INTO esami VALUES ('Basi',9,18,0);
INSERT INTO esami VALUES ('Fisica',6,26,0);
INSERT INTO esami VALUES ('Statistica',6,22,0);
INSERT INTO esami VALUES ('Discreta',9,18,0);
INSERT INTO esami VALUES ('Programmazione',12,30,1);

SELECT avg(voto_esame)as Media FROM esami;

-- non posso stamparli insieme queste due select
SELECT nome_esame as denominazione from esami;

SELECT sum(voto_esame * cfu_esame)/sum(cfu_esame) as votopesato 
FROM esami;
-- fino qui

SELECT  * FROM esami WHERE nome_esame LIKE "%mm%";
SELECT  * FROM esami WHERE nome_esame LIKE "%si%";

