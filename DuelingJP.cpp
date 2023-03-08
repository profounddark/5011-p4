// Created by Andrew Asplund
// Date: 02/07/2023
// Revision: 1.0

#include <algorithm>
#include "DuelingJP.h"


bool DuelingJP::areActive() {

    bool returnValue = true;

    int index = 0;
    while ((returnValue) && index < listSize) {
        returnValue = jumperList[index].isActive();
        index++;
    }

    return returnValue;
}


void DuelingJP::reactivateJumpers() {
    // note: the JumpPrime objects should never need to be reset

    for (int i = 0; i < listSize; i++) {
        // if JumpPrime i is inactive
        if (!jumperList[i].isActive()) {
            // revive it
            jumperList[i].revive();
        }
    }
}

bool DuelingJP::testJumper(int jumperNumber) {
    if (!jumperList[jumperNumber].isActive()) {
        return jumperList[jumperNumber].revive();
    }

    return true;
}


// assumption: all values in initValues are valid
DuelingJP::DuelingJP(const int *initValues, int size) {

    listSize = size;
    jumperList = new JumpPrime[listSize];

    for (int i = 0; i < listSize; i++) {
        JumpPrime tempJP(initValues[i]);
        jumperList[i] = tempJP;
    }
}


DuelingJP::~DuelingJP() {
    delete jumperList;

}


DuelingJP::DuelingJP(DuelingJP &sourceObject) {

    // copy list size
    listSize = sourceObject.listSize;

    jumperList = new JumpPrime[listSize];
    for (int i = 0; i < listSize; i++) {
        jumperList[i] = sourceObject.jumperList[i];
    }

}

DuelingJP::DuelingJP(DuelingJP &&sourceObject) {

    // copy parameters
    listSize = sourceObject.listSize;
    jumperList = sourceObject.jumperList;

    // clear the source
    sourceObject.listSize = 0;
    sourceObject.jumperList = nullptr;



}


DuelingJP &DuelingJP::operator=(const DuelingJP &sourceObject) {

    // check to verify they're not the same object
    if (this != &sourceObject) {

        // delete the old list of JumpPrime objects
        delete this->jumperList;

        listSize = sourceObject.listSize;

        jumperList = new JumpPrime[listSize];
        for (int i = 0; i < listSize; i++) {
            jumperList[i] = sourceObject.jumperList[i];
        }

    }

    // return the new list
    return *this;

}

DuelingJP &DuelingJP::operator=(DuelingJP &&sourceObject) {

    // swap contents
    std::swap(listSize, sourceObject.listSize);
    std::swap(jumperList, sourceObject.jumperList);



    return *this;
}

int DuelingJP::countCollisions(bool testUp) {

    struct CollisionCounter {
        unsigned int value = 0;
        int count = 0;
    };

    CollisionCounter *collisionCounter = new CollisionCounter[listSize];


    for (int i = 0; i < listSize; i++) {
        unsigned int outputValue;
        testJumper(i);
        outputValue = testUp ?
                jumperList[i].up() :
                jumperList[i].down();

        /// For determining where in the count array to store count
        int countIndex = 0;

        // move through array until either a 0 value or equal value
        while ((collisionCounter[countIndex].value > 0) &&
               (collisionCounter[countIndex].value != outputValue)) {
            countIndex++;
        }

        collisionCounter[countIndex].value = outputValue;
        collisionCounter[countIndex].count++;

    }

    // now count how many values had collisions
    int returnCount = 0;

    for (int i = 0; i < listSize; i++) {
        if (collisionCounter[i].count > 0) {
            returnCount = returnCount + collisionCounter[i].count - 1;
        }
    }

    delete[] collisionCounter;

    return returnCount;
}

int DuelingJP::countInversions() {


    unsigned int *upCount = new unsigned int[listSize];
    unsigned int *downCount = new unsigned int[listSize];

    for (int i = 0; i < listSize; i++) {
        // In case the JumpPrime was inactive
        testJumper(i);
        upCount[i] = jumperList[i].up();

        // In case the up jump deactivated it
        testJumper(i);
        downCount[i] = jumperList[i].down();
    }

    int inversionCounter = 0;

    for (int upTrack = 0; upTrack < listSize; upTrack++) {
        for (int downTrack = 0; downTrack < listSize; downTrack++) {
            if (upCount[upTrack] == downCount[downTrack]) {
                inversionCounter++;
            }
        }
    }

    delete[] upCount;
    delete[] downCount;

    return inversionCounter;
}



int DuelingJP::getSize() const {
    return listSize;
}








