// @author: savolla
// @date: Sat Apr 17 14:08:01 2021
// @desc: FizzBuzz implementation in C with State Machines

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

uint8_t numberArray[100];
uint8_t *currentNumber = numberArray;

// function declarations
void fillArray(uint32_t);
void takeNextNumber(void);
void swapWithFizz(void);
void printPhrase(void);
void swapWithBuzz(void);
void finalState(void);
void (*nextState)(void);
bool isMultiplierOf3(uint8_t);
bool isMultiplierOf5(uint8_t);
bool insideArray(uint8_t, uint8_t, uint8_t);

int main(void) {
    fillArray(100);
    nextState = takeNextNumber;
    while ( insideArray(1, 100, *currentNumber)  ) {
       nextState();
    }
    return 0;
}

// function deffinition
void fillArray(uint32_t limit) {
    for (uint8_t i = 0; i < limit; i++ ) {
        numberArray[i] = i+1;
    }
}

void takeNextNumber(void) {
    if ( isMultiplierOf3( *currentNumber )) {
        nextState = swapWithFizz;
    }
    else if ( isMultiplierOf5( *currentNumber )) {
        nextState = swapWithBuzz;
    }
    else {
        nextState = printPhrase;
    }
}

void swapWithFizz(void) {
    printf("Fizz\n");
    currentNumber++;
    nextState = takeNextNumber;
}

void printPhrase(void) {
    printf("%d\n", *currentNumber);
    nextState = takeNextNumber;
    currentNumber++; // taking next number
}

void swapWithBuzz(void) {
    printf("Buzz\n");
    currentNumber++;
    nextState = takeNextNumber;
}

bool isMultiplierOf3(uint8_t n) {
    return !(n%3);
}

bool isMultiplierOf5(uint8_t n) {
    return !(n%5);
}

bool insideArray(uint8_t lowerLimit,
                uint8_t upperLimit,
                uint8_t number) {
    return (number <= upperLimit && number >= lowerLimit);
}
