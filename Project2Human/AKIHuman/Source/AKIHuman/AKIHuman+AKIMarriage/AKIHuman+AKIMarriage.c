//
//  AKIHuman+AKIMarriage.c
//  AKIHuman
//
//  Created by Alexey Khomych on 27.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//
#include <stdio.h>
#include <string.h>

#include "AKIHuman.h"
#include "AKIHuman+AKIMarriage.h"

static
void AKIHumanSetStrongPartner(AKIHuman *object, AKIHuman *spouse);

static
void AKIHumanSetWeakPartner(AKIHuman *object, AKIHuman *spouse);

void AKIHumanSetStrongPartner(AKIHuman *object, AKIHuman *spouse) {
    AKIObjectRelease(object->_partner);
    object->_partner = spouse;
    AKIObjectRetain(spouse);
}

void AKIHumanSetWeakPartner(AKIHuman *object, AKIHuman *spouse) {
    object->_partner = spouse;
}

void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner){
    if (object) {
        if (AKIHumanGetGender(object) == AKIGenderMale) {
            if (object->_partner != partner) {
                AKIObjectRelease(object->_partner);
                
                object->_partner = partner;
                
                AKIObjectRetain(object->_partner);
            }
        } else {
            object->_partner = partner;
        }
    }
}

AKIHuman *AKIHumanGetPartner(AKIHuman *object) {
    return object ? object->_partner : NULL;
}

bool AKIHumanCanMarry(AKIHuman *object, AKIHuman *partner) {
    return object->_gender != partner->_gender;
}

void AKIHumanSetMarriedWithPartner(AKIHuman *object, AKIHuman *partner) {
    if (object && partner && AKIHumanCanMarry(object, partner)) {
        if (AKIHumanGetGender(object) == AKIGenderMale) {
            AKIHumanSetStrongPartner(object, partner);
        } else {
            AKIHumanSetWeakPartner(object, partner);
        }
    }
}

void AKIHumanDivorce(AKIHuman *object) {
    if (NULL == object || AKIGenderMale != AKIHumanGetGender(object)) {
        return;
    }

    AKIHumanSetPartner(object->_partner, NULL);
    AKIHumanSetPartner(object, NULL);
    
    AKIObjectRelease(object);
    
    printf("Congratulations %s, you are divorced!\n", object->_name);
}
