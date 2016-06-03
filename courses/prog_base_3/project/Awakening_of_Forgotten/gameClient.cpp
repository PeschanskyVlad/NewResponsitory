#include "mainMenuHeader.h"

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
   //Left
     if (sf::IntRect(0, 200, 200, 680).contains(sf::Mouse::getPosition(window))){
       cameraLeft(self);
   }
   //Down
    if (sf::IntRect(200, 880, 1520, 200).contains(sf::Mouse::getPosition(window))){
       cameraDown(self);
   }
   //Right
    if (sf::IntRect(1720, 200, 200, 680).contains(sf::Mouse::getPosition(window))){
       cameraRight(self);
    }
   //Down Left
   if (sf::IntRect(0, 880, 200, 200).contains(sf::Mouse::getPosition(window))){
        cameraDown(self);
        cameraLeft(self);
   }
   //Up Right
 //  if (sf::IntRect(1720, 0, 200, 200).contains(sf::Mouse::getPosition(window))){
 //      cameraUp(self);
 //      cameraRight(self);
  // }
   //Down Right
   if (sf::IntRect(1720, 880, 200, 200).contains(sf::Mouse::getPosition(window))){
       cameraDown(self);
       cameraRight(self);
   }
}






int gameSelection(sf::RenderWindow & window,sf::Sprite & gameMenu,sf::Texture & menu1,sf::Texture & menu2,sf::Sprite & gameEndTurn,sf::Texture & E1,sf::Texture & E2){
    if (sf::IntRect(1729, 0, 209, 104).contains(sf::Mouse::getPosition(window))) {
        gameMenu.setTexture(menu2);
        gameEndTurn.setTexture(E1);
       return 1;
    }else if(sf::IntRect(1500, 0, 209, 104).contains(sf::Mouse::getPosition(window))){
        gameMenu.setTexture(menu1);
        gameEndTurn.setTexture(E2);
        return 2;
    }else{

    gameMenu.setTexture(menu1);
    gameEndTurn.setTexture(E1);
    return 0;
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

            }
        }



}

void selectUnit(gameMap_t * self,sf::RenderWindow & window,sf::Sprite & cSel,selection_t*select){

    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                    if (sf::IntRect(self->cell[i][j].X, self->cell[i][j].Y, cell_width, cell_height).contains(sf::Mouse::getPosition(window))&&self->cell[i][j].obj_un_null==1&&sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                            cSel.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                            setSelect(&self->cell[i][j],select);

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

void  findWay(gameMap_t * self,sf::RenderWindow & window, selection_t * cUnit,sf::Sprite & aCell,sf::Sprite & aEnemy, cursor_t * gCur,sf::Sprite & gameBackground,sf::Sprite & gameInterface,sf::Sprite & gameMenu,sf::Sprite & gameEndTurn){

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

                                    //unit_t tmpUnit =
                                   // tmpT.loadFromFile(self->cell[i][j].unit->sprites.path[self->cell[i][j].unit->direction]);
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
                                            window.draw(gameEndTurn);


                                            tmpS.setPosition(tmpCX,tmpCY);
                                            window.draw(tmpS);
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

                    if(tmpSt == 1 && tmp!="" && calculateLength(tmp)<=cUnit->cell->unit->aRange){


                         aEnemy.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                         window.draw(aEnemy);

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
        map->scrollingSpeed=3;

        for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                map->cell[i][j].X = (map_width-cell_width*cellNumX)/2+i*cell_width;
                map->cell[i][j].Y = (map_height-cell_height*cellNumY)/2+j*cell_height;
                map->cell[i][j].obj_un_null=0;
                map->cell[i][j].unit = NULL;

                map->cell[i][j].iX =i;
                map->cell[i][j].jY =j;

            }
        }
}







void gameClient(sf::RenderWindow & window,char * mapName){

        int i,/*displacementX=0,displacementY=0,*/ menu=0;
        gameMap_t map;

        cursor_t gCur;
        gCur.status = 0;
        gCur.cell = NULL;



        player_t player1;
        player_t player2;



        unsigned int CurrentPlayerTurn=0;

        selection_t select;

        select.status=0;

        select.cell=NULL;


        createMap(&map);




        /*
        Set textures.
        */
        sf::Texture background, interface_image,menu1,menu2,grind,cursor,pCourse,endTurn1,endTurn2,sel,enemy;
        sf::Sprite gameBackground,gameInterface,gameMenu,gameGrind,gameCursor,aCell,gameEndTurn,cSel,cEnemy;
        menu1.loadFromFile("gameInterface/menu.png");

        enemy.loadFromFile("gameInterface/enemyCell.png");

        sel.loadFromFile("gameInterface/selected.png");
        menu2.loadFromFile("gameInterface/menuConfirmed.png");
        grind.loadFromFile("maps/grind.png");
        endTurn1.loadFromFile("gameInterface/endTurn.png");
        endTurn2.loadFromFile("gameInterface/endTurnConfirmed.png");
        //test

        addUnit(&map,window,0,TANK,10,4);

        addUnit(&map,window,1,TANK,8,4);

        addUnit(&map,window,1,TANK,6,5);
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





while (window.isOpen()){

         cameraMouseMove(window,&map);

         mouseEvents(window,&map);

         menu=gameSelection(window,gameMenu,menu1,menu2,gameEndTurn,endTurn1,endTurn2);

         gameBackground.setPosition(map.displacementX,map.displacementY);

         gameInterface.setPosition(-1,-1);

         gameMenu.setPosition(1700,0);
         gameEndTurn.setPosition(1500,5);
         //aCell.setPosition(400,400);


         selectUnit(&map,window,cSel,&select);

        if(select.status==1){
        cSel.setPosition(select.cell->X,select.cell->Y);
        }

         sf::Event event;


          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&menu==1){
                    if(pauseMenu(window)==0){
                        break;
                    }
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
                findWay(&map,window,&select,aCell,cEnemy,&gCur,gameBackground,gameInterface,gameMenu,gameEndTurn);

        }
        window.draw(gameInterface);
        window.draw(gameMenu);
        window.draw(gameEndTurn);
        window.display();






}

}

