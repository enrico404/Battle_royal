/*
* Inzio modulo principale gestione delle collisioni.
* Il modulo si occupa di gestire tutte le collisioni tra oggeti nella mappa e dei colpi.
*/
/**
* @file
* Header del modulo per la gestione delle collisioni
*/


/** funzione per il check delle collisioni tra due box,
* prende in input: x del player, y del player, x dell'enemy, y dell'enemy, larghezza e altezza del player
*/
bool collision(int x, int y, int ex, int ey, int width, int height, int we, int he);


/** funzione per il check delle collisioni tra i due player e gli ostacoli della mappa */

bool check_collision_player(Barrier obstacles[], int player);

/** funzione principale per il check delle collisioni tra lo sparo e gli oggetti della mappa e tra lo sparo e i player */
bool check_collision(Barrier obstacles[], int player, int colpi1, int colpi2);
/**funzione per il controllo delle collisioni tra player e armi nel terreno di gioco */
int check_collision_weapon(weapon WArray[], int player);

/* Fine modulo gestione delle collisioni */
