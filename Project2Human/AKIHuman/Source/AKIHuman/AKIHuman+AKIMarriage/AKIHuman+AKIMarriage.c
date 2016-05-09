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

#pragma mark -
#pragma Private Declarations

static
void AKIHumanSetStrongPartner(AKIHuman *object, AKIHuman *spouse);

static
void AKIHumanSetWeakPartner(AKIHuman *object, AKIHuman *partner);

static
void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner);

static
bool AKIHumanCanMarry(AKIHuman *object, AKIHuman *partner);

#pragma mark -
#pragma Public Implementations

AKIHuman *AKIHumanGetPartner(AKIHuman *object) {
    return object ? object->_partner : NULL;
}

void AKIHumanGetMarriedWithPartner(AKIHuman *object, AKIHuman *partner) {
    if (object && partner && AKIHumanCanMarry(object, partner)) {
        if (AKIHumanGetPartner(partner)) {
            AKIHumanDivorce(partner);
        }
        if (AKIHumanGetPartner(object)) {
            AKIHumanDivorce(object);
        }
        AKIHumanSetPartner(object, partner);
        AKIHumanSetPartner(partner, object);
    }
}

void AKIHumanDivorce(AKIHuman *object) {
    if (object) {
        AKIHumanSetPartner(AKIHumanGetPartner(object), NULL);
        AKIHumanSetPartner(object, NULL);
        
        AKIObjectRelease(object);
    }
}

#pragma mark -
#pragma Private Implementations

void AKIHumanSetStrongPartner(AKIHuman *object, AKIHuman *partner) {
    if (AKIHumanGetPartner(object) != partner) {
        AKIObjectRelease(object->_partner);
        object->_partner = partner;
        AKIObjectRetain(partner);
    }
}

void AKIHumanSetWeakPartner(AKIHuman *object, AKIHuman *partner) {
    object->_partner = partner;
}

void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner){
    if (object && partner && AKIHumanCanMarry(object, partner)) {
        if (AKIHumanGetGender(object) == AKIGenderMale) {
            AKIHumanSetStrongPartner(object, partner);
        } else {
            AKIHumanSetWeakPartner(object, partner);
        }
    }
}

bool AKIHumanCanMarry(AKIHuman *object, AKIHuman *partner) {
    return AKIHumanGetGender(object) != AKIHumanGetGender(partner);
}
