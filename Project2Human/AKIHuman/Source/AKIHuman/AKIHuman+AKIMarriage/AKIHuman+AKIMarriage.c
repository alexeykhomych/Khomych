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

void AKIHumanSetPartner(AKIHuman *object, AKIHuman *partner){
    if (NULL == object || NULL == partner) {
        return;
    }
    
    if (NULL != object->_partner) {
        AKIHumanDivorcePartners(object);
    }
    
    if (AKIHumanCanMarry(object, partner)) {
        object->_partner = partner;
        partner->_partner = object;
        
        AKIHumanRetain(object);
        AKIHumanRetain(partner);
        
        printf("Congratulations %s and %s, you are married!\n", object->_name, object->_partner->_name);
    }
}

AKIHuman AKIHumanGetPartner(AKIHuman *object) {
    if (NULL == object->_partner) {
        return *object; // BAD
    }
    
    return *object->_partner;
}

bool AKIHumanCanMarry(AKIHuman *object, AKIHuman *partner) {
    return object->_gender != partner->_gender;
}

void AKIHumanDivorcePartners(AKIHuman *object) {
    if (NULL == object || AKIGenderMale != AKIHumanGetGender(object)) {
        return;
    }
    
    AKIHumanSetPartner(object, NULL);
//    AKIHumanSetPartner(object->_partner, NULL); // ???
    
    AKIHumanRelease(object);
    
    printf("Congratulations %s, you are divorced!\n", object->_name);
}
