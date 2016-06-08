#include "mainMenuHeader.h"


#define max_map_name_length 100



struct buttonTextures{
    sf::Texture newgame1;
    sf::Texture newgame2;
    sf::Texture loadgame1;
    sf::Texture loadgame2;
    sf::Texture exit1;
    sf::Texture exit2;

};

/*
realization of backlight buttons
*/


    int menuSelection(sf::RenderWindow & window,struct buttonTextures & bt, sf::Sprite & menuNewGame, sf::Sprite & menuLoadGame, sf::Sprite & menuExit ){

    if (sf::IntRect(50, 50, 270, 65).contains(sf::Mouse::getPosition(window))) {
        menuNewGame.setTexture(bt.newgame2);
        menuLoadGame.setTexture(bt.loadgame1);
        menuExit.setTexture(bt.exit1);

        return 1;
    }
    else
    {
            if (sf::IntRect(50, 150, 270, 65).contains(sf::Mouse::getPosition(window)))
            {
                menuNewGame.setTexture(bt.newgame1);
                menuLoadGame.setTexture(bt.loadgame2);
                menuExit.setTexture(bt.exit1);

                return 2;
            }
            else
            {
                    if (sf::IntRect(50, 250, 270, 65).contains(sf::Mouse::getPosition(window)))
                    {
                        menuNewGame.setTexture(bt.newgame1);
                        menuLoadGame.setTexture(bt.loadgame1);
                        menuExit.setTexture(bt.exit2);

                        return 3;
                    }
                    else
                    {


                        menuNewGame.setTexture(bt.newgame1);
                        menuLoadGame.setTexture(bt.loadgame1);
                        menuExit.setTexture(bt.exit1);

                        return 0;

                    }
            }
    }
}

/*
draw menu
*/
void mainMenu(sf::RenderWindow & window){
    struct buttonTextures bt;
    bt.newgame1.loadFromFile("menuPictures/newGame.png");

    bt.newgame2.loadFromFile("menuPictures/newGameConfirmed.png");

    bt.loadgame1.loadFromFile("menuPictures/loadGame.png");

    bt.loadgame2.loadFromFile("menuPictures/loadGameConfirmed.png");

    bt.exit1.loadFromFile("menuPictures/exit.png");

    bt.exit2.loadFromFile("menuPictures/exitConfirmed.png");


    char * map=(char*)malloc(100);
    memset(map,0,max_map_name_length);
    strcpy(map,"maps/Map1.jpg");

    sf::Texture mainBackground;

    sf::Sprite menuBackground, menuNewGame,menuLoadGame,menuExit;

    mainBackground.loadFromFile("menuPictures/background.jpg");

    menuBackground.setTexture(mainBackground);
    menuBackground.setPosition(0,0);

    int menuNum=0;

  while (window.isOpen())
    {




    menuNum=menuSelection(window,bt,menuNewGame,menuLoadGame,menuExit);

    menuNewGame.setPosition(50,50);


    menuLoadGame.setPosition(50,150);


    menuExit.setPosition(50,250);


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{


			if (menuNum == 1)  {

                    gameClient(window,map);



                    }


			if (menuNum == 2)  {}
			if (menuNum == 3)  { window.close();}

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
      window.draw(menuBackground);
      window.draw(menuNewGame);
      window.draw(menuLoadGame);
      window.draw(menuExit);
      window.display();
      menuNum=0;
    }


}



