#include "objPosArrayList.h"
#include <iostream>

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{

    if (listSize == arrayCapacity){
        return;
    }

    for(int i = listSize; i > 0; i--){
        aList[i].setObjPos(aList[i-1]); //shuffle to tail
    }

    aList[0].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity){
        return;
    }

    aList[listSize].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{
    for (int i = 0; i < listSize-1; i++){
        aList[i].setObjPos(aList[i+1]);
    }

    listSize--; 
}

void objPosArrayList::removeTail()
{
    //delete aList[listSize-1];
    listSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}