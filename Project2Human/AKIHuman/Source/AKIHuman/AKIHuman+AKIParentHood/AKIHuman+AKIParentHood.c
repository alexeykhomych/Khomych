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

static
uint8_t AKIHumanGetFreeIndexInChildrenArray(AKIHuman *parent);
#pragma mark -
#pragma Public Implementations

AKIHuman *AKIHumanGiveBirthChild(AKIHuman *parent1, AKIHuman *parent2) {
    if (kAKIChildrenCount > AKIHumanGetChildrenCount(parent1) &&
        kAKIChildrenCount > AKIHumanGetChildrenCount(parent2))
    {
        AKIHuman *child = AKICreateHuman();
        AKIHumanSetParent(child, parent1, AKIHumanGetGender(parent1));
        AKIHumanSetParent(child, parent2, AKIHumanGetGender(parent2));
        
        return child;
    } else {
        return NULL;
    }
}

void AKIHumanRemoveChild(AKIHuman *object, AKIHuman *child) {
    
}

void AKIHumanRemoveAllChildren(AKIHuman *parent) {

}

void AKIHumanSetParent(AKIHuman *child, AKIHuman *parent, AKIGender parentGender) {
    if (child) {
        if (parentGender == AKIGenderMale) {
            if (child->_father) {
                AKIHumanRemoveChild(child->_father, child);
            }
            
            AKIHumanSetChildAtIndex(parent, child, AKIHumanGetFreeIndexInChildrenArray(parent));
            AKIHumanChangeChildrenValue(parent, 1);
            
            //bred
            child->_father = parent;
        } else if (parentGender == AKIGenderMale) {
            if (child->_mother) {
                AKIHumanRemoveChild(child->_mother, child);
            }
            
            child->_mother = parent;
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

uint8_t AKIHumanGetFreeIndexInChildrenArray(AKIHuman *parent) {
    if (parent) {
        for (uint8_t i = 0; i < kAKIChildrenCount; i++) {
            if (!parent->_children[i]) {
                return i;
            }
        }
    }
    
    return _kAKIMaximum;
}

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
        
        if (child) {
            AKIObjectRetain(child);
        } else {
            AKIObjectRelease(child);
        }
    }
}
