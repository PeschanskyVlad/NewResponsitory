#include "gameClient.h"

/*
void cameraLeft(gameMap_t * self){
    if(self->displacementX<0){
        self->displacementX+=self->scrollingSpeed;
       }
}
void cameraRight(gameMap_t * self){
    if(self->displacementX>-2580){
        self->displacementX-=self->scrollingSpeed;
       }
}
void cameraUp(gameMap_t * self){
    if(self->displacementY<0){
        self->displacementY+=self->scrollingSpeed;
       }
}
void cameraDown(gameMap_t * self){
     if(self->displacementY>-1420){
        self->displacementY-=self->scrollingSpeed;
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
   if (sf::IntRect(200, 0, 1520, 200).contains(sf::Mouse::getPosition(window))){
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
   if (sf::IntRect(1720, 0, 200, 200).contains(sf::Mouse::getPosition(window))){
       cameraUp(self);
       cameraRight(self);
   }
   //Down Right
   if (sf::IntRect(1720, 880, 200, 200).contains(sf::Mouse::getPosition(window))){
       cameraDown(self);
       cameraRight(self);
   }
}*/
