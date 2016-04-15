//
//  ICPrintIntFold.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//
#include <stdio.h>
#include <string.h>

#include "ICRunApplication.h"

int ICPrintTypeWithInt(int value) {
    ICPrintType type = ICPrintTypeNothing;
    
    if(value % 3 == 0) {
        type += ICPrintTypeMama;
    }
    
    if(value % 5 == 0) {
        type += ICPrintTypePapa;
    }
    
    if(type) {
        printf("\n");
    }
    
    return type;
}

void ICPrintMapaPapaTypes() {
    ICPrintType type = ICPrintTypeWithInt(15);
}
