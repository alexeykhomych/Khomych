//
//  ICPrintIntFold.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICPrintIntFold.h"

int ICPrintIntFold(int value) {
    if(value % 3 == 0) {
        puts("mama");
        value = 1;
    }
    else if(value % 5 == 0) {
        puts("papa");
        value = 2;
    }
    else if(value % 15 == 0) {
        puts("mamapapa");
        value = 3;
    }
    else {
        value = 0;
    }
    return value;
}
