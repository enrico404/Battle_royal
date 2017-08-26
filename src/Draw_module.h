/*
* Header del modulo Draw_module.cc contiene i prototipi delle funzioni principali di disegno
*/
/**
* @file
* Header del modulo Draw_module.cc per la gestione delle funzioni di disegno degli oggetti nella mappa
*/

/** funzione per disegnare gli ostacoli all'interno della  mappa */
void draw_obstacles(Barrier obstacles[], ALLEGRO_BITMAP *rock, ALLEGRO_BITMAP *rockH, ALLEGRO_BITMAP *wall,ALLEGRO_BITMAP *ostacolo, ALLEGRO_BITMAP *ostacolo2, ALLEGRO_BITMAP *ostacolo3,ALLEGRO_BITMAP *cactus, ALLEGRO_BITMAP *cactus2, ALLEGRO_BITMAP *rock5, ALLEGRO_BITMAP *rock6 , ALLEGRO_BITMAP *water, ALLEGRO_BITMAP *water2, ALLEGRO_BITMAP *water3, ALLEGRO_BITMAP *palma, ALLEGRO_BITMAP *ostrica, ALLEGRO_BITMAP *ostrica2, ALLEGRO_BITMAP *albero2  );



/** funzione che disegna i proiettili ad ogni frame. Utilizzata per le armi: bazooka, pistola */
void drawBullet(Barrier obstacles[], int dir, bool &sparo, int player, int colpi1, int colpi2);
/** funzione che disegna i proiettili ad ogni frame. Utilizzata per le armi: rifle */
void drawBullet_rifle(Barrier obstacles[], int dir, bool &sparo, int player, int colpi1, int colpi2);
/** funzione che disegna i proiettili ad ogni frame. Utilizzata per le armi: shotgun */
void drawBullet_shotgun(Barrier obstacles[], int dir, bool &sparo, int player, int colpi1, int colpi2);

/** funzione per la visualizzazione del terreno di gioco (senza ostacoli). Viene visualizzata ad assi invertiti rispetto al file txt */
void drawMap(int map[][COL], ALLEGRO_BITMAP *ground,ALLEGRO_BITMAP *ground2);

/** funzione che data come parametro la vita del player come stringa la disegna
* colorata a seconda degli hp rimanenti.
*/
void drawLife(ALLEGRO_FONT *font, float x, float y, char *vita, int life );

/**
* funzione per disegnare gli oggetti all'interno della mappa
*/
void draw_items(weapon WArray[], ALLEGRO_BITMAP *bazooka, ALLEGRO_BITMAP *rifle, ALLEGRO_BITMAP *heart, ALLEGRO_BITMAP *pistol, ALLEGRO_BITMAP *shotgun, ALLEGRO_BITMAP *shoes, ALLEGRO_BITMAP *HeartPlus, ALLEGRO_BITMAP *BulletPerf);
/* Fine header modulo draw */
