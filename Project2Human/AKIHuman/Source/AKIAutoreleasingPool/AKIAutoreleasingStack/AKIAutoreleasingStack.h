//
//  AKIAutoreleasingStack.h
//  AKIHuman
//
//  Created by Alexey Khomych on 02.06.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#ifndef AKIAutoreleasingStack_h
#define AKIAutoreleasingStack_h

#include <stdio.h>
#include <stdbool.h>

#include "AKIObject.h"

typedef struct AKIAutoreleasingStack AKIAutoreleasingStack;

struct AKIAutoreleasingStack {
    AKIObject _super;
    AKIObject **_data;
    void *_head;
    uint64_t _capacity;
    uint64_t _count;
};

typedef enum {
    AKIAutoreleasingStackPopTypeNULL,
    AKIAutoreleasingStackPopTypeObject
}AKIAutoreleasingStackPopType;

extern
void _AKIAutoreleasingStackDeallocate(void *object);

extern
AKIAutoreleasingStack *AKIAutoreleasingStackCreateWithSize(uint64_t size);

extern
bool AKIAutoreleasingStackIsFull(AKIAutoreleasingStack *stack);

extern
bool AKIAutoreleasingStackIsEmpty(AKIAutoreleasingStack *stack);

extern
void AKIAutoreleasingStackPushObject(AKIAutoreleasingStack *stack, void *object);

extern
AKIAutoreleasingStackPopType AKIAutoreleasingStackPopObject(AKIAutoreleasingStack *stack);

#endif /* AKIAutoreleasingStack_h */
