#include "mainMenuHeader.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
 #include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define cell_width 90
#define cell_height 90

void gameSelection(sf::RenderWindow & window,sf::Sprite & gameMenu,sf::Texture & menu1,sf::Texture & menu2){
    if (sf::IntRect(1729, 0, 209, 104).contains(sf::Mouse::getPosition(window))) {

        gameMenu.setTexture(menu2);
    }else{
        gameMenu.setTexture(menu1);
          //menu.loadFromFile("gameInterface/menu.png");
    }
}

void gameClient(sf::RenderWindow & window,char * map){

        int i;
        sf::Texture background, interface_image,menu1,menu2;
        sf::Sprite gameBackground,gameInterface,gameMenu;
        menu1.loadFromFile("gameInterface/menu.png");
        menu2.loadFromFile("gameInterface/menuConfirmed.png");
        background.loadFromFile(map);
        interface_image.loadFromFile("gameInterface/mainInterface.png");
        gameBackground.setTexture(background);
         //gameMenu.setTexture(menu);
        gameInterface.setTexture(interface_image);



while (window.isOpen()){
         gameSelection(window,gameMenu,menu1,menu2);
         gameBackground.setPosition(0,0);
         gameInterface.setPosition(-1,-1);
         gameMenu.setPosition(1700,0);
         sf::Event event;
         if (sf::IntRect(1820, 0, 100, 50).contains(sf::Mouse::getPosition(window))){

            window.close();

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
        window.draw(gameInterface);
        window.draw(gameMenu);
        window.display();




}

}

