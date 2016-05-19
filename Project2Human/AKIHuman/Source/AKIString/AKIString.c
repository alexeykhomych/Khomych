				//
//  AKIString.c
//  AKIHuman
//
//  Created by Alexey Khomych on 15.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AKIString.h"

static const size_t AKINotFound = SIZE_MAX;

void __AKIStringDeallocate(void *object) {
    AKIStringSetValue(object, NULL);
    
    __AKIObjectDeallocate(object);
}

AKIString *AKIStringCreate(char *object) {
    return AKIObjectCreateOfType(AKIString);
}

void AKIStringSetValue(AKIString *object, char *value) {
    if (object) {
        if (value != object->_value) {
            if (object->_value) {
                free(object->_value);
                object->_value = NULL;
            }
        }
        
        if (value) {
            size_t length = AKIStringGetLength(value) + 1;
            object->_value = malloc(length);
            memmove(object->_value, value, length);
        }
    }
}

size_t AKIStringGetLength(char *object) {
    return object ? strlen(object) : AKINotFound;
}

AKIString *AKIStringCopy(char *value) {
    AKIString *copy = AKIObjectCreateOfType(AKIString);
    AKIStringSetValue(copy, value);
    
    return copy;
}
