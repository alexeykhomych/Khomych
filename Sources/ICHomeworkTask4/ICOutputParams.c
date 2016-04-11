//
//  ICOutputParams.c
//  Homework_lesson1
//
//  Created by Admin on 10.04.16.
//
//

#include <stdio.h>

#include "ICRunApplicationFunction.h"

void ICOutputParamsInt(int value) {
    printf("Integer: %d\n", value);
}

void ICOutputParamsDouble(double value) {
    printf("Double: %f\n", value);
}

void ICOutputParamsChar(char chars) {
    printf("Char: %c\n", chars);
}

void ICOutputParamsString(char charsArray[]) {
    printf("String: %s", charsArray);
}

void ICOutputParamsBool(bool boolValue) {
    printf("Bool: %d\n", boolValue);
}

void ICOutputParamsFloat(float floatValue) {
    printf("Float: %f\n", floatValue);
}
