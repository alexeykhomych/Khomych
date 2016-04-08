//
//  ICPrintIntArray.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICPrintIntArray.h"

void ICPrintIntArray() {
    int array1[4] = {0, 5, 3};
    int array2[] = {5, 12, 6, 12};
    int array3[4];
    
    /* for */

    for (int iterator = 0; iterator < 4; iterator++) {
        printf("%d\n", array1[iterator]);
        printf("%d\n", array2[iterator]);
        printf("%d\n", array3[iterator]);
    }
    
    /* do..while */
    int iteratorDo = 0;
    do {
        printf("%d\n", array1[iteratorDo]);
        printf("%d\n", array2[iteratorDo]);
        printf("%d\n", array3[iteratorDo]);
        iteratorDo++;
    }
    while(iteratorDo < 4);
    
//    /* while */
    iteratorDo = 0;
    while(iteratorDo < 4) {
        printf("%d\n", array1[iteratorDo]);
        printf("%d\n", array2[iteratorDo]);
        printf("%d\n", array3[iteratorDo]);
        iteratorDo++;
    }
}
