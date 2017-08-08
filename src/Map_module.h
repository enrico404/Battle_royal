/**
* Header Map_module.cc  contenente i prototipi delle funzioni del modulo per generare la mappa
*/
/**
* @file
* Header del modulo di gestione della mappa
*/



/** funzione che dato in input il file della mappa, compila la matrice map */
bool getMap(ifstream &f1, int map[][COL]);
/** visualizzazione della mappa (viene visualizzata ad assi invertiti rispetto al file txt) */

void drawMap(int map[][COL], ALLEGRO_BITMAP *ground,ALLEGRO_BITMAP *ground2);

/** funzione per la generazione randomica della mappa */
void genRandomMap();





/* Fine header modulo mappa */
