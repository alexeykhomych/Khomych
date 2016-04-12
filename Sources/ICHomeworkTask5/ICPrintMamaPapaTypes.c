//
//  ICPrintIntFold.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICRunApplicationFunction.h"
#include <stdio.h>

typedef enum {
    //ICPrintTypeMama = "mama"
//    ICPrintTypeMama = 'mama',
    ICPrintTypeMama,
    ICPrintTypePapa,
    ICPrintTypeMamaPapa,
    ICPrintTypeNothing
}ICPrintType;

int ICPrintIntFold(int value) {
    ICPrintType type;
    if(value % 3 == 0) {
        type = ICPrintTypeMama;
    } else if(value % 5 == 0) {
        type = ICPrintTypePapa;
    } else if(value % 15 == 0) {
        type = ICPrintTypeMamaPapa;
    } else {
        type = ICPrintTypeNothing;
    }
//    
//    printf("%s", ICPrintTypeMama);
    return type;
}

void ICPrintMapaPapaTypes() {
    int value = ICPrintIntFold(3);
    if(0 == value) {
        printf("mama");
    } else if(1 == value) {
        printf("papa");
    } else if(2 == value) {
        printf("mamapapa\n");
    } else {
        //do nothing
    }
}
