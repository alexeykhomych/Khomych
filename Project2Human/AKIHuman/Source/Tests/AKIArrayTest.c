//
//  AKIArrayTest.c
//  AKIHuman
//
//  Created by Alexey Khomych on 17.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <assert.h>

#include "AKIArrayTest.h"
#include "AKIArray.h"
#include "AKIHuman.h"

void AKICreateArrayTest() {
    AKIArray *array = AKIArrayCreateWithCapacity(10);
    AKIObject *object = AKIObjectCreateOfType(AKIObject);
    
    uint8_t count = 5;
    
    for (uint64_t i = 0; i < count; i++) {
        AKIArrayAddObject(array, object);
    }
    
    assert(5 == AKIArrayGetCount(array));
    
    for (uint64_t i = 0; i < count; i++) {
        assert(AKIArrayGetObjectAtIndex(array, i) == object);
    }
    
    AKIObject *object2 = AKIObjectCreateOfType(AKIObject);
    AKIArrayAddObject(array, object2);
    
    assert (6 == AKIArrayGetCount(array));
    
    for (uint64_t i = 0; i < count; i++) {
        assert(AKIArrayGetObjectAtIndex(array, i) == object);
    }
    
    assert(AKIArrayGetObjectAtIndex(array, count) == object2);
    
    AKIArrayRemoveObjectAtIndex(array, count - 2);
    
    assert(count == AKIArrayGetCount(array));
    
    for (uint64_t i = 0; i < count - 1; i++) {
        assert(AKIArrayGetObjectAtIndex(array, i) == object);
    }
    
    assert(AKIArrayGetObjectAtIndex(array, count - 1) == object2);
    
    AKIArrayRemoveAllObjects(array);
    assert(0 == AKIArrayGetCount(array));
    
    assert(!AKIArrayContainsObject(array, object));
    assert(!AKIArrayContainsObject(array, object2));
    
    AKIObjectRelease(object2);
    AKIObjectRelease(object);
    AKIObjectRelease(array);
}
