#include "mainMenuHeader.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
 #include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct buttonTextures{
    sf::Texture continue1;
    sf::Texture continue2;

    sf::Texture exit1;
    sf::Texture exit2;

    sf::Texture save1;
    sf::Texture save2;

    sf::Texture toMain1;
    sf::Texture toMain2;


};


    int menuSelectionGame(sf::RenderWindow & window,struct buttonTextures & bt, sf::Sprite & menuSave, sf::Sprite & menuContinue, sf::Sprite & menuExit, sf::Sprite & toMain){

    if (sf::IntRect(825, 400, 270, 65).contains(sf::Mouse::getPosition(window))) {
        menuSave.setTexture(bt.save1);
        menuContinue.setTexture(bt.continue2);
        menuExit.setTexture(bt.exit1);
        toMain.setTexture(bt.toMain1);

        return 1;
    }
    else
    {
            if (sf::IntRect(825, 500, 270, 65).contains(sf::Mouse::getPosition(window)))
            {
                menuSave.setTexture(bt.save2);
                menuContinue.setTexture(bt.continue1);
                menuExit.setTexture(bt.exit1);
                toMain.setTexture(bt.toMain1);

                return 2;
            }
            else
            {
                    if (sf::IntRect(825, 600, 270, 65).contains(sf::Mouse::getPosition(window)))
                    {
                        menuSave.setTexture(bt.save1);
                        menuContinue.setTexture(bt.continue1);
                        menuExit.setTexture(bt.exit1);
                        toMain.setTexture(bt.toMain2);

                        return 3;
                    }
                    else
                    {
                        if (sf::IntRect(825, 700, 270, 65).contains(sf::Mouse::getPosition(window)))
                    {
                        menuSave.setTexture(bt.save1);
                        menuContinue.setTexture(bt.continue1);
                        menuExit.setTexture(bt.exit2);
                        toMain.setTexture(bt.toMain1);

                        return 4;
                    }else{


                        menuSave.setTexture(bt.save1);
                        menuContinue.setTexture(bt.continue1);
                        menuExit.setTexture(bt.exit1);
                        toMain.setTexture(bt.toMain1);

                        return 0;
                    }

                    }
            }
    }
}



int pauseMenu(sf::RenderWindow & window){



    struct buttonTextures bt;
    bt.continue1.loadFromFile("menuPictures/continue.png");
    bt.continue2.loadFromFile("menuPictures/continueConfirmed.png");
    bt.save1.loadFromFile("menuPictures/saveGame.png");
    bt.save2.loadFromFile("menuPictures/saveGameConfirmed.png");
    bt.exit1.loadFromFile("menuPictures/exit.png");
    bt.exit2.loadFromFile("menuPictures/exitConfirmed.png");
    bt.toMain1.loadFromFile("menuPictures/mainMenu.png");
    bt.toMain2.loadFromFile("menuPictures/mainMenuConfirmed.png");


    sf::Sprite background1, menuSave,menuContinue,menuExit,toMain;
    sf::Texture background;
    background.loadFromFile("menuPictures/background2.jpg");
    background1.setTexture(background);
    background1.setPosition(0,0);
    int menuNum=0;

     while (window.isOpen())
    {

    menuNum=menuSelectionGame(window,bt,menuSave,menuContinue,menuExit,toMain);


    menuContinue.setPosition(825,400);


    menuSave.setPosition(825,500);


    menuExit.setPosition(825,700);

    toMain.setPosition(825,600);



    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{


			if (menuNum == 1)  {return 1;}


			if (menuNum == 2)  {  }
			if (menuNum == 3)  {return 0;}
			if (menuNum == 4)  { window.close(); }

		}


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

      window.clear();
      window.draw(background1);
      window.draw(menuSave);
      window.draw(toMain);
      window.draw(menuContinue);
      window.draw(menuExit);
      window.display();
      menuNum=0;
    }


}
