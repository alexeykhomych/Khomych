//
//  AKIObject.h
//  AKIHuman
//
//  Created by Alexey Khomych on 03.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIObject_h
#define AKIObject_h

#include <stdio.h>

extern const uint64_t kAKINotFound;

typedef void (*AKIObjectDeallocator)(void *object);

typedef struct {
    uint64_t _referenceCount;
    AKIObjectDeallocator _deallocatorFunctionPointer;
}AKIObject;

#define AKIObjectCreateOfType(type) __AKIObjectCreate(sizeof(type), __##type##Deallocate)

extern
void *__AKIObjectCreate(size_t size, AKIObjectDeallocator deallocator);

extern
void *AKIObjectRetain(void *object);

extern
void AKIObjectRelease(void *address);

extern
void __AKIObjectDeallocate(void *object);

extern
uint64_t AKIObjectRetainCount(void *object);

#endif /* AKIObject_h */
