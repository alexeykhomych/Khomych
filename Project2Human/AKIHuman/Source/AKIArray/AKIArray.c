//
//  AKIArray.c
//  AKIHuman
//
//  Created by Alexey Khomych on 16.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AKIArray.h"
#include "AKIConstants.h"

#pragma mark -
#pragma Private Declarations

static
void AKIArraySetCapacity(AKIArray *array, uint64_t capacity);

static
bool AKIArrayShouldResize(AKIArray *array);

static
uint64_t AKIArrayPreferedCapacity(AKIArray *array);

static
void AKIArrayResizeIfNeeded(AKIArray *array);

static
void AKIArraySetCount(AKIArray *array, uint64_t count);

static
void AKIArrayShiftFromIndex(AKIArray *array, uint64_t index, uint64_t count);


#pragma mark -
#pragma Public Implementations

void __AKIArrayDeallocate(void *array) {
    AKIArrayRemoveAllObjects(array);
    AKIArraySetCapacity(array, 0);
    
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
        uint64_t count = AKIArrayGetCount(array);
        
        AKIArraySetObjectAtIndex(array, object, count);
        AKIArraySetCount(array, count + 1);
    }
}

uint64_t AKIArrayGetCount(AKIArray *array) {
    return array ? array->_count : kAKINotFound;
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
    
    return kAKINotFound;
}

void *AKIArrayGetObjectAtIndex(AKIArray *array, uint64_t index) {
    return array ? array->_data[index] : NULL;
}

void AKIArrayRemoveObjectAtIndex(AKIArray *array, uint64_t index) {
    if (array) {
        AKIArraySetObjectAtIndex(array, NULL, index);
        uint64_t count = AKIArrayGetCount(array);
        
        AKIArrayShiftFromIndex(array, index, count);
        
        AKIArraySetCount(array, count - 1);
    }
}

void AKIArrayRemoveAllObjects(AKIArray *array) {
    if (array) {
        uint64_t count = AKIArrayGetCount(array);
        
        for (uint64_t i = 0; i < count; i++) {
            uint64_t indexObject = count - i - 1;
            
            if (AKIArrayGetObjectAtIndex(array, indexObject)) {
                AKIArrayRemoveObjectAtIndex(array, indexObject);
            }
        }
    }
}

void AKIArraySetObjectAtIndex(AKIArray *array, void *object, uint64_t index) {
    if (array && AKIArrayGetObjectAtIndex(array, index) != object) {
        AKIObjectRelease(array->_data[index]);
        array->_data[index] = object;
        AKIObjectRetain(array->_data[index]);
    }
}

bool AKIArrayContainsObject(AKIArray *array, void *object) {
    return array && AKIArrayGetIndexOfObject(array, object) != kAKINotFound;
}

#pragma mark -
#pragma Private Implementations

void AKIArraySetCapacity(AKIArray *array, uint64_t capacity) {
    if (array && array->_capacity != capacity && kAKIArrayMaximumCapacity >= capacity) {
        size_t sizeOfData = sizeof(*array->_data);
        size_t size = capacity * sizeOfData;
        
        if (0 == size && array->_data) {
            free(array->_data);
            array->_data = NULL;
        } else {
            array->_data = realloc(array->_data, size);
            
            if (capacity > array->_capacity && array->_data) {
                void *start = array->_data + array->_capacity;
                size_t bytes = (capacity - array->_capacity) * sizeOfData;
                
                memset(start, 0, bytes);
            }
        }
        
        array->_capacity = capacity;
    }
}

bool AKIArrayShouldResize(AKIArray *array) {
    return array && AKIArrayGetCapacity(array) != AKIArrayPreferedCapacity(array);
}

void AKIArrayResizeIfNeeded(AKIArray *array) {
    if (AKIArrayShouldResize(array)) {
        AKIArraySetCapacity(array, AKIArrayPreferedCapacity(array));
    }
}

uint64_t AKIArrayPreferedCapacity(AKIArray *array) {
    if (!array) {
        return 0;
    }
    
    uint64_t count = AKIArrayGetCount(array);
    uint64_t capacity = AKIArrayGetCapacity(array);
        
    if (count < capacity / 4) {
        return capacity / 2;
    }
        
    if (count >= capacity) {
        return capacity * 2;
    }
    
    return capacity;
}

uint64_t AKIArrayGetCapacity(AKIArray *array) {
    return array ? array->_capacity : 0;
}

void AKIArraySetCount(AKIArray *array, uint64_t count) {
    if (array) {
        array->_count = count;
        AKIArrayResizeIfNeeded(array);
    }
}

void **AKIArrayGetData(AKIArray *array) {
    return array ? array->_data : NULL;
}

void AKIArrayShiftFromIndex(AKIArray *array, uint64_t index, uint64_t count) {
    if (array && index < count) {
        uint64_t elementCount = count - (index + 1);
        void **data = AKIArrayGetData(array);
        memmove(&data[index], &data[index + 1], elementCount * sizeof(data));
    }
}
