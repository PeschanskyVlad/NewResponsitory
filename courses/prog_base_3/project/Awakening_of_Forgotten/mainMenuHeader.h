#ifndef MAINMENUHEADER_H_INCLUDED
#define MAINMENUHEADER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
 #include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "gameClient.h"
#define max_map_name_length 100


void mainMenu(sf::RenderWindow & win);
void gameClient(sf::RenderWindow & win,char * map);
int pauseMenu(sf::RenderWindow & win);


#endif // MAINMENUHEADER_H_INCLUDED
