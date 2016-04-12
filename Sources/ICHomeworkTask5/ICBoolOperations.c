//
//  ICBoolOperations.c
//  Homework_lesson1
//
//  Created by Admin on 10.04.16.
//
//

#include <stdio.h>
#include <stdbool.h>

#include "ICRunApplicationFunction.h"

void ICBoolOperations(int value1, int value2) {
    bool result = value1 > value2;
    ICOutputParamsBool(result);
    
    result = value1 == value2;
    ICOutputParamsBool(result);
    
    result = (value1 - 5) <= value2;
    ICOutputParamsBool(result);
    
    result = (value1 - 8) >= value2;
    ICOutputParamsBool(result);
}
