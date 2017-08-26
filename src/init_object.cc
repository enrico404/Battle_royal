
/*
* Inizio modulo inizializzazione oggetti. Il seguente modulo si occupa di inizializzare ogni nuovo oggetto che viene
* istanziato all'interno del gioco
*/

/**
* @file
* Modulo di inizializzazione di tutti gli oggetti del gioco
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


#include "define.h"
#include "data_structure.h"
#include "init_object.h"

extern player p2;
ALLEGRO_SAMPLE *damageL;
ALLEGRO_SAMPLE *damageR;


/** numero colpi bazooka */
extern int NbulletBazooka;
/** raggio colpo bazooka */
extern int radiusBazooka;
/** velocità colpo bazooka */
extern int vel_bazooka;
/** danno colpo del bazooka */
extern int damageBazooka;
/** numero colpi shotgun */
extern int NbulletShotgun;
/** raggio colpo shotgun */
extern int radiusShotgun;
/**velocità colpo shotgun */
extern int vel_shotgun;
/** danno colpo del shotgun */
extern int damageShotgun;
/** radius del proiettile della pistola */
extern int radiusB;
/** numero colpi pistola */
extern int NbulletPistol;
/** danno della pistola */
extern int damagePistol;
/** velocità colpo pistola */
extern int vel_pistol;
/** velocità colpo rifle. */
extern int vel_Rifle;
/** danno colpo del rifle */
extern int damagerifle;
/** numero colpi rifle */
extern int NbulletRifle;

void init_player(player &p, float x, float y, int life, float movespeed, int sx, int sy, weapon pistol){
  p.x  = x;
  p.y = y;
  p.life = life;
  p.movespeed = movespeed;
  p.sourceX = sx;
  p.sourceY = sy;
  p.arma = pistol;

}

/** funzione principale per l'inizializzazione della prima mappa */

void init_mappa1(Barrier obstacles[]){

  for(int i=0; i<NUM_OBSTACLES; i++){
    obstacles[i].x = 9999;
    obstacles[i].y = 9999;
    obstacles[i].width = 60;
    obstacles[i].height = 100;
    obstacles[i].rotation = 'v';

  }
  int i=0;
  //VERTICAL OBSTACLES.
  //base player 1
  obstacles[i].x=100;
  obstacles[i].y=0;
  obstacles[i].id = 1;
  obstacles[++i].x=100;
  obstacles[i].y=100;
  obstacles[i].id = 1;
  obstacles[++i].x = 100;
  obstacles[i].y = 200;
  obstacles[i].id = 1;
  obstacles[++i].x = 100;
  obstacles[i].y = 720;
  obstacles[i].id = 1;
  obstacles[++i].x = 100;
  obstacles[i].y = 620;
  obstacles[i].id = 1;
  obstacles[++i].x = 100;
  obstacles[i].y = 520;
  obstacles[i].id = 1;
  //base player 2
  obstacles[++i].x=Swidth-200;
  obstacles[i].y=0;
  obstacles[i].id = 1;
  obstacles[++i].x=Swidth-200;
  obstacles[i].y=100;
  obstacles[i].id = 1;
  obstacles[++i].x = Swidth-200;
  obstacles[i].y = 200;
  obstacles[i].id = 1;
  obstacles[++i].x = Swidth-200;
  obstacles[i].y = 720;
  obstacles[i].id = 1;
  obstacles[++i].x = Swidth-200;
  obstacles[i].y = 620;
  obstacles[i].id = 1;
  obstacles[++i].x = Swidth-200;
  obstacles[i].y = 520;
  obstacles[i].id = 1;

  //parte centrale
  obstacles[++i].x = 420;
  obstacles[i].y = 500;
  obstacles[i].id = 2;
  obstacles[++i].x = 420;
  obstacles[i].y = 400;
  obstacles[i].id = 2;
  obstacles[++i].x = 620;
  obstacles[i].y = 280;
  obstacles[i].id = 2;
  obstacles[++i].x = 620;
  obstacles[i].y = 180;
  obstacles[i].id = 2;
  obstacles[++i].x = 620;
  obstacles[i].y = 80;
  obstacles[i].id = 2;

  //parte destra staccata
  obstacles[++i].x = 650;
  obstacles[i].y = 600;
  obstacles[i].id = 2;
  obstacles[++i].x = 650;
  obstacles[i].y = 500;
  obstacles[i].id = 2;

  //parte sinistra staccata
  obstacles[++i].x = 350;
  obstacles[i].y = 0;
  obstacles[i].id = 2;
  obstacles[++i].x = 350;
  obstacles[i].y = 100;
  obstacles[i].id = 2;

  //HORIZONTAL OBSTACLES
  obstacles[++i].x = 420;
  obstacles[i].y = 340;
  obstacles[i].rotation = 'h';
  obstacles[i].id = 2;
  obstacles[i].width = 100;
  obstacles[i].height = 60;
  obstacles[++i].x = 520;
  obstacles[i].y = 340;
  obstacles[i].rotation = 'h';
  obstacles[i].id = 2;
  obstacles[i].width = 100;
  obstacles[i].height = 60;

}


void init_mappa2(Barrier obstacles[]){
  for(int i=0; i<NUM_OBSTACLES; i++){
    obstacles[i].x = 9999;
    obstacles[i].y = 9999;
    obstacles[i].width = 150;
    obstacles[i].height = 150;
    obstacles[i].rotation = 'v';

  }
  int i=0;
  //CENTRAL OBSTACLES
  obstacles[i].x=320;
  obstacles[i].y=250;
  obstacles[i].id = 3;
  obstacles[++i].x=175;
  obstacles[i].y=350;
  obstacles[i].id = 3;
  obstacles[++i].x=470;
  obstacles[i].y=250;
  obstacles[i].id = 4;
  obstacles[++i].x = 620;
  obstacles[i].y = 250;
  obstacles[i].id = 5;


  //cactus
  obstacles[++i].x=1060;
  obstacles[i].y=60;
  obstacles[i].id = 7;
  obstacles[i].width = 55;
  obstacles[i].height = 83;
  obstacles[++i].x=30;
  obstacles[i].y=610;
  obstacles[i].id = 6;
  obstacles[i].width = 36;
  obstacles[i].height = 54;

  //rock
  obstacles[++i].x=500;
  obstacles[i].y=30;
  obstacles[i].id = 8;
  obstacles[i].width = 62;
  obstacles[i].height = 55;
  obstacles[++i].x=400;
  obstacles[i].y=640;
  obstacles[i].id = 9;
  obstacles[i].width = 47;
  obstacles[i].height = 44;


}

void init_mappa3(Barrier obstacles[]){
  for(int i=0; i<NUM_OBSTACLES; i++){
    obstacles[i].x = 9999;
    obstacles[i].y = 9999;
    obstacles[i].width = 100;
    obstacles[i].height = 60;
    obstacles[i].rotation = 'v';

  }
  int i=0;
  //WATER
  obstacles[i].x=0;
  obstacles[i].y=320;
  obstacles[i].id = 10;
  obstacles[++i].x=100;
  obstacles[i].y=320;
  obstacles[i].id = 10;
  obstacles[++i].x=200;
  obstacles[i].y=320;
  obstacles[i].id = 10;
  obstacles[++i].x = 300;
  obstacles[i].y = 320;
  obstacles[i].id = 10;
  obstacles[++i].x=400;
  obstacles[i].y=320;
  obstacles[i].id = 10;
  obstacles[++i].x=500;
  obstacles[i].y=320;
  obstacles[i].id = 10;
  obstacles[++i].x=600;
  obstacles[i].y=320;
  obstacles[i].id = 10;
  obstacles[++i].x = 700;
  obstacles[i].y = 320;
  obstacles[i].id = 11;

  obstacles[++i].x=900;
  obstacles[i].y=320;
  obstacles[i].id = 12;
  obstacles[++i].x=1000;
  obstacles[i].y=320;
  obstacles[i].id = 10;

  //albero2
  obstacles[++i].x=1000;
  obstacles[i].y=100;
  obstacles[i].id = 16;
  obstacles[i].width = 70;
  obstacles[i].height = 100;
  obstacles[++i].x=1000;
  obstacles[i].y=-20;
  obstacles[i].id = 16;
  obstacles[i].width = 70;
  obstacles[i].height = 100;
  obstacles[++i].x=950;
  obstacles[i].y = 65;
  obstacles[i].id = 16;
  obstacles[i].width = 70;
  obstacles[i].height = 100;
  obstacles[++i].x=800;
  obstacles[i].y=600;
  obstacles[i].id = 16;
  obstacles[i].width = 70;
  obstacles[i].height = 100;




  //palma
  obstacles[++i].x=50;
  obstacles[i].y=600;
  obstacles[i].id = 13;
  obstacles[i].width = 62;
  obstacles[i].height = 71;
  obstacles[++i].x=110;
  obstacles[i].y=600;
  obstacles[i].id = 13;
  obstacles[i].width = 62;
  obstacles[i].height = 71;
  obstacles[++i].x=50;
  obstacles[i].y=530;
  obstacles[i].id = 13;
  obstacles[i].width = 62;
  obstacles[i].height = 71;
  obstacles[++i].x=20;
  obstacles[i].y=240;
  obstacles[i].id = 13;
  obstacles[i].width = 62;
  obstacles[i].height = 71;

  //ostriche
  obstacles[++i].x=112;
  obstacles[i].y=530;
  obstacles[i].id = 14;
  obstacles[i].width = 22;
  obstacles[i].height = 25;
  obstacles[++i].x=1025;
  obstacles[i].y=530;
  obstacles[i].id = 15;
  obstacles[i].width = 10;
  obstacles[i].height = 10;
  obstacles[++i].x=12;
  obstacles[i].y=120;
  obstacles[i].id = 14;
  obstacles[i].width = 22;
  obstacles[i].height = 25;
  obstacles[++i].x=1002;
  obstacles[i].y=530;
  obstacles[i].id = 14;
  obstacles[i].width = 22;
  obstacles[i].height = 25;
  obstacles[++i].x=700;
  obstacles[i].y=130;
  obstacles[i].id = 14;
  obstacles[i].width = 22;
  obstacles[i].height = 25;



}


void init_bazooka(weapon &Bazooka){
  Bazooka.id = 1;
  strcpy(Bazooka.nome, "bazooka");
  Bazooka.numBullets = NbulletBazooka;

  //inizializzo i proiettili
  Bazooka.b = new Bullet[Bazooka.numBullets];
  for(int i=0; i<Bazooka.numBullets; i++){
    Bazooka.b[i].live = false;
    Bazooka.b[i].cx = 0;
    Bazooka.b[i].cy = 0;
    Bazooka.b[i].velocity = vel_bazooka;
    Bazooka.b[i].radius = radiusBazooka;
    Bazooka.b[i].Damage = damageBazooka;


  }
  Bazooka.x = 9999;
  Bazooka.y = 9999;
}

void init_shoes(weapon &shoes){
  shoes.id = 6;
  strcpy(shoes.nome, "shoes");
  shoes.numBullets = 0;

}


void init_shotgun(weapon &shotgun){
  shotgun.id = 5;
  strcpy(shotgun.nome, "shotgun");
  shotgun.numBullets = NbulletShotgun;

  //inizializzo i proiettili
  shotgun.b = new Bullet[shotgun.numBullets];
  for(int i=0; i<shotgun.numBullets; i++){
    shotgun.b[i].live = false;
    shotgun.b[i].cx = 0;
    shotgun.b[i].cy = 0;
    shotgun.b[i].velocity = vel_shotgun;
    shotgun.b[i].radius = radiusShotgun;
    shotgun.b[i].Damage = damageShotgun;


  }
  shotgun.x = 9999;
  shotgun.y = 9999;
}



void init_pistol(weapon &pistol){
  strcpy(pistol.nome, "pistol");
  pistol.id = 4;
  pistol.numBullets = NbulletPistol;
  pistol.x =9999;
  pistol.y = 9999;
  pistol.b = new Bullet[NbulletPistol];
  for(int i=0; i<pistol.numBullets; i++){
    pistol.b[i].live = false;
    pistol.b[i].cx = 9999;
    pistol.b[i].cy =9999;
    pistol.b[i].velocity = vel_pistol;
    pistol.b[i].radius = radiusB;
    pistol.b[i].Damage = damagePistol;
  }
}


void init_rifle(weapon &rifle){
  rifle.id = 2;
  strcpy(rifle.nome, "rifle");
  rifle.numBullets = NbulletRifle;

  //inizializzo i proiettili
  rifle.b = new Bullet[rifle.numBullets];
  for(int i=0; i<rifle.numBullets; i++){
    rifle.b[i].live = false;
    rifle.b[i].cx = 0;
    rifle.b[i].cy = 0;
    rifle.b[i].velocity = vel_Rifle;
    rifle.b[i].radius = radiusB;
    rifle.b[i].Damage = damagerifle;


  }
  rifle.x = 9999;
  rifle.y = 9999;
}

void init_heart(weapon &heart){
  heart.id = 3;
  strcpy(heart.nome, "heart");
  heart.numBullets = 0;

}


void init_heartPlus(weapon &HeartPlus){
  HeartPlus.id = 7;
  strcpy(HeartPlus.nome, "HeartPlus");
  HeartPlus.numBullets = 0;

}


void init_BulletPerf(weapon &BulletPerf){
  BulletPerf.id = 8;
  strcpy(BulletPerf.nome, "BulletPerf");
  BulletPerf.numBullets = 0;

}
