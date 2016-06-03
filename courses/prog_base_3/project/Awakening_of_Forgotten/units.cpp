#include "mainMenuHeader.h"
#include "gameClient.h"

unit_t * newTank(int player){

unit_t * self = (unit_t*)malloc(sizeof(unit_t));

sf::Texture tmpTexture;
strcpy(self->name,"Crucio");
strcpy(self->sprites.path[0],"units/tank/tank0.png");
strcpy(self->sprites.path[1],"units/tank/tank1.png");

strcpy(self->sprites.path[2],"units/tank/tank2.png");
strcpy(self->sprites.path[3],"units/tank/tank3.png");

strcpy(self->sprites.path[4],"units/tank/tank4.png");
strcpy(self->sprites.path[5],"units/tank/tank5.png");

strcpy(self->sprites.path[6],"units/tank/tank6.png");
strcpy(self->sprites.path[7],"units/tank/tank7.png");

strcpy(self->sprites.path[8],"units/tank/tankB.png");

//strcpy(self->sprites.path[4],"units/tank/tankD.png");


self->player = player;

self->aPoints=3;
self->cPoints=3;

self->aRange=4;

self->armor=3;

self->dmg=10;

self->hp=50;

self->direction = 2;

return self;

}

void deleteUnit(unit_t * self){
    free(self);
}

