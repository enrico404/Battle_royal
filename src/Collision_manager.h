/*
* Header del modulo Collision_manager.cc principale gestore delle collisioni.
*
*/
/**
* @file
* Header del modulo Collision_manager.cc per la gestione delle collisioni
*/


/** funzione per il check delle collisioni tra due box,
* prende in input: x del player, y del player, x dell'enemy, y dell'enemy, larghezza e altezza del player
*/
bool collision(int x, int y, int ex, int ey, int width, int height, int we, int he);


/** funzione per il check delle collisioni tra i due player e gli ostacoli della mappa. In caso di collisione ritorna true, altrimenti false. */

bool check_collision_player(Barrier obstacles[], int player);

/** funzione principale per il check delle collisioni tra i proiettili e gli oggetti della mappa e tra i proiettili e i player.
* in caso di collisione tra proiettile e player viene anche gestito il danno
*/
bool check_collision(Barrier obstacles[], int player, int colpi1, int colpi2);
/** funzione per il controllo delle collisioni tra player e armi nel terreno di gioco. Ritorna id oggetto colliso. Se non c'è collisione ritorna 0. */
int check_collision_weapon(weapon WArray[], int player);

/* Fine modulo gestione delle collisioni */
