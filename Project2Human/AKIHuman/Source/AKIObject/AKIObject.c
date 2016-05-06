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

void AKIObjectRelease(void *address) {
    if (address) {
        AKIObject *object = address;
        object->_referenceCount -= 1;
        
        if (0 == object->_referenceCount) {
            AKIObjectDeallocator deallocator = object->_deallocatorFunctionPointer;
            deallocator(address);
        }
    }
}

void __AKIObjectDeallocate(void *object) {
    if (NULL != object) {
        free(object);
    }
}

uint64_t AKIObjectRetainCount(void *object) {
    return object ? ((AKIObject *)object)->_referenceCount : 0;
}