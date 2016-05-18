//
//  AKIArray.c
//  AKIHuman
//
//  Created by Alexey Khomych on 16.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

#include "AKIArray.h"

#pragma mark -
#pragma Private Declarations

static const uint64_t kAKINotFound = UINT64_MAX;

static
void AKIArraySetCapacity(AKIArray *array, uint64_t capacity);

static
void AKIArraySetData(AKIArray *array, void **data);

static
bool AKIArrayShouldResize(AKIArray *array);

static
uint64_t AKIArrayPreferedCapacity(AKIArray *array);

static
void AKIArrayResizeIfNeeded(AKIArray *array);

#pragma mark -
#pragma Public Implementations

void __AKIArrayDeallocate(void *array) {
    AKIArraySetData(array, NULL);
    AKIArrayRemoveAllObjects(array);
    __AKIObjectDeallocate(array);
}

AKIArray *AKIArrayCreateWithCapacity(uint64_t capacity) {
    AKIArray *array = NULL;
    if (!capacity) {
        capacity = 1;
    }
    
    array =  AKIObjectCreateOfType(AKIArray);
    AKIArraySetCapacity(array, capacity);

    return array;
}

void AKIArrayAddObject(AKIArray *array, void *object) {
    if (array && object) {
        uint64_t count = AKIArrayGetCount(array) + 1;
        
        AKIArraySetCount(array, count + 1);
        AKIArraySetObjectAtIndex(array, object, count);
    }
}
uint64_t AKIArrayGetCount(AKIArray *array) {
    return array ? array->_count : kAKINotFound;
}
bool AKIArrayContainsObject(AKIArray *array, void *object) {
    return array && (AKIArrayGetIndexOfObject(array, object) != kAKINotFound);
}

uint64_t AKIArrayGetIndexOfObject(AKIArray *array, void *object) {
    if (array) {
        uint64_t count = AKIArrayGetCount(array);
        
        for (uint64_t i = 0; i < count; i++) {
            if (AKIArrayGetObjectAtIndex(array, i) == object) {
                return i;
            }
        }
    }
    
    return 0;
}

AKIArray *AKIArrayGetObjectAtIndex(AKIArray *array, uint64_t index) {
    return array ? array->_data[index] : NULL;
}
#warning re-write
void AKIArrayRemoveObjectAtIndex(AKIArray *array, uint64_t index) {
    if (array) {
        AKIArraySetObjectAtIndex(array, NULL, index);
        uint64_t count = AKIArrayGetCount(array);
        
        if (index < count - 1) {
            uint64_t elementCount = count - (index + 1);
            void **data = array->_data;
            memmove(data[index], data[index+1], elementCount);
        }
        
        AKIArraySetCount(array, count - 1);
        AKIArraySetCapacity(array, AKIArrayGetCapacity(array) - 1);
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
    }
}

void AKIArraySetCount(AKIArray *array, uint64_t count) {
    if (array) {
        array->_count = count;
        AKIArrayResizeIfNeeded(array);
    }
}

void AKIArraySetObjectAtIndex(AKIArray *array, void *object ,uint64_t index) {
    if (array) {
        array->_data[index] = object;
    }
}

#pragma mark -
#pragma Private Implementations
#warning re-write
void AKIArraySetCapacity(AKIArray *array, uint64_t capacity) {
    if (array && array->_capacity != capacity) {
        size_t size = capacity * sizeof(*array->_data);
        
        if (size && array->_data) {
            free(array->_data);
            array->_data = NULL;
        } else {
            array->_data = realloc(array->_data, size);
        }
        
        if (capacity > array->_capacity && array->_data) {
            void *start = array->_data + array->_capacity;
            size_t bytes = (capacity - array->_capacity) * sizeof(*array->_data);
            
            memset(start, 0, bytes);
        }
        
        array->_capacity = capacity;
    }
}

bool AKIArrayShouldResize(AKIArray *array) {
    return array && (array->_capacity != AKIArrayPreferedCapacity(array));
}

void AKIArraySetData(AKIArray *array, void **data) {
    #warning empty
}

void AKIArrayResizeIfNeeded(AKIArray *array) {
    if (AKIArrayShouldResize(array)) {
        AKIArraySetCapacity(array, AKIArrayPreferedCapacity(array));
    }
}
#warning re-write
uint64_t AKIArrayPreferedCapacity(AKIArray *array) {
    if (array) {
        uint64_t count = AKIArrayGetCount(array);
        uint64_t capacity = AKIArrayGetCapacity(array);
        
        if (count == capacity) {
            return capacity;
        }
        
        return count < capacity ? count : 2 * count;
    }
    
    return 0;
}

uint64_t AKIArrayGetCapacity(AKIArray *array) {
    return array ? array->_capacity : 0;
}
