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
    AKIHumanDivorce(object);
    AKIHumanSetName(object, NULL);
    
    AKIHuman *mother = AKIHumanGetMother(object);
    AKIHuman *father = AKIHumanGetFather(object);
    
    AKIHumanSetParent(object, NULL, AKIHumanGetGender(mother));
    AKIHumanSetParent(object, NULL, AKIHumanGetGender(father));
    
    AKIHumanRemoveAllChildren(object);
    
    __AKIObjectDeallocate(object);
}

AKIHuman *AKICreateHuman() {
    return AKIObjectCreateOfType(AKIHuman);
}

void AKIHumanSetName(AKIHuman *human, AKIString *name) {
    if (human && name != &human->_name) {
        AKIObjectRelease(&human->_name);
        human->_name = *name;
        AKIObjectRetain(&human->_name);
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
