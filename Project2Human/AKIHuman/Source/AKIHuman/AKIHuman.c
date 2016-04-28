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

AKIHuman AKICreateHuman() {
    AKIHuman *object = calloc(1, sizeof(AKIHuman));
    assert(NULL != object);
    
    return *object;
}

void AKIHumanSetName(AKIHuman *object, const char *name) {
    if (object) {
        if(!name) {
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
    return NULL == object ? NULL : object->_age;
}

void AKIHumanSetGender(AKIHuman *object, AKIGender gender) {
    if(NULL == object) {
        return;
    }
    
    if(gender != object->_gender) {
        object->_gender = gender;
    }
}

AKIGender AKIHumanGetGender(AKIHuman *object) {
    return NULL == object ? NULL : object->_gender;
}

void __AKIHumanDeallocate(AKIHuman *object) {
//    AKIHumanRemoveAllChildren(object);
    //    AKIHumanRemoveFromParent(object);
//        AKIHumanDivorcePartners(object);
//        AKIHumanSetName(object, NULL);
//        AKIHumanSetAge(object, NULL);
        
//        free(object); //don't work
    
//        printf("Object is deallocate\n");
}

void AKIHumanRelease(AKIHuman *object) {
    if (object) {
        object->_referenceCount -= 1;
        
        if (0 == object->_referenceCount) {
            __AKIHumanDeallocate(object);
        }
    }
}

void AKIHumanRetain(AKIHuman *object) {
    if (object) {
        object->_referenceCount += 1;
    }
}
