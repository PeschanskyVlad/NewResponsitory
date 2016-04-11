#include "mainMenuHeader.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <Windows.h>
#define cell_width 90
#define cell_height 90



void gameClient(sf::RenderWindow & win,char * map){
    //sf::Texture background,interface;
    sf::Texture background;
    sf::Sprite gameBackground,gameInterface;
     win.clear();
    background.loadFromFile(map);
    gameBackground.setTexture(background);
    gameBackground.setPosition(0,0);
     /* while (win.isOpen()){
            background.loadFromFile(map);
           gameBackground.setTexture(background);
            gameBackground.setPosition(200,200);


      }*/
      win.clear();

      Sleep(10000);

}

