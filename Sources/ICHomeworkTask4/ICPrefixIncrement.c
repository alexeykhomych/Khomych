//
//  ICPrefixIncrement.c
//  Homework_lesson1
//
//  Created by Admin on 10.04.16.
//
//

#include "ICRunApplicationFunction.h"

int ICPrefixIncrement(int prefixIncrementValue) {
    prefixIncrementValue = 2 + ++prefixIncrementValue;
    
    return prefixIncrementValue;
}
