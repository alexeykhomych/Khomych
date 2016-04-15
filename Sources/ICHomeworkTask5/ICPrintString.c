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
    for (int iterator = 0; text[iterator] != '\0'; iterator++) {
        printf("%c\n", text[iterator]);
    }
}

void ICPrintNonNullTermString(const char* text, unsigned long strLength) {
    printf("%.*s\n", 50, text);
}