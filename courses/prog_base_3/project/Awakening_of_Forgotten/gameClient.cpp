#include "mainMenuHeader.h"



void pData(sf::RenderWindow & window,selection_t * cUnit);


void drawMinMap(sf::RenderWindow & window,int currentPlayer,gameMap_t * self);
void drawPlayer(sf::RenderWindow & window,int player,player_t * players);

object_t * newObject(){
object_t * self = (object_t*)malloc(sizeof(struct object));
return self;
}

void freeObject(object_t* self){
free(self);
}

void setSelect(cell_t * cell, selection_t * self){
self->cell = cell;
self->status=1;
}

void deleteSelect(selection_t * self){
self->cell = NULL;
self->status = 0;
}





void cameraLeft(gameMap_t * self){
    if(self->displacementX<0){
        self->displacementX+=self->scrollingSpeed;


       for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
              self->cell[i][j].X+=self->scrollingSpeed;
            }
        }
        }

}
void cameraRight(gameMap_t * self){
    if(self->displacementX>-2580){
        self->displacementX-=self->scrollingSpeed;

       for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
              self->cell[i][j].X-=self->scrollingSpeed;
            }
        }
    }

}
void cameraUp(gameMap_t * self){
    if(self->displacementY<0){
        self->displacementY+=self->scrollingSpeed;

        for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
              self->cell[i][j].Y+=self->scrollingSpeed;
            }
        }

       }
}
void cameraDown(gameMap_t * self){
     if(self->displacementY>-1420){
        self->displacementY-=self->scrollingSpeed;
        for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
              self->cell[i][j].Y-=self->scrollingSpeed;
            }
        }
       }
}

void mouseEvents(sf::RenderWindow & window,gameMap_t * self){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            cameraUp(self);

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            cameraLeft(self);

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            cameraDown(self);

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            cameraRight(self);

    }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            pauseMenu(window);

    }
}

void cameraMouseMove(sf::RenderWindow & window,gameMap_t * self){

    //Up Left
    if (sf::IntRect(0, 0, 200, 200).contains(sf::Mouse::getPosition(window))){
            cameraUp(self);
            cameraLeft(self);
    }
    //Up
   if (sf::IntRect(200, 0, 1290, 200).contains(sf::Mouse::getPosition(window))){
       cameraUp(self);
   }
  // Left
     if (sf::IntRect(0, 200, 200, 680).contains(sf::Mouse::getPosition(window))){
    cameraLeft(self);
  }
   //Down
    if (sf::IntRect(200, 880, 1520, 200).contains(sf::Mouse::getPosition(window))){
       cameraDown(self);
   }
   //Right
   // if (sf::IntRect(1720, 200, 200, 680).contains(sf::Mouse::getPosition(window))){
   //    cameraRight(self);
   // }
   //dDown Left
  if (sf::IntRect(0, 880, 200, 200).contains(sf::Mouse::getPosition(window))){
       cameraDown(self);
       cameraLeft(self);
}

}






int gameSelection(sf::RenderWindow & window,sf::Sprite & gameMenu,sf::Texture & menu1,sf::Texture & menu2,sf::Sprite & gameEndTurn,sf::Texture & E1,sf::Texture & E2,sf::Sprite & cTc,sf::Texture & cT1,sf::Texture & cT2){
    if (sf::IntRect(1729, 0, 209, 104).contains(sf::Mouse::getPosition(window))) {
        gameMenu.setTexture(menu2);
        gameEndTurn.setTexture(E1);
        cTc.setTexture(cT1);
       return 1;
    }else if(sf::IntRect(1500, 0, 209, 104).contains(sf::Mouse::getPosition(window))){
        gameMenu.setTexture(menu1);
        gameEndTurn.setTexture(E2);
        cTc.setTexture(cT1);
        return 2;
    }else{
        if(sf::IntRect(1680, 750, 200, 100).contains(sf::Mouse::getPosition(window))){

        gameMenu.setTexture(menu1);
        gameEndTurn.setTexture(E1);
        cTc.setTexture(cT2);
        return 3;

        }else{

    gameMenu.setTexture(menu1);
    gameEndTurn.setTexture(E1);
    cTc.setTexture(cT1);
    return 0;
    }
}
}

int cursorConfirm(sf::RenderWindow & window,gameMap_t * self,sf::Sprite & cursorXY,cursor_t * gCur){
    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                    if (sf::IntRect(self->cell[i][j].X, self->cell[i][j].Y, cell_width, cell_height).contains(sf::Mouse::getPosition(window))) {

                            cursorXY.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                            gCur->status = 1;
                            gCur->cell = &self->cell[i][j];

                                    char tmp[100];
                                  //  sprintf(tmp,"X: %i Y: %i",i,j);
                                    sf::Font font;
                                    font.loadFromFile("gameInterface/arial.ttf");
                                    sf::Text text;
                                    text.setFont(font);
                                    text.setColor(sf::Color::Black);

                                    text.setCharacterSize(15);
                                    text.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                                    if(self->cell[i][j].unit!=NULL&&self->cell[i][j].obj_un_null==1){
                                      sprintf(tmp,"UNIT X: %i Y: %i S: %i",i,j,self->cell[i][j].obj_un_null);
                                    }else{
                                         sprintf(tmp,"NULL X: %i Y: %i S: %i",i,j,self->cell[i][j].obj_un_null);
                                    }
                                    text.setString(tmp);
                                   // window.draw(text);



                    return 1;
                    }

            }
        }
        gCur->status = 0;
        gCur->cell = NULL;
        return 0;
}



void drawUnits(gameMap_t * self,sf::RenderWindow & window){
    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){


                   if(self->cell[i][j].obj_un_null==1&&self->cell[i][j].unit!=NULL){

                        sf::Texture tmpT;
                        sf::Sprite tmpS;
                        tmpT.loadFromFile(self->cell[i][j].unit->sprites.path[self->cell[i][j].unit->direction]);
                        tmpS.setTexture(tmpT);
                        tmpS.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                        window.draw(tmpS);


                   }

                   if(self->cell[i][j].obj_un_null==1&&self->cell[i][j].object!=NULL){

                    sf::Texture tmpT;
                    sf::Sprite tmpS;

                    switch(self->cell[i][j].object->currentPlayer){
                case -1:
                    tmpT.loadFromFile(self->cell[i][j].object->sprites.path[0]);
                    break;

                      case 0:
                          tmpT.loadFromFile(self->cell[i][j].object->sprites.path[1]);
                    break;

                      case 1:
                          tmpT.loadFromFile(self->cell[i][j].object->sprites.path[2]);
                    break;
                    }

                   // tmpT.loadFromFile(self->cell[i][j].object->sprites.path[0]);
                    tmpS.setTexture(tmpT);
                    tmpS.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                    window.draw(tmpS);

                    sf::Texture tmpT1;
                    sf::Sprite tmpS1;

                    tmpT1.loadFromFile(self->cell[i][j].object->sprites.path[3]);
                    tmpS1.setTexture(tmpT1);
                    tmpS1.setPosition(self->cell[i][j].X-cell_width,self->cell[i][j].Y-cell_height);
                    window.draw(tmpS1);



                   }

            }
        }



}

void selectUnit(gameMap_t * self,sf::RenderWindow & window,sf::Sprite & cSel,selection_t*select,unsigned int player){

    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                    if(self->cell[i][j].unit!=NULL){
                    if (sf::IntRect(self->cell[i][j].X, self->cell[i][j].Y, cell_width, cell_height).contains(sf::Mouse::getPosition(window))&&self->cell[i][j].obj_un_null==1&&sf::Mouse::isButtonPressed(sf::Mouse::Left)&&self->cell[i][j].unit->player == player) {

                            cSel.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                            setSelect(&self->cell[i][j],select);

                    }
                    }

            }
        }

}



void addUnit(gameMap_t * self,sf::RenderWindow & window,int pl, Unit type,int X, int Y){
    if(self->cell[X][Y].unit!=NULL){
        return;
    }

 switch(type){
  case TANK:
    self->cell[X][Y].unit = newTank(pl);
    self->cell[X][Y].obj_un_null=1;
    break;


 }
}


void addObject(gameMap_t * self,sf::RenderWindow & window, int type,int X, int Y){

    if(self->cell[X][Y].unit!=NULL||self->cell[X][Y].object!=NULL||self->cell[X][Y].obj_un_null==1){
        return;
    }

 switch(type){
  case 0:
    self->cell[X][Y].object = newOP();
    self->cell[X][Y].obj_un_null=1;
    break;


 }
}





void endTurn(gameMap_t * self){

    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                if(self->cell[i][j].unit!=NULL){
                    self->cell[i][j].unit->cPoints = self->cell[i][j].unit->aPoints;
                }

            }
    }

}

void  findWay(gameMap_t * self,sf::RenderWindow & window, selection_t * cUnit,sf::Sprite & aCell,sf::Sprite & aEnemy, cursor_t * gCur,sf::Sprite & gameBackground,sf::Sprite & gameInterface,sf::Sprite & gameMenu, sf::Sprite & gameEndTurn,int player,sf::Sprite & cTc,player_t*pl){

    if(cUnit->status==0){
        return;
    }
    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){

                    int added = 0;

                    if (cUnit->cell!=NULL&&(float)sqrt((cUnit->cell->iX-i)*(cUnit->cell->iX-i)+(cUnit->cell->jY-j)*(cUnit->cell->jY-j)) <=  (float)(cUnit->cell->unit->cPoints) || (float)sqrt((cUnit->cell->iX-i)*(cUnit->cell->iX-i)+(cUnit->cell->jY-j)*(cUnit->cell->jY-j)) <=  (float)(cUnit->cell->unit->aRange)) {

                    std::string tmp;

                    int tmpSt = self->cell[i][j].obj_un_null;



                    if(self->cell[i][j].unit!=NULL && self->cell[i][j].unit->player  !=  cUnit->cell->unit->player && self->cell[i][j].obj_un_null == 1)
                        {
                            self->cell[i][j].obj_un_null = 0;
                            tmpSt = 1;
                        }


                    tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,i,j,self);

                    if(tmp!="" && calculateLength(tmp)<=cUnit->cell->unit->cPoints){



                         aCell.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                         window.draw(aCell);

                          if(gCur->status==1&&gCur->cell->iX == i &&gCur->cell->jY == j && tmp!=""&& self->cell[gCur->cell->iX][gCur->cell->jY].unit == NULL){

                                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                                    cUnit->cell->unit->cPoints-=calculateLength(tmp);

                                    int tmpInt = tmp[0] - 48;

                                    cUnit->cell->unit->direction=tmpInt;

                                    int tmpX = 0, tmpY = 0;

                                    cUnit->cell->unit->direction = tmpInt;


                                    tmpX = cUnit->cell->iX;
                                    tmpY = cUnit->cell->jY;

                                    self->cell[tmpX][tmpY].obj_un_null=0;

                                   int tmpCX = cUnit->cell->X;
                                   int tmpCY = cUnit->cell->Y;


                                    for(int l = 0;l<tmp.length();l++){

                                    int tmpD = tmp[l] - 48;

                                    cUnit->cell->unit->direction = tmpD;

                                    sf::Texture tmpT;
                                    sf::Sprite tmpS;


                                    tmpT.loadFromFile(cUnit->cell->unit->sprites.path[cUnit->cell->unit->direction]);
                                    tmpS.setTexture(tmpT);

                                    for(int a = 0 ; a<20;a++){
                                            switch(tmpD){
                                        case 0:
                                            tmpCX+=5;
                                             break;
                                        case 1:
                                            tmpCX+=5;
                                            tmpCY+=5;
                                             break;
                                        case 2:
                                             tmpCY+=5;
                                             break;
                                        case 3:
                                             tmpCX-=5;
                                             tmpCY+=5;
                                             break;
                                        case 4:
                                            tmpCX-=5;
                                             break;
                                        case 5:
                                            tmpCX-=5;
                                            tmpCY-=5;
                                             break;
                                        case 6:
                                             tmpCY-=5;
                                             break;
                                        case 7:
                                             tmpCY-=5;
                                              tmpCX+=5;
                                             break;

                                           }

                                            Sleep(20);

                                            window.clear(sf::Color::Black);
                                            window.draw(gameBackground);
                                            drawUnits(self,window);

                                            window.draw(gameInterface);
                                            window.draw(gameMenu);
                                            drawMinMap(window,player,self);
                                            window.draw(gameEndTurn);
                                            drawPlayer(window,player,pl);




                                            tmpS.setPosition(tmpCX,tmpCY);

                                            window.draw(tmpS);
                                            window.draw(cTc);

                                            pData(window,cUnit);


                                            window.display();

                                    }




                                    }

                                    self->cell[gCur->cell->iX][gCur->cell->jY].unit = cUnit->cell->unit;
                                    self->cell[gCur->cell->iX][gCur->cell->jY].obj_un_null=1;
                                    added = 1;



                                    setSelect(&self->cell[gCur->cell->iX][gCur->cell->jY],cUnit);
                                    self->cell[tmpX][tmpY].unit = NULL;



                                }
                            }



                   }

                    if(tmpSt == 1 && tmp!="" && calculateLength(tmp)<=cUnit->cell->unit->aRange&&cUnit->cell->unit->cPoints>0){


                         aEnemy.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                         window.draw(aEnemy);

                         if(gCur->status==1&&gCur->cell->iX == i &&gCur->cell->jY == j&& self->cell[gCur->cell->iX][gCur->cell->jY].unit != NULL && cUnit->cell->unit->player!=self->cell[i][j].unit->player){

                                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                                        if(added!=1){
                                        self->cell[i][j].obj_un_null = tmpSt;
                                        }

                                        int tmpD = tmp[0] - 48;
                                        cUnit->cell->unit->direction = tmpD;

                                            window.clear(sf::Color::Black);
                                            window.draw(gameBackground);

                                            drawUnits(self,window);

                                            window.draw(gameInterface);
                                            window.draw(gameMenu);
                                            drawMinMap(window,player,self);
                                            window.draw(gameEndTurn);
                                            drawPlayer(window,player,pl);
                                            pData(window,cUnit);



                                        sf::Texture tmpT;
                                        sf::Sprite tmpS;
                                        tmpT.loadFromFile(self->cell[i][j].unit->sprites.path[10]);
                                        tmpS.setTexture(tmpT);
                                        tmpS.setPosition(self->cell[i][j].X + rand()%50+20,self->cell[i][j].Y + rand()%50+20);
                                        window.draw(tmpS);

                                        sf::Texture tmpT1;
                                        sf::Sprite tmpS1;



                                       tmpT1.loadFromFile(self->cell[i][j].unit->sprites.path[11+cUnit->cell->unit->direction]);


                                        tmpS1.setTexture(tmpT1);
                                        tmpS1.setPosition(cUnit->cell->X,cUnit->cell->Y);


                                        window.draw(tmpS1);
                                        window.display();
                                        Sleep(400);



                                      cUnit->cell->unit->cPoints-=1;
                                      int tmpDmg = cUnit->cell->unit->dmg -  self->cell[i][j].unit->armor;
                                      if(tmpDmg<0){tmpDmg=0;}
                                      self->cell[i][j].unit->hp-=tmpDmg;






                                      if(self->cell[i][j].unit->hp<=0){

                                        sf::Texture tmpT;
                                        sf::Sprite tmpS;


                                        tmpT.loadFromFile(self->cell[i][j].unit->sprites.path[8]);
                                        tmpS.setTexture(tmpT);
                                        tmpS.setPosition(self->cell[i][j].X,self->cell[i][j].Y);



                                            window.clear(sf::Color::Black);
                                            window.draw(gameBackground);
                                            drawUnits(self,window);

                                            window.draw(gameInterface);
                                            window.draw(gameMenu);
                                            drawMinMap(window,player,self);
                                            window.draw(gameEndTurn);
                                            drawPlayer(window,player,pl);

                                            pData(window,cUnit);
                                            window.draw(tmpS);




                                        window.display();
                                        Sleep(400);

                                        deleteUnit(self->cell[i][j].unit);
                                        self->cell[i][j].unit = NULL;
                                        self->cell[i][j].obj_un_null = 0;
                                        return;




                                      }

                               }


                         }



                   }

                   if(added!=1){

                   self->cell[i][j].obj_un_null = tmpSt;
                   }









                    }

            }
        }


}

void createMap(gameMap_t * map){
        map->displacementX=0;
        map->displacementY=0;
        map->scrollingSpeed=6;

        for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                map->cell[i][j].X = (map_width-cell_width*cellNumX)/2+i*cell_width;
                map->cell[i][j].Y = (map_height-cell_height*cellNumY)/2+j*cell_height;
                map->cell[i][j].obj_un_null=0;
                map->cell[i][j].unit = NULL;
                map->cell[i][j].object = NULL;
                map->cell[i][j].iX =i;
                map->cell[i][j].jY =j;

            }
        }
}


void pData(sf::RenderWindow & window,selection_t * cUnit){

                                    std::string tmp;
                                    char tmpS[100];
                                    sf::Font font;
                                    font.loadFromFile("gameInterface/arial.ttf");
                                    sf::Text text;
                                    text.setFont(font);
                                    text.setColor(sf::Color::Black);

                                    text.setCharacterSize(18);

                                    tmp+=cUnit->cell->unit->type;
                                    tmp+=": ";
                                    tmp+=cUnit->cell->unit->name;


                                    text.setPosition(90,752);

                                    text.setString(tmp);
                                    window.draw(text);

                                    sprintf(tmpS,"Points: %i\nHp: %i\nDamage: %i\nArmor: %i\n",cUnit->cell->unit->cPoints,cUnit->cell->unit->hp,cUnit->cell->unit->dmg,cUnit->cell->unit->armor);
                                    text.setString(tmpS);
                                    text.setPosition(90,965);
                                      text.setCharacterSize(16);
                                    window.draw(text);




        sf::Texture tmpTexture;
        sf::Sprite tmpSprite;
        tmpTexture.loadFromFile(cUnit->cell->unit->sprites.path[9]);
        tmpSprite.setTexture(tmpTexture);
        tmpSprite.setPosition(41,798);
        window.draw(tmpSprite);


}

void drawMinMap(sf::RenderWindow & window,int currentPlayer,gameMap_t * self){
    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                sf::Texture tmpTexture;
                sf::Sprite tmpSprite;

                    if(self->cell[i][j].object!=NULL){
                        tmpTexture.loadFromFile("gameInterface/mMapO.png");
                        //tmpTexture.loadFromFile("gameInterface/mMapE.png");
                        tmpSprite.setTexture(tmpTexture);
                        tmpSprite.setPosition(33+i*10,41+j*10);
                        window.draw(tmpSprite);
                        continue;
                    }

                    if(self->cell[i][j].unit!=NULL){
                        if(self->cell[i][j].unit->player==currentPlayer){
                            tmpTexture.loadFromFile("gameInterface/mMapF.png");
                             tmpSprite.setTexture(tmpTexture);
                            tmpSprite.setPosition(33+i*10,41+j*10);
                            window.draw(tmpSprite);
                           //  continue;
                        }else{
                        tmpTexture.loadFromFile("gameInterface/mMapE.png");
                        tmpSprite.setTexture(tmpTexture);
                        tmpSprite.setPosition(33+i*10,41+j*10);
                        window.draw(tmpSprite);
                         //continue;
                        }
                    }

                }
               // tmpSprite.setTexture(tmpTexture);
              //  tmpSprite.setPosition(33+i*10,41+j*10);
               // window.draw(tmpSprite);
            }
}


void drawPlayer(sf::RenderWindow & window,int player,player_t * players){
                                    std::string tmp;
                                    sf::Font font;
                                    font.loadFromFile("gameInterface/SourceSansPro.ttf");
                                    sf::Text text;
                                    text.setFont(font);
                                    text.setColor(sf::Color::White);

                                    text.setCharacterSize(18);
                                    if(player==0){tmp+="First player turn";}
                                    if(player==1){tmp+="Second player turn";}
                                    text.setPosition(150,5);
                                    text.setString(tmp);
                                    window.draw(text);



                                    char tmpChar[charLength];
                                    if(player==0){sprintf(tmpChar,"Resources: %i",players->resourcesPlayer1);}
                                    if(player==1){sprintf(tmpChar,"Resources: %i",players->resourcesPlayer2);}
                                    sf::Text text1;
                                    text1.setFont(font);
                                    text1.setColor(sf::Color::White);
                                    text1.setCharacterSize(18);
                                    text1.setPosition(1680,710);
                                    text1.setString(tmpChar);
                                    window.draw(text1);


}

void createUnit(gameMap_t * self,player_t * player,int cPlayer,int type,sf::RenderWindow & window,selection_t * cUnit,sf::Sprite & gameBackground,sf::Sprite & gameInterface,sf::Sprite & gameMenu, sf::Sprite & gameEndTurn,sf::Sprite & cTc){

    if(cPlayer == 0){

            /*int tmdDX=self->displacementX+200;
            int tmpDY = self->displacementY;

            for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){

              self->cell[i][j].X-=tmdDX;

              self->cell[i][j].Y-=tmpDY;

            }
            }

        self->displacementX=-200;
        self->displacementY=0;*/

       for(int i = 9;i<16;i++){
        if(self->cell[i][0].unit==NULL&&self->cell[i][0].obj_un_null==0){
            switch(type){
            case 3:
            self->cell[i][0].unit = newTank(cPlayer);
                    if(player->resourcesPlayer1<self->cell[i][0].unit->cost){
                        deleteUnit(self->cell[i][0].unit);
                        self->cell[i][0].unit = NULL;
                        self->cell[i][0].obj_un_null=0;
                        return;
                    }

                    player->resourcesPlayer1-=self->cell[i][0].unit->cost;

                    sf::Texture tmpT;
                    sf::Sprite tmpS;

                    tmpT.loadFromFile(self->cell[i][0].unit->sprites.path[self->cell[i][0].unit->direction]);
                    tmpS.setTexture(tmpT);
                    int tmpX = self->cell[i][0].X;
                    int tmpY = self->displacementY;

            for(int j = 0;j<60;j++){
                    tmpY+=5;
                    tmpS.setPosition(tmpX,tmpY);


                    window.clear(sf::Color::Black);
                    window.draw(gameBackground);
                    drawUnits(self,window);

                    window.draw(gameInterface);
                    window.draw(gameMenu);
                    drawMinMap(window,cPlayer,self);
                    window.draw(gameEndTurn);
                    drawPlayer(window,cPlayer,player);
                    window.draw(cTc);
                   // pData(window,cUnit);
                    window.draw(tmpS);
                    window.display();
            }

            self->cell[i][0].obj_un_null=1;
            return;
            break;
            }




        }
       }
    return;
        }




      if(cPlayer == 1){


          for(int i = 27;i<34;i++){
        if(self->cell[i][18].unit==NULL&&self->cell[i][18].obj_un_null==0){
            switch(type){
            case 3:
            self->cell[i][18].unit = newTank(cPlayer);

            if(player->resourcesPlayer2<self->cell[i][0].unit->cost){
                        deleteUnit(self->cell[i][0].unit);
                        self->cell[i][0].unit = NULL;
                        self->cell[i][0].obj_un_null=0;
                        return;
                    }

                    player->resourcesPlayer2-=self->cell[i][0].unit->cost;


                    sf::Texture tmpT;
                    sf::Sprite tmpS;

                    tmpT.loadFromFile(self->cell[i][18].unit->sprites.path[self->cell[i][18].unit->direction]);
                    tmpS.setTexture(tmpT);
                    int tmpX = self->cell[i][18].X;

                    int tmpY = self->displacementY;
                    tmpY+=map_height;

            for(int j = 0;j<80;j++){
                    tmpY-=5;
                    tmpS.setPosition(tmpX,tmpY);


                    window.clear(sf::Color::Black);
                    window.draw(gameBackground);
                    drawUnits(self,window);

                    window.draw(gameInterface);
                    window.draw(gameMenu);
                    drawMinMap(window,cPlayer,self);
                    window.draw(gameEndTurn);
                    drawPlayer(window,cPlayer,player);
                    window.draw(cTc);
                   // pData(window,cUnit);
                    window.draw(tmpS);
                    window.display();
            }

            self->cell[i][18].obj_un_null=1;
            return;
            break;
            }




        }
       }






    return;
        }
}

void getResources(gameMap_t * self, int cPlayer,player_t * players){

        for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){



                   if(self->cell[i][j].obj_un_null==1&&self->cell[i][j].object!=NULL){

                   if(self->cell[i][j].object->type==0&&self->cell[i][j].object->currentPlayer==cPlayer){

                    if(cPlayer == 0){players->resourcesPlayer1+= self->cell[i][j].object->profit;}
                    if(cPlayer == 1){players->resourcesPlayer2+= self->cell[i][j].object->profit;}

                   }



                   }

            }
        }
}

void getOP(gameMap_t * self,player_t * players){

    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){

                if(self->cell[i][j].object!=NULL&&self->cell[i][j].obj_un_null==1&&self->cell[i][j].object->type==0){
                    int player1=0;
                    int player2=0;
                   // int tmpX;
                    //int tmpY;

                   //
                   int tmpX=i-1;
                   int tmpY=j-1;
                   if(tmpX<0){tmpX=0;}
                   if(tmpY<0){tmpY=0;}
                   if(self->cell[tmpX][tmpY].obj_un_null==1&&self->cell[tmpX][tmpY].unit!=NULL){
                        if(self->cell[tmpX][tmpY].unit->player==0){player1++;}
                        if(self->cell[tmpX][tmpY].unit->player==1){player2++;}
                   }
                    //
                   tmpX=i;
                   tmpY=j-1;
                   if(tmpX<0){tmpX=0;}
                   if(tmpY<0){tmpY=0;}
                   if(self->cell[tmpX][tmpY].obj_un_null==1&&self->cell[tmpX][tmpY].unit!=NULL){
                        if(self->cell[tmpX][tmpY].unit->player==0){player1++;}
                        if(self->cell[tmpX][tmpY].unit->player==1){player2++;}
                   }
                    //
                   tmpX=i+1;
                   tmpY=j-1;
                   if(tmpX<0){tmpX=0;}
                   if(tmpY<0){tmpY=0;}
                   if(self->cell[tmpX][tmpY].obj_un_null==1&&self->cell[tmpX][tmpY].unit!=NULL){
                        if(self->cell[tmpX][tmpY].unit->player==0){player1++;}
                        if(self->cell[tmpX][tmpY].unit->player==1){player2++;}
                   }
                    //
                   tmpX=i+1;
                   tmpY=j;
                   if(tmpX<0){tmpX=0;}
                   if(tmpY<0){tmpY=0;}
                   if(self->cell[tmpX][tmpY].obj_un_null==1&&self->cell[tmpX][tmpY].unit!=NULL){
                        if(self->cell[tmpX][tmpY].unit->player==0){player1++;}
                        if(self->cell[tmpX][tmpY].unit->player==1){player2++;}
                   }
                    //
                   tmpX=i+1;
                   tmpY=j+1;
                   if(tmpX<0){tmpX=0;}
                   if(tmpY<0){tmpY=0;}
                   if(self->cell[tmpX][tmpY].obj_un_null==1&&self->cell[tmpX][tmpY].unit!=NULL){
                        if(self->cell[tmpX][tmpY].unit->player==0){player1++;}
                        if(self->cell[tmpX][tmpY].unit->player==1){player2++;}
                   }
                    //
                   tmpX=i;
                   tmpY=j+1;
                   if(tmpX<0){tmpX=0;}
                   if(tmpY<0){tmpY=0;}
                   if(self->cell[tmpX][tmpY].obj_un_null==1&&self->cell[tmpX][tmpY].unit!=NULL){
                        if(self->cell[tmpX][tmpY].unit->player==0){player1++;}
                        if(self->cell[tmpX][tmpY].unit->player==1){player2++;}
                   }
                    //
                   tmpX=i-1;
                   tmpY=j+1;
                   if(tmpX<0){tmpX=0;}
                   if(tmpY<0){tmpY=0;}
                   if(self->cell[tmpX][tmpY].obj_un_null==1&&self->cell[tmpX][tmpY].unit!=NULL){
                        if(self->cell[tmpX][tmpY].unit->player==0){player1++;}
                        if(self->cell[tmpX][tmpY].unit->player==1){player2++;}
                   }
                    //
                   tmpX=i-1;
                   tmpY=j;
                   if(tmpX<0){tmpX=0;}
                   if(tmpY<0){tmpY=0;}
                   if(self->cell[tmpX][tmpY].obj_un_null==1&&self->cell[tmpX][tmpY].unit!=NULL){
                        if(self->cell[tmpX][tmpY].unit->player==0){player1++;}
                        if(self->cell[tmpX][tmpY].unit->player==1){player2++;}
                   }


                   if(player1==0&&player2>0){

                       self->cell[i][j].object->currentPlayer = 1;


                   }

                   if(player2==0&&player1>0){

                        self->cell[i][j].object->currentPlayer = 0;

                   }




                }


            }
        }





}











void gameClient(sf::RenderWindow & window,char * mapName){

        int i,/*displacementX=0,displacementY=0,*/ menu=0;
        gameMap_t map;

       // int redrawMMAP = 1;

        cursor_t gCur;
        gCur.status = 0;
        gCur.cell = NULL;



        player_t players;

        players.resourcesPlayer1 = 500;
        players.resourcesPlayer2 = 500;
      //  player_t player2;



        unsigned int currentPlayerTurn=0;

        selection_t select;

        select.status=0;

        select.cell=NULL;


        createMap(&map);




        /*
        Set textures.
        */
        sf::Texture background, interface_image,menu1,menu2,grind,cursor,pCourse,endTurn1,endTurn2,sel,enemy,fpT,spT,cT1,cT2;
        sf::Sprite gameBackground,gameInterface,gameMenu,gameGrind,gameCursor,aCell,gameEndTurn,cSel,cEnemy,cpT,cTc;
        menu1.loadFromFile("gameInterface/menu.png");

        fpT.loadFromFile("gameInterface/fpTurn.png");
        spT.loadFromFile("gameInterface/spTurn.png");

        enemy.loadFromFile("gameInterface/enemyCell.png");

        sel.loadFromFile("gameInterface/selected.png");
        menu2.loadFromFile("gameInterface/menuConfirmed.png");
        grind.loadFromFile("maps/grind.png");
        endTurn1.loadFromFile("gameInterface/endTurn.png");
        endTurn2.loadFromFile("gameInterface/endTurnConfirmed.png");
        cT1.loadFromFile("gameInterface/cTank.png");
        cT2.loadFromFile("gameInterface/cTankC.png");
        //test

        addUnit(&map,window,0,TANK,15,0);

        addUnit(&map,window,0,TANK,12,0);

        addUnit(&map,window,0,TANK,9,0);

        addUnit(&map,window,1,TANK,27,18);

        addUnit(&map,window,1,TANK,30,18);

        addUnit(&map,window,1,TANK,33,18);

        addObject(&map,window,0,20,12);

        addObject(&map,window,0,10,10);

        addObject(&map,window,0,30,8);
       //int t1 =  map.cell[1][2].object->profit;



        cpT.setPosition(130,0);
        //test


        cursor.loadFromFile("gameInterface/setCell.png");
        pCourse.loadFromFile("gameInterface/availableCell.png");

       // cursor.loadFromFile("gameInterface/menu.png");


        background.loadFromFile(mapName);




        interface_image.loadFromFile("gameInterface/mainInterface.png");
        gameBackground.setTexture(background);
        cSel.setTexture(sel);
        aCell.setTexture(pCourse);
        gameGrind.setTexture(grind);
        gameInterface.setTexture(interface_image);
        cEnemy.setTexture(enemy);
        gameCursor.setTexture(cursor);

        drawMinMap(window,currentPlayerTurn,&map);




while (window.isOpen()){

         cameraMouseMove(window,&map);

         mouseEvents(window,&map);

         menu=gameSelection(window,gameMenu,menu1,menu2,gameEndTurn,endTurn1,endTurn2,cTc,cT1,cT2);

         gameBackground.setPosition(map.displacementX,map.displacementY);

         gameInterface.setPosition(-1,-1);

         gameMenu.setPosition(1700,0);
         gameEndTurn.setPosition(1500,5);
         cTc.setPosition(1680,750);
         //aCell.setPosition(400,400);


         selectUnit(&map,window,cSel,&select,currentPlayerTurn);

        if(select.status==1){
        cSel.setPosition(select.cell->X,select.cell->Y);
        }

         sf::Event event;


          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&menu==1){
                    if(pauseMenu(window)==0){
                        break;
                    }
          }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&menu>=3){
                    //if(pauseMenu(window)==0){
                     //   break;
                    //}
                    createUnit(&map,&players,currentPlayerTurn,menu,window,&select,gameBackground,gameInterface,gameMenu,gameEndTurn,cTc);
          }

           if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&menu==2){

                getOP(&map,&players);

                    getResources(&map,currentPlayerTurn,&players);

                    if(currentPlayerTurn==0){
                            currentPlayerTurn=1;
                            deleteSelect(&select);
                            endTurn(&map);

                    }else{

                    if(currentPlayerTurn==1){
                            currentPlayerTurn=0;
                             deleteSelect(&select);
                              endTurn(&map);
                    }}

                    Sleep(500);
          }



          if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){

           deleteSelect(&select);

          }





         while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        window.clear(sf::Color::Black);
        window.draw(gameBackground);
        drawUnits(&map,window);
        if(cursorConfirm(window,&map,gameCursor,&gCur)==1){
        window.draw(gameCursor);
        }
        if(select.status==1){
                window.draw(cSel);
                findWay(&map,window,&select,aCell,cEnemy,&gCur,gameBackground,gameInterface,gameMenu,gameEndTurn,currentPlayerTurn,cTc,&players);

        }
        window.draw(gameInterface);

        if(select.status==1){
           pData(window,&select);
        }



        window.draw(gameMenu);
        window.draw(gameEndTurn);

        drawMinMap(window,currentPlayerTurn,&map);




        drawPlayer(window,currentPlayerTurn,&players);

        window.draw(cTc);



        window.display();







}

}

