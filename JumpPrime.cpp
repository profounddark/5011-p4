// Created by Andrew Asplund
// Date: 02/07/2023
// Revision: 2.0

#include "JumpPrime.h"


bool JumpPrime::isPrime(unsigned int testNumber) {

    for (unsigned int i = 2; i < testNumber; i++) {
        if (testNumber % i == 0) {
            return false;
        }
    }

    return true;
}

unsigned int JumpPrime::findPrime(unsigned int startValue, bool findNext) {
    // determine if this needs to count up or down
    int stepValue = findNext ? 1 : -1;

    unsigned int result = startValue + stepValue;

    while (!isPrime(result)) {
        result = result + stepValue;
    }

    return result;
}

void JumpPrime::setPrimeLimits() {

    upperPrime = findPrime(mainNumber, true);
    lowerPrime = findPrime(mainNumber, false);

}

void JumpPrime::resetQueryCounter() {
    queryLimit = upperPrime - lowerPrime;
    queryCount = 0;
}

void JumpPrime::jumpNumber(int jumpValue) {

    // initiate the jump
    mainNumber = mainNumber + jumpValue;

    setPrimeLimits();
    resetQueryCounter();

    jumpCount++;

    // test to see if JumpPrime object has reached the jump limit
    if (jumpCount >= jumpLimit) {
        // turn off the object
        currentState = Inactive;

    }
}

JumpPrime::JumpPrime(unsigned int initValue, unsigned int jumpBound) {

    // less than four digits
    if (initValue < 100) {
        currentState = Failed;

    }
    // otherwise, proceed with initialization
    else {
        currentState = Active;
        jumpLimit = jumpBound;
        initialNumber = initValue;
        this->reset();
    }
}

bool JumpPrime::operator==(const JumpPrime &jumpCompare) const {
    if (this->mainNumber == jumpCompare.mainNumber) {
        return true;
    } else {
        return false;
    }
}

bool JumpPrime::operator!=(const JumpPrime &jumpCompare) const {
    return !(*this == jumpCompare);
}

bool JumpPrime::operator>(const JumpPrime &jumpCompare) const {
    return (this->mainNumber > jumpCompare.mainNumber);
}

bool JumpPrime::operator>=(const JumpPrime &jumpCompare) const {
    return (this->mainNumber >= jumpCompare.mainNumber);
}

bool JumpPrime::operator<(const JumpPrime &jumpCompare) const {
    return (this->mainNumber < jumpCompare.mainNumber);
}

bool JumpPrime::operator<=(const JumpPrime &jumpCompare) const {
    return (this->mainNumber <= jumpCompare.mainNumber);
}

JumpPrime JumpPrime::operator+(int addNumber) {
    unsigned int tempValue;

    tempValue = this->mainNumber + addNumber;

    JumpPrime returnJump(tempValue);

    return returnJump;
}

JumpPrime JumpPrime::operator+(const JumpPrime &jumpAdd) {

    unsigned int tempValue;

    tempValue = this->mainNumber + jumpAdd.mainNumber;

    JumpPrime returnJump(tempValue);

    return returnJump;
}

JumpPrime& JumpPrime::operator+=(int addNumber) {
    this->initialNumber = this->mainNumber + addNumber;
    this->currentState = Active;
    this->reset();

    return *this;
}

JumpPrime& JumpPrime::operator+=(const JumpPrime &jumpAdd) {

    this->initialNumber = this->mainNumber + jumpAdd.mainNumber;
    this->currentState = Active;
    this->reset();

    return *this;
}

unsigned int JumpPrime::up() {
    if (currentState == Active) {
        // storing the upper prime in the case that the object jumps
        // after this query
        unsigned int returnValue = upperPrime;

        queryCount++;

        if (queryCount >= queryLimit) {
            jumpNumber(upperPrime + DEFAULT_JUMP_VALUE);

        }

        return returnValue;
    }
    return 0;
}


unsigned int JumpPrime::down() {
    if (currentState == Active) {
        // storing the upper prime in the case that the object jumps
        // after this query
        unsigned int returnValue = lowerPrime;

        queryCount++;

        if (queryCount >= queryLimit) {
            jumpNumber(lowerPrime - DEFAULT_JUMP_VALUE);
        }

        return returnValue;
    }
    return 0;
}



bool JumpPrime::reset() {
    if (currentState == Failed) {
        return false;
    }

    else {
        currentState = Active;
        mainNumber = initialNumber;

        setPrimeLimits();
        resetQueryCounter();

        jumpCount = 0;

        return true;
    }
}


bool JumpPrime::revive() {
    // object is not running and is not permanently broken
    if (currentState == Inactive) {
        // revive the object
        currentState = Active;
        jumpCount = 0;
        queryCount = 0;
    }
    // in any other case
    else {
        // revive permanently disables the object
        currentState = Failed;
    }

    return (currentState == Active);
}


bool JumpPrime::isActive() {
    return (currentState == Active);
}


bool JumpPrime::isDisabled() {
    return (currentState == Failed);
}

unsigned int JumpPrime::getCurrentValue() const {
    return mainNumber;
}

JumpPrime operator+(int addNumber, const JumpPrime &jumpAdd) {
    unsigned int newValue = jumpAdd.mainNumber + addNumber;

    JumpPrime newJP(newValue);

    return newJP;
}
















