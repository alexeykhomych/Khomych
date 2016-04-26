//
//  AKIHumanSet.c
//  AKIHuman
//
//  Created by Alexey Khomych on 26.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "AKIHumanSet.h"

void AKIHumanSetName(AKIHuman *object, const char *name) {
    if (NULL != object) {
        object->_name = NULL;
    }
    
    if (name) {
        object->_name = strdup(name);
    }
}

void AKIHumanSetAge(AKIHuman *object, uint8_t age) {
    if (NULL == object || !age) {
        return;
    }
    
    object->_age = NULL;
    object->_age = age;
}

void AKIHumanSetGender(AKIHuman *object, AKIGender gender) {
    if(NULL == object) {
        return;
    }
    
    if(gender != object->_gender) {
        object->_gender = NULL;
        object->_gender = gender;
    }
}

void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner) {
    if(NULL == object || NULL == partner) {
        return;
    }
    
    if(NULL != object->_partner) {
        AKIHumanDivorcePartners(object);
    }
    
    AKIHumanRetain(object);
    object->_partner = NULL;
    object->_partner = partner;
}
