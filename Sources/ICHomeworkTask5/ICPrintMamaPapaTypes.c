//
//  ICPrintIntFold.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICRunApplicationFunction.h"
#include <stdio.h>
#include <string.h>

int ICPrintTypeWithInt(int value) {
    ICPrintType type = ICPrintTypeNothing;
    
    if(value % 3 == 0) {
        type = ICPrintTypeMama;
    }
    
    if(value % 5 == 0) {
        type = ICPrintTypePapa;
    }
    
    if(value % 15 == 0) {
        type = (int)(ICPrintTypeMama + ICPrintTypePapa);
    }
    
    return type;
}

void ICPrintMapaPapaTypes() {
    ICPrintType type = ICPrintTypeWithInt(1);
    
    char* arr[4];
    arr[ICPrintTypeNothing] = ICPrintTypeNothing;
    arr[ICPrintTypeMama] = "mama";
    arr[ICPrintTypePapa] = "papa";
    arr[ICPrintTypeMamaPapa] = "mamapapa";
    
    arr[type] != NULL ? printf("%s\n", arr[type]) : printf("");
}
