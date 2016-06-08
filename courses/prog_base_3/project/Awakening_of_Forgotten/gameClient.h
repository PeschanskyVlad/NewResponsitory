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
#include <math.h>
#define WALL 1
#include <string>
#include <time.h>

#include <iostream>
#include <iomanip>
#include <queue>

#include <math.h>
#include <ctime>

#define MAXUNITS 20

#define pathCount 20


 enum Unit{ TANK , BUGGY };

 enum Turn{PLAYER1_TURN,PLAYER2_TURN};

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
    int type;
    sprite_t sprites;
    int currentPlayer;
    int profit;
}object_t;

typedef struct unit{
    int aPoints;
    int cPoints;
    int aRange;
    int direction;
    char type[charLength];
    char name[charLength];
    sprite_t sprites;
    int hp;
    unsigned int dmg;
    unsigned int armor;
    int player;
    int cost;
  //  int type;
}unit_t;





typedef struct cell{
    int X;
    int Y;
    int iX;
    int jY;
    int passability;
    int status;
    int obj_un_null;
    object_t * object;
    unit_t * unit;

}cell_t;


typedef struct selection{
    cell_t * cell;
    int status;
}selection_t;

typedef struct gameMap{
    cell_t cell[cellNumX][cellNumY];
    int displacementX;
    int displacementY;
    int scrollingSpeed;
}gameMap_t;

typedef struct player{
    unsigned int resourcesPlayer1;
    unsigned int resourcesPlayer2;
    unsigned int currentUnitsP1;
    unsigned int currentUnitsP2;
    unsigned int maxUnits;

}player_t;

typedef struct cursor{
int status;
cell_t * cell;
}cursor_t;

object_t * newOP();



unit_t * newTank(int player);
unit_t * newBuggy(int player);
void deleteUnit(unit_t * self);

typedef
    void
    (*end_fn)
    (sf::RenderWindow & window,sf::Texture & endGame);


int calculateLength(std::string path);

std::string pathFind( const int & xStart, const int & yStart,
                 const int & xFinish, const int & yFinish ,gameMap_t * self);

                 void drawUnits(gameMap_t * self,sf::RenderWindow & window);
                 void drawMinMap(sf::RenderWindow & window,int currentPlayer,gameMap_t * self);
                 void drawPlayer(sf::RenderWindow & window,int player,player_t * players);

                 void setSelect(cell_t * cell, selection_t * self);

                void deleteSelect(selection_t * self);

                void getResources(gameMap_t * self, int cPlayer,player_t * players);
                void getOP(gameMap_t * self,player_t * players);
               // int compare(char self);


void createUnit(gameMap_t * self,
                player_t * player,
                int cPlayer,
                int type,
                sf::RenderWindow & window,
                selection_t * cUnit,
                sf::Sprite & gameBackground,
                sf::Sprite & gameInterface,
                sf::Sprite & gameMenu,
                sf::Sprite & gameEndTurn,
                sf::Sprite & cTc,
                sf::Sprite & cBc);


#endif // GAMECLIENT_H_INCLUDED
