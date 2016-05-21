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

#pragma mark -
#pragma Private Declarations

static
void AKIStringSetValue(AKIString *object, AKIString *name);

#pragma mark -
#pragma Public Implementations

void __AKIStringDeallocate(void *object) {
    AKIStringSetValue(object, NULL);
    
    __AKIObjectDeallocate(object);
}

AKIString *AKIStringCreate() {
    return AKIObjectCreateOfType(AKIString);
}

void AKIStringSetValue(AKIString *object, AKIString *string) {
    if (object) {
        if (string->_value != object->_value) {
            if (object->_value) {
                free(object->_value);
                object->_value = NULL;
            }
        }
        
        if (string->_value) {
            size_t countBytes = AKIStringGetLength(string);
            object->_value = malloc(countBytes);
            memmove(object->_value, string->_value, countBytes);
        }
    }
}

size_t AKIStringGetLength(AKIString *string) {
    return string ? strlen(string->_value) : AKINotFound;
}

AKIString *AKIStringCopy(AKIString *string) {
    AKIString *copy = AKIObjectCreateOfType(AKIString);
    AKIStringSetValue(copy, AKIStringGetValue(string));
}

AKIString *AKIStringGetValue(AKIString *object) {
    return object ? object : NULL;
}