#include "mainMenuHeader.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define max_map_name_length 100

/*
realization of backlight buttons
*/

int menuSelection(sf::RenderWindow & win,sf::Texture & newgame,sf::Texture & loadgame,sf::Texture & exit){

    if (sf::IntRect(50, 50, 270, 65).contains(sf::Mouse::getPosition(win))) {

        newgame.loadFromFile("menuPictures/newGameConfirmed.png");
        loadgame.loadFromFile("menuPictures/loadGame.png");
        exit.loadFromFile("menuPictures/exit.png");
        return 1;
    }
    else
    {
            if (sf::IntRect(50, 150, 270, 65).contains(sf::Mouse::getPosition(win)))
            {

                newgame.loadFromFile("menuPictures/newGame.png");
                loadgame.loadFromFile("menuPictures/loadGameConfirmed.png");
                exit.loadFromFile("menuPictures/exit.png");
                return 2;
            }
            else
            {
                    if (sf::IntRect(50, 250, 270, 65).contains(sf::Mouse::getPosition(win)))
                    {

                        newgame.loadFromFile("menuPictures/newGame.png");
                        loadgame.loadFromFile("menuPictures/loadGame.png");
                        exit.loadFromFile("menuPictures/exitConfirmed.png");
                        return 3;
                    }
                    else
                    {
                        newgame.loadFromFile("menuPictures/newGame.png");
                        loadgame.loadFromFile("menuPictures/loadGame.png");
                        exit.loadFromFile("menuPictures/exit.png");
                        return 0;

                    }
            }
    }
}

/*
draw menu
*/


void mainMenu(sf::RenderWindow & win){

    char * map=(char*)malloc(100);
    memset(map,0,max_map_name_length);
    strcpy(map,"maps/Map1.jpg");


    sf::Texture background,newgame,loadgame,exit;
    sf::Sprite menuBackground, menuNewGame,menuLoadGame,menuExit;
    int menuNum=0;

  while (win.isOpen())
    {

background.loadFromFile("menuPictures/background.jpg");
//background.loadFromFile("maps/Map1.jpg");

    menuBackground.setTexture(background);
    menuBackground.setPosition(0,0);

    menuNum=menuSelection(win,newgame,loadgame,exit);

    menuNewGame.setTexture(newgame);
    menuNewGame.setPosition(50,50);

    menuLoadGame.setTexture(loadgame);
    menuLoadGame.setPosition(50,150);

    menuExit.setTexture(exit);
    menuExit.setPosition(50,250);


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{


			if (menuNum == 1)  {
                    gameClient(win,map);
                   // win.clear();
                    }

			if (menuNum == 2)  {}
			if (menuNum == 3)  { win.close();}

		}


        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

      win.clear();
      win.draw(menuBackground);
      win.draw(menuNewGame);
      win.draw(menuLoadGame);
      win.draw(menuExit);
      win.display();
      menuNum=0;
    }

}



