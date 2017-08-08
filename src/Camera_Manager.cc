/* Modulo per la gestione della camera */
/**
* @file
* Modulo per la gestione della camera
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

/** funzione per l'update della camera */
void CameraUpdate (float *cameraPosition, float x, float y, int width, int height){
  cameraPosition[0] = -(Swidth/2) + (x + width/2); //positivo se supero la metà dello schermo
  cameraPosition[1] = -(Sheight/2) +(y+height/2);

  if(cameraPosition[0]<0) cameraPosition[0] =0;
  if(cameraPosition[1]<0) cameraPosition[1]=0;

}


/* Fine modulo gestione camera */
