/*
* Inzio modulo principale gestione delle collisioni.
* Il modulo si occupa di gestire tutte le collisioni tra oggeti nella mappa e dei colpi.
*/
/**
* @file
* Modulo per la gestione delle collisioni
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
#include "Map_module.h"
#include "Draw_module.h"
#include "Collision_manager.h"

extern player p1,p2;

extern ALLEGRO_SAMPLE *damageR;
extern ALLEGRO_SAMPLE *damageL;
bool collision(int x, int y, int ex, int ey, int width, int height, int we, int he)
{
  if(x + width <= ex || y+height<=ey || x>=ex+we || y>=ey+he)
  {
    //no collision

    return false;
  }else{ return true; } //c'è collisione

}



bool check_collision_player(Barrier obstacles[], int player){
  if(player == 1){

    for(int i=0; i<NUM_OBSTACLES; i++){
      if(collision(p1.x,p1.y,obstacles[i].x, obstacles[i].y, 64,64, obstacles[i].width, obstacles[i].height)||collision(p1.x,p1.y,p2.x,p2.y,64,64,64,64)){
        return true;
      }
    }

  }else{
    for(int i=0; i<NUM_OBSTACLES; i++){
      if(collision(p2.x,p2.y,obstacles[i].x, obstacles[i].y, 64,64, obstacles[i].width, obstacles[i].height)||collision(p2.x,p2.y,p1.x,p1.y,64,64,64,64)){
        return true;
      }


    }

  }

}



bool check_collision(Barrier obstacles[], int player, int colpi1, int colpi2){
  if(player == 1 && p1.arma.b[colpi1].live == true){
    if(collision(p1.arma.b[colpi1].cx, p1.arma.b[colpi1].cy, p2.x, p2.y, p1.arma.b[colpi1].radius+5, p1.arma.b[colpi1].radius+5, 64,64)){
      if(!al_play_sample(damageR, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL)) std::cout << "errore" << '\n';
      p2.life -= p1.arma.b[colpi1].Damage;
      cout<<"damage"<<endl;
      return true;
    }
    for(int i=0;i<NUM_OBSTACLES; i++){
      if(collision(p1.arma.b[colpi1].cx, p1.arma.b[colpi1].cy, obstacles[i].x, obstacles[i].y, p1.arma.b[colpi1].radius+5, p1.arma.b[colpi1].radius+5, obstacles[i].width,obstacles[i].height) ){
        return true;
      }
    }

  }else if(player == 2 && p2.arma.b[colpi2].live == true) {

    if(collision(p2.arma.b[colpi2].cx, p2.arma.b[colpi2].cy, p1.x, p1.y, p2.arma.b[colpi2].radius+5, p2.arma.b[colpi2].radius+5, 64,64)){
      al_play_sample(damageL, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
      p1.life -= p2.arma.b[colpi2].Damage;
      cout<<"damage2"<<endl;
      return true;
    }
    for(int i=0;i<NUM_OBSTACLES; i++){
      if(collision(p2.arma.b[colpi2].cx, p2.arma.b[colpi2].cy, obstacles[i].x, obstacles[i].y, p2.arma.b[colpi2].radius+5, p2.arma.b[colpi2].radius+5, obstacles[i].width,obstacles[i].height) ){
        return true;
      }
    }
  }
  return false;
}

int check_collision_weapon(weapon WArray[], int player){
  if(player == 1){

    for(int i=0; i<NUM_ITEMS; i++){
      if(collision(p1.x,p1.y,WArray[i].x, WArray[i].y, 64,64, 50, 26) && WArray[i].id !=0){
        int tmp;
        tmp = WArray[i].id;
        WArray[i].id = 0;
        strcpy(WArray[i].nome, "nothing");
        return tmp;
      }
    }

  }else if(player == 2){
    for(int i=0; i<NUM_ITEMS; i++){
      if(collision(p2.x,p2.y,WArray[i].x, WArray[i].y, 64,64, 50, 26) && WArray[i].id !=0){
        int tmp;
        tmp = WArray[i].id;
        WArray[i].id = 0;
        strcpy(WArray[i].nome, "nothing");
        return tmp;
      }


    }

  }
  return 0;


}



/* Fine modulo gestione delle collisioni */
