/**
* Inizio modulo gestione dei vari tipi di spari
*/
/**
* @file
* Modulo per la generazione delle armi sulla mappa
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
#include "Weapons_generator.h"
#include "time.h"
#include <stdlib.h>

void genWeaponsArray(weapon WArray[], weapon bazooka, weapon rifle, weapon heart, weapon pistol){
  int i = 0;
  int r;
  weapon nothing;
  nothing.id = 0;
  strcpy(nothing.nome, "nothing");
  srand(time(0));
  while(i<NUM_ITEMS){
    r = rand()%5;
    if(r == 0){ WArray[i] = nothing; i++;}
    if(r == 1){ WArray[i] = bazooka; i++;}
    if(r == 2){ WArray[i] = rifle; i++;}
    if(r == 3){ WArray[i] = heart; i++;}
    if(r == 4){ WArray[i] = pistol; i++;}

  }

  // for(int i=0; i<NUM_ITEMS; i++){
  //   WArray[i] = bazooka;
  //
  // }
}

void set_position_on_map(weapon WArray[], int mappa){


  if(mappa == 1){
    WArray[0].x = 750;
    WArray[0].y = 600;
    WArray[1].x = 450;
    WArray[1].y = 100;
    WArray[2].x = 800;
    WArray[2].y = 100;
    WArray[3].x = 250;
    WArray[3].y = 600;
    WArray[4].x = 1000;
    WArray[4].y = 80;
    WArray[5].x = 30;
    WArray[5].y = 650;
  }
  if(mappa == 2){
    WArray[0].x = 380;
    WArray[0].y = 450;
    WArray[1].x = 280;
    WArray[1].y = 310;
    WArray[2].x = 800;
    WArray[2].y = 200;
    WArray[3].x = 500;
    WArray[3].y = 600;

    WArray[4].x = 1000;
    WArray[4].y = 80;
    WArray[5].x = 100;
    WArray[5].y = 650;
  }
  if(mappa == 3){
    WArray[0].x = 830;
    WArray[0].y = 335;
    WArray[1].x = 380;
    WArray[1].y = 200;
    WArray[2].x = 450;
    WArray[2].y = 500;
    WArray[3].x = 5;
    WArray[3].y = 400;
    WArray[4].x = 940;
    WArray[4].y = 10;
    WArray[5].x = 1020;
    WArray[5].y = 260;



  }
}



bool is_emptyA(weapon WArray[]){
  for(int i=0; i<NUM_ITEMS; i++)
    if(WArray[i].id != 0) return false;
  return true;


}
