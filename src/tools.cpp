#include "Arduino.h"
#include "tools.h"

// array push to back function: used in aux detection

void pushToBack(int* array, int length, int value) {
    for (int i = 0; i < length-1; i++) {
        array[i] = array[i+1];
    }

    array[length-1] = value;
}

// calculates an imprecise standard deviation

int findStandardDeviation(int *array, int count) {
    int sum = 0, sDeviation = 0, mean;
    int i;
 
    for(i = 0; i < count; i++) {
        sum += array[i];
    }
    // Calculating mean 
    mean = sum/count;
 
    for(i = 0; i < count; ++i) {
        sDeviation += (array[i] - mean)*(array[i] - mean);
    }

    return sDeviation/count; // returns STD^2 
}
