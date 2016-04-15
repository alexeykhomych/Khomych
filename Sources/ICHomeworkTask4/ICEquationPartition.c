//
//  ICEquationPartition.c
//  Homework_lesson1
//
//  Created by Admin on 10.04.16.
//
//

#include "ICRunApplication.h"

void ICEquationPartition() {
    double doubleResult = 3.0;
    
    double first = doubleResult * doubleResult;
    first = first / 4;
    first = (int)first % 7;
    
    double second = 4.0 * doubleResult;
    second = second - 1.5;
    second = second + 'A';
    
    first = first + second;
}
