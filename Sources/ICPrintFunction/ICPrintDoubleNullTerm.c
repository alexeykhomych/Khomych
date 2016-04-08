//
//  ICPrintDoubleNullTerm.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICPrintDoubleNullTerm.h"

void ICPrintDoubleNullTerm(char text[]) {
    int count = 0;
    
    for (int iterator = 0; iterator < strlen(text); iterator++) {
        if(text[iterator] == '\0') {
            count++;
        }
    }
    
    if(count == 2) {
        puts(text);
    }
}
