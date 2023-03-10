#include <iostream>
#include "JumpPrime.h"
#include "DuelingJP.h"

using std::cout;
using std::endl;

void printSeparator() {
    cout << "*---------------------------*" << endl;

}

void jumpValueOutput(JumpPrime& testJP) {
    cout << "JumpPrime encapsulated value: " << testJP.getCurrentValue() << endl;
    cout << "JumpPrime up value: " << testJP.up() << endl;
    cout << "JumpPrime down value: " << testJP.down() << endl;
}

void duelValueOutput(DuelingJP& testDJP) {
    cout << "DuelingJP size: " << testDJP.getSize() << endl;
    cout << "DuelingJP number of collisions: " << testDJP.countCollisions() << endl;
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

    cout << "Testing increment operators." << endl;
    testJP = jp1;
    cout << "Outputting pre-increment data." << endl;
    jumpValueOutput(testJP);
    cout << "Outputting JP++ data." << endl;
    testJP++;
    jumpValueOutput(testJP);
    cout << "Outputting ++JP data." << endl;
    ++testJP;
    jumpValueOutput(testJP);



    printSeparator();

    cout << "Testing comparison." << endl;
    cout << "Comparing " << TEST_VALUE_1 << " JP object to " << TEST_VALUE_2
        << " JP object." << endl;
    cout << "Test equal: " << (jp1 == jp2) << endl;
    cout << "Test not-equal: " << (jp1 != jp2) << endl;
    cout << "Test greater than: " << (jp1 > jp2) << endl;
    cout << "Test greater than equal: " << (jp1 >= jp2) << endl;
    cout << "Test less than: " << (jp1 < jp2) << endl;
    cout << "Test less than equal: " << (jp1 <= jp2) << endl;

    printSeparator();

    cout << "Testing comparison (#2)." << endl;
    cout << "Comparing " << TEST_VALUE_1 << " JP object to " << TEST_VALUE_1
        << " JP object." << endl;
    testJP = JumpPrime(TEST_VALUE_1);
    cout << "Test equal: " << (jp1 == testJP) << endl;
    cout << "Test not-equal: " << (jp1 != testJP) << endl;
    cout << "Test greater than: " << (jp1 > testJP) << endl;
    cout << "Test greater than equal: " << (jp1 >= testJP) << endl;
    cout << "Test less than: " << (jp1 < testJP) << endl;
    cout << "Test less than equal: " << (jp1 <= testJP) << endl;

    printSeparator();

}

void duelingTest() {
    const int TEST_ARRAY_1[] = {2488, 2489, 2490, 2505, 2509};
    const int ARRAY_SIZE_1 = 5;

    const int TEST_ARRAY_2[] = {941, 1843, 2401};
    const int ARRAY_SIZE_2 = 3;


    DuelingJP djp1(TEST_ARRAY_1, ARRAY_SIZE_1);
    DuelingJP djp2(TEST_ARRAY_2, ARRAY_SIZE_2);

    DuelingJP testDJP(TEST_ARRAY_1, ARRAY_SIZE_1);

    cout << "Testing comparison." << endl;
    cout << "Comparing DJP object #1 (size 5) to DJP object #2 (size 3)." << endl;
    cout << "Test equal: " << (djp1 == djp2) << endl;
    cout << "Test not-equal: " << (djp1 != djp2) << endl;
    cout << "Test greater than: " << (djp1 > djp2) << endl;
    cout << "Test greater than equal: " << (djp1 >= djp2) << endl;
    cout << "Test less than: " << (djp1 < djp2) << endl;
    cout << "Test less than equal: " << (djp1 <= djp2) << endl;

    printSeparator();

    cout << "Testing comparison (#2)." << endl;
    cout << "Comparing DJP object #1 (size 5) to duplicate DJP object (size 5)." << endl;
    cout << "Test equal: " << (djp1 == testDJP) << endl;
    cout << "Test not-equal: " << (djp1 != testDJP) << endl;
    cout << "Test greater than: " << (djp1 > testDJP) << endl;
    cout << "Test greater than equal: " << (djp1 >= testDJP) << endl;
    cout << "Test less than: " << (djp1 < testDJP) << endl;
    cout << "Test less than equal: " << (djp1 <= testDJP) << endl;

    printSeparator();

    cout << "Testing DJP+DJP" << endl;
    testDJP = djp1 + djp2;
    cout << "Expected size: " << ARRAY_SIZE_1 + ARRAY_SIZE_2 << endl;
    duelValueOutput(testDJP);

    printSeparator();

    // put the block so it will de-reference the JumpPrime
    {
        cout << "Testing DJP+JP" << endl;
        JumpPrime testJP;
        cout << "Adding default JP to DJP object #1 (size 5)." << endl;
        testDJP = djp1 + testJP;
        cout << "Expected size: " << ARRAY_SIZE_1 + 1 << endl;
        duelValueOutput(testDJP);

        printSeparator();

        cout << "Testing JP+DJP" << endl;
        cout << "Adding DJP object #1 (size 5) to default JP." << endl;
        testDJP = testJP + djp1;
        cout << "Expected size: " << ARRAY_SIZE_1 + 1 << endl;
        duelValueOutput(testDJP);

    }

    printSeparator();

    cout << "Testing DJP+=DJP" << endl;
    testDJP = djp1;
    testDJP += djp1;
    cout << "Expected size: " << ARRAY_SIZE_1 * 2 << endl;
    duelValueOutput(testDJP);

}

int main() {
    jumpPrimeTest();

    duelingTest();

    return 0;
}
