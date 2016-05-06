//
//  AKIHumanTests.c
//  AKIHuman
//
//  Created by Alexey Khomych on 25.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "AKIHumanTests.h"
#include "AKIHuman.h"
#include "AKIHuman+AKIMarriage.h"
#include "AKIHuman+AKIParentHood.h"
#include "AKIObject.h"

#pragma mark -
#pragma Private Declarations

static
void AKIHumanTest();

static
void AKIObjectTest();

static
void AKIHumanPartnerTest();

static
void AKIHumanChildrenTest();

#pragma mark -
#pragma Public Implementations

void AKIHumanTestRun() {
    AKIObjectTest();
    AKIHumanTest();
}

void AKIHumanTestPrintObject(AKIHuman *object) {
    printf("Object #1\nName: %s\n"
           "Age: %hhu\n"
           "Gendere: %u\n", AKIHumanGetName(object),
           AKIHumanGetAge(object),
           AKIHumanGetGender(object));
}

#pragma mark -
#pragma Private Declarations

void AKIObjectTest() {
    AKIHumanPartnerTest();
    AKIHumanChildrenTest();
}

void AKIHumanTest() {
    AKIHuman *object = AKICreateHuman();
    assert(NULL != object);
    assert(1 == AKIObjectRetainCount(object));
    
    AKIObjectRelease(object);
}

void AKIHumanPartnerTest() {
    AKIHuman *object = AKICreateHuman();
    AKIHuman *partner = AKICreateHuman();
    
    AKIHumanSetGender(partner, AKIGenderFemale);
    
    AKIHumanSetPartner(object, partner);
    AKIHumanSetMarriedWithPartner(object, partner);
    
    AKIHumanDivorce(partner);
    AKIHumanDivorce(object);
    
    AKIObjectRelease(partner);
    AKIObjectRelease(object);
}

void AKIHumanChildrenTest() {
    AKIHuman *object = AKICreateHuman();
    AKIHuman *partner = AKICreateHuman();
    AKIHuman *child = AKICreateHuman();
    
    AKIHumanSetGender(object, AKIGenderMale);
    AKIHumanSetGender(partner, AKIGenderFemale);
    
    AKIHumanSetParents(child, object, partner);
    
    AKIHumanRemoveChild(object, child);
    
    AKIObjectRelease(partner);
    AKIObjectRelease(object);
}
