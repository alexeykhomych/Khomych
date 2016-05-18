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
            object->_value = strdup(value);
        }
        
        AKIStringSetLength(object, value ? strlen(value) : 0);
    }
}

void AKIStringSetLength(AKIString *object, size_t length) {
    if (object && length) {
        object->_length = length;
    }
}

size_t AKIStringGetLength(AKIString *object) {
    return object ? object->_length : AKINotFound;
}

char *AKIStringGetValue(AKIString *object) {
    return object ? object->_value : NULL;
}

void AKIStringCopyValue(AKIString *object, AKIString *copiedObject) {
    if (object) {
        memcpy(copiedObject->_value, object, object->_length);
    }
}
