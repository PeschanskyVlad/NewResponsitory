#include "mainMenuHeader.h"
#include "gameClient.h"

unit_t * newTank(int player){

unit_t * self = (unit_t*)malloc(sizeof(unit_t));

sf::Texture tmpTexture;
strcpy(self->name,"Crucio");
strcpy(self->type,"Tank");
strcpy(self->sprites.path[0],"units/tank/tank0.png");
strcpy(self->sprites.path[1],"units/tank/tank1.png");

strcpy(self->sprites.path[2],"units/tank/tank2.png");
strcpy(self->sprites.path[3],"units/tank/tank3.png");

strcpy(self->sprites.path[4],"units/tank/tank4.png");
strcpy(self->sprites.path[5],"units/tank/tank5.png");

strcpy(self->sprites.path[6],"units/tank/tank6.png");
strcpy(self->sprites.path[7],"units/tank/tank7.png");

strcpy(self->sprites.path[8],"units/tank/tankB.png");
strcpy(self->sprites.path[9],"units/tank/tankP.png");
strcpy(self->sprites.path[10],"units/tank/tankA.png");

strcpy(self->sprites.path[11],"units/tank/tankF0.png");
strcpy(self->sprites.path[12],"units/tank/tankF1.png");
strcpy(self->sprites.path[13],"units/tank/tankF2.png");
strcpy(self->sprites.path[14],"units/tank/tankF3.png");
strcpy(self->sprites.path[15],"units/tank/tankF4.png");
strcpy(self->sprites.path[16],"units/tank/tankF5.png");
strcpy(self->sprites.path[17],"units/tank/tankF6.png");
strcpy(self->sprites.path[18],"units/tank/tankF7.png");

//strcpy(self->sprites.path[4],"units/tank/tankD.png");


self->player = player;

self->aPoints=3;
self->cPoints=3;
self->cost = 200;

self->aRange=4;

self->armor=3;

self->dmg=30;

self->hp=50;

if(player == 0){
self->direction = 2;
}
else{
self->direction = 6;
}

return self;

}

object_t * newOP(){

    object_t * self = (object_t*)malloc(sizeof(object_t));
    self->currentPlayer=-1;
    self->profit=50;
    self->type=0;


    strcpy(self->sprites.path[0],"objects/OP0.png");
     strcpy(self->sprites.path[1],"objects/OP1.png");
      strcpy(self->sprites.path[2],"objects/OP2.png");
    strcpy(self->sprites.path[3],"objects/OP3.png");

    return self;


}

void deleteUnit(unit_t * self){
    free(self);
}

