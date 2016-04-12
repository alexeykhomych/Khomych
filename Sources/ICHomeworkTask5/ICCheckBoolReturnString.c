//
//  ICCheckBoolReturnString.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//
#include <stdio.h>

#include "ICRunApplicationFunction.h"

char *ICCheckBoolReturnString(bool value) {
    char *result = NULL;
    if(value) {
        result = "true";
    } else {
        result = "false";
    }
    
    return result;
}
