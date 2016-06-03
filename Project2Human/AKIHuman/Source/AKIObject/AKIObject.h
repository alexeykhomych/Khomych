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

typedef void (*AKIObjectDeallocator)(void *object);
typedef void *(*AKIObjectOwnershipMethod)(void *);

typedef struct {
    uint64_t _referenceCount;
    AKIObjectDeallocator _deallocatorFunctionPointer;
} AKIObject;

#define AKIObjectCreateOfType(type) __AKIObjectCreate(sizeof(type), __##type##Deallocate)

extern
void *__AKIObjectCreate(size_t size, AKIObjectDeallocator deallocator);

extern
void __AKIObjectDeallocate(void *object);

extern
void *AKIObjectRetain(void *object);

extern
void AKIObjectRelease(void *address);

extern
uint64_t AKIObjectRetainCount(void *object);

extern
void __AKIObjectSetFieldValueWithMethod(void *object, void **ivar, void *newIvar, AKIObjectOwnershipMethod retainMethod);

#define AKIObjectAssignSetter(object, ivar, newIvar) { \
    if (object) { \
        object->ivar = newIvar; \
    } \
}

#define AKIObjectSetFieldValueWithMethod(object, ivar, newIvar, retainMethod) {\
    if (object) { \
        __AKIObjectSetFieldValueWithMethod((AKIObject *) object, (void **)&object->ivar, newIvar, (void *(*)(void *))retainMethod); \
    } \
}

#define AKIObjectSetStrong(object, ivar, newIvar) \
    AKIObjectSetFieldValueWithMethod(object, ivar, newIvar, AKIObjectRetain)

#endif /* AKIObject_h */
