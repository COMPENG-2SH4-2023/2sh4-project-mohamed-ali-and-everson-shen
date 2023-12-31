#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        
        int boardSizeX;
        int boardSizeY;
        bool loseFlag;
        int score;
        objPos foodPos;   
        objPosArrayList* foodBucket;


    public:
        GameMechs();
        ~GameMechs();
        GameMechs(int boardX, int boardY);
        
        bool getExitFlagStatus();
        void setExitTrue();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();
        void setLoseFlag();
        bool getLoseFlagStatus();
        int getScore();
        void incrementScore();
        void generateFood(objPosArrayList* blockOff); //upgrade somehow
        void getFoodPos(objPos &returnPos);
        void clearFood();
        objPosArrayList* getFoodList();

};

#endif