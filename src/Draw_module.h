/*
* Header del Draw_module, contiene i prototipi delle funzioni principali di disegno
*/
/**
* @file
* Header del modulo per la gestione delle funzioni di disegno degli oggetti nella mappa
*/

/** funzione per il draw degli ostacoli nella mappa */
void draw_obstacles(Barrier obstacles[], ALLEGRO_BITMAP *rock, ALLEGRO_BITMAP *rockH, ALLEGRO_BITMAP *wall,ALLEGRO_BITMAP *ostacolo, ALLEGRO_BITMAP *ostacolo2, ALLEGRO_BITMAP *ostacolo3,ALLEGRO_BITMAP *cactus, ALLEGRO_BITMAP *cactus2, ALLEGRO_BITMAP *rock5, ALLEGRO_BITMAP *rock6  );



/** funzione che disegna i proiettili ad ogni frame */
void drawBullet(Barrier obstacles[], int dir, bool &sparo, int player, int colpi1, int colpi2);

void drawBullet_rifle(Barrier obstacles[], int dir, bool &sparo, int player, int colpi1, int colpi2);

/** visualizzazione della mappa (viene visualizzata ad assi invertiti rispetto al file txt) */

void drawMap(int map[][COL], ALLEGRO_BITMAP *ground,ALLEGRO_BITMAP *ground2);

/** funzione che data come parametro la vita del player come stringa la disegna
* colorata a seconda degli hp rimanenti
*/
void drawLife(ALLEGRO_FONT *font, float x, float y, char *vita, int life );

/**
* funzione per il draw delle armi all'interno della mappa
*/
void draw_items(weapon WArray[], ALLEGRO_BITMAP *bazooka, ALLEGRO_BITMAP *rifle, ALLEGRO_BITMAP *heart);
/* Fine header modulo draw */