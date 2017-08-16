/** run with : g++ main.cc `pkg-config --libs allegro-5 allegro_dialog-5 allegro_font-5 allegro_ttf-5 allegro_primitives-5 allegro_image-5` */

/**
* @mainpage Battle-Royal
*
* Gioco multiplayer battle arena creato con allegro 5
*
* Vedere la documentazione della funzione ::main per maggiori dettagli
* sulle funzionalità e sulla loro implementazione.
*
* @author Enrico Sedoni
*/

/**
* @file
* Funzione principale (main) del gioco
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
#include "Camera_Manager.h"
#include "Shots_manager.h"
#include "Weapons_generator.h"



player p1,p2;

/** Enumerato per la direzione dei giocatori */
enum Direction {UP, LEFT, DOWN, RIGHT};


int deb = 0;



/** funzione per la stampa delle coordinate dei bullet. */
void stampaB(Bullet b[]){
  for(int i=0; i<NbulletPistol; i++){
    cout<<b[i].cx<<" "<<b[i].cy<<" "<<b[i].live<<endl;
    std::cout << "velocity" <<b[i].velocity<< '\n';
    std::cout << "colpo numero: "<<i << '\n';


  }

}





/** counter per i colpi del rifle del player 1 */
int counter =0;
/** counter per i colpi del rifle del player 2 */
int counter2 = 0;



int main(int argc, char **argv)
{

  bool menu = true;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_COLOR color;
  ALLEGRO_COLOR verde;
  verde = al_map_rgb(0,255,0);



  float cameraPosition[2] = {0,0};
  bool work = true, draw = true;


  float i;

  /** booleano che indica se il player 1 sta sparando */
  bool sparo=false;
  /** booleano che indica se il player 2 sta sparando */
  bool sparo2 = false;



  bool active = false;
  bool active2 = false;

  /** direzione del player 1 */
  int dir = DOWN;
  /** direzione del player 2 */
  int dir2 = UP;


  int mappa = 1; //mappa scelta, default 1
  char life[10] = "life: ";
  char vita[10];

  Barrier obstacles[NUM_OBSTACLES];
  weapon WArray[NUM_ITEMS];
  weapon bazooka;
  weapon rifle;
  weapon heart;





  init_bazooka(bazooka);
  init_rifle(rifle);
  init_heart(heart);

  init_player(p1, 10, 50, LIFE, MOVESPEED, 64, 0);
  init_player(p2, 1000, 620, LIFE, MOVESPEED, 64, 0);




  //init_obstacles(obstacles);




  if(!al_init()){
    al_show_native_message_box(display,"Error","Error","Error on initialisation", NULL,ALLEGRO_MESSAGEBOX_ERROR);
    return 1;
  }
  /** init and install components */
  al_init_primitives_addon();
  al_install_keyboard();
  al_install_mouse();
  al_init_image_addon();
  al_install_audio();
  al_init_acodec_addon();
  /** riservo lo spazio per i samples */
  al_reserve_samples(200000); //più è grande il numero, più ram occupo

  extern ALLEGRO_SAMPLE *damageR;
  extern ALLEGRO_SAMPLE *damageL;







  al_set_new_display_flags(ALLEGRO_WINDOWED);
  display = al_create_display(Swidth,Sheight);
  al_set_window_position(display, 100, 0);
  al_set_window_title(display, "Battle-Royal");
  if(!display) {
    al_show_native_message_box(display,"Error","Error","Error on initialisation", NULL,ALLEGRO_MESSAGEBOX_ERROR);
    return 1;}
    color = al_map_rgb(0,0,0);
    al_clear_to_color(color);


    ALLEGRO_KEYBOARD_STATE keyState;
    /** set the font */
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT *font = al_load_font("./fonts/Roboto-Bold.ttf", 30, 0);
    ALLEGRO_FONT *font2 = al_load_font("./fonts/Roboto-Bold.ttf", 20, 0);

    /** caricamento texture personaggi */
    ALLEGRO_BITMAP *player = al_load_bitmap("../media/player.png");
    ALLEGRO_BITMAP *player2 = al_load_bitmap("../media/player2.png");
    ALLEGRO_BITMAP *playerRifle = al_load_bitmap("../media/playerRifle.png");
    ALLEGRO_BITMAP *player2Rifle = al_load_bitmap("../media/player2Rifle.png");
    ALLEGRO_BITMAP *playerBazooka = al_load_bitmap("../media/playerBazooka.png");
    ALLEGRO_BITMAP *player2Bazooka = al_load_bitmap("../media/player2Bazooka.png");
    /** carico texture mappa */

    ALLEGRO_BITMAP *ground = al_load_bitmap("../media/ground.jpg");
    ALLEGRO_BITMAP *ground2 = al_load_bitmap("../media/ground2.jpg");
    ALLEGRO_BITMAP *ground3 = al_load_bitmap("../media/ground3.jpg");
    ALLEGRO_BITMAP *sand = al_load_bitmap("../media/sand.jpg");
    ALLEGRO_BITMAP *water = al_load_bitmap("../media/water.png");
    ALLEGRO_BITMAP *water2 = al_load_bitmap("../media/water2.png");
    ALLEGRO_BITMAP *water3 = al_load_bitmap("../media/water3.png");


    /** carico texture ostacoli */
    ALLEGRO_BITMAP *rock = al_load_bitmap("../media/rock2.png");
    ALLEGRO_BITMAP *rockH = al_load_bitmap("../media/rock2H.png");
    ALLEGRO_BITMAP *rock2 = al_load_bitmap("../media/rock3.png");
    ALLEGRO_BITMAP *rock2H = al_load_bitmap("../media/rock3H.png");
    ALLEGRO_BITMAP *rock3 = al_load_bitmap("../media/rock1.png");
    ALLEGRO_BITMAP *rock4 = al_load_bitmap("../media/rock4.png");
    ALLEGRO_BITMAP *wall = al_load_bitmap("../media/wall.png");
    ALLEGRO_BITMAP *wallH = al_load_bitmap("../media/wallH.png");
    ALLEGRO_BITMAP *ostacolo = al_load_bitmap("../media/ostacolo.png");
    ALLEGRO_BITMAP *ostacolo2 = al_load_bitmap("../media/ostacolo2.png");
    ALLEGRO_BITMAP *ostacolo3 = al_load_bitmap("../media/ostacolo3.png");
    ALLEGRO_BITMAP *cactus = al_load_bitmap("../media/cactus.png");
    ALLEGRO_BITMAP *cactus2 = al_load_bitmap("../media/cactus2.png");
    ALLEGRO_BITMAP *rock5 = al_load_bitmap("../media/rock5.png");
    ALLEGRO_BITMAP *rock6 = al_load_bitmap("../media/rock6.png");
    ALLEGRO_BITMAP *palma = al_load_bitmap("../media/palma.png");
    ALLEGRO_BITMAP *ostrica = al_load_bitmap("../media/ostrica.png");
    ALLEGRO_BITMAP *ostrica2 = al_load_bitmap("../media/ostrica2.png");
    ALLEGRO_BITMAP *albero2 = al_load_bitmap("../media/albero2.png");







    /** carico texture oggetti*/
    ALLEGRO_BITMAP *bazookaTexture = al_load_bitmap("../media/Rocket_Launcher.png");
    ALLEGRO_BITMAP *rifleTexture = al_load_bitmap("../media/rifle.png");
    ALLEGRO_BITMAP *HeartTexture = al_load_bitmap("../media/HeartTexture.png");

    /** Carico texture menu */
    ALLEGRO_BITMAP *menu1 = al_load_bitmap("../media/BRmenu.png");
    ALLEGRO_BITMAP *menu2 = al_load_bitmap("../media/BRmenu2.png");
    ALLEGRO_BITMAP *menu3 = al_load_bitmap("../media/BRmenu3.png");
    /** carico samples per gli effetti sonori */
    ALLEGRO_SAMPLE *pistolShot = al_load_sample("../media/Sounds/pistolShot.wav");
    ALLEGRO_SAMPLE *BazookaShot = al_load_sample("../media/Sounds/BazookaShot.wav");
    ALLEGRO_SAMPLE *RifleShot = al_load_sample("../media/Sounds/RifleShot.wav");
    ALLEGRO_SAMPLE *equipWeapon = al_load_sample("../media/Sounds/equipWeapon.wav");
    ALLEGRO_SAMPLE *lifeUp = al_load_sample("../media/Sounds/lifeUp.wav");
    ALLEGRO_SAMPLE *Track1 = al_load_sample("../media/Sounds/Track1_old.wav");
    ALLEGRO_SAMPLE *Track2 = al_load_sample("../media/Sounds/Track2.wav");

    damageR = al_load_sample("../media/Sounds/damageR.wav");
    damageL = al_load_sample("../media/Sounds/damageL.wav");


    ALLEGRO_SAMPLE_INSTANCE *song = al_create_sample_instance(Track1);
    al_set_sample_instance_playmode(song, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(song, al_get_default_mixer());
    /** coda eventi  */

    ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_play_sample_instance(song); //faccio partire la canzone di sottofondo

    // ---------visualizzazione menu --------------------------------

    al_draw_bitmap(menu1, 0,0,NULL);
    al_flip_display();


    while(menu){

      ALLEGRO_EVENT events;
      al_wait_for_event(event_queue, &events);

      if(events.type == ALLEGRO_EVENT_KEY_DOWN){
        switch (events.keyboard.keycode) {
          case ALLEGRO_KEY_1:
          //visualizza immagine 1
          al_play_sample(Track2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
          al_draw_bitmap(menu1, 0,0,NULL);
          mappa = 1;

          break;
          case ALLEGRO_KEY_2:
          al_play_sample(Track2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
          al_draw_bitmap(menu2, 0,0,NULL);
          mappa = 2;

          break;
          case ALLEGRO_KEY_3:
          al_play_sample(Track2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
          al_draw_bitmap(menu3, 0,0,NULL);
          mappa = 3;
          break;
          al_play_sample(Track2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
          case ALLEGRO_KEY_ENTER:
          menu = false;
          break;
          case ALLEGRO_KEY_ESCAPE:
          menu = false;
          work = false;
          break;
        }


      }
      al_flip_display();


    }

    genWeaponsArray(WArray, bazooka, rifle, heart);

    if(mappa == 1){
    init_mappa1(obstacles);
    set_position_on_map(WArray, mappa);}
    if(mappa == 2){
    init_mappa2(obstacles);
    set_position_on_map(WArray, mappa);}
    if(mappa == 3){
    init_mappa3(obstacles);
    set_position_on_map(WArray, mappa);}

    //al_show_native_message_box(display, "Istruzioni","Comandi: ", "Player 1: FRECCE DIREZIONALI e CTLR per sparare. \nPlayer 2: W,A,S,D e J per sparare. \nEsc per uscire.",  NULL, ALLEGRO_MESSAGEBOX_WARN);
    //   ALLEGRO_TRANSFORM camera;

    genRandomMap();

    ifstream f1("map.txt");
    if(!f1){
      cout << "errore in apertura della mappa" << '\n';
      return 1;
    }

    int map[ROW][COL];


    if(!getMap(f1,map)){cerr << "errore nel caricamento della mappa" << '\n';}

    int tmpX, tmpY;
    bool inCorso = false;

    // if(al_is_audio_installed()) std::cout << "audio installato" << '\n';

    al_start_timer(timer);


    // -------------------------------------------------ciclo infinito ---------------------------------------------- //
    while(work){
      ALLEGRO_EVENT events;
      al_wait_for_event(event_queue, &events);



      if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {work = false;}
      else if(p1.life <= 0){
        //vittoria player 1
        al_show_native_message_box(display, "Vittoria!","Il giocatore 2 vince! ", "Fai schifo player 1",  NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL);
        work = false;

      }
      else if(p2.life <=0){
        //vittoria player 2
        al_show_native_message_box(display, "Vittoria!","Il giocatore 1 vince! ", "Fai schifo player 2",  NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL);
        work = false;

      }

      if(events.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(events.keyboard.keycode){
          case ALLEGRO_KEY_LCTRL: {
            if(p1.arma.numBullets>0){
              if(strcmp(p1.arma.nome, "pistol") == 0){
                  if(sparo==false)
                  al_play_sample(pistolShot, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                  Shot(sparo, 1);
              }

              if(strcmp(p1.arma.nome, "bazooka") == 0){
                if(sparo==false)
                al_play_sample(BazookaShot, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                Shot(sparo, 1);

              }

              if(strcmp(p1.arma.nome, "rifle") == 0){

                al_play_sample(RifleShot, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                ShotRifle(sparo, 1);
              }


            }
          } break;
          case ALLEGRO_KEY_J:{
            if(p2.arma.numBullets>0){
              if(strcmp(p2.arma.nome, "pistol") == 0){
                if(sparo2==false)
                al_play_sample(pistolShot, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                Shot(sparo2, 2);

              }

              if(strcmp(p2.arma.nome, "bazooka") == 0){
                if(sparo2==false)
                al_play_sample(BazookaShot, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                Shot(sparo2, 2);

              }

              if(strcmp(p2.arma.nome, "rifle") == 0){
                al_play_sample(RifleShot, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                ShotRifle(sparo2, 2);
              }


            }
          } break;
          default: break;

        }

      }

      if(events.type == ALLEGRO_EVENT_TIMER){
        if(events.timer.source == timer)
        {
          active = true;
          al_get_keyboard_state(&keyState);
          if(al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)) work = false;
          if(al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
            if(sparo==false && p1.y+64<Sheight){
              p1.y += p1.movespeed; dir = DOWN;
            }
          }
          else if(al_key_down(&keyState, ALLEGRO_KEY_UP))  {
            if(sparo==false && p1.y>0){
              p1.y -= p1.movespeed; dir = UP;
            }
          }
          else if(al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
            if(sparo==false && p1.x+64<Swidth){
              p1.x += p1.movespeed; dir = RIGHT;
            }
          }
          else if(al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
            if(sparo==false && p1.x>0){
              p1.x -= p1.movespeed; dir = LEFT;
            }
          }



          else active = false;
          //animazione player
          if(active) p1.sourceX += al_get_bitmap_width(player) / 9;
          else p1.sourceX = 64;
          if(p1.sourceX >= al_get_bitmap_width(player)) p1.sourceX = 0;

          p1.sourceY = dir;



          if(check_collision_player(obstacles,1)){

            if(dir == DOWN){
              p1.y-=p1.movespeed;

            }
            if(dir == UP){
              p1.y+=p1.movespeed;

            }
            if(dir == LEFT){
              p1.x+=p1.movespeed;

            }
            if(dir == RIGHT){
              p1.x-=p1.movespeed;
            }
          }
          int oggetto;
          if((oggetto = check_collision_weapon(WArray, 1))){

            //equip oggetto
            if(oggetto == 1){
              al_play_sample(equipWeapon, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
              strcpy(p1.arma.nome, "bazooka");
              p1.arma = bazooka;

            }
            if(oggetto == 2){
              al_play_sample(equipWeapon, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
              strcpy(p1.arma.nome, "rifle");
              p1.arma = rifle;
            }
            if(oggetto == 3){
              al_play_sample(lifeUp, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
              if((p1.life+25)<100)
                p1.life += 25;
              else{
                int diff;
                diff = 100 - p1.life; // trovo quanto manca per arrivare a 100pt vita
                p1.life += diff;
              }
            }
          }

          if(al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)) work = false;
          active2 = true;

          //second player-----------------------------------------------------------

          if(al_key_down(&keyState, ALLEGRO_KEY_S)) {
            if(sparo2==false && p2.y+64<Sheight){
              p2.y += p2.movespeed; dir2 = DOWN;
            }
          }
          else if(al_key_down(&keyState, ALLEGRO_KEY_W))  {
            if(sparo2==false && p2.y>0){
              p2.y -= p2.movespeed; dir2 = UP;
            }
          }
          else if(al_key_down(&keyState, ALLEGRO_KEY_D)) {
            if(sparo2==false && p2.x+64<Swidth){
              p2.x += p2.movespeed; dir2 = RIGHT;
            }
          }
          else if(al_key_down(&keyState, ALLEGRO_KEY_A)) {
            if(sparo2==false && p2.x>0){
              p2.x -= p2.movespeed; dir2= LEFT;
            }
          }

          else active2 = false;

          //animazione player
          if(active2) p2.sourceX += al_get_bitmap_width(player2) / 9;
          else p2.sourceX = 64;
          if(p2.sourceX >= al_get_bitmap_width(player2)) p2.sourceX = 0;

          p2.sourceY = dir2;

          if(check_collision_player(obstacles,2)){
            if(dir2 == DOWN){
              p2.y-=p2.movespeed;

            }
            if(dir2 == UP){
              p2.y+=p2.movespeed;

            }
            if(dir2 == LEFT){
              p2.x+=p2.movespeed;

            }
            if(dir2 == RIGHT){
              p2.x-=p2.movespeed;
            }
          }

          int oggetto2;
          if((oggetto2 = check_collision_weapon(WArray, 2))){

            //equip oggetto2
            if(oggetto2 == 1){
              al_play_sample(equipWeapon, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
              strcpy(p2.arma.nome, "bazooka");
              p2.arma = bazooka;

            }
            if(oggetto2 == 2){
              al_play_sample(equipWeapon, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
              strcpy(p2.arma.nome, "rifle");
              p2.arma = rifle;
            }
            if(oggetto2 == 3){
              al_play_sample(lifeUp, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
              if((p2.life+25)<100)
                p2.life += 25;
              else{
                int diff;
                diff = 100 - p2.life; // trovo quanto manca per arrivare a 100pt vita
                p2.life += diff;
              }
            }
          }



        draw = true;


        // Update della camera
        //CameraUpdate(cameraPosition,x,y,64,64);
        //al_identity_transform(&camera);
        // al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]); //spostamento della camera, muovo tutto a sinistra in realtà
        //  al_use_transform(&camera);

      }


              }
      //se non ci sono più armi sul terreno di gioco, le rigenero
      if(is_emptyA(WArray)){
          genWeaponsArray(WArray, bazooka, rifle, heart);
          if(mappa == 1)
          set_position_on_map(WArray, mappa);
          if(mappa == 2)
          set_position_on_map(WArray, mappa);
          if(mappa == 3)
          set_position_on_map(WArray, mappa);
      }


      if(draw){
        draw = false;
        char colpiP1[5];
        char colpiP2[5];
        sprintf(vita,"%d",p1.life);
        sprintf(colpiP1, "%d", p1.arma.numBullets);
        sprintf(colpiP2, "%d", p2.arma.numBullets);

        if(mappa == 1){
          drawMap(map, ground,ground2);
          draw_obstacles(obstacles, rock2, rock2H, wall, ostacolo, ostacolo2, ostacolo3, cactus, cactus2, rock5, rock6, water, water2, water3, palma, ostrica, ostrica2, albero2);

        }

        if(mappa == 2 ){
          drawMap(map, ground3,ground3);
          draw_obstacles(obstacles, rock2, rock2H, wall, ostacolo, ostacolo2, ostacolo3, cactus, cactus2, rock5,rock6, water, water2, water3, palma, ostrica, ostrica2, albero2);

        }

        if(mappa == 3){
          drawMap(map, sand,sand);
          draw_obstacles(obstacles, rock2, rock2H, wall, ostacolo, ostacolo2, ostacolo3, cactus, cactus2, rock5,rock6, water, water2, water3, palma, ostrica, ostrica2, albero2);


        }

        if(p1.arma.id == 2 ){

          drawBullet_rifle(obstacles, dir,sparo,1, p1.arma.numBullets, p2.arma.numBullets);
        }
        else
        drawBullet(obstacles, dir,sparo,1, p1.arma.numBullets, p2.arma.numBullets);


        if(p2.arma.id == 2 ){

          drawBullet_rifle(obstacles, dir2,sparo2,2, p1.arma.numBullets, p2.arma.numBullets);
        }
        else
        drawBullet(obstacles, dir2,sparo2,2, p1.arma.numBullets,p2.arma.numBullets);




        draw_items(WArray, bazookaTexture, rifleTexture, HeartTexture);

        if(p1.arma.id == 1)
        al_draw_bitmap_region(playerBazooka, p1.sourceX, p1.sourceY * al_get_bitmap_height(player) / 4, 64, 64, p1.x, p1.y,0);
        if(p1.arma.id == 2)
        al_draw_bitmap_region(playerRifle, p1.sourceX, p1.sourceY * al_get_bitmap_height(player) / 4, 64, 64, p1.x, p1.y,0);
        if(p1.arma.id == 4)
        al_draw_bitmap_region(player, p1.sourceX, p1.sourceY * al_get_bitmap_height(player) / 4, 64, 64, p1.x, p1.y,0);


        if(p2.arma.id == 1)
        al_draw_bitmap_region(player2Bazooka, p2.sourceX, p2.sourceY * al_get_bitmap_height(player2) / 4, 64, 64, p2.x, p2.y, 0);
        if(p2.arma.id == 2)
        al_draw_bitmap_region(player2Rifle, p2.sourceX, p2.sourceY * al_get_bitmap_height(player2) / 4, 64, 64, p2.x, p2.y, 0);
        if(p2.arma.id == 4)
        al_draw_bitmap_region(player2, p2.sourceX, p2.sourceY * al_get_bitmap_height(player2) / 4, 64, 64, p2.x, p2.y, 0);

        al_draw_text(font, al_map_rgb(255,255,255), 20, 10, 0, life);
        drawLife(font, 75, 10, vita, p1.life);
        al_draw_text(font2, al_map_rgb(255,255,255), 20, 45, 0, "Colpi: ");
        al_draw_text(font2, al_map_rgb(255,255,255), 75, 45, 0, colpiP1);



        sprintf(vita,"%d",p2.life);

        al_draw_text(font, al_map_rgb(255,255,255), Swidth-140, 10, 0, life);
        drawLife(font, Swidth-85, 10, vita, p2.life);
        al_draw_text(font2, al_map_rgb(255,255,255), Swidth-140, 45, 0, "Colpi: ");
        al_draw_text(font2, al_map_rgb(255,255,255), Swidth-85, 45, 0, colpiP2);




        al_flip_display();
        al_clear_to_color(color);

      }

    }


    /** dallocamento risorse */

    al_destroy_sample_instance(song);
    al_destroy_sample(Track1);
    al_destroy_sample(Track2);
    al_destroy_sample(damageL);
    al_destroy_sample(damageR);
    al_destroy_sample(lifeUp);
    al_destroy_sample(equipWeapon);
    al_destroy_sample(pistolShot);
    al_destroy_sample(BazookaShot);
    al_destroy_sample(RifleShot);
    al_destroy_bitmap(HeartTexture);
    al_destroy_bitmap(rifleTexture);
    al_destroy_bitmap(bazookaTexture);
    al_destroy_bitmap(wallH);
    al_destroy_bitmap(sand);
    al_destroy_bitmap(water);
    al_destroy_bitmap(water2);
    al_destroy_bitmap(water3);
    al_destroy_bitmap(rock);
    al_destroy_bitmap(ostacolo);
    al_destroy_bitmap(ostacolo2);
    al_destroy_bitmap(palma);
    al_destroy_bitmap(ostrica);
    al_destroy_bitmap(ostrica2);
    al_destroy_bitmap(albero2);
    al_destroy_bitmap(cactus);
    al_destroy_bitmap(cactus2);
    al_destroy_bitmap(ostacolo3);
    al_destroy_bitmap(rockH);
    al_destroy_bitmap(rock2);
    al_destroy_bitmap(rock2H);
    al_destroy_bitmap(rock3);
    al_destroy_bitmap(rock5);
    al_destroy_bitmap(rock6);
    al_destroy_bitmap(rock4);
    al_destroy_bitmap(wall);
    al_destroy_bitmap(ground);
    al_destroy_bitmap(ground2);
    al_destroy_bitmap(ground3);
    al_destroy_bitmap(player);
    al_destroy_bitmap(player2);
    al_destroy_bitmap(menu1);
    al_destroy_bitmap(menu2);
    al_destroy_bitmap(menu3);
    al_destroy_bitmap(playerRifle);
    al_destroy_bitmap(player2Rifle);
    al_destroy_bitmap(playerBazooka);
    al_destroy_bitmap(player2Bazooka);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;
  }
