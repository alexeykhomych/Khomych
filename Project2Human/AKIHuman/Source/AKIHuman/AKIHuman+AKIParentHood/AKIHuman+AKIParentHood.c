//
//  AKIHuman+AKIParentHood.c
//  AKIHuman
//
//  Created by Alexey Khomych on 27.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIHuman.h"
#include "AKIHuman+AKIParentHood.h"

void AKIHumanSetParentFather(AKIHuman *object, AKIHuman *father) {
    if (object && father) {
        if(AKIGenderMale == father->_gender) {
            if (kAKIChildrenCount > AKIHumanGetChildrenCount(father)) {
                object->_father = father;
                
                father->_childrenCount += 1;
                
                AKIHumanAddChild(father, object);
            }
        }
    }
}

void AKIHumanSetParentMother(AKIHuman *object, AKIHuman *mother) {
    if (object && mother) {
        if(AKIGenderFemale == mother->_gender) {
            if (kAKIChildrenCount > AKIHumanGetChildrenCount(mother)) {
                object->_mother = mother;
                
                mother->_childrenCount += 1;
                
                AKIHumanAddChild(mother, object);
            }
        }
    }
}

AKIHuman *AKIHumanGetParentFather(AKIHuman *object) {
    return object ? object->_father : NULL;
}

AKIHuman *AKIHumanGetParentMother(AKIHuman *object) {
    return object ? object->_mother : NULL;
}

uint8_t AKIHumanGetChildrenCount(AKIHuman *object) {
    return object ? object->_childrenCount : NULL;
}

void AKIHumanAddChild(AKIHuman *object, AKIHuman *child) {
    for (uint8_t i = 0; i < kAKIChildrenCount; i++) {
        if (!object->_children[i]) {
            object->_children[i] = child;
            
            AKIHumanRetain(object);
            
            break;
        }
    }
}

void AKIHumanDeallocateChild(AKIHuman *object, AKIHuman *child) {
    if(object && child) {
        for (uint8_t i = 0; i < object->_childrenCount; i++) {
            if(object->_children[i] == child) {
                AKIHumanSetParentFather(NULL, child->_father);
                AKIHumanSetParentMother(NULL, child->_mother);
                __AKIHumanDeallocate(child);
                object->_children[i] = NULL;
                
                break;
            }
        }
    }
}