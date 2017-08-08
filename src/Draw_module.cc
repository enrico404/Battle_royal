/*
* Modulo principale per le funzioni di draw della mappa. Disegna Ostacoli, mappa e personaggi
*/
/**
* @file
* Modulo per la gestione delle funzioni di disegno degli oggetti della mappa
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
#include <fstream>
#include <string>
#include <sstream>


using namespace std;


#include "define.h"
#include "data_structure.h"
#include "init_object.h"
#include "Map_module.h"
#include "Draw_module.h"
#include "Collision_manager.h"


extern player p1,p2;
extern int counter;
extern int counter2;

void draw_obstacles(Barrier obstacles[], ALLEGRO_BITMAP *rock, ALLEGRO_BITMAP *rockH, ALLEGRO_BITMAP *wall ){
  int j=0, i=0;
  while(j<NUM_OBSTACLES){
    if(obstacles[j].base ==true){ al_draw_bitmap(wall, obstacles[j].x, obstacles[j].y, ALLEGRO_FLIP_VERTICAL);}
    else if(obstacles[j].rotation == 'v'){
      al_draw_bitmap(rock, obstacles[j].x, obstacles[j].y, ALLEGRO_FLIP_VERTICAL);
    }else
    al_draw_bitmap(rockH, obstacles[j].x, obstacles[j].y, ALLEGRO_FLIP_VERTICAL);
    // al_draw_rotated_bitmap(rock, obstacles[j].width/2, obstacles[j].height/2, obstacles[j].x, obstacles[j].y, ALLEGRO_PI/2, 0);

    j++;

  }

}




void drawBullet(Barrier obstacles[], int dir, bool &sparo, int player, int colpi1, int colpi2){

  //  if(!collision(b.cx, b.cy, 200, 155, 4, 4, 100, 120) && !collision(b.cx,b.cy,x2,y2, 64, 64, 64,64)){
  // if(deb==0 && player==2) {stampaB(b); deb++;}
  if(sparo== true)  {
    if(player==1){

      if(!check_collision(obstacles, player, colpi1, colpi2))
      {

        if(dir == 0 && p1.arma.b[colpi1].live == true ){ //UP

          al_draw_filled_circle(p1.arma.b[colpi1].cx+32, p1.arma.b[colpi1].cy, p1.arma.b[colpi1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1].cy -= p1.arma.b[colpi1].velocity;
          if(p1.arma.b[colpi1].cy <= 0){ p1.arma.b[colpi1].live = false;sparo = false; }
        }
        if(dir == 1 && p1.arma.b[colpi1].live == true ){ //LEFT

          al_draw_filled_circle(p1.arma.b[colpi1].cx, p1.arma.b[colpi1].cy+32, p1.arma.b[colpi1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1].cx -= p1.arma.b[colpi1].velocity;
          if(p1.arma.b[colpi1].cx <= 0){ p1.arma.b[colpi1].live = false;sparo = false;}
        }
        if(dir == 2 && p1.arma.b[colpi1].live == true ){ //DOWN

          al_draw_filled_circle(p1.arma.b[colpi1].cx+32, p1.arma.b[colpi1].cy+64, p1.arma.b[colpi1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1].cy += p1.arma.b[colpi1].velocity;
          if(p1.arma.b[colpi1].cy >= Sheight){ p1.arma.b[colpi1].live = false;sparo = false;}
        }
        if(dir == 3 && p1.arma.b[colpi1].live == true ){ //RIGHT

          al_draw_filled_circle(p1.arma.b[colpi1].cx+32, p1.arma.b[colpi1].cy+32, p1.arma.b[colpi1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1].cx += p1.arma.b[colpi1].velocity;
          if(p1.arma.b[colpi1].cx >= Swidth){ p1.arma.b[colpi1].live = false;sparo = false;}
        }
      } else {
        p1.arma.b[colpi1].live = false; sparo = false;
      }
    }else if (player == 2){

      if(!check_collision(obstacles, player, colpi1, colpi2))
      {


        if(dir == 0 && p2.arma.b[colpi2].live == true ){ //UP

          al_draw_filled_circle(p2.arma.b[colpi2].cx+32, p2.arma.b[colpi2].cy, p2.arma.b[colpi2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2].cy -= p2.arma.b[colpi2].velocity;

          if(p2.arma.b[colpi2].cy <= 0){ p2.arma.b[colpi2].live = false;sparo = false; }
        }
        if(dir == 1 && p2.arma.b[colpi2].live == true ){ //LEFT

          al_draw_filled_circle(p2.arma.b[colpi2].cx, p2.arma.b[colpi2].cy+32, p2.arma.b[colpi2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2].cx -= p2.arma.b[colpi2].velocity;
          if(p2.arma.b[colpi2].cx <= 0){ p2.arma.b[colpi2].live = false;sparo = false;}
        }
        if(dir == 2 && p2.arma.b[colpi2].live == true ){ //DOWN

          al_draw_filled_circle(p2.arma.b[colpi2].cx+32, p2.arma.b[colpi2].cy+64, p2.arma.b[colpi2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2].cy += p2.arma.b[colpi2].velocity;
          if(p2.arma.b[colpi2].cy >= Sheight){ p2.arma.b[colpi2].live = false;sparo = false;}
        }
        if(dir == 3 && p2.arma.b[colpi2].live == true ){ //RIGHT

          al_draw_filled_circle(p2.arma.b[colpi2].cx+32, p2.arma.b[colpi2].cy+32, p2.arma.b[colpi2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2].cx += p2.arma.b[colpi2].velocity;
          if(p2.arma.b[colpi2].cx >= Swidth){ p2.arma.b[colpi2].live = false;sparo = false;}
        }
      } else {
        p2.arma.b[colpi2].live = false; sparo = false;
      }

    }
  }



  //    } else { b.live = false; sparo = false;}

}


void drawLife(ALLEGRO_FONT *font, float x, float y, char *vita, int life ){
  if(life>70)
  al_draw_text(font, al_map_rgb(255,255,255), x, y, 0, vita);
  else if(life >= 50)
  al_draw_text(font, al_map_rgb(0,255,80), x, y , 0, vita);
  else if (life < 50)
  al_draw_text(font, al_map_rgb(255,0,0), x, y, 0, vita);

}



void draw_items(weapon WArray[], ALLEGRO_BITMAP *bazooka, ALLEGRO_BITMAP *rifle, ALLEGRO_BITMAP *heart ){
  for(int i=0; i<NUM_ITEMS; i++){
    if(strcmp(WArray[i].nome, "bazooka") == 0)
    al_draw_bitmap(bazooka, WArray[i].x, WArray[i].y, NULL);
    if(strcmp(WArray[i].nome, "rifle") == 0)
    al_draw_bitmap(rifle, WArray[i].x, WArray[i].y, NULL);
    if(strcmp(WArray[i].nome, "heart") == 0)
    al_draw_bitmap(heart, WArray[i].x, WArray[i].y, NULL);
    if(strcmp(WArray[i].nome, "nothing") == 0)
    continue;
  }



}




void drawBullet_rifle(Barrier obstacles[], int dir, bool &sparo, int player, int colpi1, int colpi2){

  if(sparo== true)  {

    if(player==1){




      if(dir == 0){ //UP

        if(p1.arma.b[colpi1].live == true && !check_collision(obstacles, player, colpi1, colpi2)){
          al_draw_filled_circle(p1.arma.b[colpi1].cx+32, p1.arma.b[colpi1].cy, p1.arma.b[colpi1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1].cy -= p1.arma.b[colpi1].velocity;
          if(p1.arma.b[colpi1].cy <= 0){ p1.arma.b[colpi1].live = false; }
        }else p1.arma.b[colpi1].live = false;

        if( p1.arma.b[colpi1+1].live == true && !check_collision(obstacles, player, colpi1+1, colpi2)){

          al_draw_filled_circle(p1.arma.b[colpi1+1].cx+32, p1.arma.b[colpi1+1].cy, p1.arma.b[colpi1+1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1+1].cy -= p1.arma.b[colpi1+1].velocity;
          if(p1.arma.b[colpi1+1].cy <= 0){ p1.arma.b[colpi1+1].live = false;}
        }else p1.arma.b[colpi1+1].live = false;


        if( p1.arma.b[colpi1+2].live == true && !check_collision(obstacles, player, colpi1+2, colpi2)){

          al_draw_filled_circle(p1.arma.b[colpi1+2].cx+32, p1.arma.b[colpi1+2].cy, p1.arma.b[colpi1+2].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1+2].cy -= p1.arma.b[colpi1+2].velocity;
          if(p1.arma.b[colpi1+2].cy <= 0){ p1.arma.b[colpi1+2].live = false;  }
        }else p1.arma.b[colpi1+2].live = false;

        if(p1.arma.b[colpi1].live==false && p1.arma.b[colpi1+1].live==false && p1.arma.b[colpi1+2].live==false) {counter = 0; sparo = false;} //se tutti e tre i colpi sono despawnati


      }


      if(dir == 1){ //LEFT

        if(p1.arma.b[colpi1].live == true && !check_collision(obstacles, player, colpi1, colpi2)){

          al_draw_filled_circle(p1.arma.b[colpi1].cx, p1.arma.b[colpi1].cy+32, p1.arma.b[colpi1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1].cx -= p1.arma.b[colpi1].velocity;
          if(p1.arma.b[colpi1].cx <= 0){ p1.arma.b[colpi1].live = false;}
        }else  p1.arma.b[colpi1].live = false;

        if( p1.arma.b[colpi1+1].live == true && !check_collision(obstacles, player, colpi1+1, colpi2)){
          al_draw_filled_circle(p1.arma.b[colpi1+1].cx, p1.arma.b[colpi1+1].cy+32, p1.arma.b[colpi1+1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1+1].cx -= p1.arma.b[colpi1+1].velocity;
          if(p1.arma.b[colpi1+1].cx <= 0){ p1.arma.b[colpi1+1].live = false;}
        }else p1.arma.b[colpi1+1].live = false;


        if( p1.arma.b[colpi1+2].live == true && !check_collision(obstacles, player, colpi1+2, colpi2)){

          al_draw_filled_circle(p1.arma.b[colpi1+2].cx, p1.arma.b[colpi1+2].cy+32, p1.arma.b[colpi1+2].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1+2].cx -= p1.arma.b[colpi1+2].velocity;
          if(p1.arma.b[colpi1+2].cx <= 0){ p1.arma.b[colpi1+2].live = false; }
        }else p1.arma.b[colpi1+2].live = false;

        if(p1.arma.b[colpi1].live==false && p1.arma.b[colpi1+1].live==false && p1.arma.b[colpi1+2].live==false){ counter = 0;sparo = false;} //se tutti e tre i colpi sono despawnati

      }



      if(dir == 2){ //DOWN
        if(p1.arma.b[colpi1].live == true && !check_collision(obstacles, player, colpi1, colpi2)){

          al_draw_filled_circle(p1.arma.b[colpi1].cx+32, p1.arma.b[colpi1].cy+64, p1.arma.b[colpi1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1].cy += p1.arma.b[colpi1].velocity;
          if(p1.arma.b[colpi1].cy >= Sheight){ p1.arma.b[colpi1].live = false;}
        }else p1.arma.b[colpi1].live = false;

        if( p1.arma.b[colpi1+1].live == true && !check_collision(obstacles, player, colpi1+1, colpi2)){
          al_draw_filled_circle(p1.arma.b[colpi1+1].cx+32, p1.arma.b[colpi1+1].cy+64, p1.arma.b[colpi1+1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1+1].cy += p1.arma.b[colpi1+1].velocity;
          if(p1.arma.b[colpi1+1].cy >= Sheight){ p1.arma.b[colpi1+1].live = false;}


        }else p1.arma.b[colpi1+1].live = false;
        if( p1.arma.b[colpi1+2].live == true && !check_collision(obstacles, player, colpi1+2, colpi2)){
          al_draw_filled_circle(p1.arma.b[colpi1+2].cx+32, p1.arma.b[colpi1+2].cy+64, p1.arma.b[colpi1+2].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1+2].cy += p1.arma.b[colpi1+2].velocity;
          if(p1.arma.b[colpi1+2].cy >= Sheight){ p1.arma.b[colpi1+2].live = false;}


        }else p1.arma.b[colpi1+2].live = false;

        if(p1.arma.b[colpi1].live==false && p1.arma.b[colpi1+1].live==false && p1.arma.b[colpi1+2].live==false) {counter = 0;sparo = false;} //se tutti e tre i colpi sono despawnati


      }


      if(dir == 3){ //RIGHT

        if(p1.arma.b[colpi1].live == true && !check_collision(obstacles, player, colpi1, colpi2)){

          al_draw_filled_circle(p1.arma.b[colpi1].cx+32, p1.arma.b[colpi1].cy+32, p1.arma.b[colpi1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1].cx += p1.arma.b[colpi1].velocity;
          if(p1.arma.b[colpi1].cx >= Swidth){ p1.arma.b[colpi1].live = false;}
        }else p1.arma.b[colpi1].live = false;

        if( p1.arma.b[colpi1+1].live == true && !check_collision(obstacles, player, colpi1+1, colpi2)){
          al_draw_filled_circle(p1.arma.b[colpi1+1].cx+32, p1.arma.b[colpi1+1].cy+32, p1.arma.b[colpi1+1].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1+1].cx += p1.arma.b[colpi1+1].velocity;
          if(p1.arma.b[colpi1+1].cx >= Swidth){ p1.arma.b[colpi1+1].live = false;}


        }else p1.arma.b[colpi1+1].live = false;
        if( p1.arma.b[colpi1+2].live == true && !check_collision(obstacles, player, colpi1+2, colpi2)){
          al_draw_filled_circle(p1.arma.b[colpi1+2].cx+32, p1.arma.b[colpi1+2].cy+32, p1.arma.b[colpi1+2].radius, al_map_rgb(255,0,0));
          p1.arma.b[colpi1+2].cx += p1.arma.b[colpi1+2].velocity;
          if(p1.arma.b[colpi1+2].cx >= Swidth){ p1.arma.b[colpi1+2].live = false; }


        }else p1.arma.b[colpi1+2].live = false;

        if(p1.arma.b[colpi1].live==false && p1.arma.b[colpi1+1].live==false && p1.arma.b[colpi1+2].live==false) {counter = 0;sparo = false;} //se tutti e tre i colpi sono despawnati

      }



    }else if (player == 2){

      if(dir == 0){ //UP

        if(p2.arma.b[colpi2].live == true && !check_collision(obstacles, player, colpi2, colpi2)){
          al_draw_filled_circle(p2.arma.b[colpi2].cx+32, p2.arma.b[colpi2].cy, p2.arma.b[colpi2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2].cy -= p2.arma.b[colpi2].velocity;
          if(p2.arma.b[colpi2].cy <= 0){ p2.arma.b[colpi2].live = false; }
        }else p2.arma.b[colpi2].live = false;

        if( p2.arma.b[colpi2+1].live == true && !check_collision(obstacles, player, colpi2+1, colpi2)){

          al_draw_filled_circle(p2.arma.b[colpi2+1].cx+32, p2.arma.b[colpi2+1].cy, p2.arma.b[colpi2+1].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2+1].cy -= p2.arma.b[colpi2+1].velocity;
          if(p2.arma.b[colpi2+1].cy <= 0){ p2.arma.b[colpi2+1].live = false;}
        }else p2.arma.b[colpi2+1].live = false;


        if( p2.arma.b[colpi2+2].live == true && !check_collision(obstacles, player, colpi2+2, colpi2)){

          al_draw_filled_circle(p2.arma.b[colpi2+2].cx+32, p2.arma.b[colpi2+2].cy, p2.arma.b[colpi2+2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2+2].cy -= p2.arma.b[colpi2+2].velocity;
          if(p2.arma.b[colpi2+2].cy <= 0){ p2.arma.b[colpi2+2].live = false;  }
        }else p2.arma.b[colpi2+2].live = false;

        if(p2.arma.b[colpi2].live==false && p2.arma.b[colpi2+1].live==false && p2.arma.b[colpi2+2].live==false) {counter2 = 0; sparo = false;} //se tutti e tre i colpi sono despawnati


      }


      if(dir == 1){ //LEFT

        if(p2.arma.b[colpi2].live == true && !check_collision(obstacles, player, colpi2, colpi2)){

          al_draw_filled_circle(p2.arma.b[colpi2].cx, p2.arma.b[colpi2].cy+32, p2.arma.b[colpi2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2].cx -= p2.arma.b[colpi2].velocity;
          if(p2.arma.b[colpi2].cx <= 0){ p2.arma.b[colpi2].live = false;}
        }else  p2.arma.b[colpi2].live = false;

        if( p2.arma.b[colpi2+1].live == true && !check_collision(obstacles, player, colpi2+1, colpi2)){
          al_draw_filled_circle(p2.arma.b[colpi2+1].cx, p2.arma.b[colpi2+1].cy+32, p2.arma.b[colpi2+1].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2+1].cx -= p2.arma.b[colpi2+1].velocity;
          if(p2.arma.b[colpi2+1].cx <= 0){ p2.arma.b[colpi2+1].live = false;}
        }else p2.arma.b[colpi2+1].live = false;


        if( p2.arma.b[colpi2+2].live == true && !check_collision(obstacles, player, colpi2+2, colpi2)){

          al_draw_filled_circle(p2.arma.b[colpi2+2].cx, p2.arma.b[colpi2+2].cy+32, p2.arma.b[colpi2+2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2+2].cx -= p2.arma.b[colpi2+2].velocity;
          if(p2.arma.b[colpi2+2].cx <= 0){ p2.arma.b[colpi2+2].live = false; }
        }else p2.arma.b[colpi2+2].live = false;

        if(p2.arma.b[colpi2].live==false && p2.arma.b[colpi2+1].live==false && p2.arma.b[colpi2+2].live==false){ counter2 = 0;sparo = false;} //se tutti e tre i colpi sono despawnati

      }



      if(dir == 2){ //DOWN
        if(p2.arma.b[colpi2].live == true && !check_collision(obstacles, player, colpi2, colpi2)){

          al_draw_filled_circle(p2.arma.b[colpi2].cx+32, p2.arma.b[colpi2].cy+64, p2.arma.b[colpi2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2].cy += p2.arma.b[colpi2].velocity;
          if(p2.arma.b[colpi2].cy >= Sheight){ p2.arma.b[colpi2].live = false;}
        }else p2.arma.b[colpi2].live = false;

        if( p2.arma.b[colpi2+1].live == true && !check_collision(obstacles, player, colpi2+1, colpi2)){
          al_draw_filled_circle(p2.arma.b[colpi2+1].cx+32, p2.arma.b[colpi2+1].cy+64, p2.arma.b[colpi2+1].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2+1].cy += p2.arma.b[colpi2+1].velocity;
          if(p2.arma.b[colpi2+1].cy >= Sheight){ p2.arma.b[colpi2+1].live = false;}


        }else p2.arma.b[colpi2+1].live = false;
        if( p2.arma.b[colpi2+2].live == true && !check_collision(obstacles, player, colpi2+2, colpi2)){
          al_draw_filled_circle(p2.arma.b[colpi2+2].cx+32, p2.arma.b[colpi2+2].cy+64, p2.arma.b[colpi2+2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2+2].cy += p2.arma.b[colpi2+2].velocity;
          if(p2.arma.b[colpi2+2].cy >= Sheight){ p2.arma.b[colpi2+2].live = false;}


        }else p2.arma.b[colpi2+2].live = false;

        if(p2.arma.b[colpi2].live==false && p2.arma.b[colpi2+1].live==false && p2.arma.b[colpi2+2].live==false) {counter2 = 0;sparo = false;} //se tutti e tre i colpi sono despawnati


      }


      if(dir == 3){ //RIGHT

        if(p2.arma.b[colpi2].live == true && !check_collision(obstacles, player, colpi2, colpi2)){

          al_draw_filled_circle(p2.arma.b[colpi2].cx+32, p2.arma.b[colpi2].cy+32, p2.arma.b[colpi2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2].cx += p2.arma.b[colpi2].velocity;
          if(p2.arma.b[colpi2].cx >= Swidth){ p2.arma.b[colpi2].live = false;}
        }else p2.arma.b[colpi2].live = false;

        if( p2.arma.b[colpi2+1].live == true && !check_collision(obstacles, player, colpi2+1, colpi2)){
          al_draw_filled_circle(p2.arma.b[colpi2+1].cx+32, p2.arma.b[colpi2+1].cy+32, p2.arma.b[colpi2+1].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2+1].cx += p2.arma.b[colpi2+1].velocity;
          if(p2.arma.b[colpi2+1].cx >= Swidth){ p2.arma.b[colpi2+1].live = false;}


        }else p2.arma.b[colpi2+1].live = false;
        if( p2.arma.b[colpi2+2].live == true && !check_collision(obstacles, player, colpi2+2, colpi2)){
          al_draw_filled_circle(p2.arma.b[colpi2+2].cx+32, p2.arma.b[colpi2+2].cy+32, p2.arma.b[colpi2+2].radius, al_map_rgb(255,0,0));
          p2.arma.b[colpi2+2].cx += p2.arma.b[colpi2+2].velocity;
          if(p2.arma.b[colpi2+2].cx >= Swidth){ p2.arma.b[colpi2+2].live = false; }


        }else p2.arma.b[colpi2+2].live = false;

        if(p2.arma.b[colpi2].live==false && p2.arma.b[colpi2+1].live==false && p2.arma.b[colpi2+2].live==false) {counter2 = 0;sparo = false;} //se tutti e tre i colpi sono despawnati

      }

     }
  }
}






/* Fine modulo draw */
