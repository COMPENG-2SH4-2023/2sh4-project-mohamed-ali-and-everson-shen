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
char frame[length][height];

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
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    for (row = 0; row < length; row++){
        for (col = 0; col < height; col++){
            if (row == 0 || col == 0 || row == length - 1 || col == length - 1) {
                frame[row][col] = '#';
            } 
            else {
                    frame[row][col] = ' ';

            }
        }
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    for (row = 0; row < length; row++){
        for (col = 0; col < height; col++){
            MacUILib_printf("%c", frame[row][col]);
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
