#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000
#define height 10
#define length 20

bool exitFlag;
int row;
int col;
char frame[height][length];
objPos player;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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
    exitFlag = false;
    player = objPos(length/2-1,height/2-1,'@');
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
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
    for (row = 0; row < height; row++){
        for (col = 0; col < length; col++){
            if ((row == player.y)&&(col == player.x)){
                MacUILib_printf("%c", player.symbol);
            }
            else{
                MacUILib_printf("%c", frame[row][col]);
        }
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
