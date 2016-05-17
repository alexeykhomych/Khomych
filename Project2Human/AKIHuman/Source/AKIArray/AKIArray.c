//
//  AKIArray.c
//  AKIHuman
//
//  Created by Alexey Khomych on 16.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include "AKIArray.h"

#pragma mark -
#pragma Private Declarations

static const uint64_t AKINotFound = UINT64_MAX;

static
void AKIArraySetCapacity(AKIArray *array, uint64_t capacity);

static
void AKIArraySetData(AKIArray *array, void **data);

static
bool AKIArrayShouldResize(AKIArray *array);

static
void AKIArrayResize(AKIArray *array, uint64_t count);

void __AKIArrayDeallocate(void *array) {
    AKIArrayRemoveAllObjects(array);
    __AKIObjectDeallocate(array);
}

AKIArray *AKIArrayCreateWithCapacity(uint64_t capacity) {
    return AKIObjectCreateOfType(AKIArray);
}

#pragma mark -
#pragma Public Implementations

void AKIArrayAddObject(AKIArray *array, void *object) {
    if (array && object) {
        uint64_t count = AKIArrayGetCount(array) + 1;
        
        if (AKIArrayShouldResize(array)) {
            AKIArrayResize(array, count);
        }
        
        AKIArraySetCount(array, count + 1);
        AKIArraySetObjectAtIndex(array, object, count);
    }
}
uint64_t AKIArrayGetCount(AKIArray *array) {
    return array ? array->_count : AKINotFound;
}
bool AKIArrayContainsObject(AKIArray *array, void *object) {
    return array && (AKIArrayGetIndexOfObject(array, object) != AKINotFound);
}

uint64_t AKIArrayGetIndexOfObject(AKIArray *array, void *object) {
    uint64_t result = 0;
    
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

AKIArray *AKIArrayGetObjectAtIndex(AKIArray *array, uint64_t index) {
    return array ? array->_data[index] : NULL;
}

void AKIArrayRemoveObjectAtIndex(AKIArray *array, uint64_t index) {
    if (array) {
        AKIArraySetObjectAtIndex(array, NULL, index);
        
        // тут должен быть memmove, но нет
        
        AKIArraySetCount(array, AKIArrayGetCount(array) - 1);
    }
}

void AKIArrayRemoveAllObjects(AKIArray *array) {
    if (array) {
        uint64_t count = AKIArrayGetCount(array);
        
        for (uint64_t i = 0; i < count; i++) {
            if (AKIArrayGetObjectAtIndex(array, i) != NULL) {
                AKIArrayRemoveObjectAtIndex(array, i);
            }
        }
        
        AKIArraySetCapacity(array, 0);
    }
}

void AKIArraySetCount(AKIArray *array, uint64_t count) {
    if (array) {
        array->_count = count;
    }
}

void AKIArraySetObjectAtIndex(AKIArray *array, void *object ,uint64_t index) {
    if (array) {
        AKIArray *result = AKIArrayGetObjectAtIndex(array, index);
        
        if (!result) {
            array->_data[index] = object;
        }
    }
}

#pragma mark -
#pragma Private Implementations

void AKIArraySetCapacity(AKIArray *array, uint64_t capacity) {
    if (array) {
        array->_capacity = capacity;
    }
}

bool AKIArrayShouldResize(AKIArray *array) {
    return false;
}

void AKIArrayResize(AKIArray *array, uint64_t count) {
    
}
