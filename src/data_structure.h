/*
*  Modulo struttura dati dell'intero progetto
* @file
* Modulo per la gestione della struttura dati del gioco
*/
struct Bullet{
  bool live;
  int cx;
  int cy;

  int velocity;
  int radius;
  int Damage;

};
struct weapon{

  char nome[30];
  int id;
  int numBullets;
  Bullet *b;
  //coordinate utili per piazzare l'arma all'interno della mappa
  int x;
  int y;
};

struct player{
  float x;
  float y;
  int life;
  float movespeed;
  int sourceX;
  int sourceY;
  // int colpi;
  // char weapon[30];
  weapon arma;

};





struct Barrier{
  int x;
  int y;
  int width;
  int height;
  char rotation;
  int id;


};



/* Fine modulo struttura dati */
