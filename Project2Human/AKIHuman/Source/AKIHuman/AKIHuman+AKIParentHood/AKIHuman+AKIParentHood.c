//
//  AKIHuman+AKIParentHood.c
//  AKIHuman
//
//  Created by Alexey Khomych on 27.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIHuman.h"
#include "AKIHuman+AKIParentHood.h"

static const uint8_t _kAKIMaximum = UINT8_MAX;

#pragma mark -
#pragma Private Declarations

static
uint8_t AKIHumanGetChildAtIndex(AKIHuman *parent, AKIHuman *child);

static
void AKIHumanChangeChildrenValue(AKIHuman *object, int value);

static
void AKIHumanSetChildAtIndex(AKIHuman *parent, AKIHuman *child, uint8_t index);

static
uint8_t AKIHumanGetChildrenCount(AKIHuman *object);

#pragma mark -
#pragma Public Implementations

void AKIHumanGiveBirthChild(AKIHuman *object, AKIHuman *child) {
}

void AKIHumanRemoveChild(AKIHuman *object, AKIHuman *child) {

}

void AKIHumanRemoveAllChildren(AKIHuman *parent) {

}

void AKIHumanSetParent(AKIHuman *object, AKIHuman *parent) {
    if (object) {
        if (parent && kAKIChildrenCount > AKIHumanGetChildrenCount(parent)) {
            if (!parent) {
                object->_father = NULL;
            } else if (AKIGenderMale == AKIHumanGetGender(parent)) {
                object->_father = parent;
            } else {
                object->_mother = parent;
            }
            
            AKIHumanGiveBirthChild(parent, object);
        }
    }
}

AKIHuman *AKIHumanGetFather(AKIHuman *object) {
    return object ? object->_father : NULL;
}

AKIHuman *AKIHumanGetMother(AKIHuman *object) {
    return object ? object->_mother : NULL;
}

#pragma mark -
#pragma Private Implementations

uint8_t AKIHumanGetChildrenCount(AKIHuman *object) {
    return object ? object->_childrenCount : 0;
}

uint8_t AKIHumanGetChildAtIndex(AKIHuman *parent, AKIHuman *child) {
    if (parent && child) {
        for (uint8_t i = 0; i < kAKIChildrenCount; i++) {
            if (parent->_children[i] == child) {
                return i;
            }
        }
    }
    
    return _kAKIMaximum;
}

void AKIHumanChangeChildrenValue(AKIHuman *object, int value) {
    object->_childrenCount += value;
}

void AKIHumanSetChildAtIndex(AKIHuman *parent, AKIHuman *child, uint8_t index) {
    if (parent) {
        parent->_children[index] = child;
    }
}
