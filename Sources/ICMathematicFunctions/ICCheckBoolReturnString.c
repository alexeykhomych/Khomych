//
//  ICCheckBoolReturnString.c
//  Homework_lesson1
//
//  Created by Admin on 08.04.16.
//
//

#include "ICCheckBoolReturnString.h"

char *ICCheckBoolReturnString(bool value) {
    char *returnValue = "";
    if(1 == value) {
        returnValue = "true";
    }
    else {
        returnValue = "false";
    }
    return returnValue;
}
