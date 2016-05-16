//
//  AKIArray.c
//  AKIHuman
//
//  Created by Alexey Khomych on 16.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIArray.h"

static const uint64_t AKINotFound = UINT64_MAX;

static
void AKIArraySetCapacity(AKIArray *array, uint64_t capacity);

static
void AKIArraySetData(AKIArray *array, void **data);

static
bool AKIArrayShouldResize(AKIArray *array);

void __AKIArrayDeallocate(void *object) {
    if (NULL != object) {
        
        __AKIObjectDeallocate(object);
    }
}

AKIArray *AKIArrayCreateWithCapacity(uint64_t capacity) {
    return AKIObjectCreateOfType(AKIArray);
}

void AKIArrayAddObject(AKIArray *array, void *object) {
    if (array) {
        uint64_t count = AKIArrayGetCount(array) + 1;
        AKIArraySetObjectAtIndex(array, object, count);
    }
}
uint64_t AKIArrayGetCount(AKIArray *array) {
    return array ? array->_count : AKINotFound;
}
bool AKIArrayContainsObject(AKIArray *array, void *object) {
    return array ? (AKIArrayGetIndexOfObject(array, object) != AKINotFound) : NULL;
}

uint64_t AKIArrayGetIndexOfObject(AKIArray *array, void *object) {
    uint64_t result = NULL;
    
    if (array) {
        uint64_t count = AKIArrayGetCount(array);
        
        for (uint64_t i = 0; i < count; i++) {
            if (AKIArrayGetObjectAtIndex(array, i) == object) {
                result = i;
                break;
            }
        }
    }
    
    return result;
}
void *AKIArrayGetObjectAtIndex(AKIArray *array, uint64_t index);
void AKIArrayRemoveObjectAtIndex(AKIArray *array, uint64_t index);
void AKIArrayRemoveAllObjects(AKIArray *array);
void AKIArraySetCount(AKIArray *array, uint64_t count);
void AKIArraySetObjectAtIndex(AKIArray *array, void *object ,uint64_t index);
