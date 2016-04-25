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
#include "AKICreateHuman.h"



void AKIHumanTestRun() {
    AKIHuman object = AKICreateHuman(&object);
    AKIHuman *object1 = &object;
    AKIHumanSetName(object1, "Alex");
    object1->_name = AKIHumanGetName(object1);
    
    AKIHumanSetAge(object1, 24);
    object1->_age = AKIHumanGetAge(object1);
}
