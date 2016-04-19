//
//  ICPrintIntArray.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICRunApplication.h"

static int array1[4] = {0, 5, 3};
static int array2[] = {5, 12, 6, 12};
static int array3[4];

void ICPrintIntArray() {
    /* for */
    int iterator = 0;
    
    for (iterator = 0; iterator < 4; iterator++) {
        ICListIntArrays(iterator);
    }
    
    /* do..while */
    iterator = 0;
    do {
        ICListIntArrays(iterator);
        iterator++;
    }
    while(iterator < 4);
    
//    /* while */
    iterator = 0;
    while(iterator < 4) {
        ICListIntArrays(iterator);
        iterator++;
    }
}

void ICListIntArrays(int iterator) {
    printf("%d\n", array1[iterator]);
    printf("%d\n", array2[iterator]);
    printf("%d\n", array3[iterator]);
}
