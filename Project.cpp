#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;       
Player* myPlayer;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();  

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(30,15);
    myPlayer = new Player(myGM);
    
    myGM->generateFood(myPlayer->getPlayerPos());
    
}

void GetInput(void)
{
    if (MacUILib_hasChar() != 0){
        myGM->setInput(MacUILib_getChar());
    } 
}

void RunLogic(void)
{

    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();
}



void DrawScreen(void)
{

    MacUILib_clearScreen();    
    
    bool drawStatus;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPosArrayList* foodBucket = myGM-> getFoodList();
    objPos tempBody;
    if(myGM->getLoseFlagStatus()){
        MacUILib_printf("\nYou lose, your score was: %d\n", myGM->getScore());

    }
    else{
        objPos foodPos;
        objPos tempFood;
        myGM->getFoodPos(foodPos);

        for (int row = 0; row < myGM->getBoardSizeY(); row++){
            for (int col = 0; col < myGM->getBoardSizeX(); col++){

                drawStatus = false;
                for (int k = 0; k < playerBody->getSize(); k++){
                    playerBody->getElement(tempBody, k);
                    if (tempBody.x == col && tempBody.y == row){
                        MacUILib_printf("%c", tempBody.symbol);
                        drawStatus = true;
                        break;
                    }
                for (int j = 0; j < foodBucket->getSize(); j++){
                    foodBucket->getElement(tempFood, j);
                    if (tempFood.x == col && tempFood.y == row){
                        MacUILib_printf("%c", tempFood.symbol);
                        drawStatus = true;
                        break;
                    }
                }
 
                }

                if(drawStatus) continue;

                
                if (row == 0 || col == 0 || row == ((myGM->getBoardSizeY()) - 1) || col == ((myGM->getBoardSizeX())-1)){
                    MacUILib_printf("#");
                } 
                // else if ((row == tempPos.y) && (col == tempPos.x)){
                //     MacUILib_printf("%c", tempPos.symbol);
                // }
                else if ((row == foodPos.y) && (col == foodPos.x)){
                    MacUILib_printf("%c", foodPos.symbol);
                }
                else{
                    MacUILib_printf(" ");
                }
            }
            MacUILib_printf("\n");
    }

    // MacUILib_printf("BoardSize: %d%d, Player Pos: <%d, %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol);
    // MacUILib_printf("Food Pos: <%d, %d> + %c\n", foodPos.x, foodPos.y, foodPos.symbol);
    MacUILib_printf("Score: %d \n", myGM->getScore());
    }
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{ 
    MacUILib_uninit();
    delete myGM;
    delete myPlayer;
}
