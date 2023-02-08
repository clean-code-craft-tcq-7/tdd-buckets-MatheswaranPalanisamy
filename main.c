#include <stdio.h>

#include "testChargeCurrentMonitor.h"

int main()
{
    // Test case for Step 1
    chargeCurrentPair outputArray[20];
    testCurrentPairOutput(NULL, 5, outputArray, 0);

    int currentPairArray1[1];
    testCurrentPairOutput(currentPairArray1, 0, outputArray, 0);

    int currentPairArray2[1] = {3};
    testCurrentPairOutput(currentPairArray2, 1, outputArray, 0);

    // Test case for Step 2
    int currentPairArray3[2] = {4, 5};
    chargeCurrentPair outputArray1[1] = {{4,5,2}};
    testCurrentPairOutput(currentPairArray3, 2, outputArray1, 1);

    int currentPairArray4[6] = {4, 5, 6, 7, 8, 9};
    chargeCurrentPair outputArray2[1] = {{4,9,6}};
    testCurrentPairOutput(currentPairArray4, 6, outputArray2, 1);

    // Test case for Step 3
    int currentPairArray5[7] = {1, 2, 3, 7, 8, 9, 10};
    chargeCurrentPair outputArray3[2] = {{1,3,3}, {7,10,4}};
    testCurrentPairOutput(currentPairArray5, 7, outputArray3, 2);

    int currentPairArray6[8] = {1, 2, 3, 7, 8, 9, 11, 12};
    chargeCurrentPair outputArray4[3] = {{1,3,3}, {7,9,3}, {11,12,2}};
    testCurrentPairOutput(currentPairArray6, 8, outputArray4, 3);

    // Test case for Step 4
    int currentPairArray7[2] = {3, 2};
    chargeCurrentPair outputArray5[1] = {{2,3,2}};
    testCurrentPairOutput(currentPairArray7, 2, outputArray5, 1);

    int currentPairArray8[5] = {6, 4, 7, 8, 5};
    chargeCurrentPair outputArray6[1] = {{4,8,5}};
    testCurrentPairOutput(currentPairArray8, 5, outputArray6, 1);

    int currentPairArray9[7] = {7, 8, 3, 12, 2, 9, 11};
    chargeCurrentPair outputArray7[3] = {{2,3,2}, {7,9,3}, {11,12,2}};
    testCurrentPairOutput(currentPairArray9, 7, outputArray7, 3);


    // Test case for Step 5
    int currentPairArray10[2] = {3, 3};
    testCurrentPairOutput(currentPairArray10, 2, outputArray, 0);
    
    int currentPairArray11[4] = {3, 2, 2, 3};
    chargeCurrentPair outputArray8[1] = {{2,3,4}};
    testCurrentPairOutput(currentPairArray11, 4, outputArray8, 1);

    int currentPairArray12[12] = {7, 8, 3, 12, 2, 9, 11, 2, 7, 9, 7, 9};
    chargeCurrentPair outputArray9[3] = {{2,3,3}, {7,9,7}, {11,12,2}};
    testCurrentPairOutput(currentPairArray12, 12, outputArray9, 3);

    return 0;
}
