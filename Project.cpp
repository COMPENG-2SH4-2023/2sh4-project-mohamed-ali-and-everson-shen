#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;       

bool exitFlag;
int row;
int col;
char frame[height][length];
Player myPlayer;


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
    row = 0;
    col = 0;

    myGM = new GameMechs(30,15);
    myPlayer = new Player(myGM);
    // myPlayer = objPos(length/2-1,height/2-1,'*');
}

void GetInput(void)
{

}

void RunLogic(void)
{

    objPos tempPos;
    myPlayer.getPlayerPos(tempPos);

    myPlayer->updatePlayerDir();
    for (row = 0; row < height; row++){
        for (col = 0; col < length; col++){
            if (row == 0 || col == 0 || row == height - 1 || col == length - 1) {
                frame[row][col] = '#';
            } 
            else
            {
                frame[row][col] = ' ';
            }

        }
    }

}



void DrawScreen(void)
{
    MacUILib_clearScreen();    

    MacUILib_printf("BoardSize: %d%d, Player Pos: <%d, %d> + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol)
    // for (row = 0; row < height; row++){
    //     for (col = 0; col < length; col++){
    //         if ((row == player.y)&&(col == player.x)){
    //             MacUILib_printf("%c", player.symbol);
    //         }
    //         else{
    //             MacUILib_printf("%c", frame[row][col]);
    //     }
    //     }
    //     MacUILib_printf("\n");
    // }

    //Debugging
    MacUILib_printf("Player coordinate x is: %d\n", player.x);
    MacUILib_printf("Player coordinate y is: %d\n", player.y);
    MacUILib_printf("Player symbol is: %c\n", player.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete GameMechsPtr;
    MacUILib_uninit();
}
