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
    ICPrintIntFoldEntityMama,
    ICPrintIntFoldEntityPapa,
    ICPrintIntFoldEntityMamaPapa,
}ICPrintIntFoldEntity;

int ICPrintIntFold(int value) {
    ICPrintIntFoldEntity entity;
    if(value % 15 == 0) {
        entity = ICPrintIntFoldEntityMamaPapa;
    } else if(value % 3 == 0) {
        entity = ICPrintIntFoldEntityMama;
    } else if(value % 5 == 0) {
        entity = ICPrintIntFoldEntityPapa;
    }
    
    switch (entity) {
        case ICPrintIntFoldEntityMama:
            printf("mama\n");
            break;
        case ICPrintIntFoldEntityPapa:
            printf("papa\n");
            break;
        case ICPrintIntFoldEntityMamaPapa:
            printf("mamapapa\n");
            break;
        default:
            break;
    }
    
    return entity;
}
