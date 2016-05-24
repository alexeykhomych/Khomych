//
//  AKIObject.c
//  AKIHuman
//
//  Created by Alexey Khomych on 03.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "AKIObject.h"
#include "AKIConstants.h"

const uint64_t kAKINotFound = UINT64_MAX;

void __AKIObjectDeallocate(void *object) {
    if (object) {
        free(object);
    }
}

void *__AKIObjectCreate(size_t size, AKIObjectDeallocator deallocator) {
    assert(deallocator);
    
    AKIObject *object = calloc(1, size);
    assert(object);
    
    object->_referenceCount = 1;
    object->_deallocatorFunctionPointer = deallocator;
    
    return object;
}

void *AKIObjectRetain(void *object) {
    if (object) {
        ((AKIObject *)object)->_referenceCount++;
    }
    
    return object;
}

void AKIObjectRelease(void *object) {
    if (object) {
        AKIObject *releasedObject = object;
        releasedObject->_referenceCount -= 1;
        
        if (0 == releasedObject->_referenceCount) {
            AKIObjectDeallocator deallocator = releasedObject->_deallocatorFunctionPointer;
            deallocator(object);
        }
    }
}

uint64_t AKIObjectRetainCount(void *object) {
    return object ? ((AKIObject *)object)->_referenceCount : 0;
}