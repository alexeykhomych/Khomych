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
#include "AKIHumanSet.h"
#include "AKIHumanGet.h"

extern
void AKIHumanRelease(AKIHuman *object);

extern
void AKIHumanRetain(AKIHuman *object);

extern
void __AKIHumanDeallocate(AKIHuman *object);

extern
void AKIHumanRemoveAllChildren(AKIHuman *object);

extern
void AKIHumanRemoveFromParent(AKIHuman *object);

extern
void AKIHumanRemoveChild(AKIHuman *object);

void AKICreateHuman() {
    AKIHuman *object = calloc(1, sizeof(AKIHuman));
    assert(NULL != object);
}

void AKIHumanRemoveChild(AKIHuman *object) {
    if(NULL == object) {
        return;
    }
    
//    __AKIHumanDeallocate(object); //xz
}

void AKIHumanRemoveAllChildren(AKIHuman *object) {
    if(NULL == object) {
        return;
    }
    
    for (uint8_t i = 0; i < object->_childrenCount; i++) {
        AKIHumanRemoveChild(object->_children[kchildrenCount - i - 1]);
    }
}

void AKIHumanDivorcePartners(AKIHuman *object) {
    if(NULL == object || AKIGenderMale != AKIHumanGetGender(object)) {
        return;
    }
    
    AKIHumanRelease(object->_partner);
    object->_partner = NULL;
}

void AKIHumanRelease(AKIHuman *object) {
    if (object) {
        object->_hardReferenceCount -= 1;
        
        if (0 == object->_hardReferenceCount) {
            __AKIHumanDeallocate(object);
        }
    }
}

void AKIHumanRetain(AKIHuman *object) {
    if (object) {
        object->_hardReferenceCount += 1;
    }
}

void __AKIHumanDeallocate(AKIHuman *object) {
    AKIHumanRemoveAllChildren(object);
//    AKIHumanRemoveFromParent(object);
    AKIHumanDivorcePartners(object);
    AKIHumanSetName(object, NULL);
    free(object);
}
