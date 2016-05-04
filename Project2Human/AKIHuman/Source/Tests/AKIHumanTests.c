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
    AKIObject *object = AKIObjectCreateOfType(AKIObject);
    AKIObjectRelease(object);
    
    AKIObjectRelease(object);
}

void AKIHumanTest() {
    AKIHuman *object = AKICreateHuman();
    assert(NULL != object);
    assert(1 == AKIObjectRetainCount(object));
    
    AKIObjectRelease(object);
}
