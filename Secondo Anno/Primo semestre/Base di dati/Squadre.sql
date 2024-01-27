DROP DATABASE IF EXISTS CHAMP_AppiceLorenzo;
CREATE DATABASE IF NOT EXISTS CHAMP_AppiceLorenzo;
USE CHAMP_AppiceLorenzo;

CREATE TABLE Squadra (
    Nome VARCHAR(30) PRIMARY KEY,
    Nome_A VARCHAR(20) NOT NULL,
    Città VARCHAR(30) NOT NULL
);

CREATE TABLE Giornata (
    Num_G INT,
    Girone VARCHAR(7),
    Data_partita DATE,
    PRIMARY KEY (Num_G, Girone)
);

CREATE TABLE Partita (
    Id_Partita INT Auto_increment PRIMARY KEY,
    Num_G INT ,
    Girone VARCHAR(7),
    Risultato VARCHAR(4),
    Casa VARCHAR(30),
    Fuori VARCHAR(30),
    FOREIGN KEY (Casa) REFERENCES Squadra(Nome),  
    FOREIGN KEY (Fuori) REFERENCES Squadra(Nome),
    FOREIGN KEY (Num_G, Girone) REFERENCES Giornata(Num_G, Girone)
);

CREATE TABLE Classifica (
    Nome VARCHAR(30),
    Num_G INT,
    Girone VARCHAR(7),
    Punti INT,
    PRIMARY KEY (Nome, Num_G, Girone),
    FOREIGN KEY (Nome) REFERENCES Squadra(Nome),
    FOREIGN KEY (Num_G, Girone) REFERENCES Giornata(Num_G, Girone)
);


INSERT INTO Squadra
VALUES ('Bari','Rossi','Bari');
INSERT INTO Squadra
VALUES ('Bologna','Luca','Bologna');
INSERT INTO Squadra
VALUES ('Milan','Pioli','Milano');
INSERT INTO Squadra
VALUES ('Inter','Inzaghi','Milano');

INSERT INTO Giornata 
VALUES (1,'Andata', '2021-09-01');
INSERT INTO Giornata 
VALUES (2,'Andata', '2021-10-03');
INSERT INTO Giornata 
VALUES (3,'Andata', '2022-10-01');
INSERT INTO Giornata 
VALUES (4,'Ritorno', '2021-09-05');
INSERT INTO Giornata 
VALUES (5,'Ritorno', '2021-10-08');
INSERT INTO Giornata 
VALUES (6,'Ritorno', '2022-10-10');





INSERT INTO Partita (Num_G, Girone, Risultato, Casa, Fuori)
VALUES (1,'Andata','1-1','Bari','Bologna');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (1,'Andata','2-1','Milan','Inter');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (2,'Andata','1-0','Milan','Bologna');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (2,'Andata','2-1','Bari','Inter');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (3,'Andata','0-0','Milan','Bari');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (3,'Andata','1-1','Bologna','Inter');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (4,'Ritorno','1-1','Bologna','Bari');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (4,'Ritorno','2-1','Inter','Milan');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (5,'Ritorno','1-0','Bologna','Milan');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (5,'Ritorno','2-1','Inter','Bari');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (6,'Ritorno','0-0','Bari','Milan');
INSERT INTO Partita(Num_G, Girone, Risultato, Casa, Fuori)
VALUES (6,'Ritorno','1-1','Inter','Bologna');

SELECT * FROM Partita;
INSERT INTO Classifica 
VALUES ('Bari',1,'Andata',1);
INSERT INTO Classifica 
VALUES ('Bologna',1,'Andata',1);
INSERT INTO Classifica 
VALUES ('Milan',1,'Andata',3);
INSERT INTO Classifica 
VALUES ('Inter',1,'Andata',0);
INSERT INTO Classifica 
VALUES ('Bari',2,'Andata',1+3);
INSERT INTO Classifica 
VALUES ('Bologna',2,'Andata',1);
INSERT INTO Classifica 
VALUES ('Milan',2,'Andata',3+3);
INSERT INTO Classifica 
VALUES ('Inter',2,'Andata',0);
INSERT INTO Classifica 
VALUES ('Bari',3,'Andata',1+3+1);
INSERT INTO Classifica 
VALUES ('Bologna',3,'Andata',1+1);
INSERT INTO Classifica 
VALUES ('Milan',3,'Andata',3+3+1);
INSERT INTO Classifica 
VALUES ('Inter',3,'Andata',0+1);
INSERT INTO Classifica 
VALUES ('Bari',4,'Ritorno',1+3+1+1);
INSERT INTO Classifica 
VALUES ('Bologna',4,'Ritorno',1+1+1);
INSERT INTO Classifica 
VALUES ('Milan',4,'Ritorno',3+3+1);
INSERT INTO Classifica 
VALUES ('Inter',4,'Ritorno',0+1+3);
INSERT INTO Classifica 
VALUES ('Bari',5,'Ritorno',1+3+1+1);
INSERT INTO Classifica 
VALUES ('Bologna',5,'Ritorno',1+1+1+3);
INSERT INTO Classifica 
VALUES ('Milan',5,'Ritorno',3+3+1);
INSERT INTO Classifica 
VALUES ('Inter',5,'Ritorno',0+1+3+3);
INSERT INTO Classifica 
VALUES ('Bari',6,'Ritorno',1+3+1+1+1);
INSERT INTO Classifica 
VALUES ('Bologna',6,'Ritorno',1+1+1+3+1);
INSERT INTO Classifica 
VALUES ('Milan',6,'Ritorno',3+3+1+1);
INSERT INTO Classifica 
VALUES ('Inter',6,'Ritorno',0+1+3+3+1);


SELECT Partita.casa, Squadra.città, Partita.fuori,Squadra.città, Partita.risultato FROM Partita JOIN Squadra ON Partita.casa = Squadra.nome AND Partita.fuori = Squadra.nome WHERE Partita.Num_G = 3 ;