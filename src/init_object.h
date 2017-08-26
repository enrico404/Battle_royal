
/*
* Header del modulo init_object.cc
*/
/**
* @file
* Header del modulo init_object.cc di inizializzazione di tutti gli oggetti del gioco
*/



/** funzione per l'inizializzazione dei player */
void init_player(player &p, float x, float y, int life, float movespeed, int sx, int sy, weapon pistol);

/** funzione per settare la posizione gli ostacoli della mappa1 */
void init_mappa1(Barrier obstacles[]);
/** funzione per settare la posizione gli ostacoli della mappa2 */
void init_mappa2(Barrier obstacles[]);
/** funzione per settare la posizione gli ostacoli della mappa3 */
void init_mappa3(Barrier obstacles[]);
/** funzione per la definizione dell'arma bazooka */
void init_bazooka(weapon &bazooka);
/** funzione per la definizione dell'arma "rifle" */
void init_rifle(weapon &rifle);
/** funzione per la definizione dell'oggetto "heart" */
void init_heart(weapon &heart);
/** funzione per la definizione dell'arma "pistola" */
void init_pistol(weapon &pistol);
/** funzione per la definizione dell'arma "shotgun" */
void init_shotgun(weapon &shotgun);
/** funzione per la definizione dell'oggetto "shoes" */
void init_shoes(weapon &shoes);
/** funzione per la definizione dell'oggetto "HeartPlus" */
void init_heartPlus(weapon &HeartPlus);
/** funzione per la definizione dell'oggetto "BulletPerf" */
void init_BulletPerf(weapon &BulletPerf);

/* fine header modulo init_object */
