/*
* Modulo mappa con le funzioni principali per generare la mappa dato un file di testo
* contenente la matrice della stessa
*/
/**
* @file
* Modulo di gestione della mappa
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


bool getMap(ifstream &f1, int map[][COL]){
  cin>>noskipws;
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COL; j++){
      f1>>map[i][j];
    }
  }
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COL; j++){
      cout<<map[i][j];
    }
    cout<<endl;
  }
  return true;

}





void genRandomMap(){
  ofstream f("map.txt");
  if(!f) {cout<<"error on generation of the game maps"; return;}
  srand(time(0));
  int num;
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COL; j++){
      num = rand() % 2;
      f<<num<<" ";
    }
    f<<'\n';
  }
  f.close();
}





/* Fine modulo mappa */
