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

int cursorConfirm(sf::RenderWindow & window,gameMap_t * self,sf::Sprite & cursorXY){
    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                    if (sf::IntRect(self->cell[i][j].X, self->cell[i][j].Y, cell_width, cell_height).contains(sf::Mouse::getPosition(window))) {
                            cursorXY.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                    return 1;
                    }

            }
        }
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
       // return 0;
}

/*
void changeXY(gameMap_t * self){
     for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
              self->cell[i][j].X+=self->displacementX;
              self->cell[i][j].Y+=self->displacementY;
            }
        }

}*/

void addUnit(gameMap_t * self,sf::RenderWindow & window, Unit type,int X, int Y){

 /*self->cell[10][4].unit = newTank(1);
 self->cell[10][4].obj_un_null=1;

 self->cell[8][4].unit = newTank(1);
 self->cell[8][4].obj_un_null=1;

 self->cell[9][4].unit = newTank(1);
 self->cell[9][4].obj_un_null=1;*/
 switch(type){
  case TANK:
    self->cell[X][Y].unit = newTank(1);
    self->cell[X][Y].obj_un_null=1;
    break;


 }
}

char * findWay(gameMap_t * self,sf::RenderWindow & window, selection_t * cUnit,sf::Sprite & aCell){

    for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){

              /* char tmp[100];
               // sprintf(tmp,"sqrt: %f", sqrt((cUnit->cell->iX-i)*(cUnit->cell->iX-i)+(cUnit->cell->jY-j)*(cUnit->cell->jY-j)) );
                sf::Font font;
                font.loadFromFile("gameInterface/arial.ttf");
                sf::Text text;
                text.setFont(font);
                text.setColor(sf::Color::Black);
              //  text.setString(tmp);
                text.setCharacterSize(10);
                //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                text.setPosition(self->cell[i][j].X,self->cell[i][j].Y);


                //window.draw(text);*/


                    if ((float)sqrt((cUnit->cell->iX-i)*(cUnit->cell->iX-i)+(cUnit->cell->jY-j)*(cUnit->cell->jY-j)) <=  (float)(cUnit->cell->unit->cPoints)) {

                    std::string tmp;
                    tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,i,j,self);

                    if(tmp!="" && calculateLength(tmp)<=3 ){


                       // text.setString(pathFind(cUnit->cell->iX,cUnit->cell->jY,i,j,self));
                       // text.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                       // window.draw(text);

                          aCell.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                         window.draw(aCell);

                   }


                    }
                   // if(lee(self,cUnit,i,j)!=NULL){
                     //     aCell.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                      //    window.draw(aCell);

                   // }
                    /*
                   if(pathFind(cUnit->cell->iX,cUnit->cell->jY,i,j,self) != ""){
                         aCell.setPosition(self->cell[i][j].X,self->cell[i][j].Y);
                         window.draw(aCell);

                   }*/
            }
        }


}







void gameClient(sf::RenderWindow & window,char * mapName){

        int i,/*displacementX=0,displacementY=0,*/ menu=0;
        gameMap_t map;



        selection_t select;
        select.status=0;
        select.cell=NULL;

        map.displacementX=0;
        map.displacementY=0;
        map.scrollingSpeed=3;

        for(int i = 0;i<cellNumX;i++){
            for(int j = 0;j<cellNumY;j++){
                map.cell[i][j].X = (map_width-cell_width*cellNumX)/2+i*cell_width;
                map.cell[i][j].Y = (map_height-cell_height*cellNumY)/2+j*cell_height;
                map.cell[i][j].obj_un_null=0;
                map.cell[i][j].unit = NULL;

                map.cell[i][j].iX =i;
                map.cell[i][j].jY =j;

            }
        }




        /*
        Set textures.
        */
        sf::Texture background, interface_image,menu1,menu2,grind,cursor,pCourse,endTurn1,endTurn2,sel;
        sf::Sprite gameBackground,gameInterface,gameMenu,gameGrind,gameCursor,aCell,gameEndTurn,cSel;
        menu1.loadFromFile("gameInterface/menu.png");
        sel.loadFromFile("gameInterface/selected.png");
        menu2.loadFromFile("gameInterface/menuConfirmed.png");
        grind.loadFromFile("maps/grind.png");
        endTurn1.loadFromFile("gameInterface/endTurn.png");
        endTurn2.loadFromFile("gameInterface/endTurnConfirmed.png");
        //test

        addUnit(&map,window,TANK,10,4);

        addUnit(&map,window,TANK,8,4);

        addUnit(&map,window,TANK,6,5);
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

        gameCursor.setTexture(cursor);





while (window.isOpen()){

         cameraMouseMove(window,&map);

         mouseEvents(window,&map);

         menu=gameSelection(window,gameMenu,menu1,menu2,gameEndTurn,endTurn1,endTurn2);

         gameBackground.setPosition(map.displacementX,map.displacementY);

         gameInterface.setPosition(-1,-1);

         gameMenu.setPosition(1700,0);
         gameEndTurn.setPosition(1500,5);
         aCell.setPosition(400,400);


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





         while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        window.clear(sf::Color::Black);


        window.draw(gameBackground);

        //window.draw(aCell);

        drawUnits(&map,window);

        if(cursorConfirm(window,&map,gameCursor)==1){
        window.draw(gameCursor);
        }

        if(select.status==1){
                window.draw(cSel);
                findWay(&map,window,&select,aCell);

        }

       // window.draw(aCell);
        window.draw(gameInterface);
        window.draw(gameMenu);

        window.draw(gameEndTurn);
        window.display();




}

}

