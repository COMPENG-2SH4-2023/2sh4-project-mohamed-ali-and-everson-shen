#include "GameMechs.h"
#include "MacUiLib.h"

GameMechs::GameMechs()
{
boardSizeX=30;
boardSizeY=15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
boardSizeX=boardX;
boardSizeY=boardY;
exitFlag=false;
loseFlag=false;
score=0;
clearInput();
}

// do you need a destructor?

bool GameMechs::getExitFlagStatus()
{
return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
return loseFlag;
}


char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag=true;
}

void GameMechs::setLoseFlag()
{
    loseFlag=true;
}


void GameMechs::setInput(char this_input)
{
    input=this_input;
}

void GameMechs::clearInput()
{
    input=0;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}