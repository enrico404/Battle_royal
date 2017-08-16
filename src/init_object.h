
/*
* Header del modulo init_object.cc
*/
/**
* @file
* Header del modulo di inizializzazione di tutti gli oggetti del gioco
*/



/** funzione per l'inizializzazione dei player */
void init_player(player &p, float x, float y, int life, float movespeed, int sx, int sy);

void init_mappa1(Barrier obstacles[]);
void init_mappa2(Barrier obstacles[]);
void init_mappa3(Barrier obstacles[]);

void init_bullets(Bullet b[], int damage, int vel);

void init_bazooka(weapon &bazooka);

void init_rifle(weapon &rifle);

void init_heart(weapon &heart);
/* fine header modulo init_object */
