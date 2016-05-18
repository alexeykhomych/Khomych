//
//  AKIArrayTest.c
//  AKIHuman
//
//  Created by Alexey Khomych on 17.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIArrayTest.h"
#include "AKIArray.h"
#include "AKIHuman.h"

void AKICreateArrayTest() {
    AKIArray *array = AKIArrayCreateWithCapacity(10);
    
    AKIArraySetCount(array, 10);
    
    for (uint64_t i = 0; i < 10; i++) {
        AKIArraySetObjectAtIndex(array, AKICreateHuman(), i);
    }
    
    for (uint64_t i = 0; i < 10; i++) {
        AKIArrayRemoveObjectAtIndex(array, i);
    }
}