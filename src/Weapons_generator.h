/**
* Header del modulo Weapons_generator.cc per la generazione delle armi sulla mappa
*/
/**
* @file
* Modulo per la generazione delle armi sulla mappa
*/



/** Funzione per creare l'array di armi (inizializzato casualmente). Prende in input l'array delle armi e tutte le possibili armi all'interno del gioco. */
void genWeaponsArray(weapon WArray[], weapon bazooka, weapon rifle, weapon heart, weapon pistol, weapon shotgun, weapon shoes, weapon HeartPlus, weapon BulletPerf);

/** funzione per settare le coordinate delle armi all'interno mappa. Prende in input Array armi e numero identificativo della mappa. */
void set_position_on_map(weapon WArray[], int mappa);


/** funzione per verificare se l'array delle armi è vuoto. Ritorna true se è vuoto, altrimenti false. */
bool is_emptyA(weapon WArray[]);

/* Fine header modulo generazione armi */
