//
//  ICPrefixIncrement.c
//  Homework_lesson1
//
//  Created by Admin on 10.04.16.
//
//

#include "ICRunApplication.h"

int ICPrefixIncrement(int prefixIncrementValue) {
    prefixIncrementValue = 2 + ++prefixIncrementValue;
    
    return prefixIncrementValue;
}
