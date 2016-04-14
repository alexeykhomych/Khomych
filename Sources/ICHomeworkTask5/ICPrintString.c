//
//  ICPrintString.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include <stdio.h>
#include <string.h>

#include "ICRunApplicationFunction.h"

void ICPrintString(char text[]) {
    for (int iterator = 0; text[iterator] != '\0'; iterator++) {
           printf("%c\n", text[iterator]);
    }
}

void ICPrintNonNullTermString(char text[], int length) {
    printf("%.*s\n", length, text);
}
