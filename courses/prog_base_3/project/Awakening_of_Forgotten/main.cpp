#include "mainMenuHeader.h"
#include "gameClient.h"


int main()
{

   srand ( time(NULL) );
   sf::RenderWindow win(sf::VideoMode(1920, 1080), "Awakening_of_forgotten");//,sf::Style::Fullscreen ); //creating window


    mainMenu(win);
    return 0;
}
