#include "AI.h"
#include "gameClient.h"




int overmindAttack(gameMap_t * self,
              sf::RenderWindow & window,
              selection_t * cUnit,sf::Sprite & aCell,
              sf::Sprite & aEnemy,
              cursor_t * gCur,
              sf::Sprite & gameBackground,
              sf::Sprite & gameInterface,
              sf::Sprite & gameMenu,
              sf::Sprite & gameEndTurn,
              int player,
              sf::Sprite & cTc,
              player_t*pl,
              sf::Sprite & cBc
              //,
              //int XI,
              //int YJ
              ){

                   for(int i = 0;i<cellNumX;i++){
                        for(int j = 0;j<cellNumY;j++){
                                if(cUnit->cell==NULL){
                                    return 0;
                                }

                            if ((float)sqrt((cUnit->cell->iX-i)*(cUnit->cell->iX-i)+(cUnit->cell->jY-j)*(cUnit->cell->jY-j)) <=  (float)(cUnit->cell->unit->aRange)) {

                                   std::string tmp;

                            if(self->cell[i][j].unit!=NULL && self->cell[i][j].unit->player  !=  1 && self->cell[i][j].obj_un_null == 1)
                                {
                                    self->cell[i][j].obj_un_null = 0;
                                    std::string tmp;
                                    tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,i,j,self);

                                    if(tmp!="" && calculateLength(tmp) <= cUnit->cell->unit->aRange && cUnit->cell->unit->cPoints>0){


                                            int tmpD = tmp[0] - 48;

                                            self->cell[i][j].obj_un_null = 1;
                                            cUnit->cell->unit->direction = tmpD;

                                            window.clear(sf::Color::Black);
                                            window.draw(gameBackground);

                                            drawUnits(self,window);

                                            window.draw(gameInterface);
                                            window.draw(gameMenu);
                                            drawMinMap(window,player,self);
                                            window.draw(gameEndTurn);

                                            drawPlayer(window,1,pl);

                                            //pData(window,cUnit);



                                        sf::Texture tmpT;
                                        sf::Sprite tmpS;
                                        tmpT.loadFromFile(self->cell[i][j].unit->sprites.path[10]);
                                        tmpS.setTexture(tmpT);
                                        tmpS.setPosition(self->cell[i][j].X + rand()%50+20,self->cell[i][j].Y + rand()%50+20);
                                        window.draw(tmpS);

                                        sf::Texture tmpT1;
                                        sf::Sprite tmpS1;



                                       tmpT1.loadFromFile(self->cell[i][j].unit->sprites.path[11+self->cell[i][j].unit->direction]);


                                        tmpS1.setTexture(tmpT1);
                                        tmpS1.setPosition(self->cell[i][j].X,self->cell[i][j].Y);


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
                                            drawPlayer(window,1,pl);


                                            window.draw(cBc);
                                            window.draw(tmpS);




                                        window.display();
                                        Sleep(400);

                                        deleteUnit(self->cell[i][j].unit);


                                        self->cell[i][j].unit = NULL;
                                        self->cell[i][j].obj_un_null = 0;
                                        return 1;
                                      }



                                      return 1;



                                    }else{
                                    self->cell[i][j].obj_un_null = 1;
                                    }
                                }



                            }

                        }
                   }
                return 0;
              }


void calculateOptimalResourses(gameMap_t * self,resources_t * res){
                  for(int i = 0;i<cellNumX;i++){
                        for(int j = 0;j<cellNumY;j++){
                                    if(self->cell[i][j].obj_un_null==1&&self->cell[i][j].object!=NULL){
                                            if(self->cell[i][j].object->type==0&&self->cell[i][j].object->currentPlayer!=1){



                                            }

                                    }

                        }
                }




}



int overmindFoundResources(gameMap_t * self,
              sf::RenderWindow & window,
              selection_t * cUnit,
              sf::Sprite & aCell,
              sf::Sprite & aEnemy,
              cursor_t * gCur,
              sf::Sprite & gameBackground,
              sf::Sprite & gameInterface,
              sf::Sprite & gameMenu,
              sf::Sprite & gameEndTurn,
              int player,
              sf::Sprite & cTc,
              player_t*pl,
              sf::Sprite & cBc,int XI,int YJ,resources_t * OP){

                  int tmpWay = 10000;
                  int tmpCount;

                  for(int i = 0;i<OP->count;i++){

                        if(OP->op[i]->object->currentPlayer!=1){

                                std::string tmp;
                                self->cell[OP->op[i]->iX][OP->op[i]->jY].obj_un_null=0;
                                        tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,OP->op[i]->iX,OP->op[i]->jY,self);
                                        if(tmpWay>calculateLength(tmp)){
                                                tmpCount = i;
                                        }
                                        self->cell[OP->op[i]->iX][OP->op[i]->jY].obj_un_null=1;
                        }


                  }

                  int tmpXX1 = cUnit->cell->iX;
                  int tmpYY1 = cUnit->cell->jY;

                  int tmpXX2 = OP->op[tmpCount]->iX+1;
                  int tmpYY2 = OP->op[tmpCount]->jY+1;

                std::string tmp = pathFind(tmpXX1,tmpYY1,tmpXX2,tmpYY2,self);
                if(tmp!=""){
                    goto startMoving;
                }
                tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,OP->op[tmpCount]->iX,OP->op[tmpCount]->jY+1,self);
                if(tmp!=""){
                    goto startMoving;
                }
                tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,OP->op[tmpCount]->iX+1,OP->op[tmpCount]->jY,self);
                if(tmp!=""){
                    goto startMoving;
                }

                tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,OP->op[tmpCount]->iX+1,OP->op[tmpCount]->jY-1,self);
                if(tmp!=""){
                    goto startMoving;
                }
                tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,OP->op[tmpCount]->iX-1,OP->op[tmpCount]->jY+1,self);
                if(tmp!=""){
                    goto startMoving;
                }
                tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,OP->op[tmpCount]->iX-1,OP->op[tmpCount]->jY,self);
                if(tmp!=""){
                    goto startMoving;
                }
                tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,OP->op[tmpCount]->iX,OP->op[tmpCount]->jY-1,self);
                if(tmp!=""){
                    goto startMoving;
                }
                tmp = pathFind(cUnit->cell->iX,cUnit->cell->jY,OP->op[tmpCount]->iX-1,OP->op[tmpCount]->jY-1,self);
                if(tmp!=""){
                    goto startMoving;
                }

                return 0;
                startMoving:;

                int tmpCP;
                 int tmpInt = tmp[0] - 48;
                 if(tmpInt==0||tmpInt==2||tmpInt==4||tmpInt==6){

                                        tmpCP=-1;
                                    }else{

                                        tmpCP=-2;
                                    }

                                    if(cUnit->cell->unit->cPoints+tmpCP>=0){

                                            cUnit->cell->unit->cPoints+=tmpCP;





                //cUnit->cell->unit->direction=tmpInt;
                cUnit->cell->unit->direction = tmpInt;



                /*
                *Start move!
                */


                                   int tmpX = cUnit->cell->iX;

                                   int tmpY = cUnit->cell->jY;

                                    self->cell[tmpX][tmpY].obj_un_null=0;



                                   int tmpCX = cUnit->cell->X;
                                   int tmpCY = cUnit->cell->Y;


                                   sf::Texture tmpT;
                                   sf::Sprite tmpS;

                                   int tX = cUnit->cell->iX;
                                   int tY = cUnit->cell->jY;

                                    tmpT.loadFromFile(cUnit->cell->unit->sprites.path[cUnit->cell->unit->direction]);

                                    tmpS.setTexture(tmpT);

                                    switch(tmpInt){
                                        case 0:

                                            tX+=1;
                                             break;
                                        case 1:

                                            tX+=1;
                                            tY+=1;
                                             break;
                                        case 2:

                                             tY+=1;
                                             break;
                                        case 3:

                                             tX-=1;
                                             tY+=1;
                                             break;
                                        case 4:

                                            tX-=1;
                                             break;
                                        case 5:

                                            tX-=1;
                                            tY-=1;
                                             break;
                                        case 6:

                                             tY-=1;
                                             break;
                                        case 7:

                                              tY-=1;
                                              tX+=1;
                                             break;

                                           }



                for(int a = 0 ; a<10;a++){
                                            switch(tmpInt){
                                        case 0:
                                            tmpCX+=10;

                                             break;
                                        case 1:
                                            tmpCX+=10;
                                            tmpCY+=10;

                                             break;
                                        case 2:
                                             tmpCY+=10;

                                             break;
                                        case 3:
                                             tmpCX-=10;
                                             tmpCY+=10;

                                             break;
                                        case 4:
                                            tmpCX-=10;

                                             break;
                                        case 5:
                                            tmpCX-=10;
                                            tmpCY-=10;

                                             break;
                                        case 6:
                                             tmpCY-=10;

                                             break;
                                        case 7:
                                              tmpCY-=10;
                                              tmpCX+=10;

                                             break;

                                           }

                                            Sleep(20);

                                            window.clear(sf::Color::Black);
                                            window.draw(gameBackground);
                                            drawUnits(self,window);

                                           /* window.draw(gameInterface);
                                            window.draw(gameMenu);
                                            drawMinMap(window,player,self);
                                            window.draw(gameEndTurn);
                                            drawPlayer(window,player,pl);*/




                                            tmpS.setPosition(tmpCX,tmpCY);

                                            window.draw(tmpS);

                                            window.draw(gameInterface);
                                            window.draw(gameMenu);
                                            drawMinMap(window,player,self);
                                            window.draw(gameEndTurn);
                                            drawPlayer(window,player,pl);


                                            window.draw(cTc);
                                            window.draw(cBc);


                                            window.display();

                                    }




                                    self->cell[tX][tY].unit = self->cell[tmpX][tmpY].unit;
                                    self->cell[tX][tY].obj_un_null=1;






                                    cUnit->cell = &self->cell[tX][tY];
                                    cUnit->status = 1;

                                    int TEST = cUnit->cell->unit->cPoints;



                                    self->cell[tmpX][tmpY].unit = NULL;


                                    window.clear(sf::Color::Black);
                                            window.draw(gameBackground);
                                            drawUnits(self,window);

                                          /*  window.draw(gameInterface);
                                            window.draw(gameMenu);
                                            drawMinMap(window,player,self);
                                            window.draw(gameEndTurn);
                                            drawPlayer(window,player,pl);*/




                                            tmpS.setPosition(tmpCX,tmpCY);

                                            window.draw(tmpS);


                                            window.draw(gameInterface);
                                            window.draw(gameMenu);
                                            drawMinMap(window,player,self);
                                            window.draw(gameEndTurn);
                                            drawPlayer(window,player,pl);

                                            window.draw(cTc);
                                            window.draw(cBc);



                                            window.display();



                                    return 1;





              }
              return 0;

              }

void overmindKILL(gameMap_t * self,
              sf::RenderWindow & window,
              selection_t * cUnit,sf::Sprite & aCell,
              sf::Sprite & aEnemy,
              cursor_t * gCur,
              sf::Sprite & gameBackground,
              sf::Sprite & gameInterface,
              sf::Sprite & gameMenu,
              sf::Sprite & gameEndTurn,
              int player,
              sf::Sprite & cTc,
              player_t*pl,
              sf::Sprite & cBc,
              int XI,
              int YJ){






              }

void overmind(gameMap_t * self,
              sf::RenderWindow & window,
              selection_t * cUnit,sf::Sprite & aCell,
              sf::Sprite & aEnemy,
              cursor_t * gCur,
              sf::Sprite & gameBackground,
              sf::Sprite & gameInterface,
              sf::Sprite & gameMenu,
              sf::Sprite & gameEndTurn,
              int player,
              sf::Sprite & cTc,
              player_t*pl,
              sf::Sprite & cBc){

                  resources_t r;
                  r.count = 0;
                  r.optimal = 0;

                  int tCost=200;
                  int bCost=150;
                  int ran;

                  if(pl->resourcesPlayer2>=bCost){
                  if(pl->resourcesPlayer2>=tCost){
                        createUnit(self,pl,1,3,window,cUnit,gameBackground,gameInterface,gameMenu,gameEndTurn,cTc,cBc);
                  }else{
                   createUnit(self,pl,1,4,window,cUnit,gameBackground,gameInterface,gameMenu,gameEndTurn,cTc,cBc);
                  }
                  }

                  for(int i = 0;i<cellNumX*cellNumY;i++){
                    r.op[i] = NULL;
                  }


                  for(int i = 0;i<cellNumX;i++){
                        for(int j = 0;j<cellNumY;j++){

                            if(self->cell[i][j].object!=NULL&&self->cell[i][j].obj_un_null==1&&self->cell[i][j].object->type==0){
                                    r.op[r.count] = &self->cell[i][j];
                                        r.count++;
                            }
                        }
                  }


                  for(int i = 0;i<cellNumX;i++){
                        for(int j = 0;j<cellNumY;j++){
                            if (self->cell[i][j].unit!=NULL&&self->cell[i][j].obj_un_null==1) {

                                    if(self->cell[i][j].unit->player == 1){

                                            selection_t tSel;
                                            setSelect(&self->cell[i][j],&tSel);

                                            while(tSel.cell->unit->cPoints>0){

                                                    if(overmindAttack(self,window,&tSel,aCell,aEnemy,gCur,gameBackground,gameInterface,gameMenu,gameEndTurn,1,cTc,pl,cBc)==1){
                                                        continue;
                                                    }
                                                    if(overmindFoundResources(self,window,&tSel,aCell,aEnemy,gCur,gameBackground,gameInterface,gameMenu,gameEndTurn,1,cTc,pl,cBc,i,j,&r)==1){

                                                        continue;
                                                    }

                                                    tSel.cell->unit->cPoints-=1;






                                            }




                                    }
                            }
                        }
                  }

                getOP(self,pl);
                getResources(self,1,pl);









}
