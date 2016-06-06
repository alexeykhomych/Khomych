//
//  AKIAutoreleasingStack.c
//  AKIHuman
//
//  Created by Alexey Khomych on 02.06.16.
//  Copyright © 2016 Alexey Khomych. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AKIAutoreleasingStack.h"
#include "AKIObject.h"
#include "AKIConstants.h"
#include "AKIAutoreleasingPool.h"

#pragma mark -
#pragma mark Private Declarations

static
void AKIAutoreleasingStackSetCount(AKIAutoreleasingStack *stack, uint64_t count);

static
uint64_t AKIAutoreleasingStackGetCount(AKIAutoreleasingStack *stack);

static
void AKIAutoreleasingStackSetCapacity(AKIAutoreleasingStack *stack, uint64_t capacity);

static
uint64_t AKIAutoreleasingStackGetCapacity(AKIAutoreleasingStack *stack);

static
void AKIAutoreleasingStackSetData(AKIAutoreleasingStack *stack, void *data);

static
void *AKIAutoreleasingStackGetData(AKIAutoreleasingStack *stack);

static
void AKIAutoreleasingStackSetHead(AKIAutoreleasingStack *stack, void *head);

static
void *AKIAutoreleasingStackGetHead(AKIAutoreleasingStack *stack);

#pragma mark -
#pragma mark Public Implementations

void __AKIAutoreleasingStackDeallocate(void *object) {
    AKIAutoreleasingStack *stack = object;

    AKIAutoreleasingStackSetCapacity(stack, 0);
    AKIAutoreleasingStackSetCount(stack, 0);
    AKIAutoreleasingStackSetData(stack, NULL);
    
    __AKIObjectDeallocate(object);
}

AKIAutoreleasingStack *AKIAutoreleasingStackCreateWithSize(uint64_t size) {
    AKIAutoreleasingStack *stack = AKIObjectCreateOfType(AKIAutoreleasingStack);
    AKIAutoreleasingStackSetCapacity(stack, size);
    AKIAutoreleasingStackSetHead(stack, AKIAutoreleasingStackGetHead(stack));
    
    return stack;
}

bool AKIAutoreleasingStackIsFull(AKIAutoreleasingStack *stack) {
    return stack && AKIAutoreleasingStackGetCapacity(stack) == AKIAutoreleasingStackGetCount(stack);
}

bool AKIAutoreleasingStackIsEmpty(AKIAutoreleasingStack *stack) {
    return !(stack && AKIAutoreleasingStackGetCount(stack));
}

void AKIAutoreleasingStackPushObject(AKIAutoreleasingStack *stack, void *object) {
    if (!stack && !AKIAutoreleasingStackIsFull(stack)) {
        return;
    }
    
    AKIAutoreleasingStackSetHead(stack, object);
    AKIAutoreleasingStackSetCount(stack, AKIAutoreleasingStackGetCount(stack) + 1);
}

AKIAutoreleasingStackPopType AKIAutoreleasingStackPopObject(AKIAutoreleasingStack *stack) {
    return AKIAutoreleasingStackPopTypeNULL;
}

#pragma mark -
#pragma mark Private Implementations

void AKIAutoreleasingStackSetCount(AKIAutoreleasingStack *stack, uint64_t count) {
    AKIObjectAssignSetter(stack, _count, count);
}

uint64_t AKIAutoreleasingStackGetCount(AKIAutoreleasingStack *stack) {
    return stack ? stack->_count : kAKINotFound;
}

void AKIAutoreleasingStackSetCapacity(AKIAutoreleasingStack *stack, uint64_t capacity) {
    if (!stack) {
        return;
    }
    
    if (stack->_data) {
        free(stack->_data);
    }
    
    if (capacity) {
        stack->_data = calloc(1, capacity * sizeof(*stack->_data));
    }
    
    AKIObjectAssignSetter(stack, _capacity, capacity);
}

uint64_t AKIAutoreleasingStackGetCapacity(AKIAutoreleasingStack *stack) {
    return stack ? stack->_capacity : kAKINotFound;
}

void AKIAutoreleasingStackSetData(AKIAutoreleasingStack *stack, void *data) {
    AKIObjectSetStrong(stack, _data, data);
}

void *AKIAutoreleasingStackGetData(AKIAutoreleasingStack *stack) {
    return stack ? stack->_data : NULL;
}

void AKIAutoreleasingStackSetHead(AKIAutoreleasingStack *stack, void *object) {
    if (!stack) {
        return;
    }
    
    void **head = AKIAutoreleasingStackGetHead(stack);
    head = object;
    
    AKIObjectAssignSetter(stack, _head, head);
}

void *AKIAutoreleasingStackGetHead(AKIAutoreleasingStack *stack) {
    return stack ? stack->_head : NULL;
}
