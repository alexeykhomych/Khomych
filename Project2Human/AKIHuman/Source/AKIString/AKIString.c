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
#include "AKIConstants.h"

#pragma mark -
#pragma Private Declarations

static
void AKIStringSetValue(AKIString *string, char *value);

#pragma mark -
#pragma Public Implementations

void __AKIStringDeallocate(void *object) {
    AKIStringSetValue(object, NULL);
    
    __AKIObjectDeallocate(object);
}

AKIString *AKIStringCreate(char *value) {
    AKIString *object = AKIObjectCreateOfType(AKIString);
    AKIStringSetValue(object, value);
    
    return object;
}

AKIString *AKIStringCopy(AKIString *string) {
    AKIString *copy = AKIObjectCreateOfType(AKIString);
    AKIStringSetValue(copy, AKIStringGetValue(string));
    
    return copy;
}

size_t AKIStringGetLength(AKIString *string) {
    return string ? strlen(string->_value) : kAKINotFound;
}

char *AKIStringGetValue(AKIString *string) {
    return string ? string->_value : NULL;
}

#pragma mark -
#pragma mark Private Implementations

void AKIStringSetValue(AKIString *string, char *value) {
    if (string) {
        if (string->_value != value) {
            if (string->_value) {
                free(string->_value);
                string->_value = NULL;
            }
        }
        
        if (value) {
            size_t countBytes = strlen(value);
            string->_value = malloc(countBytes);
            memmove(string->_value, value, countBytes);
        }
    }
}

void AKIStringPrintObject(AKIString *string) {
    if (string) {
        printf("%s\n", string->_value);
    }
}
