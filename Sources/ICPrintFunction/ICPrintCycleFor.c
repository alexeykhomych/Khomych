//
//  ICPrintCycleFor.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICPrintCycleFor.h"

void ICPrintCycleFor(int count, int min, int max) {
    for (int i = 0; i < count; i++) {
        if(i <= 20) {
            if(i % 3 == 0 || i == 0) {
                int value = rand() % (min - max + 1) + min;
                if(value != 50) {
                    printf("%d\n", value);
                }
                else {
                    break;
                }
            }
        }
        else {
            break;
        }
    }
}
