//
//  AKIHuman+AKIParentHood.c
//  AKIHuman
//
//  Created by Alexey Khomych on 27.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIHuman.h"
#include "AKIHuman+AKIParentHood.h"

#pragma mark -
#pragma Private Declarations

static
uint8_t AKIHumanGetChildAtIndex(AKIHuman *parent, AKIHuman *child);

static
void AKIHumanAddValueToChildrenCount(AKIHuman *object, int value);

static
void AKIHumanSetChildAtIndex(AKIHuman *parent, AKIHuman *child, uint8_t index);

static
uint8_t AKIHumanGetChildrenCount(AKIHuman *object);

static
uint8_t AKIHumanGetFreeIndexInChildrenArray(AKIHuman *parent);

static
void AKIHumanSetParentAtIvar(AKIHuman *child, AKIHuman **ivar, AKIHuman *parent);

#pragma mark -
#pragma Public Implementations

AKIHuman *AKIHumanGiveBirthToChild(AKIHuman *parent1, AKIHuman *parent2) {
    AKIHuman *child = NULL;
    
    if (kAKIChildrenCount > AKIHumanGetChildrenCount(parent1)
        && kAKIChildrenCount > AKIHumanGetChildrenCount(parent2))
    {
        child = AKICreateHuman();
        AKIHumanSetParent(child, parent1, AKIHumanGetGender(parent1));
        AKIHumanSetParent(child, parent2, AKIHumanGetGender(parent2));
        
        AKIObjectRelease(child);
    }
    
    return child;
}

void AKIHumanRemoveChild(AKIHuman *parent, AKIHuman *child) {
    if (parent) {
        uint8_t childIndex = AKIHumanGetChildAtIndex(parent, child);
        AKIHumanSetParent(child, NULL, AKIHumanGetGender(parent));
        AKIHumanSetChildAtIndex(parent, NULL, childIndex);
        AKIHumanAddValueToChildrenCount(parent, -1);
    }
}

void AKIHumanRemoveAllChildren(AKIHuman *parent) {
    if (parent) {
        for (uint8_t i = 0; i < kAKIChildrenCount; i++) {
            AKIHuman *deletedObject = parent->_children[i];
            
            if (deletedObject) {
                AKIHumanRemoveChild(parent, deletedObject);
            }
        }
    }
}

void AKIHumanSetParent(AKIHuman *child, AKIHuman *parent, AKIGender parentGender) {
    if (!child) {
        return;
    }
    
    AKIHuman **ivar = parentGender == AKIGenderMale ? &child->_father : &child->_mother;
    
    AKIHumanSetParentAtIvar(child, ivar, parent);
}

AKIHuman *AKIHumanGetFather(AKIHuman *object) {
    return object ? object->_father : NULL;
}

AKIHuman *AKIHumanGetMother(AKIHuman *object) {
    return object ? object->_mother : NULL;
}

#pragma mark -
#pragma Private Implementations

void AKIHumanSetParentAtIvar(AKIHuman *child, AKIHuman **ivar, AKIHuman *parent) {
    AKIHumanRemoveChild(*ivar, parent);
    *ivar = parent;
    
    if (AKIHumanGetChildrenCount(parent) < kAKIChildrenCount) {
        AKIHumanSetChildAtIndex(parent, child, AKIHumanGetFreeIndexInChildrenArray(parent));
        AKIHumanAddValueToChildrenCount(parent, 1);
    }
}

uint8_t AKIHumanGetFreeIndexInChildrenArray(AKIHuman *parent) {
    if (parent) {
        for (uint8_t i = 0; i < kAKIChildrenCount; i++) {
            if (!parent->_children[i]) {
                return i;
            }
        }
    }
    
    return kAKINotFound;
}

uint8_t AKIHumanGetChildrenCount(AKIHuman *object) {
    return object ? object->_childrenCount : kAKINotFound;
}

uint8_t AKIHumanGetChildAtIndex(AKIHuman *parent, AKIHuman *child) {
    if (parent && child) {
        for (uint8_t i = 0; i < kAKIChildrenCount; i++) {
            if (parent->_children[i] == child) {
                return i;
            }
        }
    }
    
    return kAKINotFound;
}

void AKIHumanAddValueToChildrenCount(AKIHuman *object, int value) {
    object->_childrenCount += value;
}

void AKIHumanSetChildAtIndex(AKIHuman *parent, AKIHuman *child, uint8_t index) {
    if (parent) {
        AKIObjectRetain(child);
        AKIObjectRelease(parent->_children[index]);
        
        parent->_children[index] = child;
    }
}
