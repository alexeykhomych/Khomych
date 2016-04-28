//
//  AKIHumanTests.c
//  AKIHuman
//
//  Created by Alexey Khomych on 25.04.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "AKIHumanTests.h"
#include "AKIHuman.h"
#include "AKIHuman+AKIMarriage.h"
#include "AKIHuman+AKIParentHood.h"

static
void AKIHumanTestPrintObject(AKIHuman *object);

static
AKIHuman AKIHumanTestCreateMale();

static
AKIHuman AKIHumanTestCreateFemale();

void AKIHumanTestRun() {
    AKIHuman obj1 = AKIHumanTestCreateMale();
    AKIHuman obj2 = AKIHumanTestCreateFemale();
    
    
    AKIHumanSetPartner(&obj1, &obj2);
    AKIHumanDivorcePartners(&obj2); //false
    AKIHumanDivorcePartners(&obj1); //true
    
//    AKIHuman objTest = AKIHumanGetPartner(&obj1);
}

void AKIHumanTestPrintObject(AKIHuman *object) {
    printf("Object #1\nName: %s\n"
           "Age: %hhu\n"
           "Gendere: %u\n", AKIHumanGetName(object),
           AKIHumanGetAge(object),
           AKIHumanGetGender(object));
}

AKIHuman AKIHumanTestCreateMale() {
    AKIHuman object = AKICreateHuman();
    AKIHumanSetName(&object, "Vasya");
    AKIHumanSetAge(&object, 24);
    AKIHumanSetGender(&object, AKIGenderMale);
    
    AKIHumanTestPrintObject(&object);
    
    
//    __AKIHumanDeallocate(&object);
    
    return object;
}

AKIHuman AKIHumanTestCreateFemale() {
    AKIHuman object = AKICreateHuman();
    AKIHumanSetName(&object, "Katya");
    AKIHumanSetAge(&object, 22);
    AKIHumanSetGender(&object, AKIGenderFemale);
    
    AKIHumanTestPrintObject(&object);
    
    
//    __AKIHumanDeallocate(&object);
    
        return object;
}
