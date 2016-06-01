#include "mainMenuHeader.h"
#include "gameClient.h"

unit_t * newTank(int player){

unit_t * self = (unit_t*)malloc(sizeof(unit_t));

sf::Texture tmpTexture;
strcpy(self->name,"Crucio");
strcpy(self->sprites.path[0],"units/tank/tankN.png");

strcpy(self->sprites.path[1],"units/tank/tankE.png");

strcpy(self->sprites.path[2],"units/tank/tankW.png");

strcpy(self->sprites.path[3],"units/tank/tankS.png");

strcpy(self->sprites.path[4],"units/tank/tankD.png");


self->player = player;
self->aPoints=3;
self->cPoints=3;
self->armor=3;
self->dmg=10;
self->hp=50;
self->direction = 3;
return self;

}

