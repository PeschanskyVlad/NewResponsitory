#include "mainMenuHeader.h"

int main()
{
    sf::RenderWindow win(sf::VideoMode(1000, 800), "Awakening_of_forgotten", sf::Style::Fullscreen ); //creating window
    mainMenu(win);
    return 0;
}