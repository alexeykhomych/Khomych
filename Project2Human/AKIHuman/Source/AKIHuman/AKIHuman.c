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

void __AKIHumanDeallocate(void *object) {
    if (NULL != object) {
        AKIHumanDivorce(object);
        AKIHumanSetName(object, NULL);
        
        __AKIObjectDeallocate(object);
    }
}

AKIHuman *AKICreateHuman() {
    return AKIObjectCreateOfType(AKIHuman);
}

void AKIHumanSetName(AKIHuman *human, char *string) {
    if (human) {
        if (string) {
            AKIObjectRetain(&human->_name);
        } else {
            AKIObjectRelease(&human->_name);
        }
        
        AKIStringSetValue(&human->_name, string);
    }
}

AKIString *AKIHumanGetName(AKIHuman *object) {
    return object ? &object->_name : NULL;
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
    if (object && gender != object->_gender) {
        object->_gender = gender;
    }   
}

AKIGender AKIHumanGetGender(AKIHuman *object) {
    return object ? object->_gender : AKIGenderUndefined;
}
