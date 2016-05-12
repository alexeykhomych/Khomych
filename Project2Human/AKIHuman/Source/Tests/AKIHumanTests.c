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
#pragma Private Implementations

void AKIObjectTest() {
    AKIHumanTest();
    AKIHumanPartnerTest();
    AKIHumanChildrenTest();
}

void AKIHumanTest() {
    printf("Test 1: create human start\n");
    
    AKIHuman *object = AKICreateHuman();
    
    AKIHumanSetGender(object, AKIGenderMale);
    assert(AKIHumanGetGender(object) == AKIGenderMale);
    
    AKIHumanSetName(object, "Alex");
    AKIHumanSetName(object, NULL);
    AKIHumanSetName(object, "Dmitriy");
    
    AKIHumanSetAge(object, 24);
    assert(AKIHumanGetAge(object) == 24);
    
    AKIObjectRelease(object);
    
    printf("Test 1 finish.\n");
}

void AKIHumanPartnerTest() {
    printf("Test 2: partner human start\n");
    
    AKIHuman *object = AKICreateHuman();
    AKIHuman *partner = AKICreateHuman();
    
    AKIHumanSetGender(partner, AKIGenderFemale);
    AKIHumanSetGender(object, AKIGenderMale);
    
    AKIHumanGetMarriedWithPartner(object, partner);
    
    AKIHumanDivorce(object);
    
    AKIObjectRelease(partner);
    AKIObjectRelease(object);
    
    printf("Test 2 finish.\n");
}

void AKIHumanChildrenTest() {
    printf("Test 3: child human start\n");
    
    AKIHuman *object = AKICreateHuman();
    AKIHuman *partner = AKICreateHuman();
    AKIHuman *child = AKICreateHuman();
    
    AKIHumanSetGender(object, AKIGenderMale);
    AKIHumanSetGender(partner, AKIGenderFemale);
    
    AKIHumanSetParent(child, object, AKIHumanGetGender(object));
    
    AKIHumanRemoveChild(object, child);
    
    AKIObjectRelease(partner);
    AKIObjectRelease(object);
    
    printf("Test 3 finish.\n");
}
