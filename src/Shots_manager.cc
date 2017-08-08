/**
* Inizio modulo gestione dei vari tipi di spari
*/
/**
* @file
* Modulo per la gestione dei proiettili
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
#include "Camera_Manager.h"
#include "Shots_manager.h"

extern player p1,p2;
extern int counter;
extern int counter2;
void Shot(bool &sparo, int player){

  if(sparo == false ){

    if(player == 1 && p1.arma.numBullets > 0){
      p1.arma.b[p1.arma.numBullets-1].live = true;
      p1.arma.b[p1.arma.numBullets-1].cx = p1.x;
      p1.arma.b[p1.arma.numBullets-1].cy = p1.y;
      p1.arma.numBullets--;
      sparo = true;
      //  stampaB(b);


    }else if(player == 2 && p2.arma.numBullets > 0) {

      p2.arma.b[p2.arma.numBullets-1].live = true;
      p2.arma.b[p2.arma.numBullets-1].cx = p2.x;
      p2.arma.b[p2.arma.numBullets-1].cy = p2.y;
      p2.arma.numBullets--;
      sparo = true;
      //  stampaB(b);


      }

  }
}


void ShotRifle(bool &sparo, int player){


    // if(counter == 3) {
    //   if(sparo == false){
    //     if(player == 1 && p1.arma.numBullets > 0){
    //         p1.arma.b[p1.arma.numBullets-1].live = true;
    //         p1.arma.b[p1.arma.numBullets-1].cx = p1.x;
    //         p1.arma.b[p1.arma.numBullets-1].cy = p1.y;
    //         p1.arma.numBullets--;
    //         sparo = true;
    //     }
    //     counter = 1;
    //
    //   }
    // }
    //else
    if(counter < 3)
     if(player == 1 && p1.arma.numBullets > 0){
      p1.arma.b[p1.arma.numBullets-1].live = true;
      p1.arma.b[p1.arma.numBullets-1].cx = p1.x;
      p1.arma.b[p1.arma.numBullets-1].cy = p1.y;
      p1.arma.numBullets--;
      sparo = true;
      counter++;
      //  stampaB(b);

  }
  if(counter2 < 3)
   if(player == 2 && p2.arma.numBullets > 0){
    p2.arma.b[p2.arma.numBullets-1].live = true;
    p2.arma.b[p2.arma.numBullets-1].cx = p2.x;
    p2.arma.b[p2.arma.numBullets-1].cy = p2.y;
    p2.arma.numBullets--;
    sparo = true;
    counter2++;
    //  stampaB(b);

  }
}



/* Fine modulo Shot manager */
