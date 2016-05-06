//
//  AKIHuman+AKIParentHood.c
//  AKIHuman
//
//  Created by Alexey Khomych on 27.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIHuman.h"
#include "AKIHuman+AKIParentHood.h"

static
void AKIHumanSetFather(AKIHuman *object, AKIHuman *father);

static
void AKIHumanSetMother(AKIHuman *object, AKIHuman *mother);

static
AKIHuman *AKIHumanGetFather(AKIHuman *object);

static
AKIHuman *AKIHumanGetMother(AKIHuman *object);

AKIHuman *AKIHumanGetParent(AKIHuman *child, AKIHuman *parent) {
    if (AKIHumanGetGender(parent) == AKIGenderMale) {
        //find child at children array current parent
        //GetChildrenAtIndex(child);
        return AKIHumanGetFather(child);
    } else {
        return AKIHumanGetMother(child);
    }
}

void AKIHumanSetParents(AKIHuman *child, AKIHuman *father, AKIHuman *mother) {
    if (child) {
        AKIHumanSetFather(child, father);
        AKIHumanSetMother(child, mother);
    }
}

void AKIHumanSetFather(AKIHuman *object, AKIHuman *father) {
    if (object) {
        if (AKIGenderMale == father->_gender) {
            if (kAKIChildrenCount > AKIHumanGetChildrenCount(father)) {
                object->_father = father;
                
                AKIHumanAddChild(father, object);
            }
        }
    }
}

void AKIHumanSetMother(AKIHuman *object, AKIHuman *mother) {
    if (object) {
        if (AKIGenderFemale == mother->_gender) {
            if (kAKIChildrenCount > AKIHumanGetChildrenCount(mother)) {
                object->_mother = mother;
                
                AKIHumanAddChild(mother, object);
            }
        }
    }
}

AKIHuman *AKIHumanGetFather(AKIHuman *object) {
    return object ? object->_father : NULL;
}

AKIHuman *AKIHumanGetMother(AKIHuman *object) {
    return object ? object->_mother : NULL;
}

uint8_t AKIHumanGetChildrenCount(AKIHuman *object) {
    return object ? object->_childrenCount : 0;
}

void AKIHumanAddChild(AKIHuman *object, AKIHuman *child) {
    for (uint8_t i = 0; i < kAKIChildrenCount; i++) {
        if (!object->_children[i]) {
            object->_children[i] = child;
            
            object->_childrenCount += 1;
            
            AKIObjectRetain(object);
            
            break;
        }
    }
}

void AKIHumanRemoveChild(AKIHuman *object, AKIHuman *child) {
    if(object && child) {
        for (uint8_t i = 0; i < object->_childrenCount; i++) {
            if(object->_children[i] == child) {
                AKIHumanSetParents(child, NULL, NULL);
                
                AKIObjectRelease(child);
                
                object->_children[i] = NULL;
                
                break;
            }
        }
    }
}