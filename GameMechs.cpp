#include "GameMechs.h"
#include "MacUiLib.h"
#include "objPosArrayList.h"

GameMechs::GameMechs()
{
boardSizeX=30;
boardSizeY=15;
exitFlag=false;
loseFlag=false;
score=0;
clearInput();
}

GameMechs::GameMechs(int boardX, int boardY)
{
boardSizeX=boardX;
boardSizeY=boardY;
exitFlag=false;
loseFlag=false;
score=0;
objPos foodPos;
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

void GameMechs::generateFood(objPosArrayList* blockOff)
{
    srand ((unsigned) time (NULL));
    int randx, randy;
    bool duplicate;
    objPos temp;

    do {
        duplicate = false;

        randx = (rand() % (boardSizeX - 2)) + 1;
        randy = (rand() % (boardSizeY - 2)) + 1;

        for (int i = 0; i < blockOff->getSize(); i++){
            blockOff->getElement(temp, i);
            if (randx == temp.x && randy == temp.y){
                duplicate = true;
            }
        }

            if (randx == foodPos.x && randy == foodPos.y) {
                duplicate = true;
                break;
            }
    } while (duplicate);

    foodPos.setObjPos(randx, randy, 'o');

}


void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);
}
