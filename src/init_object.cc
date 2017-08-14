
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

void init_player(player &p, float x, float y, int life, float movespeed, int sx, int sy){
  p.x  = x;
  p.y = y;
  p.life = life;
  p.movespeed = movespeed;
  p.sourceX = sx;
  p.sourceY = sy;
  strcpy(p.arma.nome, "pistol");
  p.arma.id = 4;
  p.arma.numBullets = NbulletPistol;
  p.arma.x =0;
  p.arma.y = 0;
  p.arma.b = new Bullet[NbulletPistol];
  for(int i=0; i<p.arma.numBullets; i++){
    p.arma.b[i].live = false;
    p.arma.b[i].cx = 9999;
    p.arma.b[i].cy =9999;
    p.arma.b[i].velocity = vel_pistol;
    p.arma.b[i].radius = radiusB;
    p.arma.b[i].Damage = damagePistol;
  }


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



void init_bullets(Bullet b[], int damage, int vel){
  for(int i=0; i<NbulletPistol; i++){
    b[i].live = false;
    b[i].cx = p2.x;
    b[i].cy =p2.y;
    b[i].velocity = vel;
    b[i].radius = radiusB;
    b[i].Damage = damage;
  }
}

void init_bazooka(weapon &bazooka){
  bazooka.id = 1;
  strcpy(bazooka.nome, "bazooka");
  bazooka.numBullets = NbulletBazooka;

  //inizializzo i proiettili
  bazooka.b = new Bullet[bazooka.numBullets];
  for(int i=0; i<bazooka.numBullets; i++){
    bazooka.b[i].live = false;
    bazooka.b[i].cx = 0;
    bazooka.b[i].cy = 0;
    bazooka.b[i].velocity = vel_bazooka;
    bazooka.b[i].radius = radiusBazooka;
    bazooka.b[i].Damage = damageBazooka;


  }
  bazooka.x = 9999;
  bazooka.y = 9999;
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
