//
//  AKIInitializeHuman.c
//  AKIHuman
//
//  Created by Alexey Khomych on 21.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "AKICreateHuman.h"

AKIHuman AKICreateHuman(AKIHuman *object) {
    object = malloc(sizeof(AKIHuman));
    assert(NULL != object);
    
    return *object;
}

void AKIHumanSetName(AKIHuman *object, const char *name) {
    if(NULL != object) {
        object->_name = NULL;
    }
    
    if(name) {
        object->_name = strdup(name);
    }
}

char *AKIHumanGetName(AKIHuman *object) {
    return NULL == object ? NULL : object->_name;
}

void AKIHumanSetAge(AKIHuman *object, uint8_t age) {
    if(NULL == object) {
        return;
    }
    
    object->_age = age;
}

uint8_t AKIHumanGetAge(AKIHuman *object) {
    return NULL == object ? NULL : object->_age;
}

void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner) {
    if(NULL != object && NULL != partner) {
        object->partner = partner;
        object->_isMarried = true;
        object->_referenceCount++;
        
//        partner->_referenceCount++;
    } else {
        return;
    }
}

AKIHuman AKIHumanGetPartner(AKIHuman *object) {
    return *(NULL == object ? NULL : object->partner);
}

void AKIHumanSetParents(AKIHuman *object, AKIHuman *parents) {
    if(NULL == parents || NULL == object) {
        return;
    }
    
    object->parents = parents;
    object->_referenceCount++;
    
//    parents->_referenceCount++; //not shure
}

void AKIHumanSetGender(AKIHuman *object, AKIGender gender) {
    if(NULL == object) {
        return;
    }
    
    object->_gender = gender;
}

AKIGender AKIHumanGetGender(AKIHuman *object) {
    return NULL == object ? NULL : object->_gender;
}

void AKIHumanSetChild(AKIHuman *partner1, AKIHuman *partner2, AKIHuman *child) {
    if(NULL == partner1 || NULL == partner2 || NULL == child) {
        return;
    }
    
    partner1->children[partner1->_childrenCount] = child;
    partner1->_childrenCount++;
    partner1->_referenceCount++;

    partner2->children[partner2->_childrenCount] = child;
    partner2->_childrenCount++;
    partner2->_referenceCount++;
}

AKIHuman *AKIHumanGetChild(AKIHuman *object) {
    return *(NULL == object ? NULL : object->children);
}

void AKIHumanDivorcePartners(AKIHuman *partner1, AKIHuman *partner2) {
    if(NULL == partner1 || NULL == partner2) {
        return;
    }
    
    partner1->partner = NULL;
    partner1->_isMarried = false;
    partner1->_referenceCount--;
    
    partner2->partner = NULL;
    partner2->_isMarried = false;
    partner2->_referenceCount--;
}
