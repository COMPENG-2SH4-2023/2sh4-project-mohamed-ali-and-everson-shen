#include "GameMechs.h"
#include "MacUiLib.h"
#include "objPosArrayList.h"
#include <iostream>

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    clearInput();
}

GameMechs::GameMechs(int boardX, int boardY)
   
{
    boardSizeX =boardX; 
    boardSizeY = boardY; 
    exitFlag = false; 
    loseFlag = false; 
    score = 0;
    clearInput();
    foodBucket = new objPosArrayList;
}

GameMechs::~GameMechs()
{
    delete foodBucket;
}

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
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
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
    srand((unsigned)time(NULL));
    int randx, randy;
    bool duplicate;
    objPos temp;
    bool specialFlag;
    int foodCount = 0;

    while (foodCount < 3)
    {
        specialFlag = (foodCount == 0);
        do
        {
            duplicate = false;
            randx = (rand() % (boardSizeX - 2)) + 1;
            randy = (rand() % (boardSizeY - 2)) + 1;

            for (int i = 0; i < blockOff->getSize(); i++)
            {
                blockOff->getElement(temp, i);
                if (randx == temp.x && randy == temp.y)
                {
                    duplicate = true;
                    break;
                }
            }

            for (int x = 0; x < foodCount; x++){
                blockOff->getElement(temp, x);
                    if (randx == temp.x && randy == temp.y)
                    {
                        duplicate = true;
                    }
                }
        } while (duplicate);

        if (specialFlag)
        {
            foodPos.setObjPos(randx, randy, 'X');
        }
        else
        {
            foodPos.setObjPos(randx, randy, 'o');
        }

        foodCount++;
        foodBucket->insertTail(foodPos);
        
    }
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}

 objPosArrayList* GameMechs::getFoodList()
{
    return (foodBucket);
}

void GameMechs::clearFood(){
    while(foodBucket->getSize() != 0){
        foodBucket->removeTail();
    }
}
