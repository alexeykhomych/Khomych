//
//  ICCheckBoolReturnString.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//
#include <stdio.h>

#include "ICRunApplication.h"

char *ICStringWithBool(bool value) {
    if(value) {
        return "true";
    } else {
        return "false";
    }
}
