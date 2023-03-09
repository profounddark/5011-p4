#include <iostream>
#include "JumpPrime.h"

using std::cout;
using std::endl;

void printSeparator() {
    cout << "*------------------------*" << endl;

}

void jumpValueOutput(JumpPrime testJP) {
    cout << "JumpPrime encapsulated value: " << testJP.getCurrentValue() << endl;
    cout << "JumpPrime up value: " << testJP.up() << endl;
    cout << "JumpPrime down value: " << testJP.down() << endl;
}

void jumpPrimeTest() {
    const unsigned int TEST_VALUE_1 = 938;
    const unsigned int TEST_VALUE_2 = 1732;
    const int ADD_VALUE = 5283;

    cout << "Testing JumpPrime addition operators." << endl;
    cout << "Instancing new JumpPrime objects with initial values " <<
        TEST_VALUE_1 << " and " << TEST_VALUE_2 << endl;
    JumpPrime jp1(TEST_VALUE_1);
    JumpPrime jp2(TEST_VALUE_2);

    cout << "Testing JP+JP." << endl;
    JumpPrime testJP = jp1 + jp2;
    jumpValueOutput(testJP);

    printSeparator();

    cout << "Testing JP + int." << endl;
    cout << "Adding " << ADD_VALUE << " to " << TEST_VALUE_1
        << " JP object." << endl;
    testJP = jp1 + ADD_VALUE;
    jumpValueOutput(testJP);

    printSeparator();

    cout << "Testing JP += JP." << endl;
    cout << "Adding " << TEST_VALUE_1 << " JP Object to " << TEST_VALUE_2
        << " JP object." << endl;
    testJP = JumpPrime(TEST_VALUE_2);
    testJP += jp1;
    jumpValueOutput(testJP);

    printSeparator();

    cout << "Testing JP += int." << endl;
    cout << "Adding " << ADD_VALUE << " int to " << TEST_VALUE_2
         << " JP object." << endl;
    testJP = JumpPrime(TEST_VALUE_2);
    testJP += ADD_VALUE;
    jumpValueOutput(testJP);

    printSeparator();

    cout << "Testing int + JP." << endl;
    cout << "Adding " << TEST_VALUE_1 << " JP object to " << ADD_VALUE
        << " integer." << endl;
    testJP = ADD_VALUE + jp1;
    jumpValueOutput(testJP);

    printSeparator();

    cout << "Testing comparison." << endl;
    cout << "Comparing " << TEST_VALUE_1 << " JP object to " << TEST_VALUE_2
        << " JP object." << endl;
    cout << "Test equal: " << (jp1 == jp2) << endl;
    cout << "Test not-equal: " << (jp1 != jp2) << endl;

    printSeparator();

    cout << "Testing comparison (#2)." << endl;
    cout << "Comparing " << TEST_VALUE_1 << " JP object to " << TEST_VALUE_1
        << " JP object." << endl;
    testJP = JumpPrime(TEST_VALUE_1);
    cout << "Test equal: " << (jp1 == testJP) << endl;
    cout << "Test not-equal: " << (jp1 != testJP) << endl;

}

void duelingTest() {

}

int main() {
    jumpPrimeTest();


    return 0;
}
