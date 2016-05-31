#ifndef GAMECLIENT_H_INCLUDED
#define GAMECLIENT_H_INCLUDED
#define cell_width 100
#define cell_height 100
#define map_width 4500
#define map_height 2500
#define cellNumX 39
#define charLength 100
#define cellNumY 19
#include "mainMenuHeader.h"

#define pathCount 6





typedef struct sprite{
   // sf::Sprite north;
    //sf::Sprite south;
   // sf::Sprite east;
   // sf::Sprite west;

   // sf::Sprite curT;


   // sf::Sprite death;
   // sf::Sprite face;

   char path[pathCount][charLength];

   /*char north[charLength];
   char south[charLength];
   char east[charLength];
   char west[charLength];



   char death[charLength];

   char face[charLength];
   */
}sprite_t;

typedef struct object{
int status;
int  process;
char name[charLength];
sf::Sprite face;
sf::Sprite model;
int hp;
int damage;


}object_t;

typedef struct unit{
    int aPoints;
    int cPoints;

    int direction;

    char name[charLength];
    sprite_t sprites;
    int hp;
    unsigned int dmg;
    unsigned int armor;


}unit_t;




typedef struct cell{
    int X;
    int Y;
    int passability;
    int status;
    int obj_un_null;
    object_t * object;
    unit_t * unit;

}cell_t;

typedef struct gameMap{
    cell_t cell[cellNumX][cellNumY];
    int displacementX;
    int displacementY;
    int scrollingSpeed;
}gameMap_t;

/*
void cameraLeft(gameMap_t * self);
void cameraRight(gameMap_t * self);
void cameraUp(gameMap_t * self);
void cameraDown(gameMap_t * self);
void cameraMouseMove(sf::RenderWindow & window,gameMap_t * self);
void mouseEvents(sf::RenderWindow & window,gameMap_t * self);*/

unit_t * newTank();



#endif // GAMECLIENT_H_INCLUDED
