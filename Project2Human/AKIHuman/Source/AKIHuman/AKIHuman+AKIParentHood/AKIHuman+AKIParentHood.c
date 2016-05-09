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
void AKIHumanSetFather(AKIHuman *object, AKIHuman *father);

static
void AKIHumanSetMother(AKIHuman *object, AKIHuman *mother);

static
AKIHuman *AKIHumanGetFather(AKIHuman *object);

static
AKIHuman *AKIHumanGetMother(AKIHuman *object);

static
uint8_t AKIHumanGetChildAtIndex(AKIHuman *parent, AKIHuman *child);

static
void AKIHumanSetChildrenCount(AKIHuman *object, int value);

static
void AKIHumanSetChildAtIndex(AKIHuman *parent, AKIHuman *child, uint8_t index);

static
uint8_t AKIHumanGetChildrenCount(AKIHuman *object);

#pragma mark -
#pragma Public Implementations

AKIHuman *AKIHumanGetParent(AKIHuman *child, AKIGender parentGender) {
    if (parentGender == AKIGenderMale) {
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

void AKIHumanAddChild(AKIHuman *object, AKIHuman *child) {
    for (uint8_t i = 0; i < kAKIChildrenCount; i++) {
        if (!object->_children[i]) {
            AKIHumanSetChildAtIndex(object, child, i);
            
            break;
        }
    }
}

void AKIHumanRemoveChild(AKIHuman *object, AKIHuman *child) {
    if (object && child) {
        AKIHumanSetParents(child, NULL, NULL);
        
        AKIObjectRelease(child);
        
        object->_children[AKIHumanGetChildAtIndex(object, child)] = NULL;
        AKIHumanSetChildrenCount(object, -1);
        
        AKIObjectRelease(object);
    }
}

#pragma mark -
#pragma Private Implementations

void AKIHumanSetFather(AKIHuman *object, AKIHuman *father) {
    if (object) {
        if (father && AKIGenderMale == AKIHumanGetGender(father)) {
            if (kAKIChildrenCount > AKIHumanGetChildrenCount(father)) {
                object->_father = father;
                
                AKIHumanAddChild(father, object);
            }
        } else if (!father) {
            object->_father = NULL;
        }
    }
}

void AKIHumanSetMother(AKIHuman *object, AKIHuman *mother) {
    if (object) {
        if (mother && AKIGenderFemale == AKIHumanGetGender(mother)) {
            if (kAKIChildrenCount > AKIHumanGetChildrenCount(mother)) {
                object->_mother = mother;
                
                AKIHumanAddChild(mother, object);
            }
        } else if (!mother) {
            object->_mother = NULL;
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

uint8_t AKIHumanGetChildAtIndex(AKIHuman *parent, AKIHuman *child) {
    if (parent && child) {
        for (uint8_t i = 0; i < parent->_childrenCount; i++) {
            if (parent->_children[i] == child) {
                return i;
            }
        }
    }
    
    return 0;
}

void AKIHumanSetChildrenCount(AKIHuman *object, int value) {
    object->_childrenCount += value;
}

void AKIHumanSetChildAtIndex(AKIHuman *parent, AKIHuman *child, uint8_t index) {
    if (parent && child) {
        parent->_children[index] = child;
        AKIHumanSetChildrenCount(parent, 1);
        AKIObjectRetain(parent);
    }
}
