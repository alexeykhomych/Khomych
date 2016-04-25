//
//  ICPrintString.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include <stdio.h>
#include <string.h>

#include "ICRunApplication.h"

void ICPrintString(const char *text) {
    ICPrintStringWithLength(text, strlen(text));
}

void ICPrintStringWithLength(const char* text, size_t length) {
    for (size_t iterator = 0; iterator < length; iterator++) {
        printf("%c\n", text[iterator]);
    }
}