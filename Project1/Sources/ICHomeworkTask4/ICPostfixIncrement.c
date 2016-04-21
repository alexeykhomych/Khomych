//
//  ICPostfixIncrement.c
//  Homework_lesson1
//
//  Created by Admin on 10.04.16.
//
//

#include "ICRunApplication.h"

int ICPostfixIncrement(int postfixIncrementValue) {
    postfixIncrementValue = 2 * postfixIncrementValue++;
    
    return postfixIncrementValue;
}
