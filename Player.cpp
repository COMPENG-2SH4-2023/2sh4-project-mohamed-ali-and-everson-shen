#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    
}


Player::~Player()
{
    // delete player;
    delete playerPosList;
    // delete mainGameMechsRef;
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    if (input != 0){
        switch (input) {
            case 27:
                mainGameMechsRef->setExitTrue();
            case 119: // w
            case 87:
                if (myDir != DOWN){
                    myDir = UP;
                }
                break;
            case 97: // a
            case 65:
                if (myDir != RIGHT){
                    myDir = LEFT;
                }
                break;
            case 115:
            case 83: // s
                if (myDir != UP){
                    myDir = DOWN;
                }
                break;
            case 100:
            case 68: // d
                if (myDir != LEFT){
                    myDir = RIGHT;
                }
                break;
            default:
                break;
        }

    }
}

void Player::movePlayer()
{
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);
    
    switch(myDir) {
        case UP:

            currentHead.y--;
            break;
        case DOWN:
            currentHead.y++;
            break;
        case RIGHT:
            currentHead.x++;
            break;
        case LEFT:
            currentHead.x--;        
            break;
        default:
            break;
    }

    if (currentHead.x == 0){
        currentHead.x = mainGameMechsRef->getBoardSizeX()-2;
    }
    else if (currentHead.x == mainGameMechsRef->getBoardSizeX()-1){
        currentHead.x = 1;
    }

    if (currentHead.y == 0){
        currentHead.y = mainGameMechsRef->getBoardSizeY()-2;
    }
    else if (currentHead.y == mainGameMechsRef->getBoardSizeY()-1){
        currentHead.y = 1;
    }

    playerPosList->insertHead(currentHead);
    playerPosList->removeTail();
}



