#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY/2, '*');
}


Player::~Player()
{
    // delete player;
    // delete mainGameMechsRef;
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol)
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
        switch (input) {
            case 27:
                exitFlag = 1;
                break;
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

void Player::movePlayer()
{
    switch(myDir) {
        case UP:
            playerPos.y--;
            break;
        case DOWN:
            playerPos.y++;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        case LEFT:
            playerPos.x--;        
            break;
        default:
            break;
    }
}

