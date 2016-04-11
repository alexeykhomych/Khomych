//
//  ICBoolPrintMamaPapaIfElse.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//
#include <stdio.h>

#include "ICRunApplicationFunction.h"

void ICBoolPrintMamaPapaIfElse(int value1, int value2) {
    if(value1 > value2) {
        puts("Mama");
    } else {
        puts("Papa");
    }
}
