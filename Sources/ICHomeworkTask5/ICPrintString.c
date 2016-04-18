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

void ICPrintString(char text[]) {
    ICPrintStringWithLength(text, strlen(text));
}

void ICPrintStringWithLength(const char* text, unsigned long strLength) {
    for (int iterator = 0; text[iterator] != '\0'; iterator++) {
        printf("%c\n", text[iterator]);
    }
}