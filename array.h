/* ARRAY FUNCTIONS HEADER

This header file contains basic functions for arrays which are mostly useless of
course.

All functions have the prefix "arr_" and are in PascalCase


Function included are:

    PrintArray(Array, Length)
        This prints a 1d array with spaces inbetween values

    Print2DArray(Array, Length, Width)
        Prints a 2d array with spaces inbetween values and
        a new line for each new row

    PrintAnySizeArray(Array, Length)
        The exact same as PrintArray, there is zero difference
        you work out length by multiplying all the dimensions
        together.
        e.g.
            arr[4][7][2], length = 4*7*2 = 56
            arr[5][7][3][2][5] length = 5*7*1*2*5 = 1050

        In theory this trick could be used on any function in
        here.

    Fill(Array, ValueToFillWith, Length)
        Fills an array with length Length with ValueToFillWith

    RandomFill(Array, LowerBound, UpperBound, Length)
        Fills an array with random numbers determined by
        LowerBound and UpperBound

*/


#include <stdio.h> // Used for printing
#include <time.h> // Used to call time in SRAND
#include <stdlib.h> // Used for random function

#pragma GCC diagnostic push // Start Warning ignore
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"   // Used to stop warnings made by
                                                                // passing an array to a function.




// Prints a 1D array with length Length with spaces inbetween values
void arr_PrintArray(int *arr, size_t length) {
    for (int i=0; i<length; ++i) {
        printf("%d ", *arr);
        arr++;
    }
}

// Prints a 2D array with length Length and width Width. There are
// spaces between values and new lines between rows.
void arr_Print2DArray(int *arr, size_t length, size_t width) {
    for (int i=0; i<length;++i){
        for (int j=0; j<width;++j){
            printf("%d ", *arr);
            arr++;
        }
        printf("\n");
    }
}

/* 
Prints an array with N-Dimensions- Just multiply the value of 
all the dimensions together to get the length.

e.g.
    arr[4][7][2], length = 4*7*2 = 56
    arr[5][7][3][2][5], length = 5*7*1*2*5 = 1050

Note: This function is the exact same as PrintArray just with a different comment
*/
void arr_PrintAnySizeArray(int *arr, size_t length) {
    for (int i=0; i<length; ++i) {
        printf("%d ", *arr);
        arr++;
    }
}

// Fill an array of length length with the value given to valueToFillWith
void arr_Fill(int *arr, int valueToFillWith, size_t length) {
    for (int i=0; i<length; ++i){
        *arr = valueToFillWith;
        arr++;
    }
}

// Fills an array with random numbers determined by LowerBound and UpperBound
void arr_RandomFill(int *arr, int lowerBound, int upperBound, size_t length) {
    srand(time(NULL));

    for (int i=0; i<length; ++i){
        *arr = ((rand() % (int)(((upperBound) + 1) - (lowerBound))) + (lowerBound));
        arr++;
    }
}


#pragma GCC diagnostic pop // Stop warning ignore