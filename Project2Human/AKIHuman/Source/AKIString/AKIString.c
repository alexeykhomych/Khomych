				//
//  AKIString.c
//  AKIHuman
//
//  Created by Alexey Khomych on 15.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

#include "AKIString.h"

static
void AKIStringSetName(void *object, const char *name);

static
char *AKIStringGetName(void *object);

void __AKIStringDeallocate(void *object) {
    __AKIObjectDeallocate(object);
}

AKIString *AKIStringCreate(char *object) {
    return AKIObjectCreateOfType(AKIString);
}

void AKIStringSetName(void *object, const char *name) {
    AKIString *stringObject = object;
    
    if (stringObject) {
        if (name != stringObject->_name) {
            if(stringObject->_name) {
                free(stringObject->_name);
                stringObject->_name = NULL;
            }
        }
        
        if (name) {
            stringObject->_name = strdup(name);
        }
    }
}

char *AKIStringGetName(void *object) {
    return NULL == object ? NULL : ((AKIString *) object)->_name;
}
