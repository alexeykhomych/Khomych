//
//  ICMathematicOperations.c
//  Homework_lesson1
//
//  Created by Admin on 10.04.16.
//
//

#include <stdio.h>
#include <stdbool.h>

#include "ICRunApplication.h"

bool ICMathematicOperations(int value1, int value2) {
    printf("%s", ICStringWithBool(value1 / value2));
    printf("%s", ICStringWithBool(value1 * value2));
    printf("%s", ICStringWithBool(value1 + value2));
    printf("%s", ICStringWithBool(value1 - value2));
    
    return 0;
}
