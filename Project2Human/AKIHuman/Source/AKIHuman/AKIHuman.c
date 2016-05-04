//
//  AKIHuman.c
//  AKIHuman
//
//  Created by Alexey Khomych on 21.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "AKIHuman.h"
#include "AKIHuman+AKIMarriage.h"
#include "AKIHuman+AKIParentHood.h"

AKIHuman *AKICreateHuman() {
    AKIHuman *object = AKIObjectCreateOfType(AKIHuman);
    
    return object;
}

void AKIHumanSetName(AKIHuman *object, const char *name) {
    if (object) {
        if (!name) {
            object->_name = NULL;
        }
        if (name != object->_name) {
            free(object->_name);
            object->_name = strdup(name);
        }
    }
}

char *AKIHumanGetName(AKIHuman *object) {
    return NULL == object ? NULL : object->_name;
}

void AKIHumanSetAge(AKIHuman *object, uint8_t age) {
    if (NULL == object) {
        return;
    }
    
    object->_age = age;
}

uint8_t AKIHumanGetAge(AKIHuman *object) {
    return object ? object->_age : 0;
}

void AKIHumanSetGender(AKIHuman *object, AKIGender gender) {
    if (NULL == object) {
        return;
    }
    
    if (gender != object->_gender) {
        object->_gender = gender;
    }
}

AKIGender AKIHumanGetGender(AKIHuman *object) {
    return object ? object->_gender : 1;
}

void __AKIHumanDeallocate(void *object) {
    if (NULL != object) {
        AKIHumanSetPartner(object, NULL);
        AKIHumanSetName(object, NULL);
        
        __AKIObjectDeallocate(object);
    }
}

void AKIHumanRelease(AKIHuman *object) {
    if (object) {
        AKIObjectRelease(object);
    }
}

void AKIHumanRetain(AKIHuman *object) {
    if (object) {
        AKIObjectRetain(object);
    }
}
