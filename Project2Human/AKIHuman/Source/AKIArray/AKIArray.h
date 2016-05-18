//
//  AKIArray.h
//  AKIHuman
//
//  Created by Alexey Khomych on 16.05.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIArray_h
#define AKIArray_h

#include <stdio.h>
#include <stdbool.h>

#include "AKIObject.h"

typedef struct {
    AKIObject _super;
    
    void **_data;
    uint64_t _count;
    uint64_t _capacity;
}AKIArray;

extern
AKIArray *AKIArrayCreateWithCapacity(uint64_t capacity);

extern
void AKIArrayAddObject(AKIArray *array, void *object);

extern
void AKIArrayRemoveObjectAtIndex(AKIArray *array, uint64_t index);

extern
void AKIArrayRemoveAllObjects(AKIArray *array);

extern
void AKIArraySetCount(AKIArray *array, uint64_t count);

extern
uint64_t AKIArrayGetCount(AKIArray *array);

extern
bool AKIArrayContainsObject(AKIArray *array, void *object);

extern
uint64_t AKIArrayGetIndexOfObject(AKIArray *array, void *object);

extern
AKIArray *AKIArrayGetObjectAtIndex(AKIArray *array, uint64_t index);

extern
void __AKIArrayDeallocate(void *object);

extern
void AKIArraySetObjectAtIndex(AKIArray *array, void *object ,uint64_t index);

extern
uint64_t AKIArrayGetCapacity(AKIArray *array);

#endif /* AKIArray_h */
