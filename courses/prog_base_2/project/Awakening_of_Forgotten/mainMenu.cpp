#include "mainMenuHeader.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

int menuSelection(sf::RenderWindow & win,sf::Texture & newgame,sf::Texture & loadgame,sf::Texture & exit){

    if (sf::IntRect(50, 50, 270, 65).contains(sf::Mouse::getPosition(win))) {

        newgame.loadFromFile("newGameConfirmed.png");
        loadgame.loadFromFile("loadGame.png");
        exit.loadFromFile("exit.png");
        return 1;
    }
    else
    {
            if (sf::IntRect(50, 150, 270, 65).contains(sf::Mouse::getPosition(win)))
            {

                newgame.loadFromFile("newGame.png");
                loadgame.loadFromFile("loadGameConfirmed.png");
                exit.loadFromFile("exit.png");
                return 2;
            }
            else
            {
                    if (sf::IntRect(50, 250, 270, 65).contains(sf::Mouse::getPosition(win)))
                    {

                        newgame.loadFromFile("newGame.png");
                        loadgame.loadFromFile("loadGame.png");
                        exit.loadFromFile("exitConfirmed.png");
                        return 3;
                    }
                    else
                    {
                        newgame.loadFromFile("newGame.png");
                        loadgame.loadFromFile("loadGame.png");
                        exit.loadFromFile("exit.png");
                        return 0;

                    }
            }
    }
}


void mainMenu(){


    sf::RenderWindow win(sf::VideoMode(1000, 800), "Awakening_of_forgotten", sf::Style::Fullscreen );
    sf::Texture background,newgame,loadgame,exit;
    sf::Sprite menuBackground, menuNewGame,menuLoadGame,menuExit;
    int menuNum=0;

  while (win.isOpen())
    {

    background.loadFromFile("background.jpg");


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


			if (menuNum == 1)  {}
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



