#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    // objPos foodPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    // myGM->getFoodPos(foodPos);

    
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

    //playerPosList->insertHead(currentHead);

    increasePlayerLength(currentHead);

    if (checkDeathFood()){
        mainGameMechsRef->setLoseFlag();   
        mainGameMechsRef->setExitTrue(); 
    }

    if (!checkFoodConsumption()){
        playerPosList->removeTail();
    }

    
    if (checkSelfCollision()){
        mainGameMechsRef->setLoseFlag();   
        mainGameMechsRef->setExitTrue(); 
    }



}


// void objPosArrayList::getElement(objPos &returnPos, int index)
// {
//     returnPos.setObjPos(aList[index]);
// }

bool Player::checkFoodConsumption(){
    objPosArrayList* foodbucket = mainGameMechsRef->getFoodList();

    objPos head;
    objPos temp;
    
    playerPosList->getHeadElement(head);
    
    for (int i = 0; i < 3; i++){
        foodbucket->getElement(temp, i);
            if (head.x == temp.x && head.y == temp.y){
                // if (temp.symbol == 'X'){
                //     mainGameMechsRef->setLoseFlag();   
                //     mainGameMechsRef->setExitTrue(); 
                // }
                // else{
                mainGameMechsRef->incrementScore();
                mainGameMechsRef->clearFood();
                mainGameMechsRef->generateFood(playerPosList);
                return true;
                //}
            }
    }
    return false;

    
    

}

void Player::increasePlayerLength(objPos head){
    // objPos head;
    // playerPosList->getHeadElement(head);
    
    playerPosList->insertHead(head);

}

bool Player::checkSelfCollision() {
    if (playerPosList->getSize() <= 1) {
        return false;
    }

    objPos currentHead;
    objPos currentPos;
    playerPosList->getHeadElement(currentHead);

    for (int i = 1; i < playerPosList->getSize(); i++) {
        playerPosList->getElement(currentPos, i);

        if (currentPos.x == currentHead.x && currentPos.y == currentHead.y) {
            return true;
        }
    }

    return false;
}

bool Player::checkDeathFood() {
    objPos death;
    objPos head;
    objPosArrayList* foodbucket = mainGameMechsRef->getFoodList();
    playerPosList->getHeadElement(head);

    for (int m = 0; m < 3; m++){
        foodbucket->getElement(death, m);

        if (head.x == death.x && head.y == death.y && death.symbol == 'X'){
            return true;
        }
    }

    return false;
    
}
