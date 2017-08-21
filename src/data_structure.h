/*
*  Modulo struttura dati dell'intero progetto
* @file
* Modulo per la gestione della struttura dati del gioco
*/

/** Struct Bullet del proiettile, contiene gli attributi principlai per gestire il singolo proiettile */
struct Bullet{
  /** variabile booleana che indica se il proiettile è all'interno della mappa e vivo */
  bool live;
  /** Coordinata x attuale del proiettile */
  int cx;
  /** Coordinata y attuale del proiettile */
  int cy;
  /** Velocità del proiettile */
  int velocity;
  /** Raggio del proiettile */
  int radius;
  /** Danno del proiettile */
  int Damage;

};


/** Struc Weapon, contiene gli attributi principali per gestire la singola arma */
struct weapon{
  /** Nome dell'arma */
  char nome[30];
  /** Id dell'arma */
  int id;
  /** Numero colpi dell'arma */
  int numBullets;
  /** Array dei proiettili dell'arma */
  Bullet *b;
  /** coordinate utili per piazzare l'arma all'interno della mappa */
  int x;
  int y;
};

/** Struct Player del giocatore contenente gli attributi principli per la gestione di esso */
struct player{
  /** Coordinata x attuale del player */
  float x;
  /** Coordinata y attuale del player */
  float y;
  /** Vita rimanente del giocatore */
  int life;
  /** Velocità di movimento del player */
  float movespeed;
  /** Coordinata x utile per gestire l'animazione del player */
  int sourceX;
  /** Coordinata y utile per gestire l'animazione del player */
  int sourceY;
  /** Arma equipaggiata dal giocatore */
  weapon arma;

};




/** Struct Barrier, per la gestione degli ostacoli all'interno della mappa */
struct Barrier{
  /** Coordinata x dell'ostacolo */
  int x;
  /** Coordinata y dell'ostacolo */
  int y;
  /** Larghezza dell'ostacolo */
  int width;
  /** Altezza dell'ostacolo */
  int height;
  /** Rotazione sprite ostacolo */
  char rotation;
  /** Id dell'ostacolo */
  int id;


};



/* Fine modulo struttura dati */
