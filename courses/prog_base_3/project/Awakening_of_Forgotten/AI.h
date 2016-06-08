#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

#include "gameClient.h"
#include "mainMenuHeader.h"

void overmind(gameMap_t * self,
              sf::RenderWindow & window,
              selection_t * cUnit,sf::Sprite & aCell,
              sf::Sprite & aEnemy,
              cursor_t * gCur,
              sf::Sprite & gameBackground,
              sf::Sprite & gameInterface,
              sf::Sprite & gameMenu,
              sf::Sprite & gameEndTurn,
              int player,
              sf::Sprite & cTc,
              player_t*pl,
              sf::Sprite & cBc);

typedef struct resources{
    cell_t * op[cellNumX*cellNumY];
    int count;

    int optimal;
}resources_t;


#endif // AI_H_INCLUDED
